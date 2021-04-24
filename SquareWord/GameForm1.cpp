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
		dataGridView->Rows[0]->Cells[0]->Value = "Ñ";
		dataGridView->Rows[0]->Cells[1]->Value = "Ë";
		dataGridView->Rows[0]->Cells[2]->Value = "Å";
		dataGridView->Rows[0]->Cells[3]->Value = "Ç";
		dataGridView->Rows[0]->Cells[4]->Value = "À";

		dataGridView->Rows[2]->Cells[2]->Value = "Ë";
		dataGridView->Rows[2]->Cells[3]->Value = "Å";
		dataGridView->Rows[2]->Cells[4]->Value = "Ñ";
	}
	else if (size == 6)
	{
		dataGridView->Rows[0]->Cells[0]->Value = "Ã";
		dataGridView->Rows[0]->Cells[1]->Value = "Ë";
		dataGridView->Rows[0]->Cells[2]->Value = "Î";
		dataGridView->Rows[0]->Cells[3]->Value = "Á";
		dataGridView->Rows[0]->Cells[4]->Value = "Ó";
		dataGridView->Rows[0]->Cells[5]->Value = "Ñ";

		dataGridView->Rows[2]->Cells[2]->Value = "Ë";
		dataGridView->Rows[2]->Cells[3]->Value = "Ó";
		dataGridView->Rows[2]->Cells[4]->Value = "Ã";

		dataGridView->Rows[4]->Cells[3]->Value = "Ã";
		dataGridView->Rows[4]->Cells[4]->Value = "Î";
		dataGridView->Rows[4]->Cells[5]->Value = "Ë";
	}
	else if (size == 7)
	{
		dataGridView->Rows[0]->Cells[0]->Value = "Ð";
		dataGridView->Rows[0]->Cells[1]->Value = "È";
		dataGridView->Rows[0]->Cells[2]->Value = "Ñ";
		dataGridView->Rows[0]->Cells[3]->Value = "Ó";
		dataGridView->Rows[0]->Cells[4]->Value = "Í";
		dataGridView->Rows[0]->Cells[5]->Value = "Î";
		dataGridView->Rows[0]->Cells[6]->Value = "Ê";

		dataGridView->Rows[2]->Cells[3]->Value = "Ñ";
		dataGridView->Rows[2]->Cells[4]->Value = "Ó";
		dataGridView->Rows[2]->Cells[5]->Value = "Ê";

		dataGridView->Rows[4]->Cells[3]->Value = "Í";
		dataGridView->Rows[4]->Cells[4]->Value = "Î";
		dataGridView->Rows[4]->Cells[5]->Value = "Ñ";

		dataGridView->Rows[6]->Cells[4]->Value = "Ð";
		dataGridView->Rows[6]->Cells[5]->Value = "È";
		dataGridView->Rows[6]->Cells[6]->Value = "Ñ";
	}
}

void SquareWord::GameForm1::SetPosition(coord crd, char ch)
{
	map.set_position(crd.x, crd.y, ch);
}

System::Void SquareWord::GameForm1::³Ð³âåíüToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (sound)
	{
		soundClick->Play();
	}
}

System::Void SquareWord::GameForm1::³²Ð³âåíüToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (sound)
	{
		soundClick->Play();
	}
}

System::Void SquareWord::GameForm1::³²²Ð³âåíüToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
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
	SetPosition(selected_cell, 'Ñ');
	dataGridView->Rows[selected_cell.x]->Cells[selected_cell.y]->Value = "Ñ";
}

System::Void SquareWord::GameForm1::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (sound)
	{
		soundClick->Play();
	}

	// Make a move
	SetPosition(selected_cell, 'Ë');
	dataGridView->Rows[selected_cell.x]->Cells[selected_cell.y]->Value = "Ë";
}

System::Void SquareWord::GameForm1::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (sound)
	{
		soundClick->Play();
	}

	// Make a move
	SetPosition(selected_cell, 'Å');
	dataGridView->Rows[selected_cell.x]->Cells[selected_cell.y]->Value = "Å";
}

System::Void SquareWord::GameForm1::button4_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (sound)
	{
		soundClick->Play();
	}

	// Make a move
	SetPosition(selected_cell, 'Ç');
	dataGridView->Rows[selected_cell.x]->Cells[selected_cell.y]->Value = "Ç";
}

System::Void SquareWord::GameForm1::button5_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (sound)
	{
		soundClick->Play();
	}

	// Make a move
	SetPosition(selected_cell, 'À');
	dataGridView->Rows[selected_cell.x]->Cells[selected_cell.y]->Value = "À";
}
