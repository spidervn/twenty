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

struct CommandSwitcher
{
	std::string code;
	std::string name;

	bool mandatory;
	bool unique;
	bool needContent;
	
	std::vector<std::string> availableContents;
	void* validation;

	CommandSwitcher()
	{
		mandatory = false;	// Is optional
		unique = true;		// Appear only one
		needContent = true;	

		availableContents.clear();
		validation = NULL;
	}	
};

#define CMDLINE_ELEMENT_TYPE_CONST 		1
#define CMDLINE_ELEMENT_TYPE_SWITCHER 	2
#define CMDLINE_ELEMENT_TYPE_VALUE 		3
struct CommandLineElement
{
	int type;
	std::string value; 						// Type == const or value
	std::vector<std::string> _vSwitchers;	// Type==Swicher
};

struct CommandLineLayout
{
	std::vector<CommandLineElement> v_Order;	// Element's order
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
	{}

	std::string cmdName;
	// std::vector<std::string> v_Switcher_;
	int position[3];	// Position[0] = BEGIN
						// Position[1] = { List of Available switcher }
						// Position[2] = {}

	std::vector<CommandSwitcher> v_Switcher_;			// All available layout
	std::vector<CommandLineLayout> vLayout;				// All available layout
};

class ICommandSwitcher
{
public: 
	virtual ~ICommandSwitcher() {}
};

class IAutocompletion
{
public:
	virtual ~IAutocompletion() {}
	virtual std::vector<std::string> suggest_Contents_(std::string switcherVal) = 0;
	virtual void suggest_Contents_() = 0;
	
};
#endif /* APP_MAINAPP_INTERFACE_LIB_IAUTOCOMPLETION_H_ */
