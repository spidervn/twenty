#include <iostream>
#include "app/CMemAccuUI.h"
#include "app/architecture.h"
#include "app/mainapp/CAppUI.h"

using namespace std;

int main() {
	ICursesPyr* pcur = new CAppUI();

	pcur->initialize();
	pcur->start();
	pcur->shutdown();

	return 0;
}
