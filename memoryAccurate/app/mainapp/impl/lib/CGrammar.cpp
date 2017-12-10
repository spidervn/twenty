/*
 * CGrammar.cpp
 *
 *  Created on: Dec 9, 2017
 *      Author: spider
 */

#include <mainapp/impl/lib/CGrammar.h>

CGrammar::CGrammar() {
	// TODO Auto-generated constructor stub

}

CGrammar::~CGrammar() {
	// TODO Auto-generated destructor stub
}

void CGrammar::autoComplete(std::string currentCmd,
								std::string currentWord,
								std::vector<std::string>& vout)
{
	vout.clear();
	if (currentCmd.size() == 0)
	{
		vout.push_back("add");
		vout.push_back("doquiz");
		vout.push_back("about");
	}
	else
	{
		if (currentCmd.find("doquiz"))
		{
			currentWord = "";	// List of code here
		}
	}
}
