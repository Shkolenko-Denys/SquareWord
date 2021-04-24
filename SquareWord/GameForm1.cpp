#include "GameForm1.h"
#include "StartForm.h"

// common data
GameMap map(5);
coord selected_cell;

// flags
bool sound;

System::Void SquareWord::GameForm1::GameForm1_Load(System::Object^ sender, System::EventArgs^ e)
{
	// Initializing sounds
	soundClick = gcnew System::Media::SoundPlayer("..\\Resources\\click.wav");
	sound = true;

	StartGame();
}

void SquareWord::GameForm1::StartGame()
{
	CreateGameGrid(map.get_size()); // creating a playing field
	SetStartGameGrid(map.get_size()); // set starting parameters
}

void SquareWord::GameForm1::CreateGameGrid(int size)
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

void SquareWord::GameForm1::SetStartGameGrid(int size)
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

void SquareWord::GameForm1::SetPosition(coord crd, char ch)
{
	map.set_position(crd.x, crd.y, ch);
}

System::Void SquareWord::GameForm1::�г����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (sound)
	{
		soundClick->Play();
	}
}

System::Void SquareWord::GameForm1::��г����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (sound)
	{
		soundClick->Play();
	}
}

System::Void SquareWord::GameForm1::���г����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (sound)
	{
		soundClick->Play();
	}
}

System::Void SquareWord::GameForm1::dataGridView_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
	if (sound) {
		soundClick->Play();
	}

	auto senderGrid = (DataGridView^)sender; // transform the obj into a table

	// Remember the indices of the selected cell
	selected_cell.x = e->RowIndex;
	selected_cell.y = e->ColumnIndex;
}

System::Void SquareWord::GameForm1::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (sound)
	{
		soundClick->Play();
	}

	// Make a move
	SetPosition(selected_cell, '�');
	dataGridView->Rows[selected_cell.x]->Cells[selected_cell.y]->Value = "�";
}

System::Void SquareWord::GameForm1::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (sound)
	{
		soundClick->Play();
	}

	// Make a move
	SetPosition(selected_cell, '�');
	dataGridView->Rows[selected_cell.x]->Cells[selected_cell.y]->Value = "�";
}

System::Void SquareWord::GameForm1::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (sound)
	{
		soundClick->Play();
	}

	// Make a move
	SetPosition(selected_cell, '�');
	dataGridView->Rows[selected_cell.x]->Cells[selected_cell.y]->Value = "�";
}

System::Void SquareWord::GameForm1::button4_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (sound)
	{
		soundClick->Play();
	}

	// Make a move
	SetPosition(selected_cell, '�');
	dataGridView->Rows[selected_cell.x]->Cells[selected_cell.y]->Value = "�";
}

System::Void SquareWord::GameForm1::button5_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (sound)
	{
		soundClick->Play();
	}

	// Make a move
	SetPosition(selected_cell, '�');
	dataGridView->Rows[selected_cell.x]->Cells[selected_cell.y]->Value = "�";
}
