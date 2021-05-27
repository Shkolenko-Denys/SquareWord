#pragma once

#include "GameForm.h" // for create the form and pass starting values to it

namespace SquareWord
{
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Summary for StartForm
    /// </summary>
    public ref class StartForm : public System::Windows::Forms::Form
    {
    public:
        StartForm() {
            InitializeComponent();
        }

    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~StartForm() {
            if (components) {
                delete components;
            }
        }

    private: System::Windows::Forms::MenuStrip^ menuStrip;
    private: System::Windows::Forms::ToolStripMenuItem^ InstructionToolStripMenuItem;
    private: System::Windows::Forms::ToolStripMenuItem^ SoundToolStripMenuItem;
    private: System::Windows::Forms::ToolStripMenuItem^ melody1ToolStripMenuItem;
    private: System::Windows::Forms::ToolStripMenuItem^ melody2ToolStripMenuItem;
    private: System::Windows::Forms::ToolStripMenuItem^ melody3ToolStripMenuItem;
    private: System::Windows::Forms::ToolStripMenuItem^ melody4ToolStripMenuItem;
    private: System::Windows::Forms::ToolStripMenuItem^ nomelodyToolStripMenuItem;

    private: System::Windows::Forms::Label^ labelSize;
    private: System::Windows::Forms::NumericUpDown^ numSize;

    private: System::Windows::Forms::GroupBox^ groupBoxGameMode;
    private: System::Windows::Forms::RadioButton^ radioButtonNone;
    private: System::Windows::Forms::RadioButton^ radioButtonShowConfChars;
    private: System::Windows::Forms::RadioButton^ radioButtonHideButtons;

    private: System::Windows::Forms::Button^ buttonStartGame;
    private: System::Windows::Forms::Button^ buttonExitGame;
    private: System::ComponentModel::BackgroundWorker^ backgroundWorkerMusic;

    private:
        /// <summary>
        /// Required designer variable.
        /// </summary>
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        void InitializeComponent()
        {
            this->menuStrip = (gcnew System::Windows::Forms::MenuStrip());
            this->InstructionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->SoundToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->melody1ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->melody2ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->melody3ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->melody4ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->nomelodyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
            this->labelSize = (gcnew System::Windows::Forms::Label());
            this->numSize = (gcnew System::Windows::Forms::NumericUpDown());
            this->groupBoxGameMode = (gcnew System::Windows::Forms::GroupBox());
            this->radioButtonNone = (gcnew System::Windows::Forms::RadioButton());
            this->radioButtonShowConfChars = (gcnew System::Windows::Forms::RadioButton());
            this->radioButtonHideButtons = (gcnew System::Windows::Forms::RadioButton());
            this->buttonStartGame = (gcnew System::Windows::Forms::Button());
            this->buttonExitGame = (gcnew System::Windows::Forms::Button());
            this->backgroundWorkerMusic = (gcnew System::ComponentModel::BackgroundWorker());
            this->menuStrip->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numSize))->BeginInit();
            this->groupBoxGameMode->SuspendLayout();
            this->SuspendLayout();
            // 
            // menuStrip
            // 
            this->menuStrip->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 9));
            this->menuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
                this->InstructionToolStripMenuItem,
                    this->SoundToolStripMenuItem
            });
            this->menuStrip->Location = System::Drawing::Point(0, 0);
            this->menuStrip->Name = L"menuStrip";
            this->menuStrip->Size = System::Drawing::Size(512, 35);
            this->menuStrip->TabIndex = 2;
            this->menuStrip->Text = L"menuStrip";
            // 
            // InstructionToolStripMenuItem
            // 
            this->InstructionToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 14, System::Drawing::FontStyle::Bold));
            this->InstructionToolStripMenuItem->ForeColor = System::Drawing::Color::Navy;
            this->InstructionToolStripMenuItem->Name = L"InstructionToolStripMenuItem";
            this->InstructionToolStripMenuItem->Size = System::Drawing::Size(121, 31);
            this->InstructionToolStripMenuItem->Text = L"Інструкція";
            this->InstructionToolStripMenuItem->Click += gcnew System::EventHandler(this, &StartForm::InstructionToolStripMenuItem_Click);
            // 
            // SoundToolStripMenuItem
            // 
            this->SoundToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
                this->melody1ToolStripMenuItem,
                    this->melody2ToolStripMenuItem, this->melody3ToolStripMenuItem, this->melody4ToolStripMenuItem, this->nomelodyToolStripMenuItem
            });
            this->SoundToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 14, System::Drawing::FontStyle::Bold));
            this->SoundToolStripMenuItem->ForeColor = System::Drawing::Color::Navy;
            this->SoundToolStripMenuItem->Name = L"SoundToolStripMenuItem";
            this->SoundToolStripMenuItem->Size = System::Drawing::Size(65, 31);
            this->SoundToolStripMenuItem->Text = L"Звук";
            this->SoundToolStripMenuItem->Click += gcnew System::EventHandler(this, &StartForm::SoundToolStripMenuItem_Click);
            // 
            // melody1ToolStripMenuItem
            // 
            this->melody1ToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Bold));
            this->melody1ToolStripMenuItem->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
                static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
            this->melody1ToolStripMenuItem->Name = L"melody1ToolStripMenuItem";
            this->melody1ToolStripMenuItem->Size = System::Drawing::Size(180, 24);
            this->melody1ToolStripMenuItem->Text = L"Мелодія 1";
            this->melody1ToolStripMenuItem->Click += gcnew System::EventHandler(this, &StartForm::melody1ToolStripMenuItem_Click);
            // 
            // melody2ToolStripMenuItem
            // 
            this->melody2ToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Bold));
            this->melody2ToolStripMenuItem->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
                static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
            this->melody2ToolStripMenuItem->Name = L"melody2ToolStripMenuItem";
            this->melody2ToolStripMenuItem->Size = System::Drawing::Size(180, 24);
            this->melody2ToolStripMenuItem->Text = L"Мелодія 2";
            this->melody2ToolStripMenuItem->Click += gcnew System::EventHandler(this, &StartForm::melody2ToolStripMenuItem_Click);
            // 
            // melody3ToolStripMenuItem
            // 
            this->melody3ToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Bold));
            this->melody3ToolStripMenuItem->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
                static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
            this->melody3ToolStripMenuItem->Name = L"melody3ToolStripMenuItem";
            this->melody3ToolStripMenuItem->Size = System::Drawing::Size(180, 24);
            this->melody3ToolStripMenuItem->Text = L"Мелодія 3";
            this->melody3ToolStripMenuItem->Click += gcnew System::EventHandler(this, &StartForm::melody3ToolStripMenuItem_Click);
            // 
            // melody4ToolStripMenuItem
            // 
            this->melody4ToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Bold));
            this->melody4ToolStripMenuItem->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
                static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
            this->melody4ToolStripMenuItem->Name = L"melody4ToolStripMenuItem";
            this->melody4ToolStripMenuItem->Size = System::Drawing::Size(180, 24);
            this->melody4ToolStripMenuItem->Text = L"Мелодія 4";
            this->melody4ToolStripMenuItem->Click += gcnew System::EventHandler(this, &StartForm::melody4ToolStripMenuItem_Click);
            // 
            // nomelodyToolStripMenuItem
            // 
            this->nomelodyToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Consolas", 12, System::Drawing::FontStyle::Bold));
            this->nomelodyToolStripMenuItem->ForeColor = System::Drawing::Color::Maroon;
            this->nomelodyToolStripMenuItem->Name = L"nomelodyToolStripMenuItem";
            this->nomelodyToolStripMenuItem->Size = System::Drawing::Size(180, 24);
            this->nomelodyToolStripMenuItem->Text = L"Без мелодії";
            this->nomelodyToolStripMenuItem->Click += gcnew System::EventHandler(this, &StartForm::nomelodyToolStripMenuItem_Click);
            // 
            // labelSize
            // 
            this->labelSize->AutoSize = true;
            this->labelSize->Font = (gcnew System::Drawing::Font(L"Cambria", 18, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->labelSize->Location = System::Drawing::Point(28, 70);
            this->labelSize->Name = L"labelSize";
            this->labelSize->Size = System::Drawing::Size(251, 28);
            this->labelSize->TabIndex = 0;
            this->labelSize->Text = L"Виберіть розмір поля:";
            // 
            // numSize
            // 
            this->numSize->Font = (gcnew System::Drawing::Font(L"Consolas", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->numSize->Location = System::Drawing::Point(357, 69);
            this->numSize->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 7, 0, 0, 0 });
            this->numSize->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
            this->numSize->Name = L"numSize";
            this->numSize->ReadOnly = true;
            this->numSize->Size = System::Drawing::Size(120, 36);
            this->numSize->TabIndex = 3;
            this->numSize->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
            this->numSize->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
            this->numSize->ValueChanged += gcnew System::EventHandler(this, &StartForm::numSize_ValueChanged);
            // 
            // groupBoxGameMode
            // 
            this->groupBoxGameMode->Controls->Add(this->radioButtonNone);
            this->groupBoxGameMode->Controls->Add(this->radioButtonShowConfChars);
            this->groupBoxGameMode->Controls->Add(this->radioButtonHideButtons);
            this->groupBoxGameMode->Font = (gcnew System::Drawing::Font(L"Cambria", 14.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
                System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
            this->groupBoxGameMode->ForeColor = System::Drawing::Color::Navy;
            this->groupBoxGameMode->Location = System::Drawing::Point(33, 125);
            this->groupBoxGameMode->Name = L"groupBoxGameMode";
            this->groupBoxGameMode->Size = System::Drawing::Size(444, 156);
            this->groupBoxGameMode->TabIndex = 5;
            this->groupBoxGameMode->TabStop = false;
            this->groupBoxGameMode->Text = L"Режим гри";
            // 
            // radioButtonNone
            // 
            this->radioButtonNone->AutoSize = true;
            this->radioButtonNone->Font = (gcnew System::Drawing::Font(L"Times New Roman", 18, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->radioButtonNone->ForeColor = System::Drawing::Color::Black;
            this->radioButtonNone->Location = System::Drawing::Point(6, 33);
            this->radioButtonNone->Name = L"radioButtonNone";
            this->radioButtonNone->Size = System::Drawing::Size(156, 31);
            this->radioButtonNone->TabIndex = 2;
            this->radioButtonNone->TabStop = true;
            this->radioButtonNone->Text = L"Самостійно";
            this->radioButtonNone->UseVisualStyleBackColor = true;
            // 
            // radioButtonShowConfChars
            // 
            this->radioButtonShowConfChars->AutoSize = true;
            this->radioButtonShowConfChars->Font = (gcnew System::Drawing::Font(L"Times New Roman", 18, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->radioButtonShowConfChars->ForeColor = System::Drawing::Color::Black;
            this->radioButtonShowConfChars->Location = System::Drawing::Point(6, 70);
            this->radioButtonShowConfChars->Name = L"radioButtonShowConfChars";
            this->radioButtonShowConfChars->Size = System::Drawing::Size(385, 31);
            this->radioButtonShowConfChars->TabIndex = 0;
            this->radioButtonShowConfChars->TabStop = true;
            this->radioButtonShowConfChars->Text = L"Підсвічування конфліктуючих букв";
            this->radioButtonShowConfChars->UseVisualStyleBackColor = true;
            this->radioButtonShowConfChars->CheckedChanged += gcnew System::EventHandler(this, &StartForm::radioButtonShowConfChars_CheckedChanged);
            // 
            // radioButtonHideButtons
            // 
            this->radioButtonHideButtons->AutoSize = true;
            this->radioButtonHideButtons->Font = (gcnew System::Drawing::Font(L"Times New Roman", 18, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->radioButtonHideButtons->ForeColor = System::Drawing::Color::Black;
            this->radioButtonHideButtons->Location = System::Drawing::Point(6, 107);
            this->radioButtonHideButtons->Name = L"radioButtonHideButtons";
            this->radioButtonHideButtons->Size = System::Drawing::Size(424, 31);
            this->radioButtonHideButtons->TabIndex = 1;
            this->radioButtonHideButtons->TabStop = true;
            this->radioButtonHideButtons->Text = L"Відображення тільки правильних букв";
            this->radioButtonHideButtons->UseVisualStyleBackColor = true;
            this->radioButtonHideButtons->CheckedChanged += gcnew System::EventHandler(this, &StartForm::radioButtonHideButtons_CheckedChanged);
            // 
            // buttonStartGame
            // 
            this->buttonStartGame->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)));
            this->buttonStartGame->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->buttonStartGame->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->buttonStartGame->Location = System::Drawing::Point(266, 313);
            this->buttonStartGame->Name = L"buttonStartGame";
            this->buttonStartGame->Size = System::Drawing::Size(211, 59);
            this->buttonStartGame->TabIndex = 4;
            this->buttonStartGame->Text = L"Старт";
            this->buttonStartGame->UseVisualStyleBackColor = false;
            this->buttonStartGame->Click += gcnew System::EventHandler(this, &StartForm::buttonStartGame_Click);
            // 
            // buttonExitGame
            // 
            this->buttonExitGame->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)));
            this->buttonExitGame->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 20, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(204)));
            this->buttonExitGame->ForeColor = System::Drawing::Color::Maroon;
            this->buttonExitGame->Location = System::Drawing::Point(33, 313);
            this->buttonExitGame->Name = L"buttonExitGame";
            this->buttonExitGame->Size = System::Drawing::Size(211, 59);
            this->buttonExitGame->TabIndex = 4;
            this->buttonExitGame->Text = L"Вийти";
            this->buttonExitGame->UseVisualStyleBackColor = false;
            this->buttonExitGame->Click += gcnew System::EventHandler(this, &StartForm::buttonExitGame_Click);
            // 
            // backgroundWorkerMusic
            // 
            this->backgroundWorkerMusic->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &StartForm::backgroundWorkerMusic_DoWork);
            // 
            // StartForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::SystemColors::Menu;
            this->ClientSize = System::Drawing::Size(512, 403);
            this->Controls->Add(this->groupBoxGameMode);
            this->Controls->Add(this->buttonExitGame);
            this->Controls->Add(this->buttonStartGame);
            this->Controls->Add(this->numSize);
            this->Controls->Add(this->labelSize);
            this->Controls->Add(this->menuStrip);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
            this->MainMenuStrip = this->menuStrip;
            this->Name = L"StartForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Головоломка SquareWord";
            this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &StartForm::StartForm_FormClosing);
            this->Load += gcnew System::EventHandler(this, &StartForm::StartForm_Load);
            this->menuStrip->ResumeLayout(false);
            this->menuStrip->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numSize))->EndInit();
            this->groupBoxGameMode->ResumeLayout(false);
            this->groupBoxGameMode->PerformLayout();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

        // Game fields
    private: bool soundInterface; /* if it is true, then
        the sound of the keys and the sound of victory at the end of the game
        are turned on, else these sounds are turned off
        and background music is played */
    private: System::Media::SoundPlayer^ soundClick; // key sound (value)
    private: System::Media::SoundPlayer^ backgroundMusic;

           // Game methods
    private: void TurnOnMelody(System::String^ melodyName);

           // Game events
    private: System::Void StartForm_Load(System::Object^ sender, System::EventArgs^ e);

    private: System::Void InstructionToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void SoundToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void melody1ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void melody2ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void melody3ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void melody4ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void nomelodyToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);

    private: System::Void numSize_ValueChanged(System::Object^ sender, System::EventArgs^ e);

    private: System::Void radioButtonNone_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
    private: System::Void radioButtonShowConfChars_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
    private: System::Void radioButtonHideButtons_CheckedChanged(System::Object^ sender, System::EventArgs^ e);

    private: System::Void buttonStartGame_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void buttonExitGame_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void StartForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
    private: System::Void backgroundWorkerMusic_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e);
    };
}
