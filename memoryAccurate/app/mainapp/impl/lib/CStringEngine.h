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

	int needleman_Wunsch_(std::string s1, std::string s2);
	int levenshteinDistance(std::string s1, std::string s2);
	int damerau_Levenshtein(std::string s1, std::string s2);
	int demonstrate_DamerauLevenstein(std::string s1, std::string s2);
	int paragraphMatching(std::string para1, std::string para2);
};

#endif /* APP_MAINAPP_IMPL_LIB_CSTRINGENGINE_H_ */
