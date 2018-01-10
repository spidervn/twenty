/*
 * CBinomialCoefficient.h
 *
 *  Created on: Jan 10, 2018
 *      Author: spider
 */

#ifndef APP_FUNDAMENTAL_IMPL_CBINOMIALCOEFFICIENT_H_
#define APP_FUNDAMENTAL_IMPL_CBINOMIALCOEFFICIENT_H_

#include "fundamental/interface/IBinominalCoeffients.h"

class CBinomialCoefficient: public IBinomialCoefficient {
public:
	CBinomialCoefficient();
	virtual ~CBinomialCoefficient();

	double bino(int n, int k);
};

#endif /* APP_FUNDAMENTAL_IMPL_CBINOMIALCOEFFICIENT_H_ */
