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


#include "Controller.h"

/// <summary>
/// Default constructor
/// Initializes the form and view objects to default
/// </summary>
Controller::Controller() : form{ std::make_unique<Form>(0,0,0,0) },
	view{ std::make_unique<View>() } {}

// initialize all variables to zero
void Controller::initialize() {
	this->form->setAnnualInterest(0);
	this->form->setInitialAmount(0);
	this->form->setMonthlyDeposit(0);
	this->form->setNumberYears(0);
}

// main program loop
void Controller::run() {

	while (true) {
		system("cls");
		initialize();

		// get and display form information using View object
		view.get()->displayForm(form);
		view.get()->displayInstructions();
		view.get()->pressEnterToContinue(cin);
		

		// update the form
		updateForm();
		view.get()->pressEnterToContinue(cin);

		// display results
		system("cls");
		view.get()->displayMonthly(form);
		view.get()->displayMonthlyDeposit(form);


		// loop to see if customer wants to continue or exit
		view.get()->printInputText("Press 'c' to continue, or 'q' to exit");
		string userInput = getValidString();
		switch (userInput[0]) {
		case 'q':
			view.get()->printNotice("Thank you for using our app!");
			return;
			break;
		case 'c':
			continue;
		default:
			break;
		}


	}
}

/// <summary>
/// Obtain user input to update the form
/// </summary>
void Controller::updateForm() {

	// Display the updated form and get the intial investment
	system("cls");
	view.get()->displayForm(form);
	setAmount("initial investment");


	// Display the updated form and get the monthly deposit
	system("cls");
	view.get()->displayForm(form);
	setAmount("monthly deposit");

	// Display the updated form and get the interest rate
	system("cls");
	view.get()->displayForm(form);
	setInterestRate();

	// Display the updated form and get the number of years
	system("cls");
	view.get()->displayForm(form);
	setYears();

	// Display the completed form
	system("cls");
	view.get()->displayForm(form);
	view.get()->printNotice("Investment Form is complete");

}

/// <summary>
/// Function to set the amount for investment
/// it verifies input to ensure it is between 0 and 10-million
/// </summary>
/// <param name="t_msg"></param>
void Controller::setAmount(const string& t_msg) {
	double temp{};
	string message = "Enter the " + t_msg;
	while (true) {
		view.get()->printInputText(message);
		cout << "$ ";


		temp = getValidDouble();

		if (temp < 0 || temp > 9'999'999) {
			view.get()->printErrorMessage("The number entered is out of bounds");
			continue;
		}
		else {
			if (t_msg == "initial investment")
				form->setInitialAmount(temp);
			else
				form->setMonthlyDeposit(temp);

			return;
		}
	}
}

/// <summary>
/// Function to get a valid double
/// </summary>
/// <returns></returns>
double Controller::getValidDouble() {
	string temp{};
	double val{};

	while (true) {
		getline(cin, temp);

		if (containsDoublesOnly(temp)) {
			try {
				val = std::stod(temp);
			}
			catch (std::exception e) {
				view.get()->printErrorMessage("The double is over system limit");
				view.get()->printInputText("Please try again");
				val = 0.0;
				continue;
			}

			return val;
		}
		else {
			view.get()->printErrorMessage("Input Error");
			view.get()->printInputText("Please enter a number");
			val = 0.0;
			continue;
		}
	}
}

/// <summary>
/// Helper function to capitalize a string if needed
/// </summary>
/// <param name="t_str"></param>
void Controller::capitalizeString(string& t_str) {
	char next = ' ';
	for (auto it = t_str.begin(); it != t_str.end(); ++it) {
		*it = isspace(next) ? toupper(*it) : tolower(*it);
		next = *it;
	}

}

bool Controller::containsCommonValidation(const string& t_str) {
	// test for return or beginning with a space
	if (t_str.empty() || isspace(t_str[0])) {
		return false;
	}

	// test for consecutive spaces
	if (t_str.find("  ") != string::npos) {
		return false;
	}

	// test for last character being a space
	if (t_str[t_str.length() - 1] == ' ') {
		return false;
	}

	return true;
}

// validate doubles
bool Controller::containsDoublesOnly(const string& t_str) {

	if (containsCommonValidation(t_str)) {

		// make sure the first digits are not ..
		if (t_str[0] == '.' && t_str[1] == '.') {
			cout << "two decimals" << "\n";
			return false;
		}


		return t_str.find_first_not_of("0123456789.") == string::npos;
	}

	return false;

}

/// <summary>
/// Function to set the number of years
/// </summary>
void Controller::setYears() {
	double temp{};
	while (true) {
		view.get()->printInputText("Enter term of the investment (0-99 years)");
		temp = getValidDouble();

		if (temp < 0 || temp > 99) {
			view.get()->printErrorMessage("The number entered is out of bounds");
			continue;
		}
		else {
			form->setNumberYears(temp);
			return;
		}
	}
}

/// <summary>
/// Function to set the interest rate
/// </summary>
void Controller::setInterestRate() {
	double temp{};
	while (true) {
		view.get()->printInputText("Enter the annual interest rate");
		temp = getValidDouble();

		if (temp < 0 || temp > 99) {
			view.get()->printErrorMessage("The number entered is out of bounds");
			continue;
		}
		else {
			form->setAnnualInterest(temp);
			return;
		}
	}
}

/// <summary>
/// Function to get a valid string used for testing user input
/// </summary>
/// <returns></returns>
string Controller::getValidString() {
	string temp{};

	while (true) {
		getline(cin, temp);

		if (containsCommonValidation(temp)) {
			return temp;
		}
		else {
			view.get()->printErrorMessage("Bad Input");
			view.get()->printInputText("Please try again");
		}
	}
}

/// <summary>
/// function to get the instructions displayed at start of app
/// </summary>
void Controller::introduction() {

	view.get()->displayInstructions();
	

}
