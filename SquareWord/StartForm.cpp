#include "StartForm.h"
#include "GameForm1.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main(array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    SquareWord::StartForm form;
    Application::Run(% form);
}

System::Void SquareWord::StartForm::ïðîÏðîãðàìóToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    return System::Void();
}

System::Void SquareWord::StartForm::numSize_ValueChanged(System::Object^ sender, System::EventArgs^ e)
{
    return System::Void();
}

System::Void SquareWord::StartForm::computerHelp_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
    return System::Void();
}

System::Void SquareWord::StartForm::buttonStartGame_Click(System::Object^ sender, System::EventArgs^ e)
{
    return System::Void();
}

System::Void SquareWord::StartForm::buttonExitGame_Click(System::Object^ sender, System::EventArgs^ e)
{
    return System::Void();
}
