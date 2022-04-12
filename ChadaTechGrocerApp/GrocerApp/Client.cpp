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



int main() {

	/// <summary>
	/// Set filenames as a string
	/// </summary>
	/// <returns></returns>
	string pythonScript{ "Client" };
	string frequencyFile("frequency.dat");


	/// <summary>
	/// Create a controller object to control the application
	/// </summary>
	/// <returns></returns>
	Controller controller = Controller(pythonScript, frequencyFile);

	/// <summary>
	/// Call the run method of controller to operate the program
	/// </summary>
	/// <returns></returns>
	controller.run();


	std::cin.get();

}





