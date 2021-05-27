#pragma once

#include "StartForm.h"
#include "GameMap.h"
#include "Stopwatch.h"

// computer help modes
enum GameMode { none, showConf, hideChars };

namespace SquareWord
{
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
        GameForm() {
            InitializeComponent();
        }

    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~GameForm() {
            delete map;
            delete stopwatch;
            delete selected_cell;
            if (components) {
                delete components;
            }
        }

    private: System::Windows::Forms::MenuStrip^ menuStrip;
    private: System::Windows::Forms::ToolStripMenuItem^ goBackToolStripMenuItem;
    private: System::Windows::Forms::ToolStripMenuItem^ rulesToolStripMenuItem;

    private: System::Windows::Forms::Label^ labelSteps;
    private: System::Windows::Forms::Label^ labelStepsValue;
    private: System::Windows::Forms::Label^ labelTime;
    private: System::Windows::Forms::Label^ labelTimerValue;

    private: System::Windows::Forms::DataGridView^ dataGridView;
    private: System::Windows::Forms::GroupBox^ groupBoxChars;
    private: System::Windows::Forms::Button^ button1;
    private: System::Windows::Forms::Button^ button2;
    private: System::Windows::Forms::Button^ button3;
    private: System::Windows::Forms::Button^ button4;
    private: System::Windows::Forms::Button^ button5;
    private: System::Windows::Forms::Button^ button6;
    private: System::Windows::Forms::Button^ button7;

    private: System::Windows::Forms::Label^ labelMessage;
    private: System::Windows::Forms::Button^ buttonFinishGame;

    private: System::Windows::Forms::Timer^ timer;
    private: System::Windows::Forms::Button^ button8;

    private:
        /// <summary>
        /// Required designer variable.
        /// </summary>
        System::ComponentModel::IContainer^ components;


#pragma region Windows Form Designer generated code
        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        void InitializeComponent()
        {
            this->components = (gcnew System::ComponentModel::Container());
            System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
            this->menuStrip = (gcnew System::Windows::Forms::MenuStrip());
            this->goBackToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->rulesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->labelSteps = (gcnew System::Windows::Forms::Label());
            this->labelStepsValue = (gcnew System::Windows::Forms::Label());
            this->labelTime = (gcnew System::Windows::Forms::Label());
            this->labelTimerValue = (gcnew System::Windows::Forms::Label());
            this->dataGridView = (gcnew System::Windows::Forms::DataGridView());
            this->groupBoxChars = (gcnew System::Windows::Forms::GroupBox());
            this->button4 = (gcnew System::Windows::Forms::Button());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->button2 = (gcnew System::Windows::Forms::Button());
            this->button3 = (gcnew System::Windows::Forms::Button());
            this->button5 = (gcnew System::Windows::Forms::Button());
            this->button6 = (gcnew System::Windows::Forms::Button());
            this->button8 = (gcnew System::Windows::Forms::Button());
            this->button7 = (gcnew System::Windows::Forms::Button());
            this->labelMessage = (gcnew System::Windows::Forms::Label());
            this->buttonFinishGame = (gcnew System::Windows::Forms::Button());
            this->timer = (gcnew System::Windows::Forms::Timer(this->components));
            this->menuStrip->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->BeginInit();
            this->groupBoxChars->SuspendLayout();
            this->SuspendLayout();
            // 
            // menuStrip
            // 
            this->menuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
                this->goBackToolStripMenuItem,
                    this->rulesToolStripMenuItem
            });
            this->menuStrip->Location = System::Drawing::Point(0, 0);
            this->menuStrip->Name = L"menuStrip";
            this->menuStrip->Size = System::Drawing::Size(621, 35);
            this->menuStrip->TabIndex = 5;
            this->menuStrip->Text = L"menuStrip";
            // 
            // goBackToolStripMenuItem
            // 
            this->goBackToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 14, System::Drawing::FontStyle::Bold));
            this->goBackToolStripMenuItem->ForeColor = System::Drawing::Color::Navy;
            this->goBackToolStripMenuItem->Name = L"goBackToolStripMenuItem";
            this->goBackToolStripMenuItem->Size = System::Drawing::Size(237, 31);
            this->goBackToolStripMenuItem->Text = L"Повернутися до меню";
            this->goBackToolStripMenuItem->Click += gcnew System::EventHandler(this, &GameForm::goBackToolStripMenuItem_Click);
            // 
            // rulesToolStripMenuItem
            // 
            this->rulesToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 14, System::Drawing::FontStyle::Bold));
            this->rulesToolStripMenuItem->ForeColor = System::Drawing::Color::Navy;
            this->rulesToolStripMenuItem->Name = L"rulesToolStripMenuItem";
            this->rulesToolStripMenuItem->Size = System::Drawing::Size(107, 31);
            this->rulesToolStripMenuItem->Text = L"Правила";
            this->rulesToolStripMenuItem->Click += gcnew System::EventHandler(this, &GameForm::rulesToolStripMenuItem_Click);
            // 
            // labelSteps
            // 
            this->labelSteps->AutoSize = true;
            this->labelSteps->Font = (gcnew System::Drawing::Font(L"Cambria", 16, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->labelSteps->Location = System::Drawing::Point(12, 57);
            this->labelSteps->Name = L"labelSteps";
            this->labelSteps->Size = System::Drawing::Size(184, 26);
            this->labelSteps->TabIndex = 8;
            this->labelSteps->Text = L"Кількість кроків:";
            // 
            // labelStepsValue
            // 
            this->labelStepsValue->AutoSize = true;
            this->labelStepsValue->Font = (gcnew System::Drawing::Font(L"Consolas", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->labelStepsValue->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
            this->labelStepsValue->Location = System::Drawing::Point(202, 58);
            this->labelStepsValue->Name = L"labelStepsValue";
            this->labelStepsValue->Size = System::Drawing::Size(48, 26);
            this->labelStepsValue->TabIndex = 7;
            this->labelStepsValue->Text = L"000";
            this->labelStepsValue->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
            // 
            // labelTime
            // 
            this->labelTime->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->labelTime->AutoSize = true;
            this->labelTime->Font = (gcnew System::Drawing::Font(L"Cambria", 16, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->labelTime->Location = System::Drawing::Point(380, 57);
            this->labelTime->Name = L"labelTime";
            this->labelTime->Size = System::Drawing::Size(91, 26);
            this->labelTime->TabIndex = 10;
            this->labelTime->Text = L"Час гри:";
            // 
            // labelTimerValue
            // 
            this->labelTimerValue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->labelTimerValue->AutoSize = true;
            this->labelTimerValue->Font = (gcnew System::Drawing::Font(L"Consolas", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->labelTimerValue->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
            this->labelTimerValue->Location = System::Drawing::Point(489, 58);
            this->labelTimerValue->Name = L"labelTimerValue";
            this->labelTimerValue->Size = System::Drawing::Size(108, 26);
            this->labelTimerValue->TabIndex = 9;
            this->labelTimerValue->Text = L"00:00:00";
            this->labelTimerValue->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
            // 
            // dataGridView
            // 
            this->dataGridView->AllowUserToAddRows = false;
            this->dataGridView->AllowUserToDeleteRows = false;
            this->dataGridView->AllowUserToResizeColumns = false;
            this->dataGridView->AllowUserToResizeRows = false;
            this->dataGridView->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
            this->dataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridView->ColumnHeadersVisible = false;
            this->dataGridView->Cursor = System::Windows::Forms::Cursors::Default;
            dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
            dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Window;
            dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            dataGridViewCellStyle1->ForeColor = System::Drawing::Color::Black;
            dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
            dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
            dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
            this->dataGridView->DefaultCellStyle = dataGridViewCellStyle1;
            this->dataGridView->GridColor = System::Drawing::SystemColors::AppWorkspace;
            this->dataGridView->Location = System::Drawing::Point(17, 116);
            this->dataGridView->MultiSelect = false;
            this->dataGridView->Name = L"dataGridView";
            this->dataGridView->RowHeadersVisible = false;
            this->dataGridView->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders;
            this->dataGridView->ScrollBars = System::Windows::Forms::ScrollBars::None;
            this->dataGridView->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::CellSelect;
            this->dataGridView->Size = System::Drawing::Size(350, 350);
            this->dataGridView->TabIndex = 3;
            this->dataGridView->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &GameForm::dataGridView_CellContentClick);
            // 
            // groupBoxChars
            // 
            this->groupBoxChars->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->groupBoxChars->Controls->Add(this->button4);
            this->groupBoxChars->Controls->Add(this->button1);
            this->groupBoxChars->Controls->Add(this->button2);
            this->groupBoxChars->Controls->Add(this->button3);
            this->groupBoxChars->Controls->Add(this->button5);
            this->groupBoxChars->Controls->Add(this->button6);
            this->groupBoxChars->Controls->Add(this->button8);
            this->groupBoxChars->Controls->Add(this->button7);
            this->groupBoxChars->Font = (gcnew System::Drawing::Font(L"Cambria", 14, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->groupBoxChars->ForeColor = System::Drawing::Color::Navy;
            this->groupBoxChars->Location = System::Drawing::Point(385, 102);
            this->groupBoxChars->Name = L"groupBoxChars";
            this->groupBoxChars->Size = System::Drawing::Size(210, 364);
            this->groupBoxChars->TabIndex = 11;
            this->groupBoxChars->TabStop = false;
            this->groupBoxChars->Text = L"Клавіатура букв";
            // 
            // button4
            // 
            this->button4->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
            this->button4->Font = (gcnew System::Drawing::Font(L"Arial", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->button4->ForeColor = System::Drawing::Color::Black;
            this->button4->Location = System::Drawing::Point(28, 194);
            this->button4->Name = L"button4";
            this->button4->Size = System::Drawing::Size(75, 75);
            this->button4->TabIndex = 4;
            this->button4->UseVisualStyleBackColor = false;
            this->button4->Visible = false;
            this->button4->Click += gcnew System::EventHandler(this, &GameForm::button4_Click);
            // 
            // button1
            // 
            this->button1->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
            this->button1->Font = (gcnew System::Drawing::Font(L"Arial", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->button1->ForeColor = System::Drawing::Color::Black;
            this->button1->Location = System::Drawing::Point(109, 32);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(75, 75);
            this->button1->TabIndex = 4;
            this->button1->UseVisualStyleBackColor = false;
            this->button1->Visible = false;
            this->button1->Click += gcnew System::EventHandler(this, &GameForm::button1_Click);
            // 
            // button2
            // 
            this->button2->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
            this->button2->Font = (gcnew System::Drawing::Font(L"Arial", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->button2->ForeColor = System::Drawing::Color::Black;
            this->button2->Location = System::Drawing::Point(28, 113);
            this->button2->Name = L"button2";
            this->button2->Size = System::Drawing::Size(75, 75);
            this->button2->TabIndex = 4;
            this->button2->UseVisualStyleBackColor = false;
            this->button2->Visible = false;
            this->button2->Click += gcnew System::EventHandler(this, &GameForm::button2_Click);
            // 
            // button3
            // 
            this->button3->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
            this->button3->Font = (gcnew System::Drawing::Font(L"Arial", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->button3->ForeColor = System::Drawing::Color::Black;
            this->button3->Location = System::Drawing::Point(109, 113);
            this->button3->Name = L"button3";
            this->button3->Size = System::Drawing::Size(75, 75);
            this->button3->TabIndex = 4;
            this->button3->UseVisualStyleBackColor = false;
            this->button3->Visible = false;
            this->button3->Click += gcnew System::EventHandler(this, &GameForm::button3_Click);
            // 
            // button5
            // 
            this->button5->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
            this->button5->Font = (gcnew System::Drawing::Font(L"Arial", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->button5->ForeColor = System::Drawing::Color::Black;
            this->button5->Location = System::Drawing::Point(109, 194);
            this->button5->Name = L"button5";
            this->button5->Size = System::Drawing::Size(75, 75);
            this->button5->TabIndex = 4;
            this->button5->UseVisualStyleBackColor = false;
            this->button5->Visible = false;
            this->button5->Click += gcnew System::EventHandler(this, &GameForm::button5_Click);
            // 
            // button6
            // 
            this->button6->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
            this->button6->Font = (gcnew System::Drawing::Font(L"Arial", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->button6->ForeColor = System::Drawing::Color::Black;
            this->button6->Location = System::Drawing::Point(28, 275);
            this->button6->Name = L"button6";
            this->button6->Size = System::Drawing::Size(75, 75);
            this->button6->TabIndex = 4;
            this->button6->UseVisualStyleBackColor = false;
            this->button6->Visible = false;
            this->button6->Click += gcnew System::EventHandler(this, &GameForm::button6_Click);
            // 
            // button8
            // 
            this->button8->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
            this->button8->Font = (gcnew System::Drawing::Font(L"Arial", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->button8->ForeColor = System::Drawing::Color::Black;
            this->button8->Location = System::Drawing::Point(28, 32);
            this->button8->Name = L"button8";
            this->button8->Size = System::Drawing::Size(75, 75);
            this->button8->TabIndex = 4;
            this->button8->UseVisualStyleBackColor = false;
            this->button8->Visible = false;
            this->button8->Click += gcnew System::EventHandler(this, &GameForm::button8_Click);
            // 
            // button7
            // 
            this->button7->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
            this->button7->Font = (gcnew System::Drawing::Font(L"Arial", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->button7->ForeColor = System::Drawing::Color::Black;
            this->button7->Location = System::Drawing::Point(109, 275);
            this->button7->Name = L"button7";
            this->button7->Size = System::Drawing::Size(75, 75);
            this->button7->TabIndex = 4;
            this->button7->UseVisualStyleBackColor = false;
            this->button7->Visible = false;
            this->button7->Click += gcnew System::EventHandler(this, &GameForm::button7_Click);
            // 
            // labelMessage
            // 
            this->labelMessage->AutoSize = true;
            this->labelMessage->Font = (gcnew System::Drawing::Font(L"Calibri", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->labelMessage->ForeColor = System::Drawing::Color::Red;
            this->labelMessage->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
            this->labelMessage->Location = System::Drawing::Point(12, 498);
            this->labelMessage->Name = L"labelMessage";
            this->labelMessage->Size = System::Drawing::Size(144, 27);
            this->labelMessage->TabIndex = 6;
            this->labelMessage->Text = L"Error Message";
            this->labelMessage->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            this->labelMessage->Visible = false;
            // 
            // buttonFinishGame
            // 
            this->buttonFinishGame->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->buttonFinishGame->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
            this->buttonFinishGame->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->buttonFinishGame->ForeColor = System::Drawing::Color::Maroon;
            this->buttonFinishGame->Location = System::Drawing::Point(385, 485);
            this->buttonFinishGame->Name = L"buttonFinishGame";
            this->buttonFinishGame->Size = System::Drawing::Size(210, 51);
            this->buttonFinishGame->TabIndex = 12;
            this->buttonFinishGame->Text = L"Завершити гру";
            this->buttonFinishGame->UseVisualStyleBackColor = false;
            this->buttonFinishGame->Click += gcnew System::EventHandler(this, &GameForm::buttonFinishGame_Click);
            // 
            // timer
            // 
            this->timer->Interval = 1000;
            this->timer->Tick += gcnew System::EventHandler(this, &GameForm::timer_Tick);
            // 
            // GameForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(621, 548);
            this->Controls->Add(this->buttonFinishGame);
            this->Controls->Add(this->groupBoxChars);
            this->Controls->Add(this->labelTime);
            this->Controls->Add(this->labelTimerValue);
            this->Controls->Add(this->labelSteps);
            this->Controls->Add(this->labelStepsValue);
            this->Controls->Add(this->labelMessage);
            this->Controls->Add(this->dataGridView);
            this->Controls->Add(this->menuStrip);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
            this->MainMenuStrip = this->menuStrip;
            this->Name = L"GameForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Головоломка SquareWord";
            this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &GameForm::GameForm_FormClosing);
            this->Load += gcnew System::EventHandler(this, &GameForm::GameForm_Load);
            this->menuStrip->ResumeLayout(false);
            this->menuStrip->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->EndInit();
            this->groupBoxChars->ResumeLayout(false);
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

        // Game fields
    public: int size;
    public: int steps;
    public: enum GameMode mode;
    public: bool soundInterface; // sound of keys and victory at the end of the game (flag)
    private: System::Media::SoundPlayer^ soundClick; // sound of key (value)
    private: System::Media::SoundPlayer^ soundIncorrect;
    private: System::Media::SoundPlayer^ soundWin;
    private: GameMap* map;
    private: Stopwatch* stopwatch;
    private: coord* selected_cell;

           // Game methods
    private: System::String^ CharToSysString(char);
    private: void CreateGameGrid();
    private: void SetStartGameGrid();
    private: void InitializeButtons();
    private: void ShowAllButtons();
    private: void HideAllButtons();
    private: void HideButton(char);
    private: void ButtonSetChar(int, int);
    private: void FindConflict(const char&);
    private: void CheckMap();

           // Game events
    private: System::Void GameForm_Load(System::Object^ sender, System::EventArgs^ e);
    private: System::Void dataGridView_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
    private: System::Void goBackToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void rulesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);

    private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void SquareWord::GameForm::buttonFinishGame_Click(System::Object^ sender, System::EventArgs^ e);

    private: System::Void timer_Tick(System::Object^ sender, System::EventArgs^ e);
    private: System::Void GameForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
};
}
