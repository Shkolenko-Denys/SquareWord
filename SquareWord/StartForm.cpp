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

System::Void SquareWord::StartForm::StartForm_Load(System::Object^ sender, System::EventArgs^ e)
{
    sound = true;
    radioButtonNone->Checked = true;

    // Initializing sounds
    soundClick = gcnew System::Media::SoundPlayer("..\\Resources\\click.wav");
    // backgroundMusic = gcnew System::Media::SoundPlayer("..\\Resources\\melody1.wav");
    
    // while (sound) { backgroundMusic->PlayLooping(); }
}

System::Void SquareWord::StartForm::InstructionToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    soundClick->Play();
    MessageBox::Show("��� ���������� �� �����������", "����������");
}

System::Void SquareWord::StartForm::SoundToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    soundClick->Play();
}

System::Void SquareWord::StartForm::melody1ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    soundClick->Play();
    backgroundMusic = gcnew System::Media::SoundPlayer("..\\Resources\\melody1.wav");
    sound = true;
}

System::Void SquareWord::StartForm::melody2ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    soundClick->Play();
    backgroundMusic = gcnew System::Media::SoundPlayer("..\\Resources\\melody2.wav");
    sound = true;
}

System::Void SquareWord::StartForm::melody3ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    soundClick->Play();
    backgroundMusic = gcnew System::Media::SoundPlayer("..\\Resources\\melody3.wav");
    sound = true;
}

System::Void SquareWord::StartForm::melody4ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    soundClick->Play();
    backgroundMusic = gcnew System::Media::SoundPlayer("..\\Resources\\melody4.wav");
    sound = true;
}

System::Void SquareWord::StartForm::nomelodyToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    soundClick->Play();
    sound = false;
}

System::Void SquareWord::StartForm::numSize_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
    soundClick->Play();
}

System::Void SquareWord::StartForm::radioButtonNone_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
    soundClick->Play();
}

System::Void SquareWord::StartForm::radioButtonShowConfChars_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
    soundClick->Play();
}

System::Void SquareWord::StartForm::radioButtonHideButtons_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
    soundClick->Play();
}

System::Void SquareWord::StartForm::buttonStartGame_Click(System::Object^ sender, System::EventArgs^ e)
{
    soundClick->Play();
    int size = Convert::ToInt32(numSize->Value);

    // Create GameForm 
    GameForm^ form = gcnew GameForm();
    form->size = size;
    form->steps = form->s = form->m = form->h = 0;

    if (radioButtonShowConfChars->Checked) {
        form->mode = GameMode::showConf;
    }
    else if (radioButtonHideButtons->Checked) {
        form->mode = GameMode::hideChars;
    }
    form->ShowDialog();
    // Hide();
}

System::Void SquareWord::StartForm::buttonExitGame_Click(System::Object^ sender, System::EventArgs^ e)
{
    soundClick->Play();
    Application::Exit();
}