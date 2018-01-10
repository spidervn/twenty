//============================================================================
// Name        : BinomialCoefficientSolver.cpp
// Author      : ducvd
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <time.h>
#include "problems/CJan2018.h"
using namespace std;

int main() {
	srand(time(NULL));

	CJan2018 prob1;

	prob1.inequality_01();

	return 0;
}
