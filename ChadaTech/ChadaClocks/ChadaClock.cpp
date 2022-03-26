#define _CRT_SECURE_NO_WARNINGS
/**
 * Author:		Chris Trimmer
 * Course:		CS-210-H7406 (Programming Languages)
 * Semester:	22EW4
 * Professor:	Professor Bary Pollack
 * Date:		14Mar2022
 *
 * Title:	Assignment 3-1 (Chada Clocks)
 *
 */

 // Include statements
#include "ChadaClock.h"
#include <iomanip>
#include <sstream>
#include <chrono>
#include <thread>
#include <conio.h>
#include <iostream>
#include <memory>
#include <Windows.h>


// Using Statements
using std::cout; using std::cin; using std::string;
using std::setfill; using std::setprecision; using std::setw;
using namespace std::chrono_literals;

// enum to represent text colors
enum class TEXTCOLOR {
	LIGHT_GRAY = 7,
	LIGHT_GREEN = 10,
	LIGHT_CYAN = 11,
	LIGHT_MAGENTA = 13
};

// Forward declare functions
int MenuSelection(const char& ch, std::shared_ptr<Clock> clock);
void EndMessage();
void DisplayMenu();
void DisplayClocks(const std::shared_ptr<Clock> sClock, const std::shared_ptr<Clock> mClock);
void DisplayHeader();
void SetColor(TEXTCOLOR);
void ResetTextColor();



int main() {

	// Declare and initialize clocks by getting singleton instance reference
	auto standardClock = Clock::GetInstance();
	auto militaryClock = Clock::GetInstance();

	// terminating variable
	int quit = 0;

	/// <summary>
	/// Main Loop
	/// Loop will continue until the user presses 4 on keyboard
	/// Loop will print the clock in standard and military format each iteration,
	/// and it will increment the clock seconds every 1000ms
	/// If user hits keyboard 1, 2, or 3 the clock will increment
	/// hours, minutes, or seconds respectively
	/// </summary>
	/// <returns></returns>
	while (quit != 4) {

		DisplayHeader();

		// Print both versions of the clock
		DisplayClocks(standardClock, militaryClock);

		// Display the menu
		DisplayMenu();

		/// <summary>
		/// If keyboard is hit, test to see what key, and
		/// to respectively increment hours, mins, or secs.
		/// Loop ends with user presses 4
		/// </summary>
		/// <returns></returns>
		if (_kbhit()) {
			quit = MenuSelection(_getch(), standardClock);
		}
		else {
			standardClock.get()->IncrementSecond();
			std::this_thread::sleep_for(1000ms);

		}

		// clear screen each iteration
		std::system("cls");
	}

	return 0;
}

/// <summary>
/// Function to test user input for respective menu options
/// </summary>
/// <param name="ch"></param>
/// <param name="clock"></param>
/// <returns></returns>
int MenuSelection(const char& ch, std::shared_ptr<Clock> clock) {
	switch (ch) {
	case '1':
		clock.get()->IncrementHour();
		break;
	case '2':
		clock.get()->IncrementMinute();
		break;
	case '3':
		clock.get()->IncrementSecond();
		break;
	case '4':
		atexit(EndMessage);
		return 4;
		break;
	default:
		break;
	}

	return 1;
}

/// <summary>
/// Function to display the menu
/// </summary>
void DisplayMenu() {
	cout << "\n";

	SetColor(TEXTCOLOR::LIGHT_MAGENTA);

	cout << setw(50) << setfill(' ') << "**************************" << "\n";
	cout << setw(50) << setfill(' ') << "*                        *" << "\n";

	cout << setw(50) << setfill(' ') << std::right << "*   1 - Add One Hour     *" << "\n";
	cout << setw(50) << setfill(' ') << std::right << "*   2 - Add One Minute   *" << "\n";
	cout << setw(50) << setfill(' ') << std::right << "*   3 - Add One Second   *" << "\n";
	cout << setw(50) << setfill(' ') << std::right << "*   4 - Exit Program     *" << "\n";
	cout << setw(50) << setfill(' ') << "*                        *" << "\n";
	cout << setw(50) << setfill(' ') << "**************************";

	ResetTextColor();
}

/// <summary>
/// Print the final message when user exits the application
/// </summary>
void EndMessage() {

	SetColor(TEXTCOLOR::LIGHT_GREEN);
	cout << "\n\n\t< Thank you for using our app! >\n\n";
	ResetTextColor();
}

/// <summary>
/// Function to display the clocks
/// </summary>
/// <param name="sClock"></param>
/// <param name="mClock"></param>
void DisplayClocks(const std::shared_ptr<Clock> sClock, const std::shared_ptr<Clock> mClock) {

	SetColor(TEXTCOLOR::LIGHT_CYAN);

	cout << "\n\t" << "**************************" << "\t" << "**************************" << "\n";
	cout << "\t" << "*                        *" << "\t" << "*                        *" << "\n";
	cout << "\t" << "*      12-Hour Clock     *" << "\t" << "*      24-Hour Clock     *" << "\n";
	cout << "\t" << "*                        *" << "\t" << "*                        *" << "\n";
	cout << "\t" << "*       " << sClock.get()->PrintStandard() << "      *" <<
		"\t" << "*        " << mClock.get()->PrintMilitary() << "        *" << "\n";
	cout << "\t" << "*                        *" << "\t" << "*                        *" << "\n";
	cout << "\t" << "**************************" << "\t" << "**************************" << "\n";
	cout << "\n\n\n";

	ResetTextColor();
}


/// <summary>
/// Function to display the Chada Tech header
/// </summary>
void DisplayHeader() {
	SetColor(TEXTCOLOR::LIGHT_GREEN);
	cout << "\n\n" << setw(46) << "Chada Tech Clocks" << "\n\n\n";
	ResetTextColor();
}

/// <summary>
/// Function to get Windows handle to set color of standard output
/// </summary>
/// <param name="textColor"></param>
void SetColor(TEXTCOLOR textColor) {
	HANDLE text_color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(text_color, static_cast<int>(textColor));
}

/// <summary>
/// Function to reset text color back to default (light gray)
/// </summary>
void ResetTextColor() {
	SetColor(TEXTCOLOR::LIGHT_GRAY);
}