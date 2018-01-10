/*
 * CJan2018.cpp
 *
 *  Created on: Jan 10, 2018
 *      Author: spider
 */

#include <problems/CJan2018.h>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include "fundamental/impl/CBinomialCoefficient.h"
CJan2018::CJan2018() {
}

CJan2018::~CJan2018() {
}

void CJan2018::inequality_01()
{
	/*
	 * Check whether this inequality is true?
	 * 	sum(j-0,k) (mk+m-1, j) <= 2^(mk)
	 */

	IBinomialCoefficient* pBino;
	pBino = new CBinomialCoefficient();

	printf("****** Validating inequality sum(j-0,k) (mk+m-1, j) <= 2^(mk) ?\r\n");
	for (int m=10; m<=12;m++)
	{
		for (int k=13;k<=14;k++)
		{
			double dSumL = 0;
			double dSumR = 1;

			for (int j=0;j<=k;j++)
			{
				dSumL += pBino->bino(m*k+m-1, j);
			}

			for (int j=0;j<m*k;j++)
			{
				dSumR *= 2;
			}

			if (dSumL <= dSumR)
			{
				double dSub1 = dSumR - dSumL;
				printf("\t(m=%d,k=%d) TRUE. %f <= %f. Variation = %f\r\n", m, k, dSumL, dSumR, dSub1);
			}
			else
			{
				printf("\t(m=%d,k=%d) [ERROR]. %f > %f.\r\n", m, k, dSumL, dSumR);
			}
		}
	}

	delete pBino;
}
