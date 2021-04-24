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
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ ≥–≥‚ÂÌ¸ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ≥≤–≥‚ÂÌ¸ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ≥≤≤–≥‚ÂÌ¸ToolStripMenuItem;
	private: System::Windows::Forms::DataGridView^ dataGridView;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;

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
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->≥–≥‚ÂÌ¸ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->≥≤–≥‚ÂÌ¸ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->≥≤≤–≥‚ÂÌ¸ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->checkBox1->Location = System::Drawing::Point(623, 89);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(310, 35);
			this->checkBox1->TabIndex = 1;
			this->checkBox1->Text = L"ƒÓÔÓÏÓ„‡ ÍÓÏÔ\'˛ÚÂ‡";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &GameForm::checkBox1_CheckedChanged);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->≥–≥‚ÂÌ¸ToolStripMenuItem,
					this->≥≤–≥‚ÂÌ¸ToolStripMenuItem, this->≥≤≤–≥‚ÂÌ¸ToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(963, 38);
			this->menuStrip1->TabIndex = 2;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ≥–≥‚ÂÌ¸ToolStripMenuItem
			// 
			this->≥–≥‚ÂÌ¸ToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16));
			this->≥–≥‚ÂÌ¸ToolStripMenuItem->Name = L"≥–≥‚ÂÌ¸ToolStripMenuItem";
			this->≥–≥‚ÂÌ¸ToolStripMenuItem->Size = System::Drawing::Size(103, 34);
			this->≥–≥‚ÂÌ¸ToolStripMenuItem->Text = L"≤ ≥‚ÂÌ¸";
			this->≥–≥‚ÂÌ¸ToolStripMenuItem->Click += gcnew System::EventHandler(this, &GameForm::≥–≥‚ÂÌ¸ToolStripMenuItem_Click);
			// 
			// ≥≤–≥‚ÂÌ¸ToolStripMenuItem
			// 
			this->≥≤–≥‚ÂÌ¸ToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16));
			this->≥≤–≥‚ÂÌ¸ToolStripMenuItem->Name = L"≥≤–≥‚ÂÌ¸ToolStripMenuItem";
			this->≥≤–≥‚ÂÌ¸ToolStripMenuItem->Size = System::Drawing::Size(109, 34);
			this->≥≤–≥‚ÂÌ¸ToolStripMenuItem->Text = L"≤≤ ≥‚ÂÌ¸";
			this->≥≤–≥‚ÂÌ¸ToolStripMenuItem->Click += gcnew System::EventHandler(this, &GameForm::≥≤–≥‚ÂÌ¸ToolStripMenuItem_Click);
			// 
			// ≥≤≤–≥‚ÂÌ¸ToolStripMenuItem
			// 
			this->≥≤≤–≥‚ÂÌ¸ToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16));
			this->≥≤≤–≥‚ÂÌ¸ToolStripMenuItem->Name = L"≥≤≤–≥‚ÂÌ¸ToolStripMenuItem";
			this->≥≤≤–≥‚ÂÌ¸ToolStripMenuItem->Size = System::Drawing::Size(115, 34);
			this->≥≤≤–≥‚ÂÌ¸ToolStripMenuItem->Text = L"≤≤≤ ≥‚ÂÌ¸";
			this->≥≤≤–≥‚ÂÌ¸ToolStripMenuItem->Click += gcnew System::EventHandler(this, &GameForm::≥≤≤–≥‚ÂÌ¸ToolStripMenuItem_Click);
			// 
			// dataGridView
			// 
			this->dataGridView->AllowUserToAddRows = false;
			this->dataGridView->AllowUserToDeleteRows = false;
			this->dataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView->Location = System::Drawing::Point(22, 64);
			this->dataGridView->Name = L"dataGridView";
			this->dataGridView->Size = System::Drawing::Size(476, 346);
			this->dataGridView->TabIndex = 3;
			this->dataGridView->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &GameForm::dataGridView_CellContentClick);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(623, 168);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 75);
			this->button1->TabIndex = 4;
			this->button1->Text = L"—";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &GameForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(719, 168);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 75);
			this->button2->TabIndex = 4;
			this->button2->Text = L"À";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &GameForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(811, 168);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 75);
			this->button3->TabIndex = 4;
			this->button3->Text = L"≈";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &GameForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button4->Location = System::Drawing::Point(668, 259);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 75);
			this->button4->TabIndex = 4;
			this->button4->Text = L"«";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &GameForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button5->Location = System::Drawing::Point(770, 259);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 75);
			this->button5->TabIndex = 4;
			this->button5->Text = L"¿";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &GameForm::button5_Click);
			// 
			// GameForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(963, 443);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->dataGridView);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"GameForm";
			this->Text = L"SquareWord";
			this->Load += gcnew System::EventHandler(this, &GameForm::GameForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	// Game fields
	private: System::Media::SoundPlayer^ soundClick;

	// Game methods
	private: void StartGame();
	private: void CreateGameGrid(int);
	private: void SetStartGameGrid(int);
	private: void SetPosition(coord, char);
	
	// Game events
	private: System::Void GameForm_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ≥–≥‚ÂÌ¸ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ≥≤–≥‚ÂÌ¸ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void ≥≤≤–≥‚ÂÌ¸ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void dataGridView_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e);
};
}
