/*
 * cmdline_model.h
 *
 *  Created on: Dec 1, 2017
 *      Author: ducvd
 */

#ifndef APP_MAINAPP_INTERFACE_CMDLINE_MODEL_H_
#define APP_MAINAPP_INTERFACE_CMDLINE_MODEL_H_

#include <vector>
#include <string>

typedef struct
{
	std::string currentCommand;
	std::vector<std::string> outputHistory;

} CmdLineModel;

typedef struct 
{
	std::string code;
	std::string name;
	std::vector<std::string> memUnits;
} QuizModel;

#endif /* APP_MAINAPP_INTERFACE_CMDLINE_MODEL_H_ */
