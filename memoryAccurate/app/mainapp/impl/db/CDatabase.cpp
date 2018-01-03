/*
 * CDatabase.cpp
 *
 *  Created on: Jan 3, 2018
 *      Author: ducvd
 */

#include <mainapp/impl/db/CDatabase.h>

CDatabase::CDatabase() {
	// TODO Auto-generated constructor stub

}

CDatabase::~CDatabase() {
	// TODO Auto-generated destructor stub
}

int CDatabase::getMemStick(std::string code, MemoryStick& out)
{
	//TODO: Implement at least one database here
	out.code = "Twenty";
	out.name = "Twenty quiz code";
	out.created_date = 0;
	out.author = "ducvd";

	out.listmemory_.push_back("1. When high rollers are the biggest drivers of Macau’s casino revenue, it’s much harder for analysts to predict betting results.");
	out.listmemory_.push_back("1.2. Analysts attributed the unexpected slower growth to bad luck for casinos as gamblers took home greater-than-expected winnings");
	out.listmemory_.push_back("1.3. Many of those winning gamblers were high rollers");
	out.listmemory_.push_back("2. This volatility can be driven by the luck factor or even by the timing of VIP trips, especially on the part of some of the biggest VIP players");
	out.listmemory_.push_back("2.1. High rollers drove revenue at a faster pace than casual gamblers for most of last year.");
	out.listmemory_.push_back("2.2. As they continued their return to Macau after a Beijing crackdown on corruption kept them away from the tables, actual monthly gaming revenue deviated from analysts’ estimates.");
	out.listmemory_.push_back("3. In nine separate months, actual casino receipts growth showed more than a three percentage point difference from analyst estimates.");
	out.listmemory_.push_back("3.1. Analysts also had a harder time forecasting during peak seasons, especially when VIPs delayed their trips.");
	out.listmemory_.push_back("3.3. Despite the the weaker-than-expected performance in December, analysts are still optimistic about the gaming market in 2018.");

	return 0;
}

int CDatabase::save_Stick_(MemoryStick quiz)
{
	return 0;
}

int CDatabase::deleteStick(MemoryStick quiz)
{
	return 0;
}

int CDatabase::queryStick_(std::string codeText, std::vector<MemoryStick>& out)
{
	MemoryStick quiz1;
	MemoryStick quiz2;

	quiz1.code = "Twenty";
	quiz1.name = "Twenty quiz code";
	quiz1.created_date = 0;
	quiz1.author = "ducvd";

	quiz1.listmemory_.push_back("1. When high rollers are the biggest drivers of Macau’s casino revenue, it’s much harder for analysts to predict betting results.");
	quiz1.listmemory_.push_back("1.2. Analysts attributed the unexpected slower growth to bad luck for casinos as gamblers took home greater-than-expected winnings");
	quiz1.listmemory_.push_back("1.3. Many of those winning gamblers were high rollers");
	quiz1.listmemory_.push_back("2. This volatility can be driven by the luck factor or even by the timing of VIP trips, especially on the part of some of the biggest VIP players");
	quiz1.listmemory_.push_back("2.1. High rollers drove revenue at a faster pace than casual gamblers for most of last year.");
	quiz1.listmemory_.push_back("2.2. As they continued their return to Macau after a Beijing crackdown on corruption kept them away from the tables, actual monthly gaming revenue deviated from analysts’ estimates.");
	quiz1.listmemory_.push_back("3. In nine separate months, actual casino receipts growth showed more than a three percentage point difference from analyst estimates.");
	quiz1.listmemory_.push_back("3.1. Analysts also had a harder time forecasting during peak seasons, especially when VIPs delayed their trips.");
	quiz1.listmemory_.push_back("3.3. Despite the the weaker-than-expected performance in December, analysts are still optimistic about the gaming market in 2018.");

	quiz2.code = "Twenty2";
	quiz2.name = "Twenty quiz code2";
	quiz2.created_date = 0;
	quiz2.author = "ducvd";

	quiz2.listmemory_.push_back("1. When high rollers are the biggest drivers of Macau’s casino revenue, it’s much harder for analysts to predict betting results.");
	quiz2.listmemory_.push_back("1.2. Analysts attributed the unexpected slower growth to bad luck for casinos as gamblers took home greater-than-expected winnings");
	quiz2.listmemory_.push_back("1.3. Many of those winning gamblers were high rollers");
	quiz2.listmemory_.push_back("2. This volatility can be driven by the luck factor or even by the timing of VIP trips, especially on the part of some of the biggest VIP players");
	quiz2.listmemory_.push_back("2.1. High rollers drove revenue at a faster pace than casual gamblers for most of last year.");
	quiz2.listmemory_.push_back("2.2. As they continued their return to Macau after a Beijing crackdown on corruption kept them away from the tables, actual monthly gaming revenue deviated from analysts’ estimates.");
	quiz2.listmemory_.push_back("3. In nine separate months, actual casino receipts growth showed more than a three percentage point difference from analyst estimates.");
	quiz2.listmemory_.push_back("3.1. Analysts also had a harder time forecasting during peak seasons, especially when VIPs delayed their trips.");
	quiz2.listmemory_.push_back("3.3. Despite the the weaker-than-expected performance in December, analysts are still optimistic about the gaming market in 2018.");

	out.clear();
	out.push_back(quiz1);
	out.push_back(quiz2);
	return 0;
}
