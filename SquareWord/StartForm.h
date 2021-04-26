#pragma once

namespace SquareWord {

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
		StartForm(void);

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~StartForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::CheckBox^ computerHelp;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ ïðîÏðîãðàìóToolStripMenuItem;

	private: System::Windows::Forms::Button^ buttonStartGame;
	private: System::Windows::Forms::Button^ buttonExitGame;
	private: System::Windows::Forms::NumericUpDown^ numSize;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->computerHelp = (gcnew System::Windows::Forms::CheckBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->ïðîÏðîãðàìóToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->numSize = (gcnew System::Windows::Forms::NumericUpDown());
			this->buttonStartGame = (gcnew System::Windows::Forms::Button());
			this->buttonExitGame = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numSize))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(42, 86);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(238, 26);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Âèáåð³òü ðîçì³ð ïîëÿ:";
			// 
			// computerHelp
			// 
			this->computerHelp->AutoSize = true;
			this->computerHelp->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->computerHelp->Location = System::Drawing::Point(47, 137);
			this->computerHelp->Name = L"computerHelp";
			this->computerHelp->Size = System::Drawing::Size(255, 30);
			this->computerHelp->TabIndex = 1;
			this->computerHelp->Text = L"Äîïîìîãà êîìï\'þòåðà";
			this->computerHelp->UseVisualStyleBackColor = true;
			this->computerHelp->CheckedChanged += gcnew System::EventHandler(this, &StartForm::computerHelp_CheckedChanged);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->ïðîÏðîãðàìóToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(447, 33);
			this->menuStrip1->TabIndex = 2;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ïðîÏðîãðàìóToolStripMenuItem
			// 
			this->ïðîÏðîãðàìóToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14));
			this->ïðîÏðîãðàìóToolStripMenuItem->Name = L"ïðîÏðîãðàìóToolStripMenuItem";
			this->ïðîÏðîãðàìóToolStripMenuItem->Size = System::Drawing::Size(148, 29);
			this->ïðîÏðîãðàìóToolStripMenuItem->Text = L"Ïðî ïðîãðàìó";
			this->ïðîÏðîãðàìóToolStripMenuItem->Click += gcnew System::EventHandler(this, &StartForm::ïðîÏðîãðàìóToolStripMenuItem_Click);
			// 
			// numSize
			// 
			this->numSize->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->numSize->Location = System::Drawing::Point(301, 86);
			this->numSize->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 7, 0, 0, 0 });
			this->numSize->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->numSize->Name = L"numSize";
			this->numSize->ReadOnly = true;
			this->numSize->Size = System::Drawing::Size(120, 29);
			this->numSize->TabIndex = 3;
			this->numSize->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->numSize->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->numSize->ValueChanged += gcnew System::EventHandler(this, &StartForm::numSize_ValueChanged);
			// 
			// buttonStartGame
			// 
			this->buttonStartGame->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonStartGame->Location = System::Drawing::Point(261, 213);
			this->buttonStartGame->Name = L"buttonStartGame";
			this->buttonStartGame->Size = System::Drawing::Size(108, 59);
			this->buttonStartGame->TabIndex = 4;
			this->buttonStartGame->Text = L"Ñòàðò";
			this->buttonStartGame->UseVisualStyleBackColor = true;
			this->buttonStartGame->Click += gcnew System::EventHandler(this, &StartForm::buttonStartGame_Click);
			// 
			// buttonExitGame
			// 
			this->buttonExitGame->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->buttonExitGame->Location = System::Drawing::Point(65, 213);
			this->buttonExitGame->Name = L"buttonExitGame";
			this->buttonExitGame->Size = System::Drawing::Size(108, 59);
			this->buttonExitGame->TabIndex = 4;
			this->buttonExitGame->Text = L"Âèéòè";
			this->buttonExitGame->UseVisualStyleBackColor = true;
			this->buttonExitGame->Click += gcnew System::EventHandler(this, &StartForm::buttonExitGame_Click);
			// 
			// StartForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(447, 301);
			this->Controls->Add(this->buttonExitGame);
			this->Controls->Add(this->buttonStartGame);
			this->Controls->Add(this->numSize);
			this->Controls->Add(this->computerHelp);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"StartForm";
			this->Text = L"StartForm";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numSize))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Media::SoundPlayer^ sound;

	private: System::Void ïðîÏðîãðàìóToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void numSize_ValueChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void computerHelp_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonStartGame_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void buttonExitGame_Click(System::Object^ sender, System::EventArgs^ e);
};
}
