

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

#pragma region MyRegion


class places
{
public:
	string name ;
	int start;
	int size ;

	places()
	{
		size = 0;
		start = 0 ;
	}
};
class memory
{
public:
	int full ;
	string Pname;
	
	memory()
	{
		full = 1 ;
		Pname = "" ;

	}

};
class process 
{
public:
	string name;
	int size ;

	process()
	{
		size = 0 ;
		name = "" ;
	}
};


void empty_mem(memory x[] ,int start ,int size)
{
	for(int i =start; i<start+size ; i++)
	{
		x[i].full = 0 ;
		x[i].Pname = "empty" ;
	}
}

void full_areas (memory x[] ,vector <places> &y,int n)
{
	string currentname = x[0].Pname;
	int currentsize = 0 ;
	int j = 0 ;
	places temp ;



	for(int i = 0 ; i<n ;i++)
	{
		if(x[i].full == 1)
		{
			currentname = x[i].Pname ;
			if(i!= n -1)
			{
				if(currentname == x[i+1].Pname)
					currentsize++;
				else
				{
					temp.name =currentname;
					temp.size = currentsize+1;
					temp.start = i-currentsize ;
					y.push_back(temp);
					currentsize=0;
				}
			}
			else
			{
				temp.name =currentname;
				temp.size = currentsize+1;
				temp.start = i-currentsize ;
				y.push_back(temp);
			}

		}

	}
}


void empty_areas (memory x[] ,vector <places> &y,int n)
{
	string currentname = x[0].Pname;
	int currentsize = 0 ;
	int j = 0 ;
	places temp ;


	for(int i = 0 ; i<n ;i++)
	{
		if(x[i].full == 0)
		{
			currentname = x[i].Pname ;
			if(i!= (n -1))
			{
 				if(currentname == x[i+1].Pname)
					currentsize++;
				else
				{
					temp.size = currentsize+1;
					temp.start = i-currentsize ;
					y.push_back(temp);
					currentsize=0;
				}
			}
			if(i== (n -1))
			{
					temp.size = currentsize+1;
					temp.start = i-currentsize ;
					y.push_back(temp);
			}

		}


	}
}


int fit (process x , vector <places> &y ,memory mymemory[])
{
	for(unsigned int i = 0 ;i< y.size() ; i++)
	{
		if (y[i].size >= x.size)
		{	
			for(int j = y[i].start ; j<(y[i].start +x.size);j++ )
			{
				mymemory[j].Pname = x.name ;
				mymemory[j].full = 1;
			}
			return 1;
		}
	}
	return 0 ;
}


#pragma endregion

#pragma once

int memorySize ,AType;
int iiii =0 ,ii= 0 ,iii =0;
memory* mymemory ;


namespace gui {





	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;




	/// <summary>
	/// Summary for MyForm
	/// </summary>
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
	private: System::Windows::Forms::GroupBox^  groupBoxHoles;
	protected: 
	private: System::Windows::Forms::TextBox^  textBoxHSize;
	private: System::Windows::Forms::TextBox^  textBoxHStartingAddress;
	private: System::Windows::Forms::Label^  labelHSize;
	private: System::Windows::Forms::Label^  labelHStartingAddress;
	private: System::Windows::Forms::GroupBox^  groupBoxProcesses;
	private: System::Windows::Forms::TextBox^  textBoxPSize;
	private: System::Windows::Forms::TextBox^  textBoxPName;
	private: System::Windows::Forms::Label^  labelPsize;
	private: System::Windows::Forms::Label^  labelPName;
	private: System::Windows::Forms::Label^  labelMemorySize;
	private: System::Windows::Forms::TextBox^  textBoxMemorySize;
	private: System::Windows::Forms::Button^  buttonHoles;
	private: System::Windows::Forms::Button^  buttonProcess;
	private: System::Windows::Forms::GroupBox^  groupBoxGeneral;
	private: System::Windows::Forms::Button^  buttonGeneral;
	private: System::Windows::Forms::RadioButton^  radioButtonBF;
	private: System::Windows::Forms::RadioButton^  radioButtonFF;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  MemoryMap;
	private: System::Windows::Forms::GroupBox^  groupBoxdProcess;
	private: System::Windows::Forms::Button^  buttonDProcess;
	private: System::Windows::Forms::TextBox^  textBoxDProcess;
	private: System::Windows::Forms::Label^  labeldProcess;


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
			this->groupBoxHoles = (gcnew System::Windows::Forms::GroupBox());
			this->buttonHoles = (gcnew System::Windows::Forms::Button());
			this->textBoxHSize = (gcnew System::Windows::Forms::TextBox());
			this->textBoxHStartingAddress = (gcnew System::Windows::Forms::TextBox());
			this->labelHSize = (gcnew System::Windows::Forms::Label());
			this->labelHStartingAddress = (gcnew System::Windows::Forms::Label());
			this->groupBoxProcesses = (gcnew System::Windows::Forms::GroupBox());
			this->buttonProcess = (gcnew System::Windows::Forms::Button());
			this->textBoxPSize = (gcnew System::Windows::Forms::TextBox());
			this->textBoxPName = (gcnew System::Windows::Forms::TextBox());
			this->labelPsize = (gcnew System::Windows::Forms::Label());
			this->labelPName = (gcnew System::Windows::Forms::Label());
			this->labelMemorySize = (gcnew System::Windows::Forms::Label());
			this->textBoxMemorySize = (gcnew System::Windows::Forms::TextBox());
			this->groupBoxGeneral = (gcnew System::Windows::Forms::GroupBox());
			this->buttonGeneral = (gcnew System::Windows::Forms::Button());
			this->radioButtonBF = (gcnew System::Windows::Forms::RadioButton());
			this->radioButtonFF = (gcnew System::Windows::Forms::RadioButton());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->MemoryMap = (gcnew System::Windows::Forms::TextBox());
			this->groupBoxdProcess = (gcnew System::Windows::Forms::GroupBox());
			this->buttonDProcess = (gcnew System::Windows::Forms::Button());
			this->textBoxDProcess = (gcnew System::Windows::Forms::TextBox());
			this->labeldProcess = (gcnew System::Windows::Forms::Label());
			this->groupBoxHoles->SuspendLayout();
			this->groupBoxProcesses->SuspendLayout();
			this->groupBoxGeneral->SuspendLayout();
			this->groupBoxdProcess->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBoxHoles
			// 
			this->groupBoxHoles->Controls->Add(this->buttonHoles);
			this->groupBoxHoles->Controls->Add(this->textBoxHSize);
			this->groupBoxHoles->Controls->Add(this->textBoxHStartingAddress);
			this->groupBoxHoles->Controls->Add(this->labelHSize);
			this->groupBoxHoles->Controls->Add(this->labelHStartingAddress);
			this->groupBoxHoles->Enabled = false;
			this->groupBoxHoles->Location = System::Drawing::Point(288, 46);
			this->groupBoxHoles->Name = L"groupBoxHoles";
			this->groupBoxHoles->Size = System::Drawing::Size(262, 251);
			this->groupBoxHoles->TabIndex = 0;
			this->groupBoxHoles->TabStop = false;
			this->groupBoxHoles->Text = L"#Holes";
			// 
			// buttonHoles
			// 
			this->buttonHoles->Location = System::Drawing::Point(84, 200);
			this->buttonHoles->Name = L"buttonHoles";
			this->buttonHoles->Size = System::Drawing::Size(84, 31);
			this->buttonHoles->TabIndex = 7;
			this->buttonHoles->Text = L"Submit";
			this->buttonHoles->UseVisualStyleBackColor = true;
			this->buttonHoles->Click += gcnew System::EventHandler(this, &MyForm::buttonHoles_Click);
			// 
			// textBoxHSize
			// 
			this->textBoxHSize->Location = System::Drawing::Point(153, 133);
			this->textBoxHSize->Name = L"textBoxHSize";
			this->textBoxHSize->Size = System::Drawing::Size(100, 26);
			this->textBoxHSize->TabIndex = 4;
			// 
			// textBoxHStartingAddress
			// 
			this->textBoxHStartingAddress->Location = System::Drawing::Point(153, 56);
			this->textBoxHStartingAddress->Name = L"textBoxHStartingAddress";
			this->textBoxHStartingAddress->Size = System::Drawing::Size(100, 26);
			this->textBoxHStartingAddress->TabIndex = 3;
			// 
			// labelHSize
			// 
			this->labelHSize->AutoSize = true;
			this->labelHSize->Location = System::Drawing::Point(19, 136);
			this->labelHSize->Name = L"labelHSize";
			this->labelHSize->Size = System::Drawing::Size(40, 20);
			this->labelHSize->TabIndex = 2;
			this->labelHSize->Text = L"Size";
			// 
			// labelHStartingAddress
			// 
			this->labelHStartingAddress->AutoSize = true;
			this->labelHStartingAddress->Location = System::Drawing::Point(19, 62);
			this->labelHStartingAddress->Name = L"labelHStartingAddress";
			this->labelHStartingAddress->Size = System::Drawing::Size(128, 20);
			this->labelHStartingAddress->TabIndex = 1;
			this->labelHStartingAddress->Text = L"Starting Address";
			// 
			// groupBoxProcesses
			// 
			this->groupBoxProcesses->Controls->Add(this->buttonProcess);
			this->groupBoxProcesses->Controls->Add(this->textBoxPSize);
			this->groupBoxProcesses->Controls->Add(this->textBoxPName);
			this->groupBoxProcesses->Controls->Add(this->labelPsize);
			this->groupBoxProcesses->Controls->Add(this->labelPName);
			this->groupBoxProcesses->Enabled = false;
			this->groupBoxProcesses->Location = System::Drawing::Point(572, 55);
			this->groupBoxProcesses->Name = L"groupBoxProcesses";
			this->groupBoxProcesses->Size = System::Drawing::Size(200, 242);
			this->groupBoxProcesses->TabIndex = 1;
			this->groupBoxProcesses->TabStop = false;
			this->groupBoxProcesses->Text = L"#Processes";
			// 
			// buttonProcess
			// 
			this->buttonProcess->Location = System::Drawing::Point(66, 191);
			this->buttonProcess->Name = L"buttonProcess";
			this->buttonProcess->Size = System::Drawing::Size(84, 31);
			this->buttonProcess->TabIndex = 9;
			this->buttonProcess->Text = L"Submit";
			this->buttonProcess->UseVisualStyleBackColor = true;
			this->buttonProcess->Click += gcnew System::EventHandler(this, &MyForm::buttonProcess_Click);
			// 
			// textBoxPSize
			// 
			this->textBoxPSize->Location = System::Drawing::Point(90, 127);
			this->textBoxPSize->Name = L"textBoxPSize";
			this->textBoxPSize->Size = System::Drawing::Size(100, 26);
			this->textBoxPSize->TabIndex = 8;
			// 
			// textBoxPName
			// 
			this->textBoxPName->Location = System::Drawing::Point(90, 50);
			this->textBoxPName->Name = L"textBoxPName";
			this->textBoxPName->Size = System::Drawing::Size(100, 26);
			this->textBoxPName->TabIndex = 7;
			// 
			// labelPsize
			// 
			this->labelPsize->AutoSize = true;
			this->labelPsize->Location = System::Drawing::Point(11, 127);
			this->labelPsize->Name = L"labelPsize";
			this->labelPsize->Size = System::Drawing::Size(40, 20);
			this->labelPsize->TabIndex = 6;
			this->labelPsize->Text = L"Size";
			// 
			// labelPName
			// 
			this->labelPName->AutoSize = true;
			this->labelPName->Location = System::Drawing::Point(11, 50);
			this->labelPName->Name = L"labelPName";
			this->labelPName->Size = System::Drawing::Size(51, 20);
			this->labelPName->TabIndex = 5;
			this->labelPName->Text = L"Name";
			// 
			// labelMemorySize
			// 
			this->labelMemorySize->AutoSize = true;
			this->labelMemorySize->Location = System::Drawing::Point(9, 33);
			this->labelMemorySize->Name = L"labelMemorySize";
			this->labelMemorySize->Size = System::Drawing::Size(100, 20);
			this->labelMemorySize->TabIndex = 0;
			this->labelMemorySize->Text = L"Memory Size";
			// 
			// textBoxMemorySize
			// 
			this->textBoxMemorySize->Location = System::Drawing::Point(115, 30);
			this->textBoxMemorySize->Name = L"textBoxMemorySize";
			this->textBoxMemorySize->Size = System::Drawing::Size(140, 26);
			this->textBoxMemorySize->TabIndex = 2;
			// 
			// groupBoxGeneral
			// 
			this->groupBoxGeneral->Controls->Add(this->buttonGeneral);
			this->groupBoxGeneral->Controls->Add(this->radioButtonBF);
			this->groupBoxGeneral->Controls->Add(this->radioButtonFF);
			this->groupBoxGeneral->Controls->Add(this->label1);
			this->groupBoxGeneral->Controls->Add(this->textBoxMemorySize);
			this->groupBoxGeneral->Controls->Add(this->labelMemorySize);
			this->groupBoxGeneral->Location = System::Drawing::Point(3, 56);
			this->groupBoxGeneral->Name = L"groupBoxGeneral";
			this->groupBoxGeneral->Size = System::Drawing::Size(266, 240);
			this->groupBoxGeneral->TabIndex = 3;
			this->groupBoxGeneral->TabStop = false;
			this->groupBoxGeneral->Text = L"General";
			// 
			// buttonGeneral
			// 
			this->buttonGeneral->Location = System::Drawing::Point(86, 190);
			this->buttonGeneral->Name = L"buttonGeneral";
			this->buttonGeneral->Size = System::Drawing::Size(84, 31);
			this->buttonGeneral->TabIndex = 6;
			this->buttonGeneral->Text = L"Submit";
			this->buttonGeneral->UseVisualStyleBackColor = true;
			this->buttonGeneral->Click += gcnew System::EventHandler(this, &MyForm::buttonGeneral_Click);
			// 
			// radioButtonBF
			// 
			this->radioButtonBF->AutoSize = true;
			this->radioButtonBF->Location = System::Drawing::Point(103, 123);
			this->radioButtonBF->Name = L"radioButtonBF";
			this->radioButtonBF->Size = System::Drawing::Size(89, 24);
			this->radioButtonBF->TabIndex = 5;
			this->radioButtonBF->TabStop = true;
			this->radioButtonBF->Text = L"Best Fit";
			this->radioButtonBF->UseVisualStyleBackColor = true;
			// 
			// radioButtonFF
			// 
			this->radioButtonFF->AutoSize = true;
			this->radioButtonFF->Location = System::Drawing::Point(103, 87);
			this->radioButtonFF->Name = L"radioButtonFF";
			this->radioButtonFF->Size = System::Drawing::Size(87, 24);
			this->radioButtonFF->TabIndex = 4;
			this->radioButtonFF->TabStop = true;
			this->radioButtonFF->Text = L"First Fit";
			this->radioButtonFF->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(13, 91);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(84, 20);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Input Type";
			// 
			// MemoryMap
			// 
			this->MemoryMap->HideSelection = false;
			this->MemoryMap->Location = System::Drawing::Point(827, 55);
			this->MemoryMap->Multiline = true;
			this->MemoryMap->Name = L"MemoryMap";
			this->MemoryMap->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->MemoryMap->Size = System::Drawing::Size(140, 335);
			this->MemoryMap->TabIndex = 4;
			// 
			// groupBoxdProcess
			// 
			this->groupBoxdProcess->Controls->Add(this->buttonDProcess);
			this->groupBoxdProcess->Controls->Add(this->textBoxDProcess);
			this->groupBoxdProcess->Controls->Add(this->labeldProcess);
			this->groupBoxdProcess->Location = System::Drawing::Point(572, 303);
			this->groupBoxdProcess->Name = L"groupBoxdProcess";
			this->groupBoxdProcess->Size = System::Drawing::Size(200, 123);
			this->groupBoxdProcess->TabIndex = 5;
			this->groupBoxdProcess->TabStop = false;
			this->groupBoxdProcess->Text = L"Deallocate Process";
			this->groupBoxdProcess->Visible = false;
			// 
			// buttonDProcess
			// 
			this->buttonDProcess->Location = System::Drawing::Point(66, 86);
			this->buttonDProcess->Name = L"buttonDProcess";
			this->buttonDProcess->Size = System::Drawing::Size(84, 31);
			this->buttonDProcess->TabIndex = 10;
			this->buttonDProcess->Text = L"Submit";
			this->buttonDProcess->UseVisualStyleBackColor = true;
			this->buttonDProcess->Click += gcnew System::EventHandler(this, &MyForm::buttonDProcess_Click);
			// 
			// textBoxDProcess
			// 
			this->textBoxDProcess->Location = System::Drawing::Point(90, 37);
			this->textBoxDProcess->Name = L"textBoxDProcess";
			this->textBoxDProcess->Size = System::Drawing::Size(100, 26);
			this->textBoxDProcess->TabIndex = 9;
			// 
			// labeldProcess
			// 
			this->labeldProcess->AutoSize = true;
			this->labeldProcess->Location = System::Drawing::Point(11, 37);
			this->labeldProcess->Name = L"labeldProcess";
			this->labeldProcess->Size = System::Drawing::Size(51, 20);
			this->labeldProcess->TabIndex = 8;
			this->labeldProcess->Text = L"Name";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1078, 438);
			this->Controls->Add(this->groupBoxdProcess);
			this->Controls->Add(this->MemoryMap);
			this->Controls->Add(this->groupBoxGeneral);
			this->Controls->Add(this->groupBoxProcesses);
			this->Controls->Add(this->groupBoxHoles);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->groupBoxHoles->ResumeLayout(false);
			this->groupBoxHoles->PerformLayout();
			this->groupBoxProcesses->ResumeLayout(false);
			this->groupBoxProcesses->PerformLayout();
			this->groupBoxGeneral->ResumeLayout(false);
			this->groupBoxGeneral->PerformLayout();
			this->groupBoxdProcess->ResumeLayout(false);
			this->groupBoxdProcess->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}



			
#pragma endregion
		
		string printing()
		{
			string ms = "--- 1 ---\r\n";
			 if(mymemory[0].full==0)
				 ms+= "Empty \r\n";

			 else if (mymemory[0].full==1)
				 ms+="Full " +mymemory[0].Pname+"\r\n";

			
			for(int i =1;i<memorySize ;i++)
			 {
				 if(mymemory[i-1].Pname != mymemory[i].Pname)
				 {
					 ms+= "--- " + to_string(i)+ " --- \r\n";
					 if(mymemory[i].full==0)
						 ms+= "Empty \r\n";

					 else if (mymemory[i].full==1)
						 ms+="Full " +mymemory[i].Pname+"\r\n";
				 }
			 }
			ms+= "--- " + to_string(memorySize)+ " --- \r\n";
			return ms;
		}

		static bool sortEmptyBySize(const places &lhs, const places &rhs) { return lhs.size < rhs.size; }

	
		

	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
				 
			 }
private: System::Void buttonGeneral_Click(System::Object^  sender, System::EventArgs^  e) {
			 String^ a;
			 memorySize = Convert::ToInt32(textBoxMemorySize->Text );
			 if(radioButtonBF->Checked == 1)
				 AType = 0;
			 else if(radioButtonFF->Checked== 1)
				 AType = 1;

			 if (textBoxMemorySize->Text == "")
				 MessageBox::Show("Memory Size is Empty");
			 else
			 {
				 if (radioButtonBF->Checked == 0 &&radioButtonFF->Checked== 0 )
					MessageBox::Show("You should choose a Type");
				 else
				 {
					 MemoryMap->Text ="--- 0 ---\r\n Full \r\n" +"--- " + Convert::ToString( memorySize)+ " ---\r\n";
			 
 					 mymemory= new memory [memorySize] ;
					 if(ii==0)
						groupBoxHoles->Enabled = true ;
				}
			}
			 
		 }
private: System::Void buttonHoles_Click(System::Object^  sender, System::EventArgs^  e) {
			 int sa,s;
			 vector <places> empty ,full ;

			 sa = Convert::ToInt32(textBoxHStartingAddress->Text);
			 s = Convert::ToInt32(textBoxHSize->Text);

			 if (textBoxHStartingAddress->Text == "")
				 MessageBox::Show("Starting Address is Empty");
			 else
			 {
				 if (textBoxHSize->Text == "")
					MessageBox::Show("Size is Empty");
				 else
				 {
					 if (sa+s >memorySize)
						 MessageBox::Show("no enough memory");
					 else
					 {
						 empty_mem(mymemory,sa,s);

						 string str = printing () ;
						 String^ str2 = gcnew String(str.c_str()); 
						 MemoryMap->Text = str2 + "\r\n" ;
				 
						 if (iii==0)
							groupBoxProcesses ->Enabled = true ;
					 }
				 }
			 }


		 }
private: System::Void buttonProcess_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 int check ;
			 string name;
			 process p ;
			 vector <places> empty ,full ;
			 empty.clear();
			 empty_areas(mymemory,empty,memorySize);
			 p.size = Convert::ToInt32(textBoxPSize->Text);

			 char cStr[50];
			 sprintf(cStr, "%s", textBoxPName->Text);
			 p.name = cStr;

			 if (textBoxPName->Text == "")
				 MessageBox::Show("Process Name is Empty");
			 else
			 {
				 if (textBoxPSize->Text == "")
					MessageBox::Show("Size is Empty");
				 else
				 {
					 if (p.size >memorySize)
						 MessageBox::Show("no enough memory");

					 if(AType ==1)
					{
						check = fit (p, empty ,mymemory);
						if (check == 0)
						{
						MessageBox::Show("no enough memory"); 
						}
						else
						{
							empty.clear();
							empty_areas(mymemory,empty,memorySize);
							string str = printing () ;
							String^ str2 = gcnew String(str.c_str()); 
							MemoryMap->Text = str2 + "\r\n" ;
							if (iiii==0)
								groupBoxdProcess->Visible = true ;

						}
				
				
					
					}
					if(AType==0)
					{
						sort(empty.begin(), empty.end(), sortEmptyBySize);
						check = fit (p, empty ,mymemory);
						if (check == 0)
						{
						MessageBox::Show("no enough memory");
						}
						else
						{
							empty.clear();
							empty_areas(mymemory,empty,memorySize);
							string str = printing () ;
							 String^ str2 = gcnew String(str.c_str()); 
							 MemoryMap->Text = str2 + "\r\n" ;
							 if (iiii==0)
								groupBoxdProcess->Visible = true ;

						}
					}
				}

			}

			


		 }
private: System::Void buttonDProcess_Click(System::Object^  sender, System::EventArgs^  e) {
			 
			 vector <places> empty ,full ;
			 int dstart,dsize;
			 char cStr[50];
			 sprintf(cStr, "%s", textBoxDProcess->Text);
			 
			 string pname = cStr;
			 if (textBoxDProcess->Text == "")
				 MessageBox::Show("TextBox is Empty");
			 else
			 {
				full.clear();
				full_areas(mymemory,full,memorySize);
				
				for(int i = 0 ;i<full.size();i++)
				{
					if(full[i].name == pname)
					{
						dstart = full[i].start;
						dsize = full[i].size ;
					}
				}

				empty_mem(mymemory,dstart,dsize);
				string str = printing () ;
				 String^ str2 = gcnew String(str.c_str()); 
				 MemoryMap->Text = str2 + "\r\n" ;
			 }
		 }
};
}
