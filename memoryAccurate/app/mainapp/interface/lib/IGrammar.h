/*
 * IGrammar.h
 *
 *  Created on: Dec 9, 2017
 *      Author: spider
 */

#ifndef APP_MAINAPP_INTERFACE_LIB_IGRAMMAR_H_
#define APP_MAINAPP_INTERFACE_LIB_IGRAMMAR_H_

#include <string>
#include <vector>

class IGrammar
{
public:
	virtual void autoComplete(std::string currentCmd, std::string currentWord, std::vector<std::string>& vout) = 0;
};


#endif /* APP_MAINAPP_INTERFACE_LIB_IGRAMMAR_H_ */
