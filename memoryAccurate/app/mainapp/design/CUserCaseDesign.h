/*
 * CUserCaseDesign.h
 *
 *  Created on: Nov 29, 2017
 *      Author: spider
 */

#ifndef APP_MAINAPP_DESIGN_CUSERCASEDESIGN_H_
#define APP_MAINAPP_DESIGN_CUSERCASEDESIGN_H_

class CUserCaseDesign {
public:
	CUserCaseDesign();
	virtual ~CUserCaseDesign();

	int cmdLineExecute();
	int cmdLineTyping();
	int cmdLineShowAutoCompletion();
	int cmdLineDoQuiz();


};

#endif /* APP_MAINAPP_DESIGN_CUSERCASEDESIGN_H_ */
