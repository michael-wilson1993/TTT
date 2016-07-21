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
	private: System::Windows::Forms::Button^  button11;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  p1_wins;
	private: System::Windows::Forms::Label^  p1_lose;
	private: System::Windows::Forms::Label^  p1_tie;
	private: System::Windows::Forms::Label^  p2_tie;
	private: System::Windows::Forms::Label^  p2_lose;

	private: System::Windows::Forms::Label^  p2_wins;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;

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
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->p1_wins = (gcnew System::Windows::Forms::Label());
			this->p1_lose = (gcnew System::Windows::Forms::Label());
			this->p1_tie = (gcnew System::Windows::Forms::Label());
			this->p2_tie = (gcnew System::Windows::Forms::Label());
			this->p2_lose = (gcnew System::Windows::Forms::Label());
			this->p2_wins = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
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
			this->button1->Click += gcnew System::EventHandler(this, &UI::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(69, 13);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(50, 50);
			this->button2->TabIndex = 1;
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &UI::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(125, 13);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(50, 50);
			this->button3->TabIndex = 2;
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &UI::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(13, 69);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(50, 50);
			this->button4->TabIndex = 3;
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &UI::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(69, 69);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(50, 50);
			this->button5->TabIndex = 4;
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &UI::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(125, 69);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(50, 50);
			this->button6->TabIndex = 5;
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &UI::button6_Click);
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(13, 125);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(50, 50);
			this->button7->TabIndex = 6;
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &UI::button7_Click);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(69, 125);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(50, 50);
			this->button8->TabIndex = 7;
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &UI::button8_Click);
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(125, 125);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(50, 50);
			this->button9->TabIndex = 8;
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &UI::button9_Click);
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(278, 15);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1410065408, 2, 0, 0 });
			this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(59, 20);
			this->numericUpDown1->TabIndex = 9;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->numericUpDown1->ValueChanged += gcnew System::EventHandler(this, &UI::numericUpDown1_ValueChanged);
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
			this->gamesPlayedLabel->Location = System::Drawing::Point(226, 42);
			this->gamesPlayedLabel->Name = L"gamesPlayedLabel";
			this->gamesPlayedLabel->Size = System::Drawing::Size(76, 13);
			this->gamesPlayedLabel->TabIndex = 11;
			this->gamesPlayedLabel->Text = L"games Played:";
			// 
			// gamesPlayedCounter
			// 
			this->gamesPlayedCounter->AutoSize = true;
			this->gamesPlayedCounter->Location = System::Drawing::Point(301, 42);
			this->gamesPlayedCounter->Name = L"gamesPlayedCounter";
			this->gamesPlayedCounter->Size = System::Drawing::Size(13, 13);
			this->gamesPlayedCounter->TabIndex = 12;
			this->gamesPlayedCounter->Text = L"0";
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(197, 125);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(142, 23);
			this->button10->TabIndex = 13;
			this->button10->Text = L"Clear Agents";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &UI::button10_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(225, 106);
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
			this->checkBox1->Location = System::Drawing::Point(297, 106);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(15, 14);
			this->checkBox1->TabIndex = 15;
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(197, 152);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(142, 23);
			this->button11->TabIndex = 16;
			this->button11->Text = L"clear Board";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &UI::button11_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(229, 57);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(97, 13);
			this->label2->TabIndex = 17;
			this->label2->Text = L"W           L           T";
			// 
			// p1_wins
			// 
			this->p1_wins->AutoSize = true;
			this->p1_wins->Location = System::Drawing::Point(231, 70);
			this->p1_wins->Name = L"p1_wins";
			this->p1_wins->Size = System::Drawing::Size(13, 13);
			this->p1_wins->TabIndex = 18;
			this->p1_wins->Text = L"0";
			// 
			// p1_lose
			// 
			this->p1_lose->AutoSize = true;
			this->p1_lose->Location = System::Drawing::Point(272, 70);
			this->p1_lose->Name = L"p1_lose";
			this->p1_lose->Size = System::Drawing::Size(13, 13);
			this->p1_lose->TabIndex = 19;
			this->p1_lose->Text = L"0";
			// 
			// p1_tie
			// 
			this->p1_tie->AutoSize = true;
			this->p1_tie->Location = System::Drawing::Point(313, 70);
			this->p1_tie->Name = L"p1_tie";
			this->p1_tie->Size = System::Drawing::Size(13, 13);
			this->p1_tie->TabIndex = 20;
			this->p1_tie->Text = L"0";
			// 
			// p2_tie
			// 
			this->p2_tie->AutoSize = true;
			this->p2_tie->Location = System::Drawing::Point(313, 87);
			this->p2_tie->Name = L"p2_tie";
			this->p2_tie->Size = System::Drawing::Size(13, 13);
			this->p2_tie->TabIndex = 23;
			this->p2_tie->Text = L"0";
			// 
			// p2_lose
			// 
			this->p2_lose->AutoSize = true;
			this->p2_lose->Location = System::Drawing::Point(272, 87);
			this->p2_lose->Name = L"p2_lose";
			this->p2_lose->Size = System::Drawing::Size(13, 13);
			this->p2_lose->TabIndex = 22;
			this->p2_lose->Text = L"0";
			// 
			// p2_wins
			// 
			this->p2_wins->AutoSize = true;
			this->p2_wins->Location = System::Drawing::Point(231, 87);
			this->p2_wins->Name = L"p2_wins";
			this->p2_wins->Size = System::Drawing::Size(13, 13);
			this->p2_wins->TabIndex = 21;
			this->p2_wins->Text = L"0";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(208, 70);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(19, 13);
			this->label3->TabIndex = 24;
			this->label3->Text = L"p1";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(209, 86);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(19, 13);
			this->label4->TabIndex = 25;
			this->label4->Text = L"p2";
			// 
			// UI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(349, 198);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->p2_tie);
			this->Controls->Add(this->p2_lose);
			this->Controls->Add(this->p2_wins);
			this->Controls->Add(this->p1_tie);
			this->Controls->Add(this->p1_lose);
			this->Controls->Add(this->p1_wins);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button11);
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
			void runGame()
			{
				for (int x = 0; x < (int)numericUpDown1->Value; x++)
				{
					game->playgame(); // plays game
					gamesPlayedCounter->Text = gcnew String(std::to_string(game->getGamesPlayed()).c_str());
					p1_wins->Text = gcnew String(std::to_string(game->p1_win).c_str());
					p1_lose->Text = gcnew String(std::to_string(game->p1_lose).c_str());

					p2_wins->Text = gcnew String(std::to_string(game->p2_win).c_str());
					p2_lose->Text = gcnew String(std::to_string(game->p2_lose).c_str());

					p1_tie->Text = gcnew String(std::to_string(game->tie).c_str());
					p2_tie->Text = gcnew String(std::to_string(game->tie).c_str());
					Update();
					if (checkBox1->Checked)
					{
						drawBoard();
					}
				}
			}
			void drawBoard()
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
			gameMaster *game = new gameMaster();
	private: System::Void runButton_Click(System::Object^  sender, System::EventArgs^  e) {
		runGame();
	}
private: System::Void button10_Click(System::Object^  sender, System::EventArgs^  e) {
	game->clearAgent();
	gamesPlayedCounter->Text = gcnew String(std::to_string(game->getGamesPlayed()).c_str());

}
private: System::Void button11_Click(System::Object^  sender, System::EventArgs^  e) {
	game->resetState();
	drawBoard();
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	game->humanVsPCMove(0);
	drawBoard();
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	game->humanVsPCMove(1);
	drawBoard();
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	game->humanVsPCMove(2);
	drawBoard();
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	game->humanVsPCMove(3);
	drawBoard();
}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
	game->humanVsPCMove(4);
	drawBoard();
}
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
	game->humanVsPCMove(5);
	drawBoard();
}
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
	game->humanVsPCMove(6);
	drawBoard();
}
private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
	game->humanVsPCMove(7);
	drawBoard();
}
private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {
	game->humanVsPCMove(8);
	drawBoard();
}
private: System::Void numericUpDown1_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
	runGame();
}
};
}
