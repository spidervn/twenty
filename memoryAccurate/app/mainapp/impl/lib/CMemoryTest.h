/*
 * CMemoryTest.h
 *
 *  Created on: Dec 16, 2017
 *      Author: spider
 */

#ifndef APP_MAINAPP_IMPL_LIB_CMEMORYTEST_H_
#define APP_MAINAPP_IMPL_LIB_CMEMORYTEST_H_

#include <mainapp/interface/lib/IMemoryTest.h>

class CMemoryTest: public IMemoryTest {
public:
	CMemoryTest();
	virtual ~CMemoryTest();

	QuizTestModel generateTest(MemoryStick);
	int match_score(const char* szQuestion_, const char* szAnswer);
private:
	int knuth_shuffle(int permutation[], int n);
};

#endif /* APP_MAINAPP_IMPL_LIB_CMEMORYTEST_H_ */
