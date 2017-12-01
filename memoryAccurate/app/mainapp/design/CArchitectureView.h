/*
 * CArchitectureView.h
 *
 *  Created on: Dec 1, 2017
 *      Author: ducvd
 */

#ifndef APP_MAINAPP_DESIGN_CARCHITECTUREVIEW_H_
#define APP_MAINAPP_DESIGN_CARCHITECTUREVIEW_H_

class CArchitectureView {
public:
	CArchitectureView();
	virtual ~CArchitectureView();

	int viewCursesICmdLine();
	int insideCursesCmdLine();
};

#endif /* APP_MAINAPP_DESIGN_CARCHITECTUREVIEW_H_ */
