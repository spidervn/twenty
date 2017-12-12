/*
 * CGrammar.cpp
 *
 *  Created on: Dec 9, 2017
 *      Author: spider
 */

#include <mainapp/impl/lib/CGrammar.h>
#include <boost/algorithm/string.hpp>

using namespace std;

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
	/*
	std::string arrRules[][] =
	{
			{ "quiz", "do", "*"},
			{ "quiz", "add", ""},
			{ "about", "", ""},
			{ "quit", "", "" }
	};

	vout.clear();
	string cmdTrim = boost::trim(currentCmd);

	if (cmdTrim.size() == 0)
	{
		vout.push_back("quiz");
		vout.push_back("about");
		vout.push_back("quit");
	}
	else
	{
		// Split string
		// Parsing first
		if (cmdTrim.find("doquiz"))
		{
			currentWord = "";	// List of code here

		}
	}
	*/
}
