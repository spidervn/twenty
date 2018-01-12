#include <iostream>
#include "app/CMemAccuUI.h"
#include "app/architecture.h"
#include "app/mainapp/CAppUI.h"
#include "app/mainapp/ncurses/ICursesApp.h"
#include "app/mainapp/impl/ui/CCmdLineUI.h"
#include "app/example/CPyramidExample.h"
#include "mainapp/impl/ui/CWinQuiz.h"

#include "mainapp/impl/lib/CMemoryTest.h"

using namespace std;

int main()
{

	/*ICursesCmdLine* icmd = new CCmdLineUI();

	icmd->initialize();
	icmd->run();

	delete icmd;*/

	//ICursesApp* pApp_;
	//ICursesWinQuiz* iwin = new CWinQuiz();

	//iwin->doModal();
	//delete iwin;

	int a[][2] = {
			{1, 2},
			{3, 4},
			{5, 6},
			{7, 8},
			{9, 10}
	};

	int n = sizeof(a)/sizeof(a[0]);
	printf("Size of a = %d\r\n", n);

	return 0;
}
