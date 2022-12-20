#include "MainPage.h"

using namespace System;
using namespace System::Windows::Forms;


[STAThreadAttribute]
void __clrcall MainPage(array<String^>^ args)
{

    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    ProjetPoo::MainPage main;
    Application::Run(% main);
}
