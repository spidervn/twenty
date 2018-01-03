/*
 * IDB.h
 *
 *  Created on: Dec 16, 2017
 *      Author: spider
 */

#ifndef APP_MAINAPP_INTERFACE_DB_IDB_H_
#define APP_MAINAPP_INTERFACE_DB_IDB_H_

#include "mainapp/interface/model/quiz_model.h"
#include "mainapp/interface/model/cmdline_model.h"

#include <string>
#include <vector>

class IDatabase
{
public:
	virtual int getMemStick(std::string code, MemoryStick& out) = 0;

	virtual int save_Stick_(MemoryStick quiz) = 0;

	virtual int deleteStick(MemoryStick quiz) = 0;

	virtual int queryStick_(std::string codeText, std::vector<MemoryStick>& out) = 0;
};


#endif /* APP_MAINAPP_INTERFACE_DB_IDB_H_ */
