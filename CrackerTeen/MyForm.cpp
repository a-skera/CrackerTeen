#include "MyForm.h"
#include <conio.h>
#include <windows.h>
#include<thread>

using namespace Project1;
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(/*array<String^>^ args*/)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Project1::MyForm form;  // Replace 'YourNamespace' with your actual namespace
    Application::Run(% form);
   
    return 0;
}
