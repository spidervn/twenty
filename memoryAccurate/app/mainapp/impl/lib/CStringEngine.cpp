/*
 * CStringEngine.cpp
 *
 *  Created on: Mar 5, 2018
 *      Author: ducvd
 */

#include "mainapp/impl/lib/CStringEngine.h"
#include <algorithm>

using namespace std;

CStringEngine::CStringEngine() {
}

CStringEngine::~CStringEngine() {
}

int CStringEngine::needleman_Wunsch_(std::string s1, std::string s2)
{
	return 0;
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
					v3 = m[i-1][j-1] + vdiff;

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

int CStringEngine::damerau_Levenshtein(std::string s1, std::string s2)
{
	int n1 = s1.size();
	int n2 = s2.size();
	int** d_val; // = new int[n1*n2];
	int ret = 0;

	if (n1==0 || n2==0)
	{
		ret = max(n1,n2);
	}
	else
	{
		// Memory allocation
		d_val = new int*[n1];
		for (int i = 0; i < n1; ++i)
		{
			d_val[i] = new int[n2];
		}

		for (int i=0; i< n1; ++i)
		{
			d_val[i][0] = i;
		}

		for (int j=0; j<n2;j++)
		{
			d_val[0][j] = j;
		}

		for (int i = 1; i < n1; ++i)
		{
			for (int j = 1; j < n2; ++j)
			{
				if (i>1 && j>1 && s1[i]==s2[j-1] && s1[i-1]==s2[j])
				{
					int vdiff = s1[i]==s2[j] ? 0 : 1;
					int d1 = d_val[i-1][j] + 1;
					int d2 = d_val[i][j-1] + 1;
					int d3 = d_val[i-1][j-1] + vdiff;
					int d4 = d_val[i-2][j-2] + 1;

					d_val[i][j] = min(d1, min(d2,min(d3,d4)));
				}
				else
				{
					int vdiff = s1[i]==s2[j] ? 0 : 1;
					int d1 = d_val[i-1][j] + 1;
					int d2 = d_val[i][j-1] + 1;
					int d3 = d_val[i-1][j-1] + vdiff;

					d_val[i][j] = min(d1,min(d2,d3));
				}
			}
		}

		ret = d_val[n1-1][n2-1];
		// Free memory
		for (int i = 0; i < n1; ++i)
		{
			delete [] d_val[i];
		}		
		delete[] d_val;
	}

	return ret;
}

int CStringEngine::demonstrate_DamerauLevenstein(std::string s1, std::string s2)
{
	int n1 = s1.size();
	int n2 = s2.size();
	int** d_val; // = new int[n1*n2];
	int arTrace[100][100];	
	int ret = 0;

	int OP_INSERT = 1;
	int OP_DELETE = 2;
	int OP_SUBSTITUTION = 3;
	int OP_NONE = 4;
	int OP_TRANSPOS = 5;

	int x_op_ray[5] = { 1,			// Nothing
							1,		// After OP_INSERT, s1.index + 1
							0, 		// After OP_DELETE, s1.index unchanged
							1, 		// After OP_SUBSTITUTION, s2.index + 1
							0, 		// After OP_NONE, se

	};	// increase of string s1 after an operation.
	int aop[100];			// Storing operations
	int nop = 0;			// The top of stack

	// String substitution
	if (n1==0 || n2==0)
	{
		printf("Simple cases\r\n");
		ret = max(n1,n2);
	}
	else if (n1 > 100 || n2 > 100)
	{
		printf("Unsupported data!\r\n");
		return -1;
	}
	else
	{
		// Memory allocation
		d_val = new int*[n1];
		for (int i = 0; i < n1; ++i)
		{
			d_val[i] = new int[n2];
		}

		for (int i=0; i< n1; ++i)
		{
			d_val[i][0] = i;
		}

		for (int j=0; j<n2;j++)
		{
			d_val[0][j] = j;
		}

		for (int i = 1; i < n1; ++i)
		{
			for (int j = 1; j < n2; ++j)
			{
				if (i>1 && j>1 && s1[i]==s2[j-1] && s1[i-1]==s2[j])
				{
					int vdiff = s1[i]==s2[j] ? 0 : 1;
					int d1 = d_val[i-1][j] + 1;
					int d2 = d_val[i][j-1] + 1;
					int d3 = d_val[i-1][j-1] + vdiff;
					int d4 = d_val[i-2][j-2] + 1;

					// d_val[i][j] = min(d1, min(d2,min(d3,d4)));
					d_val[i][j] = d1;
					arTrace[i][j] = OP_INSERT;


					if (d2 < d_val[i][j])
					{
						d_val[i][j] = d2;
						arTrace[i][j] = OP_DELETE;
					}

					if (d3 < d_val[i][j])
					{
						d_val[i][j] = d3;
						arTrace[i][j] = vdiff == 1 ? OP_SUBSTITUTION : OP_NONE;
					}

					if (d4 < d_val[i][j])
					{
						d_val[i][j] = d4;
						arTrace[i][j] = OP_TRANSPOS;
					}

				}
				else
				{
					int vdiff = s1[i]==s2[j] ? 0 : 1;
					int d1 = d_val[i-1][j] + 1;
					int d2 = d_val[i][j-1] + 1;
					int d3 = d_val[i-1][j-1] + vdiff;

					// d_val[i][j] = min(d1,min(d2,d3));
					d_val[i][j] = d1;
					arTrace[i][j] = OP_INSERT;


					if (d2 < d_val[i][j])
					{
						d_val[i][j] = d2;
						arTrace[i][j] = OP_DELETE;
					}

					if (d3 < d_val[i][j])
					{
						d_val[i][j] = d3;
						arTrace[i][j] = vdiff == 1 ? OP_SUBSTITUTION : OP_NONE;
					}
				}
			}
		}

		/*
		int p1 = n1-1;
		int p2 = n2-1;
		int aop[100];
		int nop;
		int stack = 0;
		int stackOp[100];
		// Traceback

		while (p1 >=0 && p2>=0)
		{
			switch (arTrace[p1][p2]) {
				case OP_INSERT:

						p1 -= x_op_ray[arTrace[p1][p2]];
						p2 -= y_op_ray[arTrace[p1][p2]];
						aop[nop++] = 1;
						aop[nop++];
					break;
				case OP_DELETE:
					break;
				case OP_NONE:
					break;
				case OP_SUBSTITUTION:
					break;
				case OP_TRANSPOS:
				default:
					break;
			}
		}
		*/

		ret = d_val[n1-1][n2-1];
		// Free memory
		for (int i = 0; i < n1; ++i)
		{
			delete [] d_val[i];
		}		
		delete[] d_val;
	}

	return ret;	
}

// int lcs_length(char* A, char* B)
// {
// 	if (*A == '\0' || *B == '\0') return 0;
// 	else if (*A == *B) return 1 + lcs_length(A+1, B+1);
// 	else return max(lcs_length(A+1, B), lcs_length(A, B+1));
// }

//int CStringEngine::LCS_Test1(char* P, char* T)
//{
//	bool b_Res = FALSE;
//
//	while (*T != '\0')
//	{
//		if (*P == *T++ && *++P == '\0')
//		{
//			b_Res = TRUE;
//			break;
//		}
//	}
//
//	//b_Res is the final result
//	return 0;
//}

