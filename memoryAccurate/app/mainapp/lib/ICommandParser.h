/*
 * ICommandParser.h
 *
 *  Created on: Nov 29, 2017
 *      Author: spider
 */

#ifndef APP_MAINAPP_LIB_ICOMMANDPARSER_H_
#define APP_MAINAPP_LIB_ICOMMANDPARSER_H_

#include <string>
#include <arch/pyramid.h>

class ICommandParser : public IPyramidPenta {
public:
	ICommandParser();
	virtual ~ICommandParser();

	int parseCmd(std::string cmd) { return 0; }
	std::vector<std::string> autoComplete(std::string currentCmd, std::string currentWord)
	{ return std::vector<std::string>(); }
};

#endif /* APP_MAINAPP_LIB_ICOMMANDPARSER_H_ */
