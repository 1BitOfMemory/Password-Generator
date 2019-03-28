//	Author: Ryan Beebe
//  Date: 3/26/2019

#include "Form1.h"

using namespace System;
using namespace System::Windows::Forms;

//Entry point to  start the form
[STAThread]
void main(array<String^>^args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	PasswordGeneratorWinAPI::Form1 form;
	Application::Run(%form);
}
