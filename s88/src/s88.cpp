//============================================================================
// Name        : s88.cpp
// Author      : ducvd
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

#include "IMemoryUnit.h"
#include "IMemoryRegion.h"

using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl;
	printf("---- Pulzze (Accuracy)");

	/*
	 * State definition
	 *	=> Remember item
	 *		=> 5_breakdown = Parse item into 05 pieces (W, E,N, S, C)
	 */

	//	Accuracy remember unit
	//		5_breakdown

	vector<int> v1;

	v1.push_back(1);
	v1.push_back(2);

	IMemoryRegion* pMr;
	IMemoryUnit* pWorldClass;

	//
	//	Stick them together

	return 0;
}
