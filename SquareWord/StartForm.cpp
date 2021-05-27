#include "StartForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<System::String^>^ args) {
    // Enabling Windows visual effects before any controls are created
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    SquareWord::StartForm form;
    Application::Run(% form);
}

void SquareWord::StartForm::TurnOnMelody(System::String^ melodyName)
{ // mutes interface sound and turns on background music
    if (soundInterface) { soundClick->Play(); }
    backgroundMusic = gcnew System::Media::SoundPlayer("..\\Resources\\" + melodyName + ".wav");
    soundInterface = false; // turn off key sound
    backgroundWorkerMusic->RunWorkerAsync(1); // turn on background music
}

System::Void SquareWord::StartForm::StartForm_Load(System::Object^ sender, System::EventArgs^ e)
{ // Form loading actions
    soundInterface = false;
    radioButtonNone->Checked = true; // by default the user plays without help

    // Initializing sounds
    soundClick = gcnew System::Media::SoundPlayer("..\\Resources\\click.wav");
    backgroundMusic = gcnew System::Media::SoundPlayer("..\\Resources\\melody1.wav");
    backgroundWorkerMusic->RunWorkerAsync(1); // turn on background music
}

System::Void SquareWord::StartForm::InstructionToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (soundInterface) { soundClick->Play(); }
    MessageBox::Show("*************************************************************************\n"
        "Вітаємо Вас у Грі-Головоломці SquareWord\n"
        "*************************************************************************\n\n"
        "1. Щоб вибрати розмір грального поля, натискайте клавіші вверх-вниз на лічильнику. "
        "Мінімальний розмір — 5, максимальний — 7. Чим більше розмір гральної карти, тим складніше і цікавіше грати :)\n\n"
        "2. Далі Вам запропоновані 3 режима гри:\n"
        "    \"Самостійно\" — Якщо Ви справжній профі або Вам до впороби складнощі, то обирайте цей режим.\n"
        "Грати доведеться самостійно, ЖОДНОЇ підказки або допомоги. Тільки Ви і Гральне поле.\n"
        "Заповніть карту так, щоб комп'ютер Вас привітав. Ми віримо у Вас :)\n\n"
        "    \"Підсвічування конфліктуючих букв\" — У цього режима 2 бонуса:\n"
        "1) конфліктуючі букви підсвічуються червоним\n"
        "2) неправильні букви — пурпуровим\n"
        "Ви завжди знатимете, який хід неправильний, тому зможете швидко його виправити :)\n\n"
        "    \"Відображення тільки правильних букв\" —  Найлегший режим. Ви ніколи не зробите неправильний хід.\n"
        "Але доведеться трішки поламати голову, адже іноді правильних букв може бути декілька :)\n\n"
        "*************************************************************************\n\n"
        "Мерщій натискайте СТАРТ і вперед! Правила ще зможете прочитати і під час гри :)\n\n"
        "    Успіхів !!!",
        "Інструкція");
}

System::Void SquareWord::StartForm::SoundToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (soundInterface) { soundClick->Play(); }
}

System::Void SquareWord::StartForm::melody1ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    TurnOnMelody("melody1");
}

System::Void SquareWord::StartForm::melody2ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    TurnOnMelody("melody2");
}

System::Void SquareWord::StartForm::melody3ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    TurnOnMelody("melody3");
}

System::Void SquareWord::StartForm::melody4ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    TurnOnMelody("melody4");
}

System::Void SquareWord::StartForm::nomelodyToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    soundInterface = true; // turn on key sound
    try { // if the sound cannot be played, then we prohibit it
        soundClick->Play();
    }
    catch (...) { // disable all interface sounds
        soundInterface = false;
    }
}

System::Void SquareWord::StartForm::numSize_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
    if (soundInterface) { soundClick->Play(); }
}

System::Void SquareWord::StartForm::radioButtonNone_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
    if (soundInterface) { soundClick->Play(); }
}

System::Void SquareWord::StartForm::radioButtonShowConfChars_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
    if (soundInterface) { soundClick->Play(); }
}

System::Void SquareWord::StartForm::radioButtonHideButtons_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
    if (soundInterface) { soundClick->Play(); }
}

System::Void SquareWord::StartForm::buttonStartGame_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (soundInterface) { soundClick->Play(); }

    // Create GameForm 
    GameForm^ form = gcnew GameForm();
    form->size = Convert::ToInt32(numSize->Value);;
    form->steps = 0;
    form->soundInterface = soundInterface;

    if (radioButtonShowConfChars->Checked) {
        form->mode = GameMode::showConf;
    }
    else if (radioButtonHideButtons->Checked) {
        form->mode = GameMode::hideChars;
    }
    form->Show(); // open Game Form
    this->Hide(); // hide current form
}

System::Void SquareWord::StartForm::buttonExitGame_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (soundInterface) { soundClick->Play(); }
    if (MessageBox::Show("Ви дійсно хочете вийти з програми?", "Увага!",
        MessageBoxButtons::YesNo, MessageBoxIcon::Question) == Windows::Forms::DialogResult::Yes) {
        Application::ExitThread();
    }
}

System::Void SquareWord::StartForm::StartForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
    if (soundInterface) { soundClick->Play(); }
    if (MessageBox::Show("Ви дійсно хочете вийти з програми?", "Увага!",
        MessageBoxButtons::YesNo, MessageBoxIcon::Question) == Windows::Forms::DialogResult::Yes) {
        Application::ExitThread();
    }
    else {
        e->Cancel = true; // cancel exiting the program
    }
}

System::Void SquareWord::StartForm::backgroundWorkerMusic_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e)
{
    backgroundMusic->PlayLooping(); // loop music on background
}
