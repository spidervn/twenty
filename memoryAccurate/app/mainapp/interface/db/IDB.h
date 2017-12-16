/*
 * IDB.h
 *
 *  Created on: Dec 16, 2017
 *      Author: spider
 */

#ifndef APP_MAINAPP_INTERFACE_DB_IDB_H_
#define APP_MAINAPP_INTERFACE_DB_IDB_H_

#include "mainapp/interface/model/quiz_model.h"
#include "mainapp/interface/model/cmdline_model.h"

#include <string>
#include <vector>

class IDatabase
{
public:
	int getQuiz(std::string code, QuizModel& out) = 0;

	int saveQuiz(QuizModel quiz) = 0;

	int deleteQuiz(QuizModel quiz) = 0;

	int queryQuiz(std::string codeText, std::vector<QuizModel>& out) = 0;
};


#endif /* APP_MAINAPP_INTERFACE_DB_IDB_H_ */
