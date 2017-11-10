/*
 * IMemoryUnit.h
 *
 *  Created on: Nov 7, 2017
 *      Author: spider
 */

#ifndef IMEMORYUNIT_H_
#define IMEMORYUNIT_H_

#include "IMemoryRegion.h"

class IMemoryUnit {
public:
	IMemoryUnit() {};
	virtual ~IMemoryUnit();

	virtual IMemoryRegion* center() = 0;

	virtual IMemoryRegion* west() = 0;

	virtual IMemoryRegion* east() = 0;

	virtual IMemoryRegion* north() = 0;

	virtual IMemoryRegion* south() = 0;

	/*
	virtual IMemoryRegion center()
	{
		return IMemoryRegion();
	};

	virtual IMemoryRegion west()
	{
		return IMemoryRegion();
	}

	virtual IMemoryRegion east()
	{
		return IMemoryRegion();
	};

	virtual IMemoryRegion north()
	{
		return IMemoryRegion();
	}

	virtual IMemoryRegion south()
	{
		return IMemoryRegion();
	}
	*/
	// Iterator implementation
};

#endif /* IMEMORYUNIT_H_ */
