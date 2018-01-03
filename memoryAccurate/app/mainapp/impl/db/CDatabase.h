/*
 * CDatabase.h
 *
 *  Created on: Jan 3, 2018
 *      Author: ducvd
 */

#ifndef APP_MAINAPP_IMPL_DB_CDATABASE_H_
#define APP_MAINAPP_IMPL_DB_CDATABASE_H_

#include <mainapp/interface/db/IDB.h>

class CDatabase: public IDatabase {
public:
	CDatabase();
	virtual ~CDatabase();

	int getMemStick(std::string code, MemoryStick& out);

	int save_Stick_(MemoryStick quiz);

	int deleteStick(MemoryStick quiz);

	int queryStick_(std::string codeText, std::vector<MemoryStick>& out);
};

#endif /* APP_MAINAPP_IMPL_DB_CDATABASE_H_ */
