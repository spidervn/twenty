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
	virtual ~IAutoComplete() {}

	virtual int autoComplete(std::string currentCmd, std::string currentWord, std::vector<std::string>& vOutput) = 0;
};

#endif /* APP_MAINAPP_LIB_IAUTOCOMPLETE_H_ */
