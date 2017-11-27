#include <iostream>
#include "app/CMemAccuUI.h"
#include "app/architecture.h"

using namespace std;

int main() {
	IMemoryAccurateApp app;
	ICursesEngine curses;

	app.registerComponent(curses);
	app.name();		// Start the app
	app.start();
	app.stop();

	return 0;
}
