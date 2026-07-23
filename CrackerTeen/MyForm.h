#include<string>
#include<thread>
#include<iostream>
#include<windows.h>
#include "Open_File.cpp";
#include <msclr/marshal_cppstd.h>
#include "WindowHandling.h";
#include "BruteForce_injector.cpp"
#include "pin_4_character.cpp"
#include "PasswordCrafting.cpp"

namespace Project1 {
	using namespace msclr::interop;
	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>

	//MouseTrack Mouse;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
		
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::Windows::Forms::Button^ btnOne; // Brute Force
		System::Windows::Forms::Button^ btnTwo; // Traveling Sales Man
		System::Windows::Forms::Button^ btnThree; // temp for any case
		System::Windows::Forms::Button^ btnOK;
		System::Windows::Forms::Button^ btnReset;
		System::Windows::Forms::Button^ btnExit;
		System::Windows::Forms::Label^ lblPassList; // PassList label
		
		System::Windows::Forms::TextBox^ attemptsNum;
		System::Windows::Forms::Button^ attemptsConfirmation;


	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ txtPassList;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label1;







	    System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->btnOne = (gcnew System::Windows::Forms::Button());
			this->btnTwo = (gcnew System::Windows::Forms::Button());
			this->btnThree = (gcnew System::Windows::Forms::Button());
			this->btnOK = (gcnew System::Windows::Forms::Button());
			this->btnReset = (gcnew System::Windows::Forms::Button());
			this->btnExit = (gcnew System::Windows::Forms::Button());
			this->lblPassList = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->txtPassList = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->attemptsNum = (gcnew System::Windows::Forms::TextBox());
			this->attemptsConfirmation = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnOne
			// 
			this->btnOne->Location = System::Drawing::Point(10, 30);
			this->btnOne->Name = L"btnOne";
			this->btnOne->Size = System::Drawing::Size(100, 30);
			this->btnOne->TabIndex = 0;
			this->btnOne->Text = L"Dictionary Attack";
			this->btnOne->Click += gcnew System::EventHandler(this, &MyForm::btnOne_Click);
			// 
			// btnTwo
			// 
			this->btnTwo->Location = System::Drawing::Point(10, 70);
			this->btnTwo->Name = L"btnTwo";
			this->btnTwo->Size = System::Drawing::Size(100, 30);
			this->btnTwo->TabIndex = 1;
			this->btnTwo->Text = L"4-PIN";
			this->btnTwo->Click += gcnew System::EventHandler(this, &MyForm::btnTwo_Click);
			// 
			// btnThree
			// 
			this->btnThree->Location = System::Drawing::Point(10, 110);
			this->btnThree->Name = L"btnThree";
			this->btnThree->Size = System::Drawing::Size(100, 30);
			this->btnThree->TabIndex = 2;
			this->btnThree->Text = L"Craft-Passwords ";
			this->btnThree->Click += gcnew System::EventHandler(this, &MyForm::btnThree_Click);
			// 
			// btnOK
			// 
			this->btnOK->Location = System::Drawing::Point(1000, 620);
			this->btnOK->Name = L"btnOK";
			this->btnOK->Size = System::Drawing::Size(75, 30);
			this->btnOK->TabIndex = 3;
			this->btnOK->Text = L"Launch";
			this->btnOK->Click += gcnew System::EventHandler(this, &MyForm::btnOK_Click);
			// 
			// btnReset
			// 
			this->btnReset->Location = System::Drawing::Point(1100, 620);
			this->btnReset->Name = L"btnReset";
			this->btnReset->Size = System::Drawing::Size(75, 30);
			this->btnReset->TabIndex = 4;
			this->btnReset->Text = L"Reset";
			this->btnReset->Click += gcnew System::EventHandler(this, &MyForm::btnReset_Click);
			// 
			// btnExit
			// 
			this->btnExit->Location = System::Drawing::Point(1200, 620);
			this->btnExit->Name = L"btnExit";
			this->btnExit->Size = System::Drawing::Size(75, 30);
			this->btnExit->TabIndex = 5;
			this->btnExit->Text = L"Exit";
			this->btnExit->Click += gcnew System::EventHandler(this, &MyForm::btnExit_Click);
			// 
			// lblPassList
			// 
			this->lblPassList->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->lblPassList->AutoSize = true;
			this->lblPassList->BackColor = System::Drawing::SystemColors::MenuText;
			this->lblPassList->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->lblPassList->ForeColor = System::Drawing::SystemColors::ControlLight;
			this->lblPassList->Location = System::Drawing::Point(1128, 30);
			this->lblPassList->MinimumSize = System::Drawing::Size(10, 20);
			this->lblPassList->Name = L"lblPassList";
			this->lblPassList->Size = System::Drawing::Size(152, 20);
			this->lblPassList->TabIndex = 6;
			this->lblPassList->Text = L"External-Password-List";
			this->lblPassList->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::Desktop;
			this->button1->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->button1->Location = System::Drawing::Point(1241, 88);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 30);
			this->button1->TabIndex = 7;
			this->button1->Text = L"Import";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::btnPasswordList_Import);
			// 
			// txtPassList
			// 
			this->txtPassList->BackColor = System::Drawing::SystemColors::MenuText;
			this->txtPassList->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtPassList->ForeColor = System::Drawing::SystemColors::Window;
			this->txtPassList->Location = System::Drawing::Point(1131, 62);
			this->txtPassList->Name = L"txtPassList";
			this->txtPassList->Size = System::Drawing::Size(185, 20);
			this->txtPassList->TabIndex = 8;
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::MenuText;
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox1->ForeColor = System::Drawing::SystemColors::Menu;
			this->textBox1->Location = System::Drawing::Point(10, 516);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(471, 20);
			this->textBox1->TabIndex = 9;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::Control;
			this->button2->Font = (gcnew System::Drawing::Font(L"Arial Unicode MS", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button2->Location = System::Drawing::Point(406, 542);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 30);
			this->button2->TabIndex = 10;
			this->button2->Text = L"Validate";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::MenuText;
			this->label1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label1->ForeColor = System::Drawing::SystemColors::ControlLight;
			this->label1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"label1.Image")));
			this->label1->Location = System::Drawing::Point(12, 480);
			this->label1->MinimumSize = System::Drawing::Size(10, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(123, 20);
			this->label1->TabIndex = 11;
			this->label1->Text = L"Target Application";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// attemptsNum
			// 
			this->attemptsNum->Location = System::Drawing::Point(120, 75);
			this->attemptsNum->Name = L"attemptsNum";
			this->attemptsNum->Size = System::Drawing::Size(80, 20);
			this->attemptsNum->TabIndex = 0;
			// 
			// attemptsConfirmation
			// 
			this->attemptsConfirmation->Location = System::Drawing::Point(200, 75);
			this->attemptsConfirmation->Name = L"attemptsConfirmation";
			this->attemptsConfirmation->Size = System::Drawing::Size(30, 20);
			this->attemptsConfirmation->TabIndex = 0;
			this->attemptsConfirmation->Text = L"Ok";
			this->attemptsConfirmation->Click += gcnew System::EventHandler(this, &MyForm::attemptsConfirmation_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1347, 691);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->txtPassList);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->btnOne);
			this->Controls->Add(this->btnTwo);
			this->Controls->Add(this->btnThree);
			this->Controls->Add(this->btnOK);
			this->Controls->Add(this->btnReset);
			this->Controls->Add(this->btnExit);
			this->Controls->Add(this->lblPassList);
			this->Cursor = System::Windows::Forms::Cursors::PanNorth;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->Text = L"CrackerTeen";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		
	

	
#pragma endregion

		int attempts = 0; // for the 4pin attack -
		//Convert from Framework-String to normal string
		string Convert_to_string(String^ value_s) {
			string stringValue;
			std::string userStr = marshal_as<std::string>(value_s);
			stringValue = userStr;

			return stringValue;
		}
        //Convert from normal string to Framework-String
		String^ Convert_string(string variable) {
			string normal_string = variable;
			String^ STRING = gcnew System::String(normal_string.c_str());
			return STRING;
		}
		//Convert from int to normal string
		string Convert_int(int variable) {
			int normal_int = variable;
			std::string stringVariable = std::to_string(variable);
			return stringVariable;
		}
		//Convert from Framework-String to char 
		char* Convert_to_char(String^ managedString) {
			std::string stdStr = marshal_as<std::string>(managedString);
			char* charStr = new char[stdStr.length() + 1];
			strcpy_s(charStr, stdStr.length() + 1, stdStr.c_str());
			return charStr;
		}
		//Convert from string to int
		int Convert_to_int(string strNum) {
			string input = strNum; 
			int number = std::stoi(input);
			return number;
		}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	  

	}


	// This function is for the button that we click on if we want to import another passwords list 
	// 
		   //Local variables for the launching the attack
		   int Arraysize_ = 0;
		   String ^Password_List_local = "";

private: System::Void btnPasswordList_Import(System::Object^ sender, System::EventArgs^ e) {
	string external_Password_list;
	external_Password_list = Convert_to_string(this->txtPassList->Text);
	Open_File List(external_Password_list);
	string pass_keys = Convert_int(List.lines_for_array_size());
	string file_stat = List.validate_file() + " it has " + pass_keys + " passwords";
	Arraysize_ = List.lines_for_array_size(); // to save the number of passwords we will operate on
	Password_List_local = Convert_string(List.getZFile()); // this to save the name of the file

	MessageBox::Show(Convert_string(file_stat) , "Report" , MessageBoxButtons::OK , MessageBoxIcon::Information);

}
	
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	   

}
	   //Local variables for window (target)
	   bool win_alive = false;
	   String^ windowTitle_local = "";
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	
	if (String::IsNullOrEmpty(textBox1->Text)) {
		WindowHandling win_obj;
		win_alive = win_obj.getZtarget();
		String^ win_title = Convert_string(win_obj.getwinTitle());
		if (win_alive == true) {
			MessageBox::Show(win_title + " is found" ,"Hunting Process");
			 windowTitle_local = win_title;
			win_obj.DisplayTarget();
		}
		else {
			MessageBox::Show(win_title + " is not found" , "Hunting Process");
		}



	}
	else {
		MessageBox::Show("By chainging the target app you may need to re-adjust the x,y coordinates. ", "Alert!",
		MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
		this_thread::sleep_for(chrono::seconds(1));
		string modified_title = Convert_to_string(this->textBox1->Text);
		WindowHandling win_obj_mod(modified_title);
		
		win_alive = win_obj_mod.getZtarget();
		
		String^ win_title_mod = Convert_string(win_obj_mod.getwinTitle());
		if (win_alive == true) {
			windowTitle_local = win_title_mod;
			MessageBox::Show(win_title_mod + " is found" , "Hunting Process");
			win_obj_mod.DisplayTarget();
		}
		else {
			MessageBox::Show(win_title_mod + " is not found" , "Hunting Process");
		}

		
	}
	}

	
	   //local variables to specify the method that will be used
	   static String^ Local_Algorithm;
       // Event handler for Button 1 click Brute Force Dictionary Attack
	   void btnOne_Click(System::Object^ sender, System::EventArgs^ e) {
		   Local_Algorithm = btnOne->Text;



	   }

	   // Event handler for Button 2 click , 4-PIN charachters
	   void btnTwo_Click(System::Object^ sender, System::EventArgs^ e) {
		   //MessageBox::Show(L"Button 2 clicked!");
		   Local_Algorithm = btnTwo->Text;
		   this->Controls->Add(this->attemptsNum);
		   this->Controls->Add(this->attemptsConfirmation);
		   this->attemptsNum->Text = "0";
		   MessageBox::Show("The default attempts are 10 if you want more than 10 wirte the number in the field that just showed", "Notice", MessageBoxButtons::OK, MessageBoxIcon::Information);


	    
	   }

	   // Event handler for Button 3 click , CraftingPasswords
	   void btnThree_Click(System::Object^ sender, System::EventArgs^ e) {
		  //MessageBox::Show(L"Button 3 clicked!");
		   Local_Algorithm = btnThree->Text;
	   }
	   //---------------------------------------


// Event handler for launch attack button click

	   void btnOK_Click(System::Object^ sender, System::EventArgs^ e) {
		   //MessageBox::Show(L"OK button clicked!");
		   //Open passwordList
		   //Open the target

		   String^ approach = Local_Algorithm;
		   int NumericAlgo = 0;
		   
		   if (approach == "Dictionary Attack") {
			   NumericAlgo = 1;
		   }
		   if (approach == "4-PIN") {
			   NumericAlgo = 2;
		   }
		   if (approach == "Craft-Passwords ") {
			   NumericAlgo = 3;
		   }
		   if (approach == "UN + Paswd") {
			   NumericAlgo = 4;
		   }
		  

		   switch (NumericAlgo) {
		   case 1:
			   if (Arraysize_ == 0 || String::IsNullOrEmpty(Password_List_local) || String::IsNullOrEmpty(windowTitle_local) || win_alive == false) {
				   MessageBox::Show("You can not launch the attack while requirements are not ready specify the target application and the passworld list", "Error",
					   MessageBoxButtons::OK, MessageBoxIcon::Error);
				   return;
			   }
			   else {
				   Open_File open_file(Convert_to_string(Password_List_local));
				   string* password_keys = new string[Arraysize_];
				   open_file.get_password_keys(password_keys, Arraysize_);
					   WindowHandling win_obj(Convert_to_string(windowTitle_local));

					   MessageBox::Show(Convert_string(win_obj.getwinTitle()));
					   MessageBox::Show("The Attack will be launched on " +windowTitle_local, "Process.. ", MessageBoxButtons::OK, MessageBoxIcon::Information);
					   this_thread::sleep_for(chrono::seconds(5));
					   win_obj.DisplayVictim(win_obj.getwinTitle());
					   //win_obj.DisplayTarget();
					   //BruteForce_injector injection_;
					   BruteForce_injector injection_;
					   this_thread::sleep_for(chrono::seconds(1));
					   int passwordPos;
					   injection_.GetPasswordThenInject(password_keys , Arraysize_ , passwordPos );
	
					  if (passwordPos) {
						  MessageBox::Show("The password is " + Convert_string(password_keys[passwordPos]));
					  }
					  else {
						  MessageBox::Show("The passwords did not match try the other methods");
					  }

			   }
			   break;

		   case 2:
			   if (String::IsNullOrEmpty(windowTitle_local) || win_alive == false) {
				   MessageBox::Show("You can not launch the attack while requirements are not ready, specify the target application ", "Error",
					   MessageBoxButtons::OK, MessageBoxIcon::Error);
				   return;
			   }
			   else {
				   
				   WindowHandling win_obj_4pin(Convert_to_string(windowTitle_local) , 590,253,754,417);
				   if (attempts == 0) {
					   
					   MessageBox::Show("The Attack will be launched on " + windowTitle_local, "Process.. ", MessageBoxButtons::OK, MessageBoxIcon::Information);
					   win_obj_4pin.DisplayVictim(win_obj_4pin.getwinTitle());
					   pin_4_character PinInjector1;
					   string the_pin = PinInjector1.Generator_ReadyCommonBranch();
					   MessageBox::Show(Convert_string(the_pin));
				   }
				   else {

					   if (!win_obj_4pin.getZtarget()) {

						   MessageBox::Show("The application " + windowTitle_local + " Is not found");
						   return;
					   }
					   else {

						   pin_4_character PinInjector2;
						   MessageBox::Show("The Attack will be launched on " + windowTitle_local, "Process.. ", MessageBoxButtons::OK, MessageBoxIcon::Information);
						   win_obj_4pin.DisplayVictim(win_obj_4pin.getwinTitle());
						   string the_pin = PinInjector2.Generator(attempts);
						   MessageBox::Show(Convert_string(the_pin));
					   }
				   }
			   }

			   break;
		   case 3:
			   if (String::IsNullOrEmpty(windowTitle_local) || win_alive == false) {
				   MessageBox::Show("You can not launch the attack while requirements are not ready , specify the target application", "Error",
					   MessageBoxButtons::OK, MessageBoxIcon::Error);
				   return;
			   }
			   else {
				   WindowHandling win_obj_craftedPassword(Convert_to_string(windowTitle_local));
				   if (!win_obj_craftedPassword.getZtarget()) {
					   MessageBox::Show("The application " + windowTitle_local + " Is not found");
					   return;
				   }
				   else {
					   MessageBox::Show("The Attack will be launched on " + windowTitle_local, "Process.. ", MessageBoxButtons::OK, MessageBoxIcon::Information);
					   win_obj_craftedPassword.DisplayVictim(win_obj_craftedPassword.getwinTitle());
					   loadTheCraftedPasswordsToInjection();
					   string Result = PrintThePassword();
					   DeAllocation(); // Very very important to avoid memory leaks
					   MessageBox::Show(Convert_string(Result));

				   }


				 
			   }

			   break;
		   case 4:
			     
			   break;
		   default:
			   //cout << "Invalid choice. Please choose between 1 and 3." << endl;
			   MessageBox::Show("You can not launch the attack while requirements are not ready", "Error",
				   MessageBoxButtons::OK, MessageBoxIcon::Error);
			   break;
		   }






	   }







	   

	   // Event handler for Reset button click
	   void btnReset_Click(System::Object^ sender, System::EventArgs^ e) {
		   MessageBox::Show(L"Reset button clicked!");
		   // You can reset the values or controls in your form here
	   
	   
		   this->textBox1->ResetText();
		   this->txtPassList->ResetText();
		   this->button1->ResetBindings();
		   this->btnOne->ResetBindings();
		   this->btnTwo->ResetBindings();
		   this->Controls->Remove(attemptsConfirmation);
		   this->Controls->Remove(attemptsNum);
		   DeAllocation(); // This to free the memory from any old stored arrays from the Approach Crafting Password
	   
	   }

	   // Event handler for Exit button click
	   void btnExit_Click(System::Object^ sender, System::EventArgs^ e) {
		   if (MessageBox::Show("You want to close the program", "Exit", MessageBoxButtons::OKCancel) == System::Windows::Forms::DialogResult::OK) {
			   Application::Exit();  // This will exit the application only if OK is clicked
		   }
		   // If Cancel is clicked, nothing happens and the program continues
	   }



private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
	   //static local variable "attempts"  declared up around the converting functions 
	   //Function for validation
	   //Functions we will use 
	   bool isValidPin(const std::string& input) {
		  // if (input.length() == 5) return false;
		   for (char ch : input) {
			   if (!std::isdigit(static_cast<unsigned char>(ch))) {
				   return false;
			   }
		   }
		   return true;
	   }
	  
private: System::Void attemptsConfirmation_Click(System::Object^ sender, System::EventArgs^ e) {
	bool valid = isValidPin(Convert_to_string(this->attemptsNum->Text));
	if (valid) {
		attempts = Convert_to_int(Convert_to_string(this->attemptsNum->Text));
		int totalAttempts = 10 + attempts;
		MessageBox::Show("You have " + totalAttempts+" attempts now", "Noted",
			MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	else {
		MessageBox::Show("Wrong input so no extra attempts , please enter valid number of attempts ", "Error",
			MessageBoxButtons::OK, MessageBoxIcon::Error);
		    attempts = 0;

	}
		  
}
	
private: System::Void usernameConfirmation_Click(System::Object^ sender, System::EventArgs^ e) {

}
};
	
}
