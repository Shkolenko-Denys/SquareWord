#include "GameForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	SquareWord::GameForm form;
	Application::Run(% form);
}

GameMap map(5);
bool sound;

System::Void SquareWord::GameForm::GameForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	soundClick = gcnew System::Media::SoundPlayer("..\\Resources\\click.mp3");
	sound = true;
	StartGame();
}

void SquareWord::GameForm::StartGame()
{
	CreateGameGrid(map.get_size());
}

void SquareWord::GameForm::CreateGameGrid(int size)
{
	dataGridView->Rows->Clear();
	dataGridView->Columns->Clear();

	System::Drawing::Font^ font = gcnew System::Drawing::Font("Microsoft Sans Serif", 14);
	dataGridView->DefaultCellStyle->Font = font;
	dataGridView->ColumnHeadersDefaultCellStyle->Font = font;
	dataGridView->RowHeadersDefaultCellStyle->Font = font;

	for (int i = 0; i < size; i++) {
		DataGridViewButtonColumn^ column = gcnew DataGridViewButtonColumn();
		column->HeaderCell->Value = Convert::ToString(i + 1);
		column->Name = "column" + i;
		column->Width = 50;

		dataGridView->Columns->Add(column);
	}

	for (int i = 0; i < size; i++) {
		dataGridView->Rows->Add();
		dataGridView->Rows[i]->HeaderCell->Value = Convert::ToString(i + 1);
		dataGridView->Rows[i]->Height = 50;
	}
}

System::Void SquareWord::GameForm::≥–≥‚ÂÌ¸ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void SquareWord::GameForm::≥≤–≥‚ÂÌ¸ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void SquareWord::GameForm::≥≤≤–≥‚ÂÌ¸ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void SquareWord::GameForm::checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}

System::Void SquareWord::GameForm::dataGridView_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
	return System::Void();
}
