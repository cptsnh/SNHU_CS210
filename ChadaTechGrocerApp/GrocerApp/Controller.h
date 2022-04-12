/**
 * Author:		Chris Trimmer
 * Course:		CS-210-H7406 (Programming Languages)
 * Semester:	22EW4
 * Professor:	Professor Bary Pollack
 * Date:		12 Apr 2022
 *
 * Title:	Project 3 (Chada Grocer App)
 *
 */


#ifndef GROCERAPP_CONTROLLER_H
#define GROCERAPP_CONTROLLER_H


//#include "MyPyFunctions.h"
#include "View.h"
#include <memory>
#include <iostream>
#include <string>

using std::string;

class Controller {
private:
	std::unique_ptr<View> view;
	string pythonScript;
	string frequencyFile;

public:
	Controller() = delete;
	Controller(const string& pythonScript, const string& frequencyFile);

	void initialize();
	void introduction();
	void run();


	void CapitalizeString(string& t_str);
	bool ContainsCommonValidation(const string&);
	bool ContainsDigitsOnly(const string& str);
	double getValidDouble();
	string GetValidString();
	int GetValidInt();


//	bool containsDoublesOnly(const string&);
};


#endif GROCERAPP_CONTROLLER_H


