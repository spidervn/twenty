#include <iostream>
#include "app/CMemAccuUI.h"
#include "app/architecture.h"
#include "app/mainapp/CAppUI.h"
#include "app/mainapp/ncurses/ICursesApp.h"
#include "app/mainapp/impl/ui/CCmdLineUI.h"
#include "app/example/CPyramidExample.h"
#include "mainapp/impl/ui/CWinQuiz.h"

#include "mainapp/impl/lib/CMemoryTest.h"
#include "mainapp/impl/lib/CAutocompletion.h"

using namespace std;

int main()
{
	/*ICursesCmdLine* icmd = new CCmdLineUI();

	icmd->initialize();
	icmd->run();

	delete icmd;*/

	/*
	ICursesApp* pApp_;
	ICursesWinQuiz* iwin = new CWinQuiz();

	iwin->doModal();
	delete iwin;
	*/


	IAutocompletion* pAuto = new CAutocompletion();

	pAuto->isMatch(CommandLineDefinition(), "aaa bbb 'tgsss'");
	return 0;
}
