/*
 * CAutocompletion.h
 *
 *  Created on: Mar 22, 2018
 *      Author: spider
 */

#ifndef APP_MAINAPP_IMPL_LIB_CAUTOCOMPLETION_H_
#define APP_MAINAPP_IMPL_LIB_CAUTOCOMPLETION_H_

#include <mainapp/interface/lib/IAutocompletion.h>

class CAutocompletion: public IAutocompletion {
public:
	CAutocompletion();
	virtual ~CAutocompletion();

	std::vector<std::string> suggest_Contents_(std::string switcherVal);
	void suggest_Contents_();
};

#endif /* APP_MAINAPP_IMPL_LIB_CAUTOCOMPLETION_H_ */
