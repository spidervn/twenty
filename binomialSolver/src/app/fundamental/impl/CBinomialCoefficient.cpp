/*
 * CBinomialCoefficient.cpp
 *
 *  Created on: Jan 10, 2018
 *      Author: spider
 */

#include "CBinomialCoefficient.h"

CBinomialCoefficient::CBinomialCoefficient() {
}

CBinomialCoefficient::~CBinomialCoefficient() {
}

double CBinomialCoefficient::bino(int n, int k)
{
	double ret = 0;		// bino(n,k) = 0 if k > n
						// bino(0,0) = 1
	if (k <= n)
	{
		ret = 1;
		for (int i=1; i<=k; i++)
		{
			ret = ret * (n-i+1);
			ret = ret / i;
		}
	}

	return ret;
}
