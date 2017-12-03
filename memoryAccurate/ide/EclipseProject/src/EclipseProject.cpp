#include <iostream>
#include "app/CMemAccuUI.h"
#include "app/architecture.h"
#include "app/mainapp/CAppUI.h"
#include "app/mainapp/ncurses/ICursesApp.h"
#include "app/mainapp/impl/ui/CCmdLineUI.h"

using namespace std;

int main() {
	ICursesCmdLine* icmd = new CCmdLineUI();

	icmd->initialize();
	icmd->run();

	delete icmd;
	return 0;
}
