/*
 * CStringEngine.cpp
 *
 *  Created on: Mar 5, 2018
 *      Author: ducvd
 */

#include <mainapp/impl/lib/CStringEngine.h>
#include <algorithm>

using namespace std;

CStringEngine::CStringEngine() {
}

CStringEngine::~CStringEngine() {
}

int CStringEngine::levenshteinDistance(std::string str1, std::string str2)
{
	int m[100][100];	// TODO: declare dynamic allocation

	int n1 = str1.size();
	int n2 = str2.size();

	if (n1>100 || n2>100)
	{
		throw "Invalid string size, String could not have more than 100 characters.";
	}

	if (n1 == 0)
	{
		return n2;
	}
	else if (n2 == 0)
	{
		return n1;
	}
	else
	{
		for (int i = 0; i <= n1; ++i)
		{
			m[i][0] = i;
		}

		for (int j = 0; j <= n2; ++j)
		{
			m[0][j] = j;
		}

		for (int i = 1; i < n1; ++i)
		{
			for (int j = 1; j < n2; ++j)
			{
				{
					int v1, v2, v3;
					int vdiff = (str1[i] == str2[j]) ? 0 : 1;

					v1 = i > 0 ? m[i-1][j] + 1 : 1;
					v2 = j > 0 ? m[i][j-1] + 1 : 1;
					v3 = (i>0 && j>0) ? m[i-1][j-1] + vdiff : vdiff;

					m[i][j] = min(v1,min(v2,v3));
				}
			}
		}

		return m[n1-1][n2-1];
	}	
		
	return 0;
}

int CStringEngine::paragraphMatching(std::string para1, std::string para2)
{
	int n1 = para1.size();
	int n2 = para2.size();
	long label[100][100];	// Region 

	// 
	// Which method do u use ?
	// Dummy method
	// divide a paragraph into multiple regions 
	//		Then compare region to each other.	
	// 		
		
	int NUM_REGION = 10;


	for (int i = 0; i < NUM_REGION; ++i)
	{
		for (int j = 0; j < NUM_REGION; ++j)
		{
			// Compare Region1[i] and Region2[j]
		
			label[i][j] = 1; // Different between Region1[i] and Region2[j]			
		}
	}

	// Assign couple 
	// a[i] - b[j]
	// 		Minimum sum(label[i][j])

	return 0;
}