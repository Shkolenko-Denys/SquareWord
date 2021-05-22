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

System::Void SquareWord::StartForm::computerHelp_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
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
    form->ShowDialog();
}

System::Void SquareWord::StartForm::buttonExitGame_Click(System::Object^ sender, System::EventArgs^ e)
{
    sound->Play();
    Application::Exit();
}
