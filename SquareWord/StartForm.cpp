#include "StartForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main(array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    SquareWord::StartForm form;
    Application::Run(% form);
}

SquareWord::StartForm::StartForm(void)
{
    InitializeComponent();
    radioButtonNone->Checked = true;

    // Initializing sounds
    sound = gcnew System::Media::SoundPlayer("..\\Resources\\click.wav");
}

System::Void SquareWord::StartForm::ïðîÏðîãðàìóToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    sound->Play();
    MessageBox::Show("Ãðà \"SquareWord\".", "²íôîðìàö³ÿ ïðî ïðîãðàìó");
}

System::Void SquareWord::StartForm::numSize_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
    sound->Play();
}

System::Void SquareWord::StartForm::buttonStartGame_Click(System::Object^ sender, System::EventArgs^ e)
{
    sound->Play();
    int size;
    size = Convert::ToInt32(numSize->Value);

    // Create GameForm 
    GameForm^ form = gcnew GameForm();
    form->size = size;
    if (radioButtonShow->Checked) {
        form->mode = GameMode::show;
    }
    else if (radioButtonHide->Checked) {
        form->mode = GameMode::hide;
    }
    form->ShowDialog();
}

System::Void SquareWord::StartForm::buttonExitGame_Click(System::Object^ sender, System::EventArgs^ e)
{
    sound->Play();
    Application::Exit();
}

System::Void SquareWord::StartForm::radioButtonHelp_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
    sound->Play();
}

System::Void SquareWord::StartForm::radioButtonHide_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
    sound->Play();
}
