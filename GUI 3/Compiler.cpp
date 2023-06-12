#include <fstream>
#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <iomanip>
#include <ios>
#include <stdlib.h>

static std::string output;

#include "Compiler.h"


using namespace $safeprojectname$;

// Function declaration

void main(array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    $safeprojectname$::Compiler form;
    Application::Run(% form);
}

////////////////////////////////////////Syntax Analyzer////////////////////////////////////////////////////




//using namespace std;

enum TokenType { Error, Keyword, Constant, Identifier, Operator, Special, Space };
//Error Token used just incase the code breaks :)

//global static file object to be used by all functions.
static std::fstream momin("input.txt", std::ios::in);
//static std::ofstream outputFile("output.txt", std::ios::app);


//incase of false input, returned to identify line no
//static std::string output;
static int line = 1;

//gap between nodes when printing a tree
static int gap_tree = 5;

//expected input value and found returned when false input
static std::string expected = "";
static std::string reason = "";
static std::string found = "";

struct Momin_tokenization
{
	std::string token;
	TokenType type;
};

bool is_comment(char ch_051)//checks if a comments it read, its all skipped.
{
	if (ch_051 == '/' && momin.peek() == '/')//single line comment
	{
		ch_051 = ' ';
		while (momin.get(ch_051))
		{
			if (ch_051 == '\n')
			{
				line++;
				return true;
				break;
			}
		}
	}
	else if (ch_051 == '/' && momin.peek() == '*')//multi line comment
	{
		ch_051 = ' ';
		while (momin.get(ch_051))
		{
			if (ch_051 == '\n')
				line++;

			if (ch_051 == '*' && momin.peek() == '/')
			{
				momin.get(ch_051);//to eat up the last / that was looked using peek
				return true;
				break;
			}
		}
	}
	return false;
};

bool is_keyword(std::string word_051)
{
	if (word_051 == "IF" || word_051 == "ELSE" || word_051 == "FOR" || word_051 ==
		"DO" || word_051 == "WHILE" || word_051 == "EXIT" || word_051 == "INT" || word_051 ==
		"LONG" || word_051 == "DOUBLE" || word_051 == "CHAR" || word_051 == "FLOAT" || word_051
		== "STRING" || word_051 == "BEGIN" || word_051 == "END")
		return true;
	else
		return false;
};

bool is_identifier(std::string& word_051, char ch_051)
{
	if (word_051 == "" && ((isalpha(ch_051) || ch_051 == '_')))//checks for word starting with alphabets
	{
		word_051 += ch_051;
		do
		{
			char next_051 = momin.peek();
			if (word_051 != "" && ((isalpha(next_051) || isdigit(next_051) || next_051 == '_' || next_051 == '.')))//variable names can have numbers after first char
			{
				word_051 += next_051;
				continue;
			}
			else
			{
				return true;
			}
		} while (momin.get(ch_051));
		return true;
	}
	else
	{
		return false;
	}
};

bool is_number(std::string& word_051, char ch_051, int& count)
{
	count = 0;
	if (word_051 == "" && isdigit(ch_051))//if word starts with a digit, its a number
	{
		word_051 += ch_051;
		do
		{
			//peek used bcz if not mathcing requirements for number,
			//reading pointer is not disturbed. i.e doesnt eat the next char.
			char next_051 = momin.peek();
			if (word_051 != "" && (isdigit(next_051) || next_051 == '.'))
			{
				if (next_051 == '.')
					count++;
				word_051 += next_051;
				continue;//continues till a char is a digit
			}
			else
			{
				return true;
			}
		} while (momin.get(ch_051));
		return true;
	}
	else
		return false;
};

bool is_special(std::string& word_051, char ch_051)
{
	if (ispunct(ch_051))
	{
		//cout << ch_051;
		word_051 = "";
		word_051 += ch_051;
		return true;
	}
	else
		return false;
};

bool is_operator(std::string& word_051, char ch_051)
{
	if (ch_051 == '+' || ch_051 == '-' || ch_051 == '/' || ch_051 == '*' || ch_051 == '=' || ch_051 == '^' || ch_051 == '!' || ch_051 == '|' || ch_051 == '&' || ch_051 == '<' || ch_051 == '>')
	{
		//check next char in the file for double character operators
		if ((ch_051 == '+' && momin.peek() == '+') || (ch_051 == '-' && momin.peek() == '-') || (ch_051 == '+' && momin.peek() == '=') || (ch_051 == '-' && momin.peek() == '=') || (ch_051 == '/' && momin.peek() == '=') || (ch_051 == '*' && momin.peek() == '=') || (ch_051 == '%' && momin.peek() == '=') || (ch_051 == '>' && momin.peek() == '=') || (ch_051 == '<' && momin.peek() == '=') || (ch_051 == '=' && momin.peek() == '=') || (ch_051 == '&' && momin.peek() == '&') || (ch_051 == '|' && momin.peek() == '|'))
		{
			word_051 += ch_051;
			momin.get(ch_051);
			word_051 += ch_051;
			return true;
		}
		//cout << ch_051;
		word_051 += ch_051;
		return true;
	}
	else
		return false;
};

Momin_tokenization Lexical()
{
	char ch_051;
	std::string word_051 = "";
	Momin_tokenization token_051;
	momin.get(ch_051);
	do
	{
		int count;
		//new lines and tabs are replaced by space to be used as a standard delimeter throughout the code for simplicity.
		if (ch_051 == '\n' || ch_051 == '\t' || ch_051 == ' ')
		{
			if (ch_051 == '\n')
				line++;
			ch_051 = ' ';
		}

		if (is_comment(ch_051))
		{
			continue;
		}
		if (is_identifier(word_051, ch_051))
		{
			//cout << word_051;
			if (is_keyword(word_051))
			{
				token_051.token = word_051;
				token_051.type = Keyword;
				return token_051;
			}
			else
			{
				token_051.token = word_051;
				token_051.type = Identifier;
				return token_051;
			}
			//return Identifier;
		}
		else if (is_number(word_051, ch_051, count))
		{
			if (count > 1 && reason == "")
			{
				reason = "Invalid Number";
				token_051.token = word_051;
				token_051.type = Error;
				return token_051;
			}
			token_051.token = word_051;
			token_051.type = Constant;
			return token_051;
		}
		else if (is_operator(word_051, ch_051))
		{
			token_051.token = word_051;
			token_051.type = Operator;
			return token_051;
		}
		else if (is_special(word_051, ch_051))
		{
			token_051.token = word_051;
			token_051.type = Special;
			return token_051;
		}
		if (ch_051 == ' ')//eats up and skips empty spaces in the code
		{
			word_051 = "";
			continue;
		}

		token_051.token = "Error_val";
		token_051.type = Error;
		return token_051;
	} while (momin.get(ch_051));
	//Error Token used just incase the code breaks and reaches this part of the function.
	token_051.token = "<eof>";
	token_051.type = Space;
	return token_051;
};

void token_name(Momin_tokenization token)
{
	if (token.token.length() == 1 && token.type == Special)
	{
		switch (token.token[0])
		{
		case('{'):
			output.append("\t\topenign curly bracket\t");
			break;
		case('}'):
			output.append("\t\tclosing curly bracket\t");
			break;
		case('('):
			output.append("\t\topenign bracket\t");
			break;
		case(')'):
			output.append("\t\tclosing bracket\t");
			break;
		case('['):
			output.append("\t\topening square bracket\t");
			break;
		case(']'):
			output.append("\t\tclosing square bracket\t");
			break;
		case('$'):
			output.append("\t\tdollar sign\t");
			break;
		case(':'):
			output.append("\t\tcollon\t");
			break;
		case(';'):
			output.append("\t\tsemi collon\t");
			break;
		case('_'):
			output.append("\t\tunderscore\t");
			break;
		case(','):
			output.append("\t\tcomma\t");
			break;
		default:
			output.append("\t\tunknown character\t");
			break;
		}
	}
	else if (token.type == Operator)
	{
		if (token.token.length() == 1)
		{
			switch (token.token[0])
			{
			case('+'):
				output.append("\t\tplus Operator\t");
				break;
			case('-'):
				output.append("\t\tminus Operator\t");
				break;
			case('*'):
				output.append("\t\tmultiply Operator\t");
				break;
			case('/'):
				output.append("\t\tdivide Operator\t");
				break;
			case('='):
				output.append("\t\tequal Operator\t");
				break;
			case('&'):
				output.append("\t\tampersand Operator\t");
				break;
			case('%'):
				output.append("\t\tpercentage Operator\t");
				break;
			case('<'):
				output.append("\t\tless than Operator\t");
				break;
			case('>'):
				output.append("\t\tgreater than Operator\t");
				break;
			default:
				output.append("\t\tunknown Operator\t");
			}
		}
		else if (token.token.length() == 2)
		{
			if (token.token[0] == '/' && token.token[1] == '/')
				output.append("\t\tsingle line comment\n");
			else if (token.token[0] == '+' && token.token[1] == '+')
				output.append("\t\tincrement Operator\t");
			else if (token.token[0] == '-' && token.token[1] == '-')
				output.append("\t\tdecrement Operator\t");
			else if (token.token[0] == '+' && token.token[1] == '=')
				output.append("\t\tincrement and assign Operator\t");
			else if (token.token[0] == '-' && token.token[1] == '=')
				output.append("\t\tdecrement and assign Operator\t");
			else if (token.token[0] == '/' && token.token[1] == '=')
				output.append("\t\tdevide and assign Operator\t");
			else if (token.token[0] == '*' && token.token[1] == '=')
				output.append("\t\tmultiply and assign Operator\t");
			else if (token.token[0] == '%' && token.token[1] == '=')
				output.append("\t\tmod and assign Operator\t");
			else if (token.token[0] == '>' && token.token[1] == '=')
				output.append("\t\tgreater and equal Operator\t");
			else if (token.token[0] == '<' && token.token[1] == '=')
				output.append("\t\tless and equal Operator\t");
			else if (token.token[0] == '=' && token.token[1] == '=')
				output.append("\t\tequal equal Operator\t");
			else
				output.append("\t\tUnknown Operator\t");
		}
	}
	else if (token.type == Keyword)
	{
		if (token.token == "IF" || token.token == "ELSE")
			output.append("\t\tConditional Keyword\t");
		else if (token.token == "INT" || token.token == "FLOAT" || token.token == "DO" || token.token == "WHILE" || token.token ==
			"LONG" || token.token == "DOUBLE" || token.token == "STRING" || token.token == "CHAR" || token.token == "BEGIN" || token.token == "END")
			output.append("\tDatatype Keyword\t");
	}
	else if (token.type == Identifier)
		output.append("\t\tIdentifier\t");
	else if (token.type == Constant)
		output.append("\t\tConstant\t");
	else
		output.append("\t\tunkown token\t");
};



void print(Momin_tokenization &token)
{
	if (token.type != Error && token.type != Space)
	{
		output.append(std::to_string(token.type));
		output.append("\t\t");
		output.append(token.token);
		token_name(token);
		output.append("\n");

		//outputFile << output; 

	}
};


static bool flag = 0;
static Momin_tokenization CurrentToken;

void unGet_Momin()
{
	flag = 1;
}

Momin_tokenization Get_Momin()
{
	if (!flag && !momin.eof()) //when flag 0, run this vv
	{
		CurrentToken = Lexical();
		gap_tree += 2;
		print(CurrentToken);

		return CurrentToken;
	}
	else
	{
		flag = 0;
		return CurrentToken;
	}
}

void print_tokens()
{
	output = "";
	momin.seekg(0);
	Momin_tokenization token;
	while (!momin.eof())
	{
		token = Get_Momin();
	}
	momin.clear();
}

void print_error()
{
	output = "";

	if (CurrentToken.token == "{" || CurrentToken.token == "}")
		line--;
	output.append("\n");
	output.append("Error at line: ");
	output.append(std::to_string(line));

	if (reason == "")
	{
		output.append("\nExpected: \t");
		output.append(expected);

		output.append("\nFound: \t");
		output.append(CurrentToken.token);
	}
	else
	{
		output.append("\n\n");
		output.append(reason);
	}
}


//###############################################################

bool OR_Momin();
bool AND_Momin();
bool GreaterLesser_Momin();
bool MulDiv_Momin();
bool AddSub_Momin();
bool Equal_Momin();
bool ID_Const_Momin();

bool Program();
bool Statement_list();
bool Statement();
bool Assignment();
bool Expression();

bool IF();
bool DO();
bool WHILE();

bool is_datatype(Momin_tokenization);
bool Function();

//###############################################################

bool OR_Momin()
{
	Momin_tokenization token;
	do
	{
		if (!AND_Momin())
			return false;

		token = Get_Momin();
		//expected = "<Relational_Operator>";

		if (token.type == Error)
			return false;

	} while (token.token == "||");

	if (token.type == Error)
		return false;
	unGet_Momin();
	return true;
}

bool AND_Momin()
{
	Momin_tokenization token;
	do
	{
		if (!Equal_Momin())
			return false;
		token = Get_Momin();
		if (token.type == Error)
			return false;
	} while (token.token == "&&");

	if (token.type == Error)
		return false;

	unGet_Momin();
	return true;
}

bool Equal_Momin()
{
	Momin_tokenization token;
	do
	{
		if (!GreaterLesser_Momin())
			return false;
		token = Get_Momin();
		if (token.type == Error)
			return false;
	} while (token.token == "==" || token.token == "!=");

	if (token.type == Error)
		return false;
	unGet_Momin();
	return true;
}

bool GreaterLesser_Momin()
{
	Momin_tokenization token;
	do
	{
		if (!AddSub_Momin())
			return false;
		token = Get_Momin();
		if (token.type == Error)
			return false;
	} while (token.token == "<" || token.token == "<=" || token.token == ">=" || token.token == ">");
	if (token.type == Error)
		return false;
	unGet_Momin();
	return true;
}

bool AddSub_Momin()
{
	Momin_tokenization token;
	do
	{
		if (!MulDiv_Momin())
			return false;
		token = Get_Momin();
		if (token.type == Error)
			return false;
	} while (token.token == "+" || token.token == "-");

	if (token.type == Error)
		return false;

	unGet_Momin();
	return true;
}

bool MulDiv_Momin()
{
	Momin_tokenization token;
	do
	{
		if (!ID_Const_Momin())
			return false;
		token = Get_Momin();
		if (token.type == Error)
			return false;
	} while (token.token == "*" || token.token == "/");

	if (token.type == Error)
		return false;

	unGet_Momin();
	return true;
}

bool ID_Const_Momin()
{
	Momin_tokenization token = Get_Momin();
	if (token.type == Constant || token.type == Identifier)
	{
		return true;
	}
	else if (token.token == "(") //|| token.value == "[" || token.value == "{"
	{
		if (OR_Momin())
		{
			token = Get_Momin();
			expected = ")";
			if (token.token == ")") // || token.value == "]" || token.value == "}"
			{
				return true;
			}

		}
	}
	expected = "<ID> or <CONSTANT>";
	unGet_Momin();
	return false;
}

bool Program()
{
	line = 1;
	output = "";
	momin.seekg(0);
	Momin_tokenization token = Get_Momin();
	expected = "BEGIN";
	if (token.token == "BEGIN")
	{
		if (Statement_list())
		{
			token = Get_Momin();
			if (token.token == "}") {
				reason = "No matching '{' found for '}'";
				line++;
			}
			expected = "END";
			if (token.token == "END")
			{
				//outputFile.open("output.txt");
				
				
				//outputFile << output; // Write the string to the file
				//outputFile.close(); // Close the file

				//momin.close();
				momin.clear();
				return true;
			}
		}
	}
	print_error();
	momin.clear();
	return false;
}

bool Statement_list()  // statement list 
{
	if (Statement())
	{
		do
		{
			Momin_tokenization token = Get_Momin();
			if (token.type == Identifier || token.token == "IF" || token.token == "DO" || token.token == "WHILE")
			{
				unGet_Momin();
				if (!Statement())
				{
					unGet_Momin();
					return false;
				}
			}
			else
			{
				unGet_Momin();
				break;
			}
		} while (1);

		return true;
	}
	unGet_Momin();
	return false;
}

bool Statement()
{
	//	Momin_tokenization token = Get_Momin();
	if ( WHILE() || DO() || Function() || Assignment()||IF())
		return true;
	unGet_Momin();
	return false;
}

bool Assignment()
{
	Momin_tokenization token = Get_Momin();
	if (token.type == Identifier)
	{
		token = Get_Momin();
		if (token.token == "=" || token.token == "+=" || token.token == "-=" || token.token == "*=" || token.token == "/=" || token.token == ">=" || token.token == "<=" || token.token == "==" || token.token == "^=" || token.token == "&=")
		{
			if (Expression())
			{
				token = Get_Momin();
				expected = ";";
				if (token.token == ";")
				{
					return true;
				}

				//unGet_Momin();
				return false;
			}
		}
		if (reason == "")
			reason = "Invalid syntax for Assignment";

	}

	unGet_Momin();
	return false;

}

bool Expression()
{

	if (OR_Momin())
		return true;
	if (reason == "")
	{
		reason = "Invalid syntax for Expression";
	}
	return false;
}

bool is_datatype(Momin_tokenization token)
{
	if (token.type == Keyword)
	{
		if (token.token == "VOID" || token.token == "INT" || token.token == "FLOAT" || token.token == "LONG" || token.token == "DOUBLE" || token.token == "STRING")
			return true;
	}
	return false;
}

bool Function()
{
	Momin_tokenization token = Get_Momin();
	bool is_curly = true;

	if (!is_datatype(token))
	{
		unGet_Momin();
		return false;
	}

	token = Get_Momin();
	if (token.type != Identifier)
	{
		expected = "<Function_name>";
		unGet_Momin();
		return false;
	}

	token = Get_Momin();
	if (token.token != "(")
	{
		expected = "(";
		unGet_Momin();
		return false;
	}

	token = Get_Momin();
	if (token.token != ")")
	{
		expected = ")";
		if (!is_datatype(token))
		{
			unGet_Momin();
			return false;
		}
		token = Get_Momin();
		if (token.type != Identifier)
		{
			expected = "<Function_name>";
			unGet_Momin();
			return false;
		}

		token = Get_Momin();
		if (token.token != ")")
		{
			expected = ")";
			unGet_Momin();
			return false;
		}
	}

	token = Get_Momin();
	if (token.token != "{")
	{
		expected = "{";
		unGet_Momin();
		return false;
	}
	token = Get_Momin();
	if (token.token == "}")
		return true;
	else
		unGet_Momin();

	if (!Statement_list())
	{
		unGet_Momin();
		return false;
	}
	token = Get_Momin();
	if (token.token != "}")
	{
		expected = "}";
		unGet_Momin();
		return false;
	}

	return true;
}

bool IF()
{
	Momin_tokenization token = Get_Momin();
	bool is_curly = true;


	if (token.token != "IF")
	{
		unGet_Momin();
		return false;

	}

	token = Get_Momin();
	if (token.token != "(")
	{
		expected = "(";
		unGet_Momin();
		return false;
	}


	if (!Expression())
	{
		unGet_Momin();
		return false;
	}


	token = Get_Momin();
	if (token.token != ")")
	{
		expected = ")";
		unGet_Momin();
		return false;
	}

	token = Get_Momin();
	if (token.token != "{")
	{
		unGet_Momin();
		is_curly = false;
	}

	if (is_curly)
	{
		token = Get_Momin();
		if (token.token == "}")
			return true;
		else
			unGet_Momin();
		if (!Statement_list())
		{
			unGet_Momin();
			return false;
		}
	}
	else
	{
		if (!Statement())
		{
			unGet_Momin();
			return false;
		}
	}

	if (is_curly)
	{
		token = Get_Momin();
		if (token.token != "}")
		{
			expected = "}";
			unGet_Momin();
			return false;
		}
		//unGet_Momin();
	}
	is_curly = true;

	//if else not encountered, return true bcz its only if
	token = Get_Momin();
	if (token.token != "ELSE")
	{
		unGet_Momin();
		return true;
	}

	token = Get_Momin();
	if (token.token != "{")
	{
		unGet_Momin();
		//CHECK IF AGAIN FOR ELSE IF
		if (IF())
			return true;
		else
		{
			unGet_Momin();
			is_curly = false;
		}
	}

	if (is_curly)
	{
		token = Get_Momin();
		if (token.token == "}")
			return true;
		else
			unGet_Momin();
		if (!Statement_list())
		{
			unGet_Momin();
			return false;
		}
	}
	else {
		if (!Statement())
		{
			unGet_Momin();
			return false;
		}
	}

	if (is_curly)
	{
		token = Get_Momin();
		if (token.token != "}")
		{
			expected = "}";
			unGet_Momin();
			return false;
		}
		//unGet_Momin();
	}
	//is_curly = true;
	//unGet_Momin();
	return true;
}

bool DO()
{
	Momin_tokenization token = Get_Momin();
	bool is_curly = true;

	if (token.token != "DO")
	{
		unGet_Momin();
		return false;
	}

	token = Get_Momin();
	if (token.token != "{")
	{

		unGet_Momin();
		is_curly = false;
	}

	if (is_curly)
	{
		token = Get_Momin();
		if (token.token == "}")
			return true;
		else
			unGet_Momin();
		if (!Statement_list())
		{
			unGet_Momin();
			return false;
		}
	}
	else {
		if (!Statement())
		{
			unGet_Momin();
			return false;
		}
	}

	if (is_curly)
	{
		token = Get_Momin();
		if (token.token != "}")
		{
			expected = "}";
			unGet_Momin();
			return false;
		}
		//unGet_Momin();
	}

	token = Get_Momin();
	if (token.token != "WHILE")
	{
		expected = "WHILE";
		unGet_Momin();
		return false;
	}

	token = Get_Momin();
	if (token.token != "(")
	{
		expected = "(";
		unGet_Momin();
		return false;
	}

	if (!Expression())
	{
		unGet_Momin();
		return false;
	}

	token = Get_Momin();
	if (token.token != ")")
	{
		expected = ")";
		unGet_Momin();
		return false;
	}

	token = Get_Momin();
	if (token.token != ";")
	{
		expected = ";";
		line--;
		unGet_Momin();
		return false;
	}

	return true;
}

bool WHILE()
{
	Momin_tokenization token = Get_Momin();
	bool is_curly = true;


	if (token.token != "WHILE") {
		unGet_Momin();
		return false;
	}

	token = Get_Momin();
	if (token.token != "(")
	{
		expected = "(";
		unGet_Momin();
		return false;
	}

	if (!Expression())
	{
		unGet_Momin();
		return false;
	}

	token = Get_Momin();
	if (token.token != ")")
	{
		expected = ")";
		unGet_Momin();
		return false;
	}

	token = Get_Momin();
	if (token.token != "{")
	{
		unGet_Momin();
		is_curly = false;
	}

	if (is_curly)
	{
		token = Get_Momin();
		if (token.token == "}")
			return true;
		else
			unGet_Momin();
		if (!Statement_list())
		{
			unGet_Momin();
			return false;
		}
	}
	else {
		if (!Statement())
		{
			unGet_Momin();
			return false;
		}
	}

	if (is_curly)
	{
		token = Get_Momin();
		if (token.token != "}")
		{
			expected = "}";
			unGet_Momin();
			return false;
		}
		//unGet_Momin();
	}

	return true;
}


//###########################################################

struct treenode
{
	Momin_tokenization token1;
	treenode* leftchild;
	treenode* rightchild;
	treenode* sibling;
};

bool TreeProgram();
treenode* TreeStatementList();
treenode* TreeAssignment();
treenode* tree_id_const();
treenode* tree_mul_div();
treenode* tree_plus_minus();

Momin_tokenization token;

void printTree(treenode* node, int indent = 0)
{
	if (node == nullptr)
		return;

	// Print the current node's token with indentation

	for (int i = 0; i <= indent; i++){
		output.append(" ");
	}
	output.append(node->token1.token);

	// Print the right child recursively
	if (node->rightchild != nullptr)
	{
		output.append("\n");//<< std::setw(indent )<< "L" ;//RIght Child
		printTree(node->rightchild, indent - 4);
	}
	// Print the left child recursively
	if (node->leftchild != nullptr)
	{
		output.append("\n");// << std::setw(indent + 4) <<"R";//Left Child
		printTree(node->leftchild, indent + 4);
	}
}

float evaluate_expression(treenode* root) 
{
	if (root == nullptr) {
		// Empty tree
		output.append("Error: Empty tree!");
		return 42069;//this number returned incase of an error
	}

	if (root->token1.type == Constant) {
		return stoi(root->token1.token);
	}
	if (root->token1.type == Identifier) 
	{
		return 0;//if an integer is part of the expression, its value will be assigned 0
	}

	float leftValue = evaluate_expression(root->leftchild);
	float rightValue = evaluate_expression(root->rightchild);

	if (root->token1.token == "+")
	{
		return leftValue + rightValue;
	}
	else if (root->token1.token == "-")
	{
		return leftValue - rightValue;
	}
	else if (root->token1.token == "*")
	{
		return leftValue * rightValue;
	}
	else if (root->token1.token == "/")
	{
		if (rightValue == 0) 
		{
			output.append("Error: Division by zero!");
			return 42069;//this number returned incase of an error
		}
		return leftValue / rightValue;
	}
	else {
		output.append("Error: Invalid operator!");
		return 42069;//this number returned incase of an error
	}
}

bool print_evaluation()
{
	output = "";
	momin.seekg(0);
	treenode* t = tree_plus_minus();

	float value = evaluate_expression(t);
	int val2 = value;

	//this number assigned incase of an error
	if (value == 42069)
		return false;

	if (value == val2)
	{
		output = "";
		output.append("The Evaluated Value is: ");
		output.append(std::to_string(val2));
		momin.clear();
		delete t;
		return true;
	}

	output = "";
	output.append("The Evaluated Value is: ");
	output.append(std::to_string(value));
	momin.clear();
	delete t;
	return true;
}



bool TreeProgram()
{
	output = "";
	momin.seekg(0);
	treenode* fulltree;
	token = Get_Momin();
	if (token.token == "BEGIN")
	{
		fulltree = TreeStatementList();
		if (fulltree != nullptr)
		{
			output = " ";
			printTree(fulltree);
		}
		token = Get_Momin();
		if (token.token == "END")
		{
			momin.clear();
			delete fulltree;
			return true;
		}

			
	}
	return false;
}

treenode* TreeStatementList()
{
	treenode* stree;
	treenode* prevtree = nullptr;
	treenode* stmttree = nullptr;
	if ((prevtree = TreeAssignment()))
	{

		stmttree = prevtree;
		stmttree->sibling = NULL;
		do
		{
			prevtree->sibling = NULL;
			token = Get_Momin();
			if (token.token == "IF" || token.token == "DO" || token.type == Identifier || token.token == "WHILE")
			{
				unGet_Momin();
				if ((stree = TreeAssignment()) == nullptr)
				{
					return nullptr;
				}
				stree->sibling = nullptr;
				prevtree->sibling = stree;
				prevtree = stree;
			}
			else
			{
				unGet_Momin();
				break;
			}
		} while (true);
		return stmttree;
	}
	return nullptr;
}

treenode* TreeAssignment()
{
	treenode* identifierNode = NULL;
	treenode* tree = NULL;
	treenode* operatorNode = NULL;
	treenode* expressionNode = NULL;

	token = Get_Momin();
	if (token.type == Identifier)
	{
		identifierNode = new treenode;
		identifierNode->token1.type = Identifier;
		identifierNode->token1.token = token.token;
		identifierNode->leftchild = NULL;
		identifierNode->rightchild = NULL;

		token = Get_Momin();
		if (token.token == "=")
		{
			operatorNode = new treenode;
			operatorNode->token1.type = Operator;
			operatorNode->token1.token = token.token;
			operatorNode->leftchild = NULL;
			operatorNode->rightchild = NULL;

			identifierNode->leftchild = operatorNode;
			if (expressionNode = tree_plus_minus())
			{
				operatorNode->leftchild = expressionNode;
				tree = identifierNode;

				token = Get_Momin();
				if (token.token == ";")
				{
					return identifierNode;
				}
			}
		}
	}

	return nullptr;
}

treenode* tree_plus_minus()
{
	treenode* t, * p = nullptr;
	int flag = 0;
	do
	{
		t = tree_mul_div();
		if (flag)
		{
			p->rightchild = t;
			flag = 0;
			t = p;
		}
		token = Get_Momin();
		if (token.token == "+" || token.token == "-")
		{
			p = new treenode;
			p->token1 = token;
			p->leftchild = t;
			flag = 1;
		}
	} while (token.token == "+" || token.token == "-");
	unGet_Momin();
	return t;
}

treenode* tree_mul_div()
{
	treenode* t, * p = nullptr;
	int flag = 0;
	do {
		t = tree_id_const();
		if (flag)
		{
			p->rightchild = t;
			flag = 0;
			t = p;
		}
		token = Get_Momin();
		if (token.token == "*" || token.token == "/")
		{
			p = new treenode;
			p->token1 = token;
			p->leftchild = t;
			flag = 1;
		}
	} while (token.token == "*" || token.token == "/");
	unGet_Momin();
	return t;
}

treenode* tree_id_const()
{
	treenode* t = nullptr;
	token = Get_Momin();
	switch (token.type)
	{
	case Constant:

		t = new treenode();
		t->token1 = token;
		t->leftchild = nullptr;
		t->rightchild = nullptr;
		return t;
		break;
	case Identifier:
		t = new treenode;
		t->token1 = token;
		t->leftchild = nullptr;
		t->rightchild = nullptr;
		return t;
		break;
	default:
		if (token.token == "(")
		{
			t = tree_plus_minus();
			token = Get_Momin();
			if (token.token == ")")
			{
				return t;
				break;
			}
		}
		break;
	}
	return t;
}