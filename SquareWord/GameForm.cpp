#include "GameForm.h"
#include "StartForm.h"

// common data
GameMap map;
coord selected_cell;

// flags
bool sound;

// char to System::String^
System::String^ SquareWord::GameForm::CharToSysString(char ch)
{
	char* arr = new char[2]();
	*arr = ch;
	String^ str = gcnew String(arr);
	delete[] arr;
	return str;
}

System::Void SquareWord::GameForm::GameForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	// Initializing sounds
	soundClick = gcnew System::Media::SoundPlayer("..\\Resources\\click.wav");
	sound = true;
	if (size == 5)
	{
		this->button1->Text = L"�";
		this->button2->Text = L"�";
		this->button3->Text = L"�";
		this->button4->Text = L"�";
		this->button5->Text = L"�";
		this->button6->Visible = false;
		this->button7->Visible = false;
	}
	else if (size == 6)
	{
		this->button1->Text = L"�";
		this->button2->Text = L"�";
		this->button3->Text = L"�";
		this->button4->Text = L"�";
		this->button5->Text = L"�";
		this->button6->Text = L"�";
		this->button7->Visible = false;
	}
	else if (size == 7)
	{
		this->button1->Text = L"�";
		this->button2->Text = L"�";
		this->button3->Text = L"�";
		this->button4->Text = L"�";
		this->button5->Text = L"�";
		this->button6->Text = L"�";
		this->button7->Text = L"�";
	}

	StartGame();
}

void SquareWord::GameForm::StartGame()
{
	// Data initialization
	map.SetMap(size);

	CreateGameGrid(map.get_size()); // creating a playing field
	SetStartGameGrid(map.get_size()); // set starting parameters
}

void SquareWord::GameForm::CreateGameGrid(int size)
{
	// clear grid
	dataGridView->Rows->Clear();
	dataGridView->Columns->Clear();

	// set the style
	System::Drawing::Font^ font = gcnew System::Drawing::Font("Microsoft Sans Serif", 14);
	dataGridView->DefaultCellStyle->Font = font;
	dataGridView->ColumnHeadersDefaultCellStyle->Font = font;
	dataGridView->RowHeadersDefaultCellStyle->Font = font;

	// create columns
	for (int i = 0; i < size; i++)
	{
		DataGridViewButtonColumn^ column = gcnew DataGridViewButtonColumn();
		column->HeaderCell->Value = Convert::ToString(i + 1);
		column->Name = "column" + i;
		column->Width = 50;

		dataGridView->Columns->Add(column);
	}

	// create rows
	for (int i = 0; i < size; i++)
	{
		dataGridView->Rows->Add();
		dataGridView->Rows[i]->HeaderCell->Value = Convert::ToString(i + 1);
		dataGridView->Rows[i]->Height = 50;
	}
}

void SquareWord::GameForm::SetStartGameGrid(int size)
{
	if (size == 5)
	{
		dataGridView->Rows[0]->Cells[0]->Value = "�";
		dataGridView->Rows[0]->Cells[1]->Value = "�";
		dataGridView->Rows[0]->Cells[2]->Value = "�";
		dataGridView->Rows[0]->Cells[3]->Value = "�";
		dataGridView->Rows[0]->Cells[4]->Value = "�";

		dataGridView->Rows[2]->Cells[2]->Value = "�";
		dataGridView->Rows[2]->Cells[3]->Value = "�";
		dataGridView->Rows[2]->Cells[4]->Value = "�";
	}
	else if (size == 6)
	{
		dataGridView->Rows[0]->Cells[0]->Value = "�";
		dataGridView->Rows[0]->Cells[1]->Value = "�";
		dataGridView->Rows[0]->Cells[2]->Value = "�";
		dataGridView->Rows[0]->Cells[3]->Value = "�";
		dataGridView->Rows[0]->Cells[4]->Value = "�";
		dataGridView->Rows[0]->Cells[5]->Value = "�";

		dataGridView->Rows[2]->Cells[2]->Value = "�";
		dataGridView->Rows[2]->Cells[3]->Value = "�";
		dataGridView->Rows[2]->Cells[4]->Value = "�";

		dataGridView->Rows[4]->Cells[3]->Value = "�";
		dataGridView->Rows[4]->Cells[4]->Value = "�";
		dataGridView->Rows[4]->Cells[5]->Value = "�";
	}
	else if (size == 7)
	{
		dataGridView->Rows[0]->Cells[0]->Value = "�";
		dataGridView->Rows[0]->Cells[1]->Value = "�";
		dataGridView->Rows[0]->Cells[2]->Value = "�";
		dataGridView->Rows[0]->Cells[3]->Value = "�";
		dataGridView->Rows[0]->Cells[4]->Value = "�";
		dataGridView->Rows[0]->Cells[5]->Value = "�";
		dataGridView->Rows[0]->Cells[6]->Value = "�";

		dataGridView->Rows[2]->Cells[3]->Value = "�";
		dataGridView->Rows[2]->Cells[4]->Value = "�";
		dataGridView->Rows[2]->Cells[5]->Value = "�";

		dataGridView->Rows[4]->Cells[3]->Value = "�";
		dataGridView->Rows[4]->Cells[4]->Value = "�";
		dataGridView->Rows[4]->Cells[5]->Value = "�";

		dataGridView->Rows[6]->Cells[4]->Value = "�";
		dataGridView->Rows[6]->Cells[5]->Value = "�";
		dataGridView->Rows[6]->Cells[6]->Value = "�";
	}
}

void SquareWord::GameForm::SetPosition(coord crd, char ch)
{
	map.set_position(crd.x, crd.y, ch);
}

System::Void SquareWord::GameForm::dataGridView_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
	if (sound) {
		soundClick->Play();
	}

	auto senderGrid = (DataGridView^)sender; // transform the obj into a table

	// Remember the indices of the selected cell
	selected_cell.x = e->RowIndex;
	selected_cell.y = e->ColumnIndex;
}

System::Void SquareWord::GameForm::�����������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	Close();
}

System::Void SquareWord::GameForm::����������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (sound) {
		soundClick->Play();
	}
	MessageBox::Show("�������", "�������");
}

System::Void SquareWord::GameForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (sound) {
		soundClick->Play();
	}

	// Make a move
	char ch = map.get_value(0, 0);
	SetPosition(selected_cell, ch);
	dataGridView->Rows[selected_cell.x]->Cells[selected_cell.y]->Value = CharToSysString(ch);
}

System::Void SquareWord::GameForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (sound) {
		soundClick->Play();
	}

	// Make a move
	char ch = map.get_value(0, 1);
	SetPosition(selected_cell, ch);
	dataGridView->Rows[selected_cell.x]->Cells[selected_cell.y]->Value = CharToSysString(ch);
}

System::Void SquareWord::GameForm::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (sound) {
		soundClick->Play();
	}

	// Make a move
	char ch = map.get_value(0, 2);
	SetPosition(selected_cell, ch);
	dataGridView->Rows[selected_cell.x]->Cells[selected_cell.y]->Value = CharToSysString(ch);
}

System::Void SquareWord::GameForm::button4_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (sound) {
		soundClick->Play();
	}

	// Make a move
	char ch = map.get_value(0, 3);
	SetPosition(selected_cell, ch);
	dataGridView->Rows[selected_cell.x]->Cells[selected_cell.y]->Value = CharToSysString(ch);
}

System::Void SquareWord::GameForm::button5_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (sound) {
		soundClick->Play();
	}

	// Make a move
	char ch = map.get_value(0, 4);
	SetPosition(selected_cell, ch);
	dataGridView->Rows[selected_cell.x]->Cells[selected_cell.y]->Value = CharToSysString(ch);
}

System::Void SquareWord::GameForm::button6_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (sound) {
		soundClick->Play();
	}

	// Make a move
	char ch = map.get_value(0, 5);
	SetPosition(selected_cell, ch);
	dataGridView->Rows[selected_cell.x]->Cells[selected_cell.y]->Value = CharToSysString(ch);
}

System::Void SquareWord::GameForm::button7_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (sound) {
		soundClick->Play();
	}

	// Make a move
	char ch = map.get_value(0, 6);
	SetPosition(selected_cell, ch);
	dataGridView->Rows[selected_cell.x]->Cells[selected_cell.y]->Value = CharToSysString(ch);
}