/*
 * IStringEngine.h
 *
 *  Created on: Mar 5, 2018
 *      Author: ducvd
 */

#ifndef APP_MAINAPP_LIB_ISTRINGENGINE_H_
#define APP_MAINAPP_LIB_ISTRINGENGINE_H_

#include <string>

class IStringEngine
{
public:
	virtual ~IStringEngine() {}
	
	virtual int levenshteinDistance(std::string s1, std::string s2) = 0;
};



#endif /* APP_MAINAPP_LIB_ISTRINGENGINE_H_ */
