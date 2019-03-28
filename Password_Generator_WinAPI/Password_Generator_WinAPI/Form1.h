//	Author: Ryan Beebe
//  Date: 3/26/2019

#pragma once
#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <random>

namespace PasswordGeneratorWinAPI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Security;


	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		std::fstream& GetWord(std::fstream& WordList, unsigned int line)
		{
			std::string word;
			WordList.seekg(std::ios::beg);
			for (int i = 0; i < line - 1; ++i) {
				WordList.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			}
			return WordList;
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  aLabel;
	protected:
	private: System::Windows::Forms::TextBox^  aTextBox;
	private: System::Windows::Forms::Button^  aButton;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->aLabel = (gcnew System::Windows::Forms::Label());
			this->aTextBox = (gcnew System::Windows::Forms::TextBox());
			this->aButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// aLabel
			// 
			this->aLabel->AutoSize = true;
			this->aLabel->Location = System::Drawing::Point(12, 27);
			this->aLabel->Name = L"aLabel";
			this->aLabel->Size = System::Drawing::Size(59, 13);
			this->aLabel->TabIndex = 0;
			this->aLabel->Text = L"Password: ";
			this->aLabel->Click += gcnew System::EventHandler(this, &Form1::aLabel_Click);
			// 
			// aTextBox
			// 
			this->aTextBox->Location = System::Drawing::Point(77, 24);
			this->aTextBox->Name = L"aTextBox";
			this->aTextBox->Size = System::Drawing::Size(158, 20);
			this->aTextBox->TabIndex = 1;
			this->aTextBox->TextChanged += gcnew System::EventHandler(this, &Form1::aTextBox_TextChanged);
			// 
			// aButton
			// 
			this->aButton->Location = System::Drawing::Point(241, 22);
			this->aButton->Name = L"aButton";
			this->aButton->Size = System::Drawing::Size(120, 23);
			this->aButton->TabIndex = 2;
			this->aButton->Text = L"Generate Password";
			this->aButton->UseVisualStyleBackColor = true;
			this->aButton->Click += gcnew System::EventHandler(this, &Form1::aButton_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(373, 71);
			this->Controls->Add(this->aButton);
			this->Controls->Add(this->aTextBox);
			this->Controls->Add(this->aLabel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->Text = L"Password Generator";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		private: System::Void aLabel_Click(System::Object^  sender, System::EventArgs^  e) {}
		private: System::Void aTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {}
	
		//When the "Generate" button is clicked, a passphrase will be shown in the text box
		private: System::Void aButton_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			//Declare variables
			Random rnd;
			int rand;
			String^ Password = "";
			String^ temp;
			std::string tempo;
			std::fstream WordList("Words.txt");

			//Generate a predetermined number of words
			/*for (int i = 0; i < 2; ++i)
			{
				rand = rnd.Next(1, 3435);
				GetWord(WordList, rand);
	
				WordList >> tempo;
				Password += gcnew String(tempo.c_str()) + " ";
			}
			*/

			//Generate random words and add them to Pass phrase string until the phrase length is 8 or greater
			while (Password->Length < 8)
			{
				rand = rnd.Next(1, 3427); //Generate random line to get word from
				GetWord(WordList, rand);

				WordList >> tempo;
				Password += gcnew String(tempo.c_str()) + " "; //Convert from std::string to String^
			}

			//Add a random digit to the password
			int ran = rnd.Next(1, 9);
			Password += ran.ToString();

			//Display password in text box
			aTextBox->Text = Password;
		}
	};
}
