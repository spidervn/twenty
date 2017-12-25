/*
 * CGrammar.h
 *
 *  Created on: Dec 9, 2017
 *      Author: spider
 */

#ifndef APP_MAINAPP_IMPL_LIB_CGRAMMAR_H_
#define APP_MAINAPP_IMPL_LIB_CGRAMMAR_H_

#include "mainapp/interface/lib/IGrammar.h"

class CGrammar: public IGrammar {
public:
	CGrammar();
	virtual ~CGrammar();

	void autoComplete(std::string currentCmd, std::string currentWord, std::vector<std::string>& vout);

	int answerMatch(std::string str1, std::string str2);
};

#endif /* APP_MAINAPP_IMPL_LIB_CGRAMMAR_H_ */
