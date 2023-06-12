#pragma once

//function prototypes
bool Program();
void print_error();
bool TreeProgram();
bool print_evaluation();


namespace $safeprojectname$ {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class Compiler : public System::Windows::Forms::Form
	{
	public:
		Compiler(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Compiler()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::RichTextBox^ richTextBox2;
	private: System::Windows::Forms::Button^ button2;

	private: System::Windows::Forms::ContextMenuStrip^ contextMenuStrip1;
	private: System::Windows::Forms::Button^ button3;

	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Button^ Evaluate;
	private: System::Windows::Forms::Label^ label3;

	private: System::ComponentModel::IContainer^ components;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->Evaluate = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// richTextBox1
			// 
			this->richTextBox1->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->richTextBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBox1->Location = System::Drawing::Point(0, 53);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(562, 525);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button1->Font = (gcnew System::Drawing::Font(L"Cooper Black", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(456, 4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(99, 41);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Syntax";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Compiler::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Cooper Black", 13.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(10, 11);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(79, 26);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Input";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Cooper Black", 13.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(3, 11);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(99, 26);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Output";
			// 
			// richTextBox2
			// 
			this->richTextBox2->BackColor = System::Drawing::Color::DimGray;
			this->richTextBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBox2->Location = System::Drawing::Point(568, 53);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(543, 525);
			this->richTextBox2->TabIndex = 4;
			this->richTextBox2->Text = L"";
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button2->Font = (gcnew System::Drawing::Font(L"Cooper Black", 10.2F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(447, 4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 38);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Clear";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Compiler::button2_Click);
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->button3->Font = (gcnew System::Drawing::Font(L"Cooper Black", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(367, 4);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(83, 41);
			this->button3->TabIndex = 6;
			this->button3->Text = L"Tree";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &Compiler::button3_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ButtonShadow;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel1->Controls->Add(this->Evaluate);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->button3);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Location = System::Drawing::Point(0, 1);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(562, 52);
			this->panel1->TabIndex = 7;
			// 
			// Evaluate
			// 
			this->Evaluate->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->Evaluate->Font = (gcnew System::Drawing::Font(L"Cooper Black", 10.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Evaluate->Location = System::Drawing::Point(249, 4);
			this->Evaluate->Name = L"Evaluate";
			this->Evaluate->Size = System::Drawing::Size(112, 41);
			this->Evaluate->TabIndex = 7;
			this->Evaluate->Text = L"Evaluate";
			this->Evaluate->UseVisualStyleBackColor = false;
			this->Evaluate->Click += gcnew System::EventHandler(this, &Compiler::Evaluate_Click);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel2->Controls->Add(this->label2);
			this->panel2->Controls->Add(this->button2);
			this->panel2->Location = System::Drawing::Point(568, 1);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(543, 52);
			this->panel2->TabIndex = 8;
			// 
			// label3
			// 
			this->label3->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::Lime;
			this->label3->Location = System::Drawing::Point(578, 517);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(514, 47);
			this->label3->TabIndex = 9;
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Compiler
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LightGray;
			this->ClientSize = System::Drawing::Size(1104, 573);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->richTextBox2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->richTextBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"Compiler";
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->Text = L"Compiler";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
		
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		//empty the file from previous stuff
		String^ text = " ";

		//empty the input and outfiles
		StreamWriter^ writer = gcnew StreamWriter("input.txt");
		writer->WriteLine(text);
		writer->Close();
		/*
		StreamWriter^ writer2 = gcnew StreamWriter("output.txt");
		writer2->WriteLine(text);
		writer2->Close();
		*/

		// Get the text from the RichTextBox control
		text = richTextBox1->Text;
		writer = gcnew StreamWriter("input.txt");
		writer->WriteLine(text);
		writer->Close();

		if (Program())
		{
			//MessageBox::Show("Valid Syntax");
			this->label3->ForeColor = System::Drawing::Color::Lime;
			label3->Text = "Valid Input";
		}
		else
		{
			//MessageBox::Show("In-valid Syntax!");
			this->label3->ForeColor = System::Drawing::Color::Crimson;
			label3->Text = "In-Valid Input";
			print_error();
		}
			

		//String^ cliString = marshal_as<String^>(cppString);

		text = gcnew String(output.c_str());
		writer = gcnew StreamWriter("output.txt");
		writer->WriteLine(text);
		writer->Close();


		// Read the content from the output.txt file
		
		StreamReader^ reader = gcnew StreamReader("output.txt");
		String^ content = reader->ReadToEnd();
		reader->Close();

		// Set the content to richTextBox1
		richTextBox2->Text = content;

	}
		  
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

		
		// Save the text to a text file
		StreamWriter^ writer = gcnew StreamWriter("output.txt");
		writer->WriteLine(" ");
		writer->Close();


		StreamReader^ reader = gcnew StreamReader("output.txt");
		String^ content = reader->ReadToEnd();
		reader->Close();
		richTextBox2->Text = content;
	}

private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	//empty the file from previous stuff

	String^ text = " ";

	//empty the input and outfiles
	StreamWriter^ writer = gcnew StreamWriter("input.txt");
	writer->WriteLine(text);
	writer->Close();
	/*
	StreamWriter^ writer2 = gcnew StreamWriter("output.txt");
	writer2->WriteLine(text);
	writer2->Close();
	*/

	// Get the text from the RichTextBox control
	text = richTextBox1->Text;
	writer = gcnew StreamWriter("input.txt");
	writer->WriteLine(text);
	writer->Close();

	if (TreeProgram())
	{
		//MessageBox::Show("Valid Expression");
		this->label3->ForeColor = System::Drawing::Color::Lime;
		label3->Text = "Valid Input";
	}
	else
	{
		//MessageBox::Show("In-valid Expression");
		this->label3->ForeColor = System::Drawing::Color::Crimson;
		label3->Text = "In-Valid Input";
	}


	//String^ cliString = marshal_as<String^>(cppString);

	text = gcnew String(output.c_str());
	writer = gcnew StreamWriter("output.txt");
	writer->WriteLine(text);
	writer->Close();


	// Read the content from the output.txt file

	StreamReader^ reader = gcnew StreamReader("output.txt");
	String^ content = reader->ReadToEnd();
	reader->Close();

	// Set the content to richTextBox1
	richTextBox2->Text = content;

}

private: System::Void Evaluate_Click(System::Object^ sender, System::EventArgs^ e) {

	//empty the file from previous stuff
	String^ text = " ";

	//empty the input and outfiles
	StreamWriter^ writer = gcnew StreamWriter("input.txt");
	writer->WriteLine(text);
	writer->Close();
	/*
	StreamWriter^ writer2 = gcnew StreamWriter("output.txt");
	writer2->WriteLine(text);
	writer2->Close();
	*/

	// Get the text from the RichTextBox control
	text = richTextBox1->Text;
	writer = gcnew StreamWriter("input.txt");
	writer->WriteLine(text);
	writer->Close();

	if (print_evaluation())
	{
		//MessageBox::Show("Valid Expression");
		this->label3->ForeColor = System::Drawing::Color::Lime;
		label3->Text = "Valid Input";
	}
	else
	{
		//MessageBox::Show("In-valid Expression");
		this->label3->ForeColor = System::Drawing::Color::Crimson;
		label3->Text = "In-Valid Input";
	}


	//String^ cliString = marshal_as<String^>(cppString);

	text = gcnew String(output.c_str());
	writer = gcnew StreamWriter("output.txt");
	writer->WriteLine(text);
	writer->Close();


	// Read the content from the output.txt file

	StreamReader^ reader = gcnew StreamReader("output.txt");
	String^ content = reader->ReadToEnd();
	reader->Close();

	// Set the content to richTextBox1
	richTextBox2->Text = content;

}
};
}


