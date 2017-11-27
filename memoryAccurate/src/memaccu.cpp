#include <stdio.h>
#include <stdlib.h> 
#include "memaccu_ui.h"

int main(int argc, char const *argv[])
{
	// printf("Version %d.%d\n", MemoryAccurate_VERSION_MAJOR, MemoryAccurate_VERSION_MINOR);
	MemoryAccuUI ui;
	ui.run();
	return 0;
}
