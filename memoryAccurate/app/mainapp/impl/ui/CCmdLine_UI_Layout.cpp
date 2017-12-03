/*
 * CCmdLine_UI_Layout.cpp
 *
 *  Created on: Dec 3, 2017
 *      Author: ducvd
 */

#include "CCmdLineUI.h"
#include <stdlib.h>
#include <algorithm>

int CCmdLineUI::UI::Layout::arrangePopup(int candidatey, int candidatex, int screenRows, int screenCols, int popupRows, int popupCols, int& outputy, int& outputx)
{
	// 4 Rectangles
	// Check 04 posible Window Position
	//	The chosen position is the Rectangle which has the largest overlapped area between screen & Window position
	//	If there're two position which has the same largest overlapped area => choose the Window position which appear first

	int N = 4;
	int directionRows[4] { 1, 1, -1, -1 };	// Direction
	int directionCols[4] { 1, -1, 1, -1 };
	int deltaRows[4] { 0, 0, -2, -2};
	int deltaCols[4] { 0, 0, 0, 0 };
	int chosen = 0;
	int maxOverlapped = 0;

	int y0, y1, x0, x1;
	y0 = candidatey;
	x0 = candidatex;

	for (int i=0;i<4;++i)
	{
		x0 = candidatex + deltaCols[i];
		y0 = candidatey + deltaRows[i];

		y1 = y0 + directionRows[i] * (popupRows - 1);
		x1 = x0 + directionCols[i] * (popupCols - 1);

		// Totally inside screen => Choose & Done
		if (x0 >= 0 && x0 < screenCols &&
				x1>=0 && x1 < screenCols &&
				y0 >=0 && y0 < screenRows &&
				y1 >=0 && y1 < screenRows)
		{
			chosen = i;
			break;
		}
		else
		{
			// int overlappedArea =
			int width = std::min(screenCols - 1, std::max(x0,x1))  - std::max(0,std::min(x0,x1));
			int height = std::min(screenRows - 1, std::max(y0,y1))  - std::max(0,std::min(y0,y1));
			int area = width * height;

			if (area > maxOverlapped)
			{
				maxOverlapped = area;
				chosen = i;
			}
		}
	}

	// Calculate here
	x0 = candidatex + deltaCols[chosen];
	y0 = candidatey + deltaRows[chosen];

	y1 = y0 + directionRows[chosen] * (popupRows - 1);
	x1 = x0 + directionCols[chosen] * (popupCols - 1);

	outputx = std::min(x0, x1);
	outputy = std::min(y0, y1);
	return 0;
}

