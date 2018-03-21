/*
 * IAutocompletion.h
 *
 *  Created on: Mar 21, 2018
 *      Author: spider
 */

#ifndef APP_MAINAPP_INTERFACE_LIB_IAUTOCOMPLETION_H_
#define APP_MAINAPP_INTERFACE_LIB_IAUTOCOMPLETION_H_

#include <string>
#include <vector>

struct CommandLineLayout
{

};

struct CommandSwitcher
{

};

struct CommandLineDefinition
{
	/*
	 * A commandline includes
	 *	i) Command line name
	 *
	 *	ii) List of switcher
	 *		Name of switcher
	 *		Available value [Optional]
	 *		Mandatory?
	 *	iii) Commandline Layout
	 *		Any: Any order
	 *		Framelayout: Switcher01 must stand before switcher 02
	 *
	 *
	 */

	/*

		CommandLine layout
		Các trường hợp CommandLine layout
		- Any: Các swicher đứng Theo bất kỳ thứ tự nào; và commandline sẽ có dạng
			cmdName <<các switchers>>

		- Phụ thuộc:
			Xảy ra khi Switcher B phụ thuộc vào giá trị của Switcher A
			Ví dụ:
				 Switcher A là OS
	 */
	CommandLineDefinition()
	{
	}

	std::string cmdName;
	std::vector<std::string> v_Switcher_;
};




#endif /* APP_MAINAPP_INTERFACE_LIB_IAUTOCOMPLETION_H_ */
