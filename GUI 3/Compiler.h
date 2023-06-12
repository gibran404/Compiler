#pragma once

//function prototypes
bool Program();
void print_error();
bool TreeProgram();
bool print_evaluation();
void print_tokens();


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
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Panel^ panel4;

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
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->Evaluate = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel4->SuspendLayout();
			this->SuspendLayout();
			// 
			// richTextBox1
			// 
			this->richTextBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->richTextBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(33)),
				static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->richTextBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBox1->ForeColor = System::Drawing::SystemColors::InactiveBorder;
			this->richTextBox1->Location = System::Drawing::Point(2, 57);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(668, 527);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)));
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)),
				static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)));
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Cooper Black", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->button1->Location = System::Drawing::Point(341, 7);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(105, 41);
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
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label1->Location = System::Drawing::Point(21, 16);
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
			this->label2->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label2->Location = System::Drawing::Point(23, 16);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(99, 26);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Output";
			// 
			// richTextBox2
			// 
			this->richTextBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->richTextBox2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(33)),
				static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->richTextBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->richTextBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->richTextBox2->ForeColor = System::Drawing::SystemColors::InactiveBorder;
			this->richTextBox2->Location = System::Drawing::Point(680, 55);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(658, 531);
			this->richTextBox2->TabIndex = 4;
			this->richTextBox2->Text = L"";
			// 
			// button2
			// 
			this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)));
			this->button2->Cursor = System::Windows::Forms::Cursors::No;
			this->button2->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Cooper Black", 10.2F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->button2->Location = System::Drawing::Point(559, 6);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(86, 41);
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
			this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)));
			this->button3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button3->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)),
				static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)));
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"Cooper Black", 12, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->button3->Location = System::Drawing::Point(252, 8);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(83, 41);
			this->button3->TabIndex = 6;
			this->button3->Text = L"Tree";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &Compiler::button3_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(25)));
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->button3);
			this->panel1->Controls->Add(this->Evaluate);
			this->panel1->Controls->Add(this->button4);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Location = System::Drawing::Point(109, 3);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(561, 55);
			this->panel1->TabIndex = 7;
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)));
			this->button4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button4->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)),
				static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)));
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->Font = (gcnew System::Drawing::Font(L"Cooper Black", 10.8F, System::Drawing::FontStyle::Italic));
			this->button4->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->button4->Location = System::Drawing::Point(452, 7);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(102, 41);
			this->button4->TabIndex = 10;
			this->button4->Text = L"Lexical";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &Compiler::button4_Click);
			// 
			// Evaluate
			// 
			this->Evaluate->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)));
			this->Evaluate->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Evaluate->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)),
				static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)));
			this->Evaluate->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Evaluate->Font = (gcnew System::Drawing::Font(L"Cooper Black", 10.8F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Evaluate->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->Evaluate->Location = System::Drawing::Point(128, 6);
			this->Evaluate->Name = L"Evaluate";
			this->Evaluate->Size = System::Drawing::Size(118, 41);
			this->Evaluate->TabIndex = 7;
			this->Evaluate->Text = L"Evaluate";
			this->Evaluate->UseVisualStyleBackColor = false;
			this->Evaluate->Click += gcnew System::EventHandler(this, &Compiler::Evaluate_Click);
			// 
			// panel2
			// 
			this->panel2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(25)), static_cast<System::Int32>(static_cast<System::Byte>(25)),
				static_cast<System::Int32>(static_cast<System::Byte>(25)));
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel2->Controls->Add(this->button2);
			this->panel2->Location = System::Drawing::Point(680, 3);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(657, 55);
			this->panel2->TabIndex = 8;
			// 
			// label3
			// 
			this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->label3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(33)),
				static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::Lime;
			this->label3->Location = System::Drawing::Point(758, 517);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(514, 47);
			this->label3->TabIndex = 9;
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(33)),
				static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->panel3->Controls->Add(this->label1);
			this->panel3->Location = System::Drawing::Point(3, 3);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(127, 55);
			this->panel3->TabIndex = 11;
			// 
			// panel4
			// 
			this->panel4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->panel4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(33)),
				static_cast<System::Int32>(static_cast<System::Byte>(48)));
			this->panel4->Controls->Add(this->label2);
			this->panel4->Location = System::Drawing::Point(680, 3);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(150, 55);
			this->panel4->TabIndex = 12;
			// 
			// Compiler
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(30)),
				static_cast<System::Int32>(static_cast<System::Byte>(30)));
			this->ClientSize = System::Drawing::Size(1340, 581);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->richTextBox2);
			this->MaximumSize = System::Drawing::Size(1358, 1200);
			this->MinimumSize = System::Drawing::Size(1358, 628);
			this->Name = L"Compiler";
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->Text = L"Compiler";
			this->panel1->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
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

		// take text from textbox and save into file
		text = richTextBox1->Text;
		writer = gcnew StreamWriter("input.txt");
		writer->WriteLine(text);
		writer->Close();

		if (Program())
		{
			this->label3->ForeColor = System::Drawing::Color::Lime;
			label3->Text = "Valid Input";
		}
		else
		{
			this->label3->ForeColor = System::Drawing::Color::Crimson;
			label3->Text = "In-Valid Input";
			print_error();
		}

		//take output string data and store in file
		text = gcnew String(output.c_str());
		writer = gcnew StreamWriter("output.txt");
		writer->WriteLine(text);
		writer->Close();

		//take data from file and show in textbox
		StreamReader^ reader = gcnew StreamReader("output.txt");
		String^ content = reader->ReadToEnd();
		reader->Close();
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

	// take text from textbox and save into file
	text = richTextBox1->Text;
	writer = gcnew StreamWriter("input.txt");
	writer->WriteLine(text);
	writer->Close();

	if (TreeProgram())
	{
		this->label3->ForeColor = System::Drawing::Color::Lime;
		label3->Text = "Valid Tree Input";
	}
	else
	{
		this->label3->ForeColor = System::Drawing::Color::Crimson;
		label3->Text = "In-Valid Tree Input";
	}

	//take output string data and store in file
	text = gcnew String(output.c_str());
	writer = gcnew StreamWriter("output.txt");
	writer->WriteLine(text);
	writer->Close();

	//take data from file and show in textbox
	StreamReader^ reader = gcnew StreamReader("output.txt");
	String^ content = reader->ReadToEnd();
	reader->Close();
	richTextBox2->Text = content;


}

private: System::Void Evaluate_Click(System::Object^ sender, System::EventArgs^ e) {

	//empty the file from previous stuff
	String^ text = " ";

	//empty the input and outfiles
	StreamWriter^ writer = gcnew StreamWriter("input.txt");
	writer->WriteLine(text);
	writer->Close();

	// take text from textbox and save into file
	text = richTextBox1->Text;
	writer = gcnew StreamWriter("input.txt");
	writer->WriteLine(text);
	writer->Close();

	if (print_evaluation())
	{
		this->label3->ForeColor = System::Drawing::Color::Lime;
		label3->Text = "Valid Expression";
	}
	else
	{
		this->label3->ForeColor = System::Drawing::Color::Crimson;
		label3->Text = "In-Valid Expression";
	}

	//take output string data and store in file
	text = gcnew String(output.c_str());
	writer = gcnew StreamWriter("output.txt");
	writer->WriteLine(text);
	writer->Close();

	//take data from file and show in textbox
	StreamReader^ reader = gcnew StreamReader("output.txt");
	String^ content = reader->ReadToEnd();
	reader->Close();
	richTextBox2->Text = content;

}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {

	//empty the file from previous stuff
	String^ text = " ";

	//empty the input and outfiles
	StreamWriter^ writer = gcnew StreamWriter("input.txt");
	writer->WriteLine(text);
	writer->Close();

	// take text from textbox and save into file
	text = richTextBox1->Text;
	writer = gcnew StreamWriter("input.txt");
	writer->WriteLine(text);
	writer->Close();

	print_tokens();

	//take output string data and store in file
	text = gcnew String(output.c_str());
	writer = gcnew StreamWriter("output.txt");
	writer->WriteLine(text);
	writer->Close();


	//take data from file and show in textbox
	StreamReader^ reader = gcnew StreamReader("output.txt");
	String^ content = reader->ReadToEnd();
	reader->Close();
	richTextBox2->Text = content;
}
};
}


