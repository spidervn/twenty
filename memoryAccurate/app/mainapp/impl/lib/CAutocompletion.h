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

	int suggest_Contents_(std::string sCurrentCmd, int n_CursorPos, std::vector<std::string>& vOutput);
	
	int isMatch(CommandLineDefinition cmd_Def, std::string sCmdLine);

	int is_PotentialMatch(CommandLineDefinition pattern, std::vector<std::string> v_Token);

	int value_Dictionary_(std::string name, std::vector<std::string>&);
private:
	int splitParams(std::string cmdLine, std::vector<std::string>& vOutput);

	int layout_Diff(CommandLineLayout lay_Out, std::vector<std::string> v_Token);	// Different 

	int scan_One_Element_(CommandLineDefinition cmd_Def, CommandLineElement e, std::vector<std::string> v_Token, int start, int end, int& len);

	
};

#endif /* APP_MAINAPP_IMPL_LIB_CAUTOCOMPLETION_H_ */
