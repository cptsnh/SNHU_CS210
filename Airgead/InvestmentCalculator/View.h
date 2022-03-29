/**
 * Author:		Chris Trimmer
 * Course:		CS-210-H7406 (Programming Languages)
 * Semester:	22EW4
 * Professor:	Professor Bary Pollack
 * Date:		28Mar2022
 *
 * Title:	Project 2 (Airgead Investment Calculator)
 *
 */

#ifndef INVESTMENTCALCULATOR_VIEW_H
#define INVESTMENTCALCULATOR_VIEW_H

#include <iostream>
#include <string>
#include <iomanip>
#include <Windows.h>
#include "Form.h"

using std::cout; using std::cin; using std::string;
using std::setw; using std::setprecision; using std::fixed;
using std::left; using std::right; using std::setfill;

// enum class to represent text colors
enum class TEXT_COLOR {
	MAGENTA = 5,
	LIGHT_GRAY = 7,
	LIGHT_GREEN = 10,
	LIGHT_CYAN = 11,
	LIGHT_RED = 12,
	LIGHT_MAGENTA = 13,
	WHITE = 15
};


class View {
private:


public:
	View();

	void displayForm(std::unique_ptr<Form>& t_form);
	void displayMonthly(std::unique_ptr<Form>& t_form);
	void displayMonthlyDeposit(std::unique_ptr<Form>& form);
		
	void printColor(const TEXT_COLOR);
	void printColorReset();

	void pressEnterToContinue(std::istream& in);
	void printErrorMessage(const string& t_str);
	void printInputText(const string& t_str);
	void printNotice(const string& t_str);

	void printHeader();
	void printItem(double year, double yearlyStart, double yearlyAmount);
	void printFooter();

	void displayInstructions();
};






#endif	INVESTMENTCALCULATOR_VIEW_H

