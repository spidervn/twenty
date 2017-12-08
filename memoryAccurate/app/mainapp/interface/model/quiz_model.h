/*
 * quiz_model.h
 *
 *  Created on: Dec 8, 2017
 *      Author: spider
 */

#ifndef APP_MAINAPP_INTERFACE_MODEL_QUIZ_MODEL_H_
#define APP_MAINAPP_INTERFACE_MODEL_QUIZ_MODEL_H_

#include <string>
#include <vector>

typedef struct
{
	std::string code;
	std::string name;
	std::string author;

	long created_date;
	long modified_date;

	std::vector<std::string> listquiz;
} QuizModel;

#endif /* APP_MAINAPP_INTERFACE_MODEL_QUIZ_MODEL_H_ */
