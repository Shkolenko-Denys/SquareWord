#include "GameForm.h"

System::String^ SquareWord::GameForm::CharToSysString(char ch)
{ // convert one char to System::String^
    char* arr = new char[2](); // char + \0
    *arr = ch;
    String^ str = gcnew String(arr);
    delete[] arr;
    return str;
}

void SquareWord::GameForm::CreateGameGrid()
{ // creating a game grid on the screen
    // clear grid
    dataGridView->Rows->Clear();
    dataGridView->Columns->Clear();

    // create columns
    for (int i = 0; i < size; i++) {
        DataGridViewButtonColumn^ column = gcnew DataGridViewButtonColumn();
        column->HeaderCell->Value = Convert::ToString(i + 1);
        column->Name = "column" + i;
        column->Width = 50;

        dataGridView->Columns->Add(column);
    }

    // create rows
    for (int i = 0; i < size; i++) {
        dataGridView->Rows->Add();
        dataGridView->Rows[i]->HeaderCell->Value = Convert::ToString(i + 1);
        dataGridView->Rows[i]->Height = 50;
    }

    // set grid size
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
{ // adds starting letters to the grid
    char ch;
    System::Drawing::Font^ font = gcnew System::Drawing::Font("Microsoft Sans Serif", 20, FontStyle::Bold);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (ch = map->get_value(i, j)) { // if this cell contains a letter
                dataGridView->Rows[i]->Cells[j]->Value = CharToSysString(ch); // to make the letter appear on the screen
                dataGridView->Rows[i]->Cells[j]->Style->Font = font; // assign a style to each cell
            }
        }
    }
}

void SquareWord::GameForm::InitializeButtons()
{ // assign text to buttons
    if (size == 5) {
        this->button1->Text = L"С";
        this->button2->Text = L"Л";
        this->button3->Text = L"Е";
        this->button4->Text = L"З";
        this->button5->Text = L"А";
    }
    else if (size == 6) {
        this->button1->Text = L"Г";
        this->button2->Text = L"Л";
        this->button3->Text = L"О";
        this->button4->Text = L"Б";
        this->button5->Text = L"У";
        this->button6->Text = L"С";
    }
    else if (size == 7) {
        this->button1->Text = L"Р";
        this->button2->Text = L"И";
        this->button3->Text = L"С";
        this->button4->Text = L"У";
        this->button5->Text = L"Н";
        this->button6->Text = L"О";
        this->button7->Text = L"К";
    }
}

void SquareWord::GameForm::ShowAllButtons()
{
    this->button1->Visible = true;
    this->button2->Visible = true;
    this->button3->Visible = true;
    this->button4->Visible = true;
    this->button5->Visible = true;
    if (size == 6) {
        this->button6->Visible = true;
    }
    if (size == 7) {
        this->button6->Visible = true;
        this->button7->Visible = true;
    }

    this->button8->Visible = true;
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
    this->button8->Visible = false;
}

void SquareWord::GameForm::HideButton(char ch)
{ // hide button by char
    if (size == 5) {
        switch (ch) {
        case 'С':
            this->button1->Visible = false;
            break;
        case 'Л':
            this->button2->Visible = false;
            break;
        case 'Е':
            this->button3->Visible = false;
            break;
        case 'З':
            this->button4->Visible = false;
            break;
        case 'А':
            this->button5->Visible = false;
            break;
        }
    }
    else if (size == 6) {
        switch (ch) {
        case 'Г':
            this->button1->Visible = false;
            break;
        case 'Л':
            this->button2->Visible = false;
            break;
        case 'О':
            this->button3->Visible = false;
            break;
        case 'Б':
            this->button4->Visible = false;
            break;
        case 'У':
            this->button5->Visible = false;
            break;
        case 'С':
            this->button6->Visible = false;
            break;
        }
    }
    else if (size == 7) {
        switch (ch) {
        case 'Р':
            this->button1->Visible = false;
            break;
        case 'И':
            this->button2->Visible = false;
            break;
        case 'С':
            this->button3->Visible = false;
            break;
        case 'У':
            this->button4->Visible = false;
            break;
        case 'Н':
            this->button5->Visible = false;
            break;
        case 'О':
            this->button6->Visible = false;
            break;
        case 'К':
            this->button7->Visible = false;
            break;
        }
    }
}

void SquareWord::GameForm::ButtonSetChar(int i, int j)
{ // puts the char in the cell
    if (!timer->Enabled) { timer->Enabled = true; }

    if (map->isConst(*selected_cell)) { // if the value cannot be changed
        if (soundInterface) { soundIncorrect->Play(); }
        labelMessage->Text = "Не можна змінювати стартові букви!";
        labelMessage->Visible = true; // make message visible
    }
    else {
        if (soundInterface) { soundClick->Play(); }

        // Make a move
        char ch = map->get_value(i, j);
        map->set_position(*selected_cell, ch); // add letter to matrix
        // add letter to grid on screen
        dataGridView->Rows[selected_cell->x]->Cells[selected_cell->y]->Value = CharToSysString(ch);
        if (mode == GameMode::showConf) {
            FindConflict(ch); // finding and displaying conflicts
        }
        else {
            map->check(*selected_cell, ch); // find conflict chars and add to the vector
        }
        steps++;
        labelStepsValue->Text = Convert::ToString(steps);
        CheckMap(); // check the current state of the map
    }
}

void SquareWord::GameForm::FindConflict(const char& ch)
{ // finding and displaying conflicts
    // clearing previus conflicts
    for (int i = 0; i < map->get_conflict_ch_coord_size(); i++) {
        dataGridView->Rows[map->get_conflict_row(i)]->Cells[map->get_conflict_col(i)]->Style->BackColor = Color::White;
    }
    labelMessage->Visible = false; // make message invisible

    map->check(*selected_cell, ch); // find conflict chars and add to the vector

    // mark conflict chars on the grid
    for (int i = 0; i < map->get_conflict_ch_coord_size(); i++) {
        dataGridView->Rows[map->get_conflict_row(i)]->Cells[map->get_conflict_col(i)]->Style->BackColor = Color::Red;
    }
}

void SquareWord::GameForm::CheckMap()
{ // check the current state of the map
    if (map->get_conflict_ch_coord_size()) {
        if (mode == GameMode::showConf) { // if display mode is on
            if (soundInterface) { soundIncorrect->Play(); }
            labelMessage->Text = "Буква підпадає під обстріл!";
            labelMessage->Visible = true; // make message visible
            // mark the incorrect letter
            dataGridView->Rows[selected_cell->x]->Cells[selected_cell->y]->Style->BackColor = Color::Magenta;
        }
        map->incorrect(*selected_cell); // erase cell-coord of the correct set
    }
    else {
        // unmark the incorrect letter
        dataGridView->Rows[selected_cell->x]->Cells[selected_cell->y]->Style->BackColor = Color::White;
        map->correct(*selected_cell); // insert cell coord to the correct set
    }

    if (map->get_correct_ch_coord_size() == size * size) {
        // if the field is completely filled
        if (soundInterface) { soundWin->Play(); }
        timer->Enabled = false; // stop timer
        MessageBox::Show("Вітаємо !!!\n" +
            "Ви вирішили цю головоломку за:\n" +
            "К-сть кроків: " + steps +
            "\nЗагальний час гри: " + stopwatch->get_time(),
            "Перемога");
        StartForm^ form = gcnew StartForm();
        form->Show(); // open start form
        this->Hide(); // hide current form
    }
}

System::Void SquareWord::GameForm::GameForm_Load(System::Object^ sender, System::EventArgs^ e)
{ // Form loading actions
    // create new objects
    map = new GameMap(size);
    stopwatch = new Stopwatch;
    selected_cell = new coord;

    // Initializing sounds
    soundClick = gcnew System::Media::SoundPlayer("..\\Resources\\click.wav");
    soundIncorrect = gcnew System::Media::SoundPlayer("..\\Resources\\incorrect.wav");
    soundWin = gcnew System::Media::SoundPlayer("..\\Resources\\win.wav");

    InitializeButtons(); // assign text to buttons
    SquareWord::GameForm::map->SetMap(); // put letters in the matrix
    CreateGameGrid(); // creating a playing field
    SetStartGameGrid(); // set starting parameters
}

System::Void SquareWord::GameForm::dataGridView_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
    if (soundInterface) { soundClick->Play(); }

    ShowAllButtons(); // to hide new incorrect letters later

    // clearing previus conflicts
    for (int i = 0; i < map->get_conflict_ch_coord_size(); i++) {
        dataGridView->Rows[map->get_conflict_row(i)]->Cells[map->get_conflict_col(i)]->Style->BackColor = Color::White;
    }
    labelMessage->Visible = false; // make message invisible

    auto senderGrid = (DataGridView^)sender; // transform the obj into a table

    // Remember the indices of the selected cell
    selected_cell->x = e->RowIndex;
    selected_cell->y = e->ColumnIndex;

    if (mode == GameMode::hideChars) {
        char ch;
        map->check(*selected_cell);
        if (map->isConst(*selected_cell)) {
            // if it is a starting letter, then hide all buttons
            HideAllButtons();
        }
        else {
            for (int i = 0; i < map->get_conflict_chars_size(); i++) {
                ch = map->get_conflict_char(i);
                HideButton(ch); // hide a specific button
            }
        }
    }
}

System::Void SquareWord::GameForm::goBackToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (soundInterface) { soundClick->Play(); }
    if (MessageBox::Show("Ви дійсно хочете повернутись до меню? Прогрес гри буде втрачено!", "Увага!",
        MessageBoxButtons::YesNo, MessageBoxIcon::Question) == Windows::Forms::DialogResult::Yes) {
        StartForm^ form = gcnew StartForm();
        form->Show(); // open start form
        this->Hide(); // hide current form
    }
}

System::Void SquareWord::GameForm::rulesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (soundInterface) { soundClick->Play(); }
    MessageBox::Show("Скверворд – це квадрат, розділений на клітинки, з записаними в ньому певним чином словами. "
        "При цьому більшість клітинок порожні.\n"
        "    Завдання полягає в тому, щоб заповнити ці порожні клітинки буквами з числа наявних так, щоб в кожному "
        "ГОРИЗОНТАЛЬНОМУ, ВЕРТИКАЛЬНОМУ РЯДУ І В ДІАГОНАЛЯХ КВАДРАТА не було ДВОХ однакових букв, "
        "тобто кожна буква зустрічалася б ПО ОДНОМУ РАЗУ.\n"
        "    Якщо ви будете вирішувати скверворд навмання, підбором, "
        "то ваше терпіння вичерпається набагато раніше, ніж буде записана остання буква. "
        "Основний підхід до вирішення завдань такого типу полягає в знаходженні клітинки, для якої буде встановлена "
        "безсумнівність розташування тієї чи іншої літери.\n\n"
        "*************************************************************************\n\n"
        "Але як прийти до висновку, що в даній клітині повинна стояти якась певна буква?\n\n"
        "*************************************************************************\n\n"
        "    Вибираємо клітку і для неї проводимо чіткий, логічний аналіз, встановлюючи кількість букв, які "
        "можна вписати в цю клітку. Якщо можлива буква одна дуже добре, вписуємо і все. "
        "Дві і більше – переходимо до іншої клітки, і так до тих пір, поки пошук не увінчається успіхом.\n"
        "    Краще всього починати аналіз в місцях \"кущіння\" букв, потрапляючи під «перехресний обстріл» рядів і діагоналей.",
        "Правила");
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

System::Void SquareWord::GameForm::button8_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (!timer->Enabled) { timer->Enabled = true; }

    if (map->isConst(*selected_cell)) { // if the value cannot be changed
        if (soundInterface) { soundIncorrect->Play(); }
        labelMessage->Text = "Не можна змінювати стартові букви!";
        labelMessage->Visible = true; // make message visible
    }
    else {
        if (soundInterface) { soundClick->Play(); }

        // Make a move
        map->set_position(*selected_cell, '\0'); // add letter to matrix
        // add letter to grid on screen
        dataGridView->Rows[selected_cell->x]->Cells[selected_cell->y]->Value = CharToSysString('\0');
        dataGridView->Rows[selected_cell->x]->Cells[selected_cell->y]->Style->BackColor = Color::White;
        map->incorrect(*selected_cell); // erase cell-coord of the correct set
        steps++;
        labelStepsValue->Text = Convert::ToString(steps);
    }
}

System::Void SquareWord::GameForm::buttonFinishGame_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (soundInterface) { soundClick->Play(); }
    if (MessageBox::Show("Ви дійсно хочете завершити гру і вийти з програми?", "Увага!",
        MessageBoxButtons::YesNo, MessageBoxIcon::Question) == Windows::Forms::DialogResult::Yes) {
        Application::ExitThread();
    }
}

System::Void SquareWord::GameForm::timer_Tick(System::Object^ sender, System::EventArgs^ e)
{
    stopwatch->clock(); // + 1 sec
    labelTimerValue->Text = stopwatch->get_time(); // update label on screen
}

System::Void SquareWord::GameForm::GameForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
    // if the user clicks on the cross or the form closes for other reasons
    if (soundInterface) { soundClick->Play(); }
    if (MessageBox::Show("Ви дійсно хочете завершити гру і вийти з програми?", "Увага!",
        MessageBoxButtons::YesNo, MessageBoxIcon::Question) == Windows::Forms::DialogResult::Yes) {
        Application::ExitThread();
    }
    else {
        e->Cancel = true; // cancel form closing
    }
}
