/*
 * IAutoComplete.h
 *
 *  Created on: Nov 29, 2017
 *      Author: ducvd
 */

#ifndef APP_MAINAPP_LIB_IAUTOCOMPLETE_H_
#define APP_MAINAPP_LIB_IAUTOCOMPLETE_H_

#include <string>
#include <vector>

class IAutoComplete {
public:
	IAutoComplete();
	virtual ~IAutoComplete();

	std::vector<std::string> autoComplete(std::string currentCmd, std::string currentWord)
	{ return std::vector<std::string>(); }
};

#endif /* APP_MAINAPP_LIB_IAUTOCOMPLETE_H_ */
