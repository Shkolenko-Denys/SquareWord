#include "GameForm.h"

/*======================= Function for launching the form =======================*/
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	SquareWord::GameForm form;
	Application::Run(% form);
}