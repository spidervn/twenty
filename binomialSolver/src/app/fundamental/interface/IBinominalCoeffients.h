/*
 * IBinominalCoeffients.h
 *
 *  Created on: Jan 10, 2018
 *      Author: spider
 */

#ifndef APP_FUNDAMENTAL_INTERFACE_IBINOMINALCOEFFIENTS_H_
#define APP_FUNDAMENTAL_INTERFACE_IBINOMINALCOEFFIENTS_H_

class IBinomialCoefficient
{
public:
	virtual ~IBinomialCoefficient() {}

	virtual double bino(int n, int k) = 0;
};



#endif /* APP_FUNDAMENTAL_INTERFACE_IBINOMINALCOEFFIENTS_H_ */
