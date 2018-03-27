/*
 * CAutocompletion.cpp
 *
 *  Created on: Mar 22, 2018
 *      Author: spider
 */

#include <mainapp/impl/lib/CAutocompletion.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

CAutocompletion::CAutocompletion() {
	// TODO Auto-generated constructor stub

}

CAutocompletion::~CAutocompletion() {
	// TODO Auto-generated destructor stub
}

vector<string> CAutocompletion::suggest_Contents_(string switcherVal)
{
	// From an existing command definition.
	return std::vector<string>();
}

void CAutocompletion::suggest_Contents_()
{
}

int CAutocompletion::suggest_Contents_(std::string sCurrentCmd, int n_CursorPos, std::vector<std::string>& vOutput)
{
	CommandLineDefinition cmd_Def;

	/*
	 * 	If sCurrentCmd is potentialCorrentGrammar
	 *		=> 
	 *		=> Detect that what is at the currentPosition 
	 *			=> suggest for this position?
	 * 	Else
	 *		=> No suggest found.
	 */

	// Declare commandLine's definition here
	// cmd_Def.cmdName = "test";
	// cmd_Def.v_Switcher_.push_back("");

	return 0;
}

int CAutocompletion::isMatch(CommandLineDefinition cmd_Def, std::string sCmdLine)
{
	int n_Ret = 0;

	/*
		Split sCmdLine into multiple parts (quoted string detected)
			cmd "tesst" abc 'xyz'
			=> [cmd, tesst, abc, xyz]

		Use a state machine for :
			i) ACCEPT --(ch)-->
			ii) ACCEPT --(space)--> FINISH_A_ACCEPT
			iii) FINISH_A_ACCEPT --(space)--> FINISH_A_ACCEPT
			iv) FINISH_AN_ACCEPT --(ch) --> ACCEPT
			iv) FINISH_AN_ACCEPT --(quote) -->
	 */

	int STT_WAIT = 10;				// Wait
	int STT_ACCEPT = 0;				// Accepting characters
	int STT_FINISH_ACCEPT = 1;		// Finish accepting
	int STT_START_A_QUOTE = 2;
	int STT_END_A_QUOTE = 3;

	int STT_INVALID_MUST_SEPERATE_WITH_SPACE = 4;
	int STT_INVALID_MUST_END_QUOTE = 5;
	int STT_INVALID_MUST_SEPARATE_STRING_AND_QUOTE = 6;

	// State
	string currentToken;
	vector<string> currentState;
	bool isValid = false;
	char cCurrentQuote;

	int state = STT_WAIT;

	for (unsigned int i=0;i<=sCmdLine.size();i++)
	{
		char ch = sCmdLine[i];

		// Next state
		/*
		// Quoted string
		if (i==sCmdLine.size())	// The last character
		{
			if (state == STT_ACCEPT)
			{
				state = STT_FINISH_ACCEPT;
				if (!currentToken.empty()) 
				{
					currentState.push_back(currentToken);
				}
				currentToken = "";
			}
			else if (state == STT_FINISH_ACCEPT)
			{
			}
			else if (state == STT_START_A_QUOTE)
			{
				state = STT_INVALID_MUST_END_QUOTE;
			}
			else if (state == STT_END_A_QUOTE)
			{
				// Do nothing
			}
			else 
			{
				// Do nothing
			}
		}
		else if (ch == '\'' || ch == '"')
		{
			if (state == STT_WAIT)
			{
				state = STT_START_A_QUOTE;
				currentToken = "";
				cCurrentQuote = ch;
			}
			else if (state == STT_ACCEPT)
			{
				state = STT_INVALID_MUST_SEPARATE_STRING_AND_QUOTE;
			}
			else if (state == STT_FINISH_ACCEPT)
			{
				state = STT_INVALID_MUST_SEPERATE_WITH_SPACE;
			}
			else if (state == STT_START_A_QUOTE)
			{
				if (ch == cCurrentQuote)
				{
					cCurrentQuote = ch;
					state = STT_END_A_QUOTE;
				}
				else
				{
					currentToken += ch;
					// state remains unchanged
				}
			}
			else if (state == STT_END_A_QUOTE)
			{
				state = STT_INVALID_MUST_SEPERATE_WITH_SPACE;
			}
			else
			{
				// Nothing to do here
			}
		}
		// Space
		else if (ch == ' ' || ch == '\t')
		{
			if (state == STT_ACCEPT)
			{
				state = STT_FINISH_ACCEPT;
				if (!currentToken.empty()) {
					currentState.push_back(currentToken);
					currentToken = "";
				}
			}
			else if (state == STT_FINISH_ACCEPT)
			{
				state = STT_FINISH_ACCEPT;
			}
			else if (state == STT_START_A_QUOTE)
			{
				currentToken += ch;
			}
			else if (state == STT_END_A_QUOTE)
			{
				// Do nothing
			}
			else
			{
				// Nothing
			}
		}
		// Normal character
		else
		{
			if (state == STT_ACCEPT)
			{
				currentToken += ch;
			}
			else if (state == STT_FINISH_ACCEPT)
			{
				state = STT_ACCEPT;
				currentToken = ch;
			}
			else if (state == STT_START_A_QUOTE)
			{
				currentToken += ch;
			}
			else if (state == STT_END_A_QUOTE)
			{
				state = STT_ACCEPT;
				currentToken = ch;
			}
			else
			{
				// Do nothing
			}
		}
		*/
		
		if (state == STT_WAIT)
		{
			// Quote
			if (ch == '\"' || ch == '\'')
			{
				state = STT_START_A_QUOTE;
				currentToken = "";
				cCurrentQuote = ch;
			}
			// Space
			else if (ch == ' ' || ch == '\t')
			{
			}
			// Normal character
			else 
			{
				state = STT_ACCEPT;
				currentToken = ch;
			}
		}
		else if (state == STT_ACCEPT)
		{
			// Space
			if (ch == ' ' || ch == '\t')
			{
				if (!currentToken.empty())
				{
					currentState.push_back(currentToken);
					currentToken = "";
					state = STT_WAIT;
				}
			}
			// Normal character
			else 
			{				
				currentToken += ch;
			}
		}
		else if (state == STT_START_A_QUOTE)
		{
			// Quote
			if (ch == '\"' || ch == '\'')
			{
				if (ch == cCurrentQuote)
				{
					if (!currentToken.empty())
					{
						currentState.push_back(currentToken);
						currentToken = "";
						state = STT_END_A_QUOTE;
					}
				}
				else
				{
					currentToken += ch;
				}
			}
			// Normal character
			else 
			{
				currentToken += ch;	
			}
		}
		else if (state == STT_END_A_QUOTE)
		{
			// Space
			if (ch == ' ' || ch == '\t')
			{
				// Do nothing
				state = STT_WAIT;
			}
			else 
			{
				state = STT_INVALID_MUST_SEPARATE_STRING_AND_QUOTE;				
			}
		}
	}

	// The last character
	{
		if (state == STT_ACCEPT)
		{
			// Yield the token
			if (!currentToken.empty())
			{
				currentState.push_back(currentToken);
				currentToken = "";
			}
		}
		else if (state == STT_START_A_QUOTE)
		{
			state = STT_INVALID_MUST_END_QUOTE;
		}
		else 
		{
			// Do nothing
		}
	}

	printf("Parsing command=%s\r\n", sCmdLine.c_str());
	printf("\tResult=");
	printf("\tFinal state=%d\r\n", state);

	for (unsigned int i=0;i<currentState.size();i++)
	{
		printf("\t\t%s\r\n", currentState[i].c_str());
	}

	return n_Ret;
}

int CAutocompletion::splitParams(std::string cmdLine, std::vector<std::string>& vOutput)
{
	printf("Run the test\r\n");
	return 0;
}
