/*
 * ioutbox.h
 *
 *  Created on: Nov 7, 2017
 *      Author: ducvd
 */

#ifndef IOUTBOX_H_
#define IOUTBOX_H_

#include <string>

class IOutboxItem;

class IOutbox
{
public:
	virtual int addOutboxItem(IOutboxItem* pItem);
};

class IOutboxItem
{
public:
	virtual std::string getDescription();
};


#endif /* IOUTBOX_H_ */
