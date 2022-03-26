#pragma once
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

#include <iostream>
#include <string>
#include <ctime> 
#include <chrono>
#include <memory>

using std::string;
using std::cout;
using std::shared_ptr;

// Singleton Clock datatype
class Clock {
private:

	// Time and TimeStruct variables
	std::time_t time;
	std::tm currentTime;

public:

	// Default destructor with initialization list
	Clock() : time{ std::time(0) },
		currentTime{ *(std::localtime(&time)) } {}

	// Disable all other constructors
	Clock(Clock const&) = delete;
	Clock(Clock&&) = delete;
	Clock& operator=(Clock const&) = delete;
	Clock& operator=(Clock&&) = delete;

	/// <summary>
	/// Create send a reference of the static class back to caller
	/// Ensures this is the only object being modified
	/// </summary>
	/// <returns></returns>
	static shared_ptr<Clock>& GetInstance() {
		static shared_ptr<Clock> clock(new Clock);
		return clock;
	}

	/// <summary>
	/// Accessor functions in case we need them
	/// </summary>
	/// <returns></returns>
	int Hour() { return currentTime.tm_hour; }
	int Second() { return currentTime.tm_sec; }
	int Minute() { return currentTime.tm_min; }

	/// <summary>
	/// Function to increment hours
	/// Upon reaching 24hrs, reset the counter
	/// </summary>
	void IncrementHour() {
		if (currentTime.tm_hour + 1 > 23) {
			currentTime.tm_hour = -1;
		}

		currentTime.tm_hour += 1;
	}

	/// <summary>
	/// Function to increment seconds
	/// Upon reaching 60 seconds, increment the minute variable
	/// </summary>
	void IncrementSecond() {
		if (currentTime.tm_sec + 1 > 59) {
			currentTime.tm_sec = -1;
			IncrementMinute();
		}

		currentTime.tm_sec += 1;
	}

	/// <summary>
	/// Function to increment minutes
	/// Upon reaching 60-minutes, increment the hour variable
	/// </summary>
	void IncrementMinute() {
		if (currentTime.tm_min + 1 > 59) {
			currentTime.tm_min = -1;
			IncrementHour();
		}

		currentTime.tm_min += 1;
	}

	/// <summary>
	/// Function to print time in standard 12-hour format
	/// Using strftime to format
	/// </summary>
	/// <param name="name"></param>
	string PrintStandard() {
		char standardTime[80];
		strftime(standardTime, 80, "%I:%M:%S %p", &this->currentTime);
		//	cout << "\n\n" << name << ": " << standardTime << "\n";
		return standardTime;
	}

	/// <summary>
	/// Function to print time in military 24-hour format
	/// Using strftime to format
	/// </summary>
	/// <param name="name"></param>
	string PrintMilitary() {
		char militaryTime[80];
		strftime(militaryTime, 80, "%H:%M:%S", &this->currentTime);
		return militaryTime;
	}

	// Destructor
	~Clock() {}

};

