/*
 * CGrammar.cpp
 *
 *  Created on: Dec 9, 2017
 *      Author: spider
 */

#include <mainapp/impl/lib/CGrammar.h>
#include <boost/algorithm/string.hpp>
#include <algorithm>

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


int CGrammar::answerMatch(std::string str1, std::string str2)
{
	int n1, n2;
	int m[100][100];	// TODO: declare dynamic allocation

	n1 = str1.size();
	n2 = str2.size();

	for (int i = 0; i < n1; ++i)
	{
		for (int j = 0; j < n2; ++j)
		{
			if (i==0 || j==0)
			{
				m[i][j] = max(i,j);
			}
			else 
			{
				int v1, v2, v3;
				int vdiff = (str1[i] == str2[j]) ? 0 : 1;

				v1 = m[i-1][j] + 1 ;
				v2 = m[i][j-1] + 1;
				v3 = m[i-1][j-1] + vdiff;

				m[i][j] = min(v1,min(v2,v3));
			}
		}
	}

	if (n1 == 0)
	{
		return n1;
	}
	else if (n2 == 0)
	{
		return n2;
	}
	else
	{
		return m[n1-1][n2-1];
	}	
}

