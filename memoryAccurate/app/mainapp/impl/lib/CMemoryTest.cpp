/*
 * CMemoryTest.cpp
 *
 *  Created on: Dec 16, 2017
 *      Author: spider
 */

#include <mainapp/impl/lib/CMemoryTest.h>
#include <algorithm>
#include <stdlib.h>

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
	int n_max = 3;
	int mem_size = s.listmemory_.size();
	int n = std::min(n_max, mem_size);

	int arr[100];

	for (int i=0;i<mem_size;i++)
	{
		arr[i] = i;
	}

	knuth_shuffle(&arr[0], mem_size);
	for (int i=0; i<n; i++)
	{
		quiz_.listquiz.push_back( s.listmemory_[arr[i]] );
	}

	return quiz_;
}

int CMemoryTest::knuth_shuffle(int permutation[], int n)
{
	for (int i=0; i<=n-2;i++)
	{
		int uniform = rand() % (n-i); // 0 <= uniform  < i
		int tmp = permutation[i];
		permutation[i] = permutation[i+uniform];
		permutation[i+uniform] = tmp;
	}
	return 0;
}
