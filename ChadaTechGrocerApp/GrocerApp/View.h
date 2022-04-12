#ifndef GROCERAPP_VIEW_H
#define GROCERAPP_VIEW_H


#include <iostream>
#include <fstream>
#include <memory>
#include <Windows.h>
#include <vector>
#include <iomanip>
#include <algorithm> // for for_each lambda's




using std::cout; using std::cin; using std::string;
using std::setw; using std::setprecision; using std::fixed;
using std::left; using std::right; using std::setfill;
using std::vector;


// enum class to represent text colors
enum class TEXT_COLOR {
	GREEN = 2,
	MAGENTA = 5,
	LIGHT_GRAY = 7,
	LIGHT_GREEN = 10,
	LIGHT_CYAN = 11,
	LIGHT_RED = 12,
	LIGHT_MAGENTA = 13,
	YELLOW = 14,
	WHITE = 15
};


class View {
private:

	// call this in constructor to initialize the menulist
	void Initialize();

	// vector of strings that are the menu items
	vector<string> MenuList;

public:
	View();


	void DisplayMenu();
	void DisplayHistogram(const string& fileName);

	void PrintColor(const TEXT_COLOR);
	void PrintColorReset();

	void PressEnterToContinue(std::istream& in);
	void PrintErrorMessage(const string& t_str);
	void PrintInputText(const string& t_str);
	void PrintNotice(const string& t_str);

	void PrintHeader();
//	void printItem(double year, double yearlyStart, double yearlyAmount);
	void PrintFooter();

//	void displayInstructions();
};


//
//void View::PrintColor(const TEXT_COLOR t_textColor) {
//	static const HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
//	SetConsoleTextAttribute(handle, static_cast<int>(t_textColor));
//}
//
//void View::PrintColorReset() {
//	static const HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
//	SetConsoleTextAttribute(handle, static_cast<int>(TEXT_COLOR::LIGHT_GRAY));
//}
//




#endif GROCERAPP_VIEW_H

