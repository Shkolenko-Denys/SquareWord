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
    soundInterface = false;
    radioButtonNone->Checked = true;

    // Initializing sounds
    soundClick = gcnew System::Media::SoundPlayer("..\\Resources\\click.wav");
    backgroundMusic = gcnew System::Media::SoundPlayer("..\\Resources\\melody1.wav");
    backgroundWorkerMusic->RunWorkerAsync(1);
}

System::Void SquareWord::StartForm::InstructionToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (soundInterface) { if (soundInterface) { soundClick->Play(); } }
    MessageBox::Show("*************************************************************************\n"
        "³���� ��� � ��-����������� SquareWord\n"
        "*************************************************************************\n\n"
        "1. ��� ������� ����� ��������� ����, ���������� ������ �����-���� �� ���������. "
        "̳�������� ����� � 5, ������������ � 7. ��� ����� ����� ������� �����, ��� �������� � ������� ����� :)\n\n"
        "2. ��� ��� ������������ 3 ������ ���:\n"
        "    \"���������\" � ���� �� �������� ����� ��� ��� �� ������� ���������, �� �������� ��� �����.\n"
        "����� ���������� ���������, ����ί ������� ��� ��������. ҳ���� �� � ������� ����.\n"
        "�������� ����� ���, ��� ����'���� ��� �������. �� ����� � ��� :)\n\n"
        "    \"ϳ���������� ������������ ����\" � � ����� ������ 2 ������:\n"
        "1) ����������� ����� ����������� ��������\n"
        "2) ���������� ����� � ����������\n"
        "�� ������ ���������, ���� ��� ������������, ���� ������� ������ ���� ��������� :)\n\n"
        "    \"³���������� ����� ���������� ����\" �  ��������� �����. �� ����� �� ������� ������������ ���.\n"
        "��� ���������� ����� �������� ������, ���� ���� ���������� ���� ���� ���� ������� :)\n\n"
        "*************************************************************************\n\n"
        "������ ���������� ����� � ������! ������� �� ������� ��������� � �� ��� ��� :)\n\n"
        "    ������ !!!",
        "����������");
}

System::Void SquareWord::StartForm::SoundToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (soundInterface) { soundClick->Play(); }
}

System::Void SquareWord::StartForm::melody1ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (soundInterface) { soundClick->Play(); }
    backgroundMusic = gcnew System::Media::SoundPlayer("..\\Resources\\melody1.wav");
    soundInterface = false;
    backgroundWorkerMusic->RunWorkerAsync(1);
}

System::Void SquareWord::StartForm::melody2ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (soundInterface) { soundClick->Play(); }
    backgroundMusic = gcnew System::Media::SoundPlayer("..\\Resources\\melody2.wav");
    soundInterface = false;
    backgroundWorkerMusic->RunWorkerAsync(1);
}

System::Void SquareWord::StartForm::melody3ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (soundInterface) { soundClick->Play(); }
    backgroundMusic = gcnew System::Media::SoundPlayer("..\\Resources\\melody3.wav");
    soundInterface = false;
    backgroundWorkerMusic->RunWorkerAsync(1);
}

System::Void SquareWord::StartForm::melody4ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (soundInterface) { soundClick->Play(); }
    backgroundMusic = gcnew System::Media::SoundPlayer("..\\Resources\\melody4.wav");
    soundInterface = false;
    backgroundWorkerMusic->RunWorkerAsync(1);
}

System::Void SquareWord::StartForm::nomelodyToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    soundInterface = true;
    try {
        soundClick->Play();
    }
    catch (...) {
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
    if (soundInterface) { if (soundInterface) { soundClick->Play(); } }

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
    form->Show();
    this->Hide();
}

System::Void SquareWord::StartForm::buttonExitGame_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (soundInterface) { soundClick->Play(); }
    if (MessageBox::Show("�� ����� ������ ����� � ��������?", "�����!", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == Windows::Forms::DialogResult::Yes) {
        Application::ExitThread();
    }
}

System::Void SquareWord::StartForm::StartForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
    if (soundInterface) { soundClick->Play(); }
    if (MessageBox::Show("�� ����� ������ ����� � ��������?", "�����!", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == Windows::Forms::DialogResult::Yes) {
        Application::ExitThread();
    }
    else {
        e->Cancel = true;
    }
}

System::Void SquareWord::StartForm::backgroundWorkerMusic_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e)
{
    backgroundMusic->PlayLooping();
}
