//---------------------------------------------------------------------
// Name:    David Feldman, Edward VanDerJagt, Alex Bisbach, 
//			Junsu Jeong, Adam Larson
// Team:    C--
// Project: Play a game of Ur
// Purpose: This is the GUI for the game.
//---------------------------------------------------------------------
#include "GameWindow.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main()
{
   Application::EnableVisualStyles();
   Application::SetCompatibleTextRenderingDefault(false);
   Application::Run(gcnew gameUr::GameWindow);
}
