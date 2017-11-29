/*
 * abstract.h
 *
 *  Created on: Nov 27, 2017
 *      Author: ducvd
 */

#ifndef APP_ARCH_ABSTRACT_H_
#define APP_ARCH_ABSTRACT_H_

#include "pyramid.h"

class IEventDispatching
{
public:
	void registerEvent(int EVENT, IPyramid* pDestination, int EVENT_DESTINATION)
	{
	}

	int sendEvent(int EVENT, IPyramid* destination) { return 0; }
	int onEvent(int EVENT, IPyramid* sender) { return 0; }
};


#endif /* APP_ARCH_ABSTRACT_H_ */
