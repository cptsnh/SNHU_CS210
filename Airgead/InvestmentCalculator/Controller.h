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


#ifndef INVESTMENTCALCULATOR_CONTROLLER_H
#define INVESTMENTCALCULATOR_CONTROLLER_H

#include "Form.h"
#include "View.h"
#include <memory>


class Controller {
private:
	std::unique_ptr<Form> form;
	std::unique_ptr<View> view;

public:
	Controller();
	
	void initialize();
	void introduction();
	void run();
	void updateForm();
	void setAmount(const string&);


	void capitalizeString(string& t_str);
	bool containsCommonValidation(const string&);
	bool containsDoublesOnly(const string&);
	double getValidDouble();
	string getValidString();

	void setInterestRate();
	void setYears();

};






#endif	INVESTMENTCALCULATOR_CONTROLLER_H

