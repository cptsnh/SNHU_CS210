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
  

#include "View.h"

/// <summary>
/// Constructor
/// </summary>
View::View() {}

/// <summary>
/// Display Form
/// </summary>
/// <param name="t_form"></param>
void View::displayForm(std::unique_ptr<Form>& t_form)
{
	cout << "\n\n";
	string border{ " | " };
	string symbol{ "$" };
	const int firstColumn{ 18 };

	printColor(TEXT_COLOR::LIGHT_GREEN);


	std::ios cout_state(nullptr);
	cout_state.copyfmt(std::cout);

	cout << setw(24) << " " << "Airgead Bank" << "\n";
	cout << setw(20) << " " << "Investment Calculator" << "\n\n";


	cout << setw(10) << " " << setw(3) << border << setw(firstColumn) << left << "Initial Investment"
		<< setw(3) << border
		<< setw(2) << right << symbol
		<< setw(10) << fixed << setprecision(2) << t_form.get()->initialAmount()
		<< setw(4) << border << "\n";

	cout << setw(10) << " " << setw(3) << border << setw(firstColumn) << left << "Monthly Deposit"
		<< setw(3) << border
		<< setw(2) << right << symbol
		<< setw(10) << fixed << setprecision(2) << t_form.get()->monthlyDeposit()
		<< setw(4) << border << "\n";

	cout << setw(10) << " " << setw(3) << border << setw(firstColumn) << left << "Annual Interest"
		<< setw(5) << left << border
		<< setw(5) << left << fixed << setprecision(2) << t_form.get()->annualInterest()
		<< setw(6) << left << "%"
		<< setw(3) << border << "\n";

	cout << setw(10) << " " << setw(3) << border << setw(firstColumn) << left << "Number of Years"
		<< setw(5) << left << border
		<< setw(11) << left << setprecision(0) << t_form.get()->numberYears()
		<< setw(3) << border << "\n";


	cout << "\n";
	std::cout.copyfmt(cout_state);
	printColorReset();
}

/// <summary>
/// Print color
/// </summary>
/// <param name="t_textColor"></param>
void View::printColor(const TEXT_COLOR t_textColor) {
	static const HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, static_cast<int>(t_textColor));
}

/// <summary>
/// Print color reset
/// </summary>
void View::printColorReset() {
	static const HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, static_cast<int>(TEXT_COLOR::LIGHT_GRAY));
}

/// <summary>
/// Press enter to continue
/// </summary>
/// <param name="in"></param>
void View::pressEnterToContinue(std::istream& in) {
	printColor(TEXT_COLOR::LIGHT_CYAN);
	cout << "\n>> Press enter to continue";
	printColorReset();

	//remove anything remaining in cin including the return
	in.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
}


/// <summary>
/// print error message
/// </summary>
/// <param name="t_str"></param>
void View::printErrorMessage(const string& t_str) {
	printColor(TEXT_COLOR::LIGHT_RED);
	cout << "\n\n\t<< " << t_str << " >>\n\n";
	printColorReset();
}

void View::printInputText(const string& t_str) {
	printColor(TEXT_COLOR::LIGHT_CYAN);
	cout << "\n\n>> " << t_str << ": ";
	printColorReset();
}

void View::printNotice(const string& t_str) {
	printColor(TEXT_COLOR::LIGHT_GREEN);
	cout << "\n\n\t<< " << t_str << " >>\n\n";
	printColorReset();
}

/// <summary>
/// display monthly report
/// </summary>
/// <param name="t_form"></param>
void View::displayMonthly(std::unique_ptr<Form>& t_form) {
	cout << "\n\n";
	printColor(TEXT_COLOR::LIGHT_GREEN);
	cout << "\tBalance and Interest with monthly deposits of $0" << "\n\n";
	printColorReset();
	double totalYears{ t_form.get()->numberYears() };
	double yearlyAmount{ t_form.get()->initialAmount() };
	double annualInterest{ t_form.get()->annualInterest() };
	double yearlyAccruedInterest{};
	double yearlyStart{};


	printHeader();

	for (int i = 0; i < totalYears; ++i) {

		yearlyStart = (yearlyAmount) * (annualInterest / 100);

		yearlyAmount += yearlyStart;

		printItem(i + 1, yearlyStart, yearlyAmount);

	}

	printFooter();

}

/// <summary>
/// display monthly deposit
/// </summary>
/// <param name="t_form"></param>
void View::displayMonthlyDeposit(std::unique_ptr<Form>& t_form) {
	cout << "\n\n\n";

	double totalYears{ t_form.get()->numberYears() };
	double yearlyAmount{ t_form.get()->initialAmount() };
	double monthlyDeposit{ t_form.get()->monthlyDeposit() };
	double annualInterest{ t_form.get()->annualInterest() };
	double yearlyAccruedInterest{};
	double yearlyStart{};

	printColor(TEXT_COLOR::LIGHT_GREEN);
	cout << "\tBalance and Interest with monthly deposits of $" << fixed << setprecision(2) << monthlyDeposit << "\n\n";
	printColorReset();

	printHeader();

	for (int i = 0; i < totalYears; ++i) {

		yearlyAccruedInterest = 0;

		for (int j = 0; j < 12; ++j) {
			yearlyStart = (yearlyAmount + monthlyDeposit) * ((annualInterest / 100) / 12);

			yearlyAccruedInterest += yearlyStart;

			yearlyAmount += monthlyDeposit + yearlyStart;
		}

		printItem(i + 1, yearlyAccruedInterest, yearlyAmount);

	}

	printFooter();

}

/// <summary>
/// Display header
/// </summary>
void View::printHeader() {
	printColor(TEXT_COLOR::WHITE);
	std::ios cout_state(nullptr);
	cout_state.copyfmt(std::cout);
	cout << "\n";
	cout << "\t"
		<< setw(6) << right << " Year"
		<< "   "
		<< setw(15) << left << "Interest Earned"
		<< setw(4) << " "
		<< setw(15) << left << "Year-end Balance" << "\n";
	printColorReset();
	cout << "\t" << setw(45) << setfill('-') << " " << "\n";
	std::cout.copyfmt(cout_state);
}

/// <summary>
/// Display footer
/// </summary>
void View::printFooter() {
	std::ios cout_state(nullptr);
	cout_state.copyfmt(std::cout);
	cout << "\t " << setw(45) << setfill('-') << " " << "\n";
	std::cout.copyfmt(cout_state);
}

/// <summary>
/// Print an item
/// </summary>
/// <param name="year"></param>
/// <param name="yearlyStart"></param>
/// <param name="yearlyAmount"></param>
void View::printItem(double year, double yearlyStart, double yearlyAmount) {
	string border = " | ";
	string symbol = "$";
	std::ios cout_state(nullptr);
	cout_state.copyfmt(std::cout);
	cout << "\t"
		<< border
		<< setw(2) << fixed << setprecision(0) << std::internal << year
		<< setw(3) << left << border
		<< setw(4) << right << symbol
		<< setw(12) << fixed << setprecision(2) << right << yearlyStart
		<< setw(3) << left << border
		<< setw(4) << right << symbol
		<< setw(12) << fixed << setprecision(2) << right << yearlyAmount
		<< setw(3) << left << border << "\n";
	std::cout.copyfmt(cout_state);
}

/// <summary>
/// display instructions
/// </summary>
void View::displayInstructions() {
	printNotice("Hello! Welcome to Airgead's Investment Calculator");

	printColor(TEXT_COLOR::LIGHT_CYAN);
	cout << "\t- You will be prompted to enter the information listed above\n";
	cout << "\t- We will display two investment scenarios: \n";
	cout << "\t  1) A yearly balance sheet with no monthly deposits\n";
	cout << "\t  2) A yearly balance sheet with the monthly deposit amount you provide\n";
	printColorReset();

}