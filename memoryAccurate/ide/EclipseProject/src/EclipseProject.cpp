#include <iostream>
#include "app/CMemAccuUI.h"
#include "app/architecture.h"
#include "app/mainapp/CAppUI.h"
#include "app/mainapp/ncurses/ICursesApp.h"
#include "app/mainapp/ui/ICursesCmdLine.h"

using namespace std;

int main() {
	ICursesCmdLine* icmd = new ICursesCmdLine();

	icmd->initialize();
	icmd->run();


	delete icmd;
	return 0;
}
