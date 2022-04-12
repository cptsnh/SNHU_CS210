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


#include "Controller.h"
#include "MyPyFunctions.h"


/// <summary>
/// Default constructor
/// Initializes the form and view objects to default
/// </summary>
Controller::Controller(const string& pythonScript, const string& frequencyFile) : 
	pythonScript{ pythonScript }, frequencyFile{ frequencyFile }, 
	view{ std::make_unique<View>() } {}

// initialize all variables to zero
void Controller::initialize() {}

// main program loop
void Controller::run() {
	
	while (true) {
		int menuSelection{};
		int userInput{};
		int searchCount{};
		string searchItem{};

		system("cls");
		view.get()->DisplayMenu();

		view.get()->PrintInputText("Enter a menu selection");

		menuSelection = GetValidInt();
		switch (menuSelection) {
			case 1:
				system("cls");
				MyPyFunctions::CallProcedure(pythonScript, "GetAllItemsFrequency");
				view.get()->PressEnterToContinue(cin);
				break;
			case 2:
				view.get()->PrintInputText("Please enter the item name");
				searchItem = GetValidString();
				searchCount = MyPyFunctions::CallIntFunc(pythonScript, "FindItemFrequency", searchItem);
				view.get()->PrintNotice("Count of " + searchItem + ": " + std::to_string(searchCount));
				view.get()->PressEnterToContinue(cin);
				break;
			case 3:
				system("cls");
				MyPyFunctions::CallProcedure(pythonScript, "WriteDataToFile");
				view.get()->DisplayHistogram(frequencyFile);
				view.get()->PressEnterToContinue(cin);
				break;
			case 4:
				view.get()->PrintNotice("Thank you for using our App!");
				return;
				break;
			default:
				view.get()->PrintErrorMessage("Invalid menu selection");
				view.get()->PressEnterToContinue(cin);
				break;
		}

	}

}



// capitalize string
void Controller::CapitalizeString(string& t_str) {
	char next = ' ';
	for (auto it = t_str.begin(); it != t_str.end(); ++it) {
		*it = isspace(next) ? toupper(*it) : tolower(*it);
		next = *it;
	}

}

bool Controller::ContainsCommonValidation(const string& t_str) {
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


string Controller::GetValidString() {
	string temp{};

	while (true) {
		getline(cin, temp);

		if (ContainsCommonValidation(temp)) {
			CapitalizeString(temp);
			return temp;
		}
		else {
			view.get()->PrintErrorMessage("Bad Input");
			view.get()->PrintInputText("Please try again");
		}
	}
}

void Controller::introduction() {

//	view.get()->displayInstructions();


}


/// <summary>
/// Helper function to get a valid int
/// </summary>
/// <returns></returns>
int Controller::GetValidInt() {
	string temp{};
	int val{};

	// perform loop until we get valid input
	while (true) {
		getline(cin, temp);

		// make sure we get a valid number by calling these helper functions
		if (ContainsDigitsOnly(temp)) {
			try {

				// test to  make sure the input is not over numeric limit
				val = std::stoi(temp);

			}
			catch (std::exception e) {
				view.get()->PrintErrorMessage("The number is over system limit");
				view.get()->PrintInputText("Please try again");
				val = 0;
				continue;
			}

			return val;
		}
		else {
			view.get()->PrintErrorMessage("Input Error");
			view.get()->PrintInputText("Please enter a number");
			continue;
		}
	}
}

/// <summary>
/// Helper function to validate user input for digits only
/// </summary>
/// <param name="str"></param>
/// <returns></returns>
bool Controller::ContainsDigitsOnly(const string& str) {

	// call to verify the string passes common validation
	if (ContainsCommonValidation(str)) {

		// test to see if user entered a negative value
		int countDashes{};
		for (auto& digit : str) {
			if (digit == '-')
				countDashes++;
		}

		// if they entered more than one dash, then error
		if (countDashes > 1)
			return false;

		// return true only if the string contains all digits or a dash to allow negatives
		return str.find_first_not_of("0123456789-") == string::npos;
	}

	return false;

}