/*
 * CAutocompletionTest.cpp
 *
 *  Created on: Mar 22, 2018
 *      Author: spider
 */

#include <mainapp/test/CAutocompletionTest.h>
#include "mainapp/interface/lib/IAutocompletion.h"

CAutocompletionTest::CAutocompletionTest() {
}

CAutocompletionTest::~CAutocompletionTest() {
}

int CAutocompletionTest::run_TheTest()
{
	CommandLineDefinition cmd;
	CommandLineLayout layout1;
	CommandSwitcher switchVerbose;
	CommandSwitcher switch_Notify;
	CommandLineElement ce1;
	CommandLineElement ce2;

	cmd.cmdName = "quiz";

	ce1.type = CMDLINE_ELEMENT_TYPE_CONST;
	ce1.value = "add";

	ce2.type = CMDLINE_ELEMENT_TYPE_SWITCHER;
	ce2._vSwitchers.push_back("verbose");
	ce2._vSwitchers.push_back("notify");

	layout1.v_Order.push_back(ce1);
	layout1.v_Order.push_back(ce2);

	// Switcher
	switchVerbose.code = "verbose";
	switchVerbose.name = "-v";
	switchVerbose.mandatory = false;
	switchVerbose.unique = true;
	switchVerbose.needContent = false;

	switch_Notify.code = "notify";
	switch_Notify.name = "--notify";
	switch_Notify.mandatory = false;
	switch_Notify.unique = true;
	switch_Notify.needContent = false;

	cmd.v_Switcher_.push_back(switchVerbose);
	cmd.v_Switcher_.push_back(switch_Notify);
	cmd.vLayout.push_back(layout1);

	// CommandLine element
	return 0;
}

