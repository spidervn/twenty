/*
 * CTestString.cpp
 *
 *  Created on: Mar 5, 2018
 *      Author: ducvd
 */

#include <mainapp/impl/test/CTestString.h>
#include <string>
#include <mainapp/impl/lib/CStringEngine.h>
#include <stdlib.h>
#include <stdio.h>

CTestString::CTestString() {
	// TODO Auto-generated constructor stub
}

CTestString::~CTestString() {
	// TODO Auto-generated destructor stub
}

int CTestString::runTest()
{
	IStringEngine* p_Eng = new CStringEngine();

	std::string str1 = "Euro";
	std::string str2 = "European";

	std::string str3 = "Vietnam";
	std::string str4 = "Saigon";

	int diff1 = p_Eng->levenshteinDistance(str1, str2);
	int diff2 = p_Eng->levenshteinDistance(str3, str4);

	printf("Diff(%s,%s)=%d\r\n", str1.c_str(), str2.c_str());
	printf("Diff(%s,%s)=%d\r\n", str3.c_str(), str4.c_str());

	delete p_Eng;
	return 0;
}