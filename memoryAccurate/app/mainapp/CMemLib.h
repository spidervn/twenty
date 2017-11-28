/*
 * CMemLib.h
 *
 *  Created on: Nov 28, 2017
 *      Author: spider
 */

#ifndef APP_MAINAPP_CMEMLIB_H_
#define APP_MAINAPP_CMEMLIB_H_

#include "datastructure.h"

class CMemLib {
public:
	CMemLib();
	virtual ~CMemLib();

	int score(MemoryQuiz&,MemoryAnswer&);
};

#endif /* APP_MAINAPP_CMEMLIB_H_ */
