#include "GameForm.h"

// char to System::String^
System::String^ SquareWord::GameForm::CharToSysString(char ch)
{
	char* arr = new char[2]();
	*arr = ch;
	String^ str = gcnew String(arr);
	delete[] arr;
	return str;
}

void SquareWord::GameForm::CreateGameGrid()
{
	// clear grid
	dataGridView->Rows->Clear();
	dataGridView->Columns->Clear();

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
		dataGridView->Size = System::Drawing::Size(252, 252);
	}
	else if (size == 6) {
		dataGridView->Size = System::Drawing::Size(302, 302);
	}
	else if (size == 7) {
		dataGridView->Size = System::Drawing::Size(352, 352);
	}
}

void SquareWord::GameForm::SetStartGameGrid()
{
	char ch;
	System::Drawing::Font^ font = gcnew System::Drawing::Font("Microsoft Sans Serif", 20, FontStyle::Bold);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (ch = map->get_value(i, j)) {
				dataGridView->Rows[i]->Cells[j]->Value = CharToSysString(ch);
				dataGridView->Rows[i]->Cells[j]->Style->Font = font;
			}
		}
	}
}

void SquareWord::GameForm::InitializeButtons()
{
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
}

void SquareWord::GameForm::ShowAllButtons()
{
	if (size == 5) {
		this->button1->Visible = true;
		this->button2->Visible = true;
		this->button3->Visible = true;
		this->button4->Visible = true;
		this->button5->Visible = true;
	}
	else if (size == 6) {
		this->button1->Visible = true;
		this->button2->Visible = true;
		this->button3->Visible = true;
		this->button4->Visible = true;
		this->button5->Visible = true;
		this->button6->Visible = true;
	}
	else if (size == 7) {
		this->button1->Visible = true;
		this->button2->Visible = true;
		this->button3->Visible = true;
		this->button4->Visible = true;
		this->button5->Visible = true;
		this->button6->Visible = true;
		this->button7->Visible = true;
	}
}

void SquareWord::GameForm::HideAllButtons()
{
	this->button1->Visible = false;
	this->button2->Visible = false;
	this->button3->Visible = false;
	this->button4->Visible = false;
	this->button5->Visible = false;
	this->button6->Visible = false;
	this->button7->Visible = false;
}

void SquareWord::GameForm::HideButton(char ch)
{
	if (size == 5) {
		switch (ch) {
		case '�':
			this->button1->Visible = false;
			break;
		case '�':
			this->button2->Visible = false;
			break;
		case '�':
			this->button3->Visible = false;
			break;
		case '�':
			this->button4->Visible = false;
			break;
		case '�':
			this->button5->Visible = false;
			break;
		}
	}
	else if (size == 6) {
		switch (ch) {
		case '�':
			this->button1->Visible = false;
			break;
		case '�':
			this->button2->Visible = false;
			break;
		case '�':
			this->button3->Visible = false;
			break;
		case '�':
			this->button4->Visible = false;
			break;
		case '�':
			this->button5->Visible = false;
			break;
		case '�':
			this->button6->Visible = false;
			break;
		}
	}
	else if (size == 7) {
		switch (ch) {
		case '�':
			this->button1->Visible = false;
			break;
		case '�':
			this->button2->Visible = false;
			break;
		case '�':
			this->button3->Visible = false;
			break;
		case '�':
			this->button4->Visible = false;
			break;
		case '�':
			this->button5->Visible = false;
			break;
		case '�':
			this->button6->Visible = false;
			break;
		case '�':
			this->button7->Visible = false;
			break;
		}
	}
}

void SquareWord::GameForm::ButtonSetChar(int i, int j)
{
	if (!timer->Enabled) { timer->Enabled = true; }

	if (map->isConst(*selected_cell)) {
		if (soundInterface) { soundIncorrect->Play(); }
		labelMessage->Text = "�� ����� �������� ������� �����!";
		labelMessage->Visible = true;
	}
	else {
		if (soundInterface) { soundClick->Play(); }
		// Make a move
		char ch = map->get_value(i, j);
		map->set_position(*selected_cell, ch);
		dataGridView->Rows[selected_cell->x]->Cells[selected_cell->y]->Value = CharToSysString(ch);
		if (mode == GameMode::showConf) {
			FindConflict(ch);
		}
		steps++;
		labelStepsValue->Text = Convert::ToString(steps);
		CheckMap();
	}
}

void SquareWord::GameForm::FindConflict(const char &ch)
{
	// clearing previus conflicts
	for (int i = 0; i < map->get_conflict_size(); i++) {
		dataGridView->Rows[map->get_conflict_row(i)]->Cells[map->get_conflict_col(i)]->Style->BackColor = Color::White;
	}
	labelMessage->Visible = false;

	map->check(*selected_cell, ch);

	for (int i = 0; i < map->get_conflict_size(); i++) {
		dataGridView->Rows[map->get_conflict_row(i)]->Cells[map->get_conflict_col(i)]->Style->BackColor = Color::Red;
	}
}

void SquareWord::GameForm::CheckMap()
{
	if (map->get_conflict_size()) {
		if (mode == GameMode::showConf) {
			if (soundInterface) { soundIncorrect->Play(); }
			labelMessage->Text = "����� ������ �� ������!";
			labelMessage->Visible = true;
			dataGridView->Rows[selected_cell->x]->Cells[selected_cell->y]->Style->BackColor = Color::Magenta;
		}
		map->incorrect(*selected_cell);
	}
	else {
		dataGridView->Rows[selected_cell->x]->Cells[selected_cell->y]->Style->BackColor = Color::White;
		map->correct(*selected_cell);
	}

	if (map->get_correct_size() == size * size) {
		soundWin->Play();
		MessageBox::Show("³���� !!!\n" +
			"�� ������� �� ����������� ��" +
			steps + " ����� � ��������� ��� ���: " +
			stopwatch->get_time(),
			"��������");
		StartForm^ form = gcnew StartForm();
		form->Show();
		this->Hide();
	}
}

System::Void SquareWord::GameForm::GameForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	map = new GameMap(size);
	stopwatch = new Stopwatch;
	selected_cell = new coord;
	// Initializing sounds
	soundClick = gcnew System::Media::SoundPlayer("..\\Resources\\click.wav");
	soundIncorrect = gcnew System::Media::SoundPlayer("..\\Resources\\incorrect.wav");
	soundWin = gcnew System::Media::SoundPlayer("..\\Resources\\win.wav");
	InitializeButtons();

	// Data initialization
	SquareWord::GameForm::map->SetMap(size);

	CreateGameGrid(); // creating a playing field
	SetStartGameGrid(); // set starting parameters
}

System::Void SquareWord::GameForm::dataGridView_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
	if (soundInterface) { soundClick->Play(); }

	ShowAllButtons();

	// clearing previus conflicts
	for (int i = 0; i < map->get_conflict_size(); i++) {
		dataGridView->Rows[map->get_conflict_row(i)]->Cells[map->get_conflict_col(i)]->Style->BackColor = Color::White;
	}
	labelMessage->Visible = false;

	auto senderGrid = (DataGridView^)sender; // transform the obj into a table

	// Remember the indices of the selected cell
	selected_cell->x = e->RowIndex;
	selected_cell->y = e->ColumnIndex;

	if (mode == GameMode::hideChars) {
		char ch;
		map->check(*selected_cell);
		if (map->isConst(*selected_cell)) {
			HideAllButtons();
		}
		else {
			for (int i = 0; i < map->get_conf_size(); i++) {
				ch = map->get_conf_char(i);
				HideButton(ch);
			}
		}
	}
}

System::Void SquareWord::GameForm::goBackToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (soundInterface) { soundClick->Play(); }
	if (MessageBox::Show("�� ����� ������ ����������� �� ����? ������� ��� ���� ��������!", "�����!", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == Windows::Forms::DialogResult::Yes) {
		StartForm^ form = gcnew StartForm();
		form->Show();
		this->Hide();
	}
}

System::Void SquareWord::GameForm::rulesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (soundInterface) { soundClick->Play(); }
	MessageBox::Show("��������� � �� �������, ��������� �� �������, � ���������� � ����� ������ ����� �������. "
		"��� ����� �������� ������� �������.\n"
		"    �������� ������ � ����, ��� ��������� �� ������� ������� ������� � ����� ������� ���, ��� � ������� "
		"���������������, ������������� ���� � � Ĳ�������� �������� �� ���� ���� ��������� ����, "
		"����� ����� ����� ����������� � �� ������ ����.\n"
		"    ���� �� ������ ��������� ��������� ��������, �������, "
		"�� ���� ������� ����������� �������� ������, ��� ���� �������� ������� �����. "
		"�������� ����� �� �������� ������� ������ ���� ������ � ����������� �������, ��� ��� ���� ����������� "
		"�������������� ������������ 򳺿 �� ���� �����.\n\n"
		"*************************************************************************\n\n"
		"��� �� ������ �� ��������, �� � ����� ������ ������� ������ ����� ����� �����?\n\n"
		"*************************************************************************\n\n"
		"    �������� ����� � ��� �� ��������� ������, ������� �����, ������������ ������� ����, �� "
		"����� ������� � �� �����. ���� ������� ����� ���� ���� �����, ������� � ���. "
		"�� � ����� � ���������� �� ���� �����, � ��� �� ��� ��, ���� ����� �� ��������� ������.\n"
		"    ����� ������ �������� ����� � ����� \"�������\" ����, ����������� �� ������������ ������ ���� � ���������.",
		"�������");
}

System::Void SquareWord::GameForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	ButtonSetChar(0, 0);
}

System::Void SquareWord::GameForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	ButtonSetChar(0, 1);
}

System::Void SquareWord::GameForm::button3_Click(System::Object^ sender, System::EventArgs^ e)
{
	ButtonSetChar(0, 2);
}

System::Void SquareWord::GameForm::button4_Click(System::Object^ sender, System::EventArgs^ e)
{
	ButtonSetChar(0, 3);
}

System::Void SquareWord::GameForm::button5_Click(System::Object^ sender, System::EventArgs^ e)
{
	ButtonSetChar(0, 4);
}

System::Void SquareWord::GameForm::button6_Click(System::Object^ sender, System::EventArgs^ e)
{
	ButtonSetChar(0, 5);
}

System::Void SquareWord::GameForm::button7_Click(System::Object^ sender, System::EventArgs^ e)
{
	ButtonSetChar(0, 6);
}

System::Void SquareWord::GameForm::buttonFinishGame_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (soundInterface) { soundClick->Play(); }
	if (MessageBox::Show("�� ����� ������ ��������� ��� � ����� � ��������?", "�����!", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == Windows::Forms::DialogResult::Yes) {
		Application::ExitThread();
	}
}

System::Void SquareWord::GameForm::timer_Tick(System::Object^ sender, System::EventArgs^ e)
{
	stopwatch->clock();
	labelTimerValue->Text = stopwatch->get_time();
}

System::Void SquareWord::GameForm::GameForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
	if (soundInterface) { soundClick->Play(); }
	if (MessageBox::Show("�� ����� ������ ��������� ��� � ����� � ��������?", "�����!", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == Windows::Forms::DialogResult::Yes) {
		Application::ExitThread();
	}
	else {
		e->Cancel = true;
	}
}
