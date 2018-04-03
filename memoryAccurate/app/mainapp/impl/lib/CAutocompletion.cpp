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

int CAutocompletion::is_PotentialMatch(CommandLineDefinition pattern, std::vector<std::string> v_Token)
{
	/*
		CmdElementValueType = [
			const,
			switchers[name/alias/valueDictionary],
			options[a/b/c/d/:custom],
			value[valueDictionary]
		]

		CmdLayout = [
			{name, type},
			{name, type}*,	// Pattern
			{name, type},	// 
			{name, type},
		]
	 */

	/*
	// What is the definition of a command ?
	// CommandLine definition string:
	// {cmd_name:const} [{name:type},{name:type},{name:type}]+  {name:type}*
	// 
	// Element
	//
		Element01 = {
			name: 
			type: const/switchers/options/value
			
			const_value: 1,
			switcher: {
				switcher_name,
				switcher_alias,
				switcherValueDict: [value1,value2,value3, <dictionaryController>],
			},

			options: {
				[value1, value2, value3 ]
			},

			value: <valueController>
		}
	*/

	// const char* szType = "const/switchers/options/value";
	// Parse Element

	for (int i=0;i<pattern.vLayout.size();i++)
	{
		// Find every matching
		pattern.vLayout[i].v_Order[0].vOption[0].c_str();

		// 
		// layoutScore(layout, vToken)					: the higher score is, the more match they are 
		// potential_Layout_Score_(layout, vToken)
		// 
	}

	return 0;
}

int CAutocompletion::layout_Diff(CommandLineLayout lay_Out, std::vector<std::string> v_Token)
{
	// Dummy method
	for (int i=0;i<lay_Out.v_Order.size();++i)
	{
		// Compare 
	}

	// 
	// Dummy method 
	// 
	/*
		D1. Scan each element from left to right.
		D2. Check 
				element.values.match(Token)				
		D3. 
		For every Elements 
			Check if Match()
	 */

	/*
		ScanOneElement = sce: (element, v_token[s,e]) -> (result, l1)
							s: start position for scanning.
							e: end position for scanning.

							result = 0: Matched	
									 1: Unmached
							l : length of token for match the element (in case result==Matched)

		s = 0
		e = v_Token.size()
		for (element in layout)
		{
			result = sce(element, v_Token, s, e, len)

			if (result == Matched)
			{
				s += len
			}
		}

		What is the output of this algorithm ?
			Multiple SCE:
				(layout, v_token) -> ( {i, j, k} | i: layout1; j: start position; k length})
		The result is the matching with highest score. 		
     */

	int recordScore = 0;
	CommandLineLayout lo;
	
	// Valid data
	if (lay_Out.v_Order.size() == lay_Out.vMask.size())
	{
		// Position for SCE function
		for (size_t i = 0; i < lo.v_Order.size(); i++)
		{	
			if (lo.vMask[i] == CMDLINE_LAYOUT_MASK_ALONE)
			{
				
			}
			else if (lo.vMask[i] == CMDLINE_LAYOUT_MASK_ONE_TO_MULTIPLE)
			{
				
			}
			else if (lo.vMask[i] == CMDLINE_LAYOUT_MASK_ZERO_TO_MULTIPLE)
			{
				
			}
		}

		
	}
	

	return 0;
}
/*
 * This function produces all suggestion about name of value dictionary
 * 	For example: 
 * 		file_path:	
 * 				Return the files in current path.
 */
int CAutocompletion::value_Dictionary_(std::string name, std::vector<std::string> &v_Out)
{
	v_Out.clear();
	if (name == "quiz_quizcode")
	{
		// Load every code here
	}
	else if (name == "file_path")
	{
		// return the available file name here
	}

	return 0;
}

int CAutocompletion::scan_One_Element_(CommandLineDefinition cmd_Def, CommandLineElement e, std::vector<std::string> v_Token, int start, int end, int& len)
{
	int n_Res = 1;	// Un-Matched
	switch (e.type)
	{
		case CMDLINE_ELEMENT_TYPE_CONST:
			
			if (v_Token[start] == e.value) 
			{
				n_Res = 0; 	// Matched
				len = 1;	// Match 01 string
			}				
			break;
		case CMDLINE_ELEMENT_TYPE_OPTION:
			bool b_Found = false;
			for (size_t i = 0; i < e.vOption.size(); i++)
			{
				if (e.vOption[i] == v_Token[i])
				{
					b_Found = true;
					break;
				}
			}

			if (b_Found)
			{
				n_Res = 0;
				len = 1;
			}
			break;
		case CMDLINE_ELEMENT_TYPE_SWITCHER:
			e._vSwitchers;
			e._vSwitchers[0].c_str();

			// Find commandLine definition here
			for (size_t i = 0; i < e._vSwitchers.size(); i++)
			{
				bool b_Found = false;
				CommandSwitcher sw;
				for (size_t j = 0; j < cmd_Def.v_Switcher_.size(); j++)
				{
					if (e._vSwitchers[i] == cmd_Def.v_Switcher_[j].code) 
					{
						b_Found = true;
						sw = cmd_Def.v_Switcher_[j];
						break;
					}
				}

				if (b_Found)
				{
				}
			}

			// Which switcher found 


			break;
		case CMDLINE_ELEMENT_TYPE_VALUE:
		default:
			break;
	}

	return 0;
}