/*
 * IMemoryTest.h
 *
 *  Created on: Dec 16, 2017
 *      Author: spider
 */

#ifndef APP_MAINAPP_INTERFACE_LIB_IMEMORYTEST_H_
#define APP_MAINAPP_INTERFACE_LIB_IMEMORYTEST_H_


#include <stdio.h>
#include "mainapp/interface/model/quiz_model.h"

class IMemoryTest
{
public:
	virtual QuizTestModel generateTest(MemoryStick) = 0;
	virtual ~IMemoryTest() {}

	virtual int match_score(const char* szQuestion_, const char* szAnswer) = 0;
};

#endif /* APP_MAINAPP_INTERFACE_LIB_IMEMORYTEST_H_ */
