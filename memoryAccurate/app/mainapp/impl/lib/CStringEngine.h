/*
 * CStringEngine.h
 *
 *  Created on: Mar 5, 2018
 *      Author: ducvd
 */

#ifndef APP_MAINAPP_IMPL_LIB_CSTRINGENGINE_H_
#define APP_MAINAPP_IMPL_LIB_CSTRINGENGINE_H_

#include <mainapp/interface/lib/IStringEngine.h>
#include <string>

class CStringEngine: public IStringEngine {
public:
	CStringEngine();
	virtual ~CStringEngine();

	int levenshteinDistance(std::string s1, std::string s2);
};

#endif /* APP_MAINAPP_IMPL_LIB_CSTRINGENGINE_H_ */
