#include "View.h"

View::View() {
	Initialize();

}

void View::Initialize() {
	MenuList = vector<string> { 
		"Display daily purchases", 
		"Search item data", 
		"Display histogram", 
		"Exit"
	};
}

/// <summary>
/// display and colorize the menu
/// loop through the vector of menu items to print them
/// </summary>
void View::DisplayMenu() {

	std::ios cout_state(nullptr);
	cout_state.copyfmt(std::cout);

	cout << "\n\n";
	PrintColor(TEXT_COLOR::LIGHT_GREEN);
	string header{ "ChadaTech Grocer App" };
	int indentItems{ 5 };
	string border = " | ";

	cout << setw(35) << right << header << "\n\n";
	PrintColor(TEXT_COLOR::WHITE);
	cout << "\t " << setw(34) << std::setfill('-') << "\n";
	int count = 1;
	std::for_each(this->MenuList.begin(), this->MenuList.end(), [&count, &indentItems, &border, this](const string& e) {
		cout << "\t" << border << " ";

		PrintColor(TEXT_COLOR::GREEN);
		cout << setw(3) << std::setfill(' ') << std::left << count++
			<< setw(25) << left << e;

		PrintColor(TEXT_COLOR::WHITE);
		cout << border << "\n"; });
	cout << "\t " << right << std::setfill('-') << setw(34) << "\n";
	PrintColorReset();
	std::cout.copyfmt(cout_state);
}

void View::DisplayHistogram(const string& fileName) {
	std::ifstream inputFile;
	inputFile.open(fileName);
	string itemName{};
	int count{};

	inputFile >> itemName >> count;

	if (!inputFile.is_open()) {
		PrintErrorMessage("Could not open " + fileName);
	}
	else {
		PrintNotice("Data Analysis");
		while (!inputFile.fail()) {

			if (count < 3)
				PrintColor(TEXT_COLOR::LIGHT_RED);
			else if (count < 7)
				PrintColor(TEXT_COLOR::LIGHT_GRAY);
			else
				PrintColor(TEXT_COLOR::LIGHT_MAGENTA);

			cout << setw(5) << " " << setw(13) << left << itemName;
			PrintColorReset();
			for (auto i = 0; i < count; ++i) {
				if (count < 3) {
					PrintColor(TEXT_COLOR::LIGHT_RED);
				}
				else if (count < 7) {
					PrintColor(TEXT_COLOR::LIGHT_GRAY);
				}
				else {
					PrintColor(TEXT_COLOR::LIGHT_MAGENTA);
				}
				cout << right << "+";
			}

			PrintColorReset();

			cout << "\n";
			inputFile >> itemName >> count;
		}

		inputFile.close();
	}
}



void View::PrintColor(const TEXT_COLOR t_textColor) {
	static const HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, static_cast<int>(t_textColor));
}

void View::PrintColorReset() {
	static const HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, static_cast<int>(TEXT_COLOR::LIGHT_GRAY));
}

void View::PressEnterToContinue(std::istream& in) {
	PrintColor(TEXT_COLOR::LIGHT_CYAN);
	cout << "\n>> Press enter to continue";
	PrintColorReset();

	//remove anything remaining in cin including the return
	in.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
}


void View::PrintErrorMessage(const string& t_str) {
	PrintColor(TEXT_COLOR::LIGHT_RED);
	cout << "\n\n\t<< " << t_str << " >>\n\n";
	PrintColorReset();
}

void View::PrintInputText(const string& t_str) {
	PrintColor(TEXT_COLOR::LIGHT_CYAN);
	cout << "\n\n>> " << t_str << ": ";
	PrintColorReset();
}

void View::PrintNotice(const string& t_str) {
	PrintColor(TEXT_COLOR::LIGHT_GREEN);
	cout << "\n\n\t<< " << t_str << " >>\n\n";
	PrintColorReset();
}

//void View::displayMonthly(std::unique_ptr<Form>& t_form) {
//	cout << "\n\n";
//	PrintColor(TEXT_COLOR::LIGHT_GREEN);
//	cout << "\tBalance and Interest with monthly deposits of $0" << "\n\n";
//	PrintColorReset();
//	double totalYears{ t_form.get()->numberYears() };
//	double yearlyAmount{ t_form.get()->initialAmount() };
//	double annualInterest{ t_form.get()->annualInterest() };
//	double yearlyAccruedInterest{};
//	double yearlyStart{};
//
//
//	printHeader();
//
//	for (int i = 0; i < totalYears; ++i) {
//
//		yearlyStart = (yearlyAmount) * (annualInterest / 100);
//
//		yearlyAmount += yearlyStart;
//
//
//		//cout << (i + 1) << "\t$" << fixed << setprecision(2) << setw(10) << yearlyAmount
//		//	<< setw(5) << "$" << setw(10) << std::right << yearlyStart << "\n";
//
//		printItem(i + 1, yearlyStart, yearlyAmount);
//
//	}
//
//	printFooter();
//
//}

//void View::displayMonthlyDeposit(std::unique_ptr<Form>& t_form) {
//	cout << "\n\n\n";
//
//	double totalYears{ t_form.get()->numberYears() };
//	double yearlyAmount{ t_form.get()->initialAmount() };
//	double monthlyDeposit{ t_form.get()->monthlyDeposit() };
//	double annualInterest{ t_form.get()->annualInterest() };
//	double yearlyAccruedInterest{};
//	double yearlyStart{};
//
//	PrintColor(TEXT_COLOR::LIGHT_GREEN);
//	cout << "\tBalance and Interest with monthly deposits of $" << fixed << setprecision(2) << monthlyDeposit << "\n\n";
//	PrintColorReset();
//
//	printHeader();
//
//	for (int i = 0; i < totalYears; ++i) {
//
//		yearlyAccruedInterest = 0;
//
//		for (int j = 0; j < 12; ++j) {
//			yearlyStart = (yearlyAmount + monthlyDeposit) * ((annualInterest / 100) / 12);
//
//			yearlyAccruedInterest += yearlyStart;
//
//			yearlyAmount += monthlyDeposit + yearlyStart;
//		}
//
//		//cout << (i + 1) << "\t$" << fixed << setprecision(2) << setw(10) << yearlyAmount
//		//	<< setw(5) << "$" << setw(10) << std::right << yearlyAccruedInterest << "\n";
//
//		printItem(i + 1, yearlyAccruedInterest, yearlyAmount);
//
//	}
//
//	printFooter();
//
//}


//void View::printHeader() {
//	PrintColor(TEXT_COLOR::WHITE);
//	std::ios cout_state(nullptr);
//	cout_state.copyfmt(std::cout);
//	cout << "\n";
//	cout << "\t"
//		<< setw(6) << right << " Year"
//		<< "   "
//		<< setw(15) << left << "Interest Earned"
//		<< setw(4) << " "
//		<< setw(15) << left << "Year-end Balance" << "\n";
//	PrintColorReset();
//	cout << "\t" << setw(45) << setfill('-') << " " << "\n";
//	std::cout.copyfmt(cout_state);
//}
//
//void View::printFooter() {
//	std::ios cout_state(nullptr);
//	cout_state.copyfmt(std::cout);
//	cout << "\t " << setw(45) << setfill('-') << " " << "\n";
//	std::cout.copyfmt(cout_state);
//}

//void View::printItem(double year, double yearlyStart, double yearlyAmount) {
//	string border = " | ";
//	string symbol = "$";
//	std::ios cout_state(nullptr);
//	cout_state.copyfmt(std::cout);
//	cout << "\t"
//		<< border
//		<< setw(2) << fixed << setprecision(0) << std::internal << year
//		<< setw(3) << left << border
//		<< setw(4) << right << symbol
//		<< setw(12) << fixed << setprecision(2) << right << yearlyStart
//		<< setw(3) << left << border
//		<< setw(4) << right << symbol
//		<< setw(12) << fixed << setprecision(2) << right << yearlyAmount
//		<< setw(3) << left << border << "\n";
//	std::cout.copyfmt(cout_state);
//}
//

//void View::displayInstructions() {
//	PrintNotice("Hello! Welcome to Airgead's Investment Calculator");
//
//	PrintColor(TEXT_COLOR::LIGHT_CYAN);
//	cout << "\t- You will be prompted to enter the information listed above\n";
//	cout << "\t- We will display two investment scenarios: \n";
//	cout << "\t  1) A yearly balance sheet with no monthly deposits\n";
//	cout << "\t  2) A yearly balance sheet with the monthly deposit amount you provide\n";
//	PrintColorReset();
//
//}

