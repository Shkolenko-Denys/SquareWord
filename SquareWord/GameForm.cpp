#include "GameForm.h"

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
	soundIncorrect = gcnew System::Media::SoundPlayer("..\\Resources\\incorrect.wav");
	sound = true;
	if (size == 5)
	{
		this->button1->Text = L"С";
		this->button2->Text = L"Л";
		this->button3->Text = L"Е";
		this->button4->Text = L"З";
		this->button5->Text = L"А";
		this->button6->Visible = false;
		this->button7->Visible = false;
	}
	else if (size == 6)
	{
		this->button1->Text = L"Г";
		this->button2->Text = L"Л";
		this->button3->Text = L"О";
		this->button4->Text = L"Б";
		this->button5->Text = L"У";
		this->button6->Text = L"С";
		this->button7->Visible = false;
	}
	else if (size == 7)
	{
		this->button1->Text = L"Р";
		this->button2->Text = L"И";
		this->button3->Text = L"С";
		this->button4->Text = L"У";
		this->button5->Text = L"Н";
		this->button6->Text = L"О";
		this->button7->Text = L"К";
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

	if (size == 5) {
		dataGridView->Size = System::Drawing::Size(323, 285);
	}
	else if (size == 6) {
		dataGridView->Size = System::Drawing::Size(373, 335);
	}
	else if (size == 7) {
		dataGridView->Size = System::Drawing::Size(423, 385);
	}
}

void SquareWord::GameForm::SetStartGameGrid(int size)
{
	if (size == 5)
	{
		dataGridView->Rows[0]->Cells[0]->Value = "С";
		dataGridView->Rows[0]->Cells[1]->Value = "Л";
		dataGridView->Rows[0]->Cells[2]->Value = "Е";
		dataGridView->Rows[0]->Cells[3]->Value = "З";
		dataGridView->Rows[0]->Cells[4]->Value = "А";

		dataGridView->Rows[2]->Cells[2]->Value = "Л";
		dataGridView->Rows[2]->Cells[3]->Value = "Е";
		dataGridView->Rows[2]->Cells[4]->Value = "С";
	}
	else if (size == 6)
	{
		dataGridView->Rows[0]->Cells[0]->Value = "Г";
		dataGridView->Rows[0]->Cells[1]->Value = "Л";
		dataGridView->Rows[0]->Cells[2]->Value = "О";
		dataGridView->Rows[0]->Cells[3]->Value = "Б";
		dataGridView->Rows[0]->Cells[4]->Value = "У";
		dataGridView->Rows[0]->Cells[5]->Value = "С";

		dataGridView->Rows[2]->Cells[2]->Value = "Л";
		dataGridView->Rows[2]->Cells[3]->Value = "У";
		dataGridView->Rows[2]->Cells[4]->Value = "Г";

		dataGridView->Rows[4]->Cells[3]->Value = "Г";
		dataGridView->Rows[4]->Cells[4]->Value = "О";
		dataGridView->Rows[4]->Cells[5]->Value = "Л";
	}
	else if (size == 7)
	{
		dataGridView->Rows[0]->Cells[0]->Value = "Р";
		dataGridView->Rows[0]->Cells[1]->Value = "И";
		dataGridView->Rows[0]->Cells[2]->Value = "С";
		dataGridView->Rows[0]->Cells[3]->Value = "У";
		dataGridView->Rows[0]->Cells[4]->Value = "Н";
		dataGridView->Rows[0]->Cells[5]->Value = "О";
		dataGridView->Rows[0]->Cells[6]->Value = "К";

		dataGridView->Rows[2]->Cells[3]->Value = "С";
		dataGridView->Rows[2]->Cells[4]->Value = "У";
		dataGridView->Rows[2]->Cells[5]->Value = "К";

		dataGridView->Rows[4]->Cells[3]->Value = "Н";
		dataGridView->Rows[4]->Cells[4]->Value = "О";
		dataGridView->Rows[4]->Cells[5]->Value = "С";

		dataGridView->Rows[6]->Cells[4]->Value = "Р";
		dataGridView->Rows[6]->Cells[5]->Value = "И";
		dataGridView->Rows[6]->Cells[6]->Value = "С";
	}
}

void SquareWord::GameForm::SetPosition(coord crd, char ch)
{
	map.set_position(crd.x, crd.y, ch);
}

void SquareWord::GameForm::ShowConflict()
{
	for (int i = 0; i < map.get_conflict_size(); i++) {
		dataGridView->Rows[map.get_conflict_row(i)]->Cells[map.get_conflict_col(i)]->Style->BackColor = Color::Red;
	}
}

System::Void SquareWord::GameForm::dataGridView_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
	if (sound) {
		soundClick->Play();
	}
	labelMessage->Visible = false;

	auto senderGrid = (DataGridView^)sender; // transform the obj into a table

	// Remember the indices of the selected cell
	selected_cell.x = e->RowIndex;
	selected_cell.y = e->ColumnIndex;
}

System::Void SquareWord::GameForm::повернутисяДоМенюToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	Close();
}

System::Void SquareWord::GameForm::правилаГриToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (sound) {
		soundClick->Play();
	}
	MessageBox::Show("Правила", "Правила");
}

System::Void SquareWord::GameForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (map.isConst(selected_cell)) {
		if (sound) { soundIncorrect->Play(); }
		labelMessage->Text = "Не можна змінювати стартові букви!";
		labelMessage->Visible = true;
	}
	else {
		if (sound) { soundClick->Play(); }

		// Make a move
		char ch = map.get_value(0, 0);
		SetPosition(selected_cell, ch);
		dataGridView->Rows[selected_cell.x]->Cells[selected_cell.y]->Value = CharToSysString(ch);
		map.check(selected_cell.x, selected_cell.y, ch);
		ShowConflict();
	}
}

System::Void SquareWord::GameForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (map.isConst(selected_cell)) {
		if (sound) { soundIncorrect->Play(); }
		labelMessage->Text = "Не можна змінювати стартові букви!";
		labelMessage->Visible = true;
	}
	else {
		if (sound) { soundClick->Play(); }

		// Make a move
		char ch = map.get_value(0, 1);
		SetPosition(selected_cell, ch);
		dataGridView->Rows[selected_cell.x]->Cells[selected_cell.y]->Value = CharToSysString(ch);
		map.check(selected_cell.x, selected_cell.y, ch);
		ShowConflict();
	}
}

System::Void SquareWord::GameForm::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (map.isConst(selected_cell)) {
		if (sound) { soundIncorrect->Play(); }
		labelMessage->Text = "Не можна змінювати стартові букви!";
		labelMessage->Visible = true;
	}
	else {
		if (sound) { soundClick->Play(); }

		// Make a move
		char ch = map.get_value(0, 2);
		SetPosition(selected_cell, ch);
		dataGridView->Rows[selected_cell.x]->Cells[selected_cell.y]->Value = CharToSysString(ch);
		map.check(selected_cell.x, selected_cell.y, ch);
		ShowConflict();
	}
}

System::Void SquareWord::GameForm::button4_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (map.isConst(selected_cell)) {
		if (sound) { soundIncorrect->Play(); }
		labelMessage->Text = "Не можна змінювати стартові букви!";
		labelMessage->Visible = true;
	}
	else {
		if (sound) { soundClick->Play(); }

		// Make a move
		char ch = map.get_value(0, 3);
		SetPosition(selected_cell, ch);
		dataGridView->Rows[selected_cell.x]->Cells[selected_cell.y]->Value = CharToSysString(ch);
		map.check(selected_cell.x, selected_cell.y, ch);
		ShowConflict();
	}
}

System::Void SquareWord::GameForm::button5_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (map.isConst(selected_cell)) {
		if (sound) { soundIncorrect->Play(); }
		labelMessage->Text = "Не можна змінювати стартові букви!";
		labelMessage->Visible = true;
	}
	else {
		if (sound) { soundClick->Play(); }

		// Make a move
		char ch = map.get_value(0, 4);
		SetPosition(selected_cell, ch);
		dataGridView->Rows[selected_cell.x]->Cells[selected_cell.y]->Value = CharToSysString(ch);
		map.check(selected_cell.x, selected_cell.y, ch);
		ShowConflict();
	}
}

System::Void SquareWord::GameForm::button6_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (map.isConst(selected_cell)) {
		if (sound) { soundIncorrect->Play(); }
		labelMessage->Text = "Не можна змінювати стартові букви!";
		labelMessage->Visible = true;
	}
	else {
		if (sound) { soundClick->Play(); }

		// Make a move
		char ch = map.get_value(0, 5);
		SetPosition(selected_cell, ch);
		dataGridView->Rows[selected_cell.x]->Cells[selected_cell.y]->Value = CharToSysString(ch);
		map.check(selected_cell.x, selected_cell.y, ch);
		ShowConflict();
	}
}

System::Void SquareWord::GameForm::button7_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (map.isConst(selected_cell)) {
		if (sound) { soundIncorrect->Play(); }
		labelMessage->Text = "Не можна змінювати стартові букви!";
		labelMessage->Visible = true;
	}
	else {
		if (sound) { soundClick->Play(); }

		// Make a move
		char ch = map.get_value(0, 6);
		SetPosition(selected_cell, ch);
		dataGridView->Rows[selected_cell.x]->Cells[selected_cell.y]->Value = CharToSysString(ch);
		map.check(selected_cell.x, selected_cell.y, ch);
		ShowConflict();
	}
}