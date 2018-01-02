/*
 * CMemoryTest.cpp
 *
 *  Created on: Dec 16, 2017
 *      Author: spider
 */

#include <mainapp/impl/lib/CMemoryTest.h>
#include <algorithm>

CMemoryTest::CMemoryTest() {
	printf("Constructor of CMemoryTest\r\n");

}

CMemoryTest::~CMemoryTest() {
	printf("Destructor of CMemoryTest\r\n");
}

QuizTestModel CMemoryTest::generateTest(MemoryStick s)
{
	/*
	 *	Generate
	 *	1. A permutation of memory stick; then pick atmost 3 elements	 
	 */

	QuizTestModel quiz_;
	
	int n = std::min(3, s.listmemory_.size());
}

int CMemoryTest::knuth_shuffle(int permutation[], int n)
{
	for (int i=0; i<=n-2;i++)
	{
		int uniform = rand() % (n-i); // 0 <= uniform  < i
		int tmp = permutation[i];
		permutation[i] = permutation[i+j];
		permutation[i+j] = tmp;
	}
	return 0;
}