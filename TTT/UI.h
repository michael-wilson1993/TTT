#pragma once
using namespace System;
#include "../AI/gameMaster.h"
#include <string>
#include <iostream>

namespace TTT {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for UI
	/// </summary>
	public ref class UI : public System::Windows::Forms::Form
	{
	public:
		UI(void)
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
		~UI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::NumericUpDown^  numericUpDown1;
	private: System::Windows::Forms::Button^  runButton;
	private: System::Windows::Forms::Label^  gamesPlayedLabel;
	private: System::Windows::Forms::Label^  gamesPlayedCounter;
	private: System::Windows::Forms::Button^  button10;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	protected:

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->runButton = (gcnew System::Windows::Forms::Button());
			this->gamesPlayedLabel = (gcnew System::Windows::Forms::Label());
			this->gamesPlayedCounter = (gcnew System::Windows::Forms::Label());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(13, 13);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(50, 50);
			this->button1->TabIndex = 0;
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(69, 13);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(50, 50);
			this->button2->TabIndex = 1;
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(125, 13);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(50, 50);
			this->button3->TabIndex = 2;
			this->button3->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(13, 69);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(50, 50);
			this->button4->TabIndex = 3;
			this->button4->UseVisualStyleBackColor = true;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(69, 69);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(50, 50);
			this->button5->TabIndex = 4;
			this->button5->UseVisualStyleBackColor = true;
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(125, 69);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(50, 50);
			this->button6->TabIndex = 5;
			this->button6->UseVisualStyleBackColor = true;
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(13, 125);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(50, 50);
			this->button7->TabIndex = 6;
			this->button7->UseVisualStyleBackColor = true;
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(69, 125);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(50, 50);
			this->button8->TabIndex = 7;
			this->button8->UseVisualStyleBackColor = true;
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(125, 125);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(50, 50);
			this->button9->TabIndex = 8;
			this->button9->UseVisualStyleBackColor = true;
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(278, 15);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1410065408, 2, 0, 0 });
			this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(33, 20);
			this->numericUpDown1->TabIndex = 9;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			// 
			// runButton
			// 
			this->runButton->Location = System::Drawing::Point(197, 13);
			this->runButton->Name = L"runButton";
			this->runButton->Size = System::Drawing::Size(75, 23);
			this->runButton->TabIndex = 10;
			this->runButton->Text = L"run";
			this->runButton->UseVisualStyleBackColor = true;
			this->runButton->Click += gcnew System::EventHandler(this, &UI::runButton_Click);
			// 
			// gamesPlayedLabel
			// 
			this->gamesPlayedLabel->AutoSize = true;
			this->gamesPlayedLabel->Location = System::Drawing::Point(201, 41);
			this->gamesPlayedLabel->Name = L"gamesPlayedLabel";
			this->gamesPlayedLabel->Size = System::Drawing::Size(76, 13);
			this->gamesPlayedLabel->TabIndex = 11;
			this->gamesPlayedLabel->Text = L"games Played:";
			// 
			// gamesPlayedCounter
			// 
			this->gamesPlayedCounter->AutoSize = true;
			this->gamesPlayedCounter->Location = System::Drawing::Point(276, 41);
			this->gamesPlayedCounter->Name = L"gamesPlayedCounter";
			this->gamesPlayedCounter->Size = System::Drawing::Size(13, 13);
			this->gamesPlayedCounter->TabIndex = 12;
			this->gamesPlayedCounter->Text = L"0";
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(197, 96);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(112, 23);
			this->button10->TabIndex = 13;
			this->button10->Text = L"Clear Agents";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &UI::button10_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(201, 59);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(66, 13);
			this->label1->TabIndex = 14;
			this->label1->Text = L"show games";
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Checked = true;
			this->checkBox1->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkBox1->Location = System::Drawing::Point(273, 59);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(15, 14);
			this->checkBox1->TabIndex = 15;
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// UI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(328, 182);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->gamesPlayedCounter);
			this->Controls->Add(this->gamesPlayedLabel);
			this->Controls->Add(this->runButton);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"UI";
			this->Text = L"UI";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		public:
			gameMaster *game = new gameMaster();
	private: System::Void runButton_Click(System::Object^  sender, System::EventArgs^  e) {
		for (int x = 0; x < (int)numericUpDown1->Value; x++)
		{
			game->playgame(); // plays game
			gamesPlayedCounter->Text = gcnew String(std::to_string(game->getGamesPlayed()).c_str());
			if (checkBox1->Checked)
			{
				button1->Text = gcnew String(game->getPos(0).c_str());
				button2->Text = gcnew String(game->getPos(1).c_str());
				button3->Text = gcnew String(game->getPos(2).c_str());
				button4->Text = gcnew String(game->getPos(3).c_str());
				button5->Text = gcnew String(game->getPos(4).c_str());
				button6->Text = gcnew String(game->getPos(5).c_str());
				button7->Text = gcnew String(game->getPos(6).c_str());
				button8->Text = gcnew String(game->getPos(7).c_str());
				button9->Text = gcnew String(game->getPos(8).c_str());
				Update();
			}
		}
	}
private: System::Void button10_Click(System::Object^  sender, System::EventArgs^  e) {
	game->clearAgent();
	gamesPlayedCounter->Text = gcnew String(std::to_string(game->getGamesPlayed()).c_str());

}
};
}
