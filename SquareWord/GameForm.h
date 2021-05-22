#pragma once

#include "GameMap.h"

namespace SquareWord {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for GameForm
	/// </summary>
	public ref class GameForm : public System::Windows::Forms::Form
	{
	public:
		GameForm(void)
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
		~GameForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ ïîâåðíóòèñÿÄîÌåíþToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ïðàâèëàÃðèToolStripMenuItem;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Label^ labelMessage;
	protected:

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
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->dataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->ïîâåðíóòèñÿÄîÌåíþToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ïðàâèëàÃðèToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->labelMessage = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridView
			// 
			this->dataGridView->AllowUserToAddRows = false;
			this->dataGridView->AllowUserToDeleteRows = false;
			this->dataGridView->AllowUserToResizeColumns = false;
			this->dataGridView->AllowUserToResizeRows = false;
			this->dataGridView->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowFrame;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView->ColumnHeadersVisible = false;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView->DefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView->GridColor = System::Drawing::SystemColors::AppWorkspace;
			this->dataGridView->Location = System::Drawing::Point(22, 64);
			this->dataGridView->MultiSelect = false;
			this->dataGridView->Name = L"dataGridView";
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle3->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Arial", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle3->ForeColor = System::Drawing::SystemColors::WindowFrame;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView->RowHeadersDefaultCellStyle = dataGridViewCellStyle3;
			this->dataGridView->RowHeadersVisible = false;
			this->dataGridView->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders;
			this->dataGridView->ScrollBars = System::Windows::Forms::ScrollBars::None;
			this->dataGridView->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::CellSelect;
			this->dataGridView->Size = System::Drawing::Size(350, 350);
			this->dataGridView->TabIndex = 3;
			this->dataGridView->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &GameForm::dataGridView_CellContentClick);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(414, 64);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 75);
			this->button1->TabIndex = 4;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &GameForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(414, 150);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 75);
			this->button2->TabIndex = 4;
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &GameForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(414, 240);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 75);
			this->button3->TabIndex = 4;
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &GameForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button4->Location = System::Drawing::Point(510, 64);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 75);
			this->button4->TabIndex = 4;
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &GameForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button5->Location = System::Drawing::Point(510, 150);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 75);
			this->button5->TabIndex = 4;
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &GameForm::button5_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->ïîâåðíóòèñÿÄîÌåíþToolStripMenuItem,
					this->ïðàâèëàÃðèToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(616, 33);
			this->menuStrip1->TabIndex = 5;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ïîâåðíóòèñÿÄîÌåíþToolStripMenuItem
			// 
			this->ïîâåðíóòèñÿÄîÌåíþToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14));
			this->ïîâåðíóòèñÿÄîÌåíþToolStripMenuItem->Name = L"ïîâåðíóòèñÿÄîÌåíþToolStripMenuItem";
			this->ïîâåðíóòèñÿÄîÌåíþToolStripMenuItem->Size = System::Drawing::Size(218, 29);
			this->ïîâåðíóòèñÿÄîÌåíþToolStripMenuItem->Text = L"Ïîâåðíóòèñÿ äî ìåíþ";
			this->ïîâåðíóòèñÿÄîÌåíþToolStripMenuItem->Click += gcnew System::EventHandler(this, &GameForm::ïîâåðíóòèñÿÄîÌåíþToolStripMenuItem_Click);
			// 
			// ïðàâèëàÃðèToolStripMenuItem
			// 
			this->ïðàâèëàÃðèToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14));
			this->ïðàâèëàÃðèToolStripMenuItem->Name = L"ïðàâèëàÃðèToolStripMenuItem";
			this->ïðàâèëàÃðèToolStripMenuItem->Size = System::Drawing::Size(134, 29);
			this->ïðàâèëàÃðèToolStripMenuItem->Text = L"Ïðàâèëà ãðè";
			this->ïðàâèëàÃðèToolStripMenuItem->Click += gcnew System::EventHandler(this, &GameForm::ïðàâèëàÃðèToolStripMenuItem_Click);
			// 
			// button6
			// 
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button6->Location = System::Drawing::Point(510, 240);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(75, 75);
			this->button6->TabIndex = 4;
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &GameForm::button6_Click);
			// 
			// button7
			// 
			this->button7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button7->Location = System::Drawing::Point(461, 333);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(75, 75);
			this->button7->TabIndex = 4;
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &GameForm::button7_Click);
			// 
			// labelMessage
			// 
			this->labelMessage->AutoSize = true;
			this->labelMessage->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->labelMessage->ForeColor = System::Drawing::Color::Red;
			this->labelMessage->Location = System::Drawing::Point(18, 439);
			this->labelMessage->Name = L"labelMessage";
			this->labelMessage->Size = System::Drawing::Size(94, 24);
			this->labelMessage->TabIndex = 6;
			this->labelMessage->Text = L"message";
			this->labelMessage->Visible = false;
			// 
			// GameForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(616, 491);
			this->Controls->Add(this->labelMessage);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"GameForm";
			this->Text = L"SquareWord";
			this->Load += gcnew System::EventHandler(this, &GameForm::GameForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	// Game fields
	public: int size;
	public: bool computerHelp;
	private: System::Media::SoundPlayer^ soundClick;
	private: System::Media::SoundPlayer^ soundIncorrect;

	// Game methods
	private: System::String^ CharToSysString(char);
	private: void StartGame();
	private: void CreateGameGrid(int);
	private: void SetStartGameGrid(int);
	private: void SetPosition(coord, char);
	private: void ShowConflict(const char&);
	
	// Game events
	private: System::Void GameForm_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void dataGridView_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
	private: System::Void ïîâåðíóòèñÿÄîÌåíþToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ïðàâèëàÃðèToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e);
};
}
