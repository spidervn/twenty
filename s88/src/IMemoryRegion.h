/*
 * IMemoryRegion.h
 *
 *  Created on: Nov 7, 2017
 *      Author: spider
 */

#ifndef IMEMORYREGION_H_
#define IMEMORYREGION_H_

#include <string>

class IMemoryRegion {
public:
	virtual std::string getName()
	{
		return "";
	};
};

#endif /* IMEMORYREGION_H_ */
