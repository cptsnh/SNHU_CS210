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


#pragma warning(disable:4996)

#ifndef GROCERAPP_MYPYFUNCTIONS_H
#define GROCERAPP_MYPYFUNCTIONS_H


#include <Python.h>
#include<string>


using std::string;

class MyPyFunctions {
private:
	MyPyFunctions() {}

public:
	static void CallProcedure(string fName, string pName);
	static int CallIntFunc(string fName, string proc, string param);
	//static int CallIntFunc(string proc, int param);


};


void MyPyFunctions::CallProcedure(string fName, string pName)
{

	char* filename = new char[fName.length() + 1];
	std::strcpy(filename, fName.c_str());

	char* procname = new char[pName.length() + 1];
	std::strcpy(procname, pName.c_str());

	Py_Initialize();
	PyObject* my_module = PyImport_ImportModule(filename);
	PyErr_Print();
	PyObject* my_function = PyObject_GetAttrString(my_module, procname);
	PyObject* my_result = PyObject_CallObject(my_function, NULL);
	Py_Finalize();

	delete[] procname;
	delete[] filename;
}



int MyPyFunctions::CallIntFunc(string fName, string proc, string param)
{
	char* filename = new char[fName.length() + 1];
	std::strcpy(filename, fName.c_str());

	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	char* paramval = new char[param.length() + 1];
	std::strcpy(paramval, param.c_str());


	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)filename);
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(z)", paramval);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;
	delete[] paramval;
	delete[] filename;

	return _PyLong_AsInt(presult);
}

//
//int MyPyFunctions::CallIntFunc(string proc, int param)
//{
//	char* procname = new char[proc.length() + 1];
//	std::strcpy(procname, proc.c_str());
//
//	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
//	// Initialize the Python Interpreter
//	Py_Initialize();
//	// Build the name object
//	pName = PyUnicode_FromString((char*)"PythonCode");
//	// Load the module object
//	pModule = PyImport_Import(pName);
//	// pDict is a borrowed reference 
//	pDict = PyModule_GetDict(pModule);
//	// pFunc is also a borrowed reference 
//	pFunc = PyDict_GetItemString(pDict, procname);
//	if (PyCallable_Check(pFunc))
//	{
//		pValue = Py_BuildValue("(i)", param);
//		PyErr_Print();
//		presult = PyObject_CallObject(pFunc, pValue);
//		PyErr_Print();
//	}
//	else
//	{
//		PyErr_Print();
//	}
//	//printf("Result is %d\n", _PyLong_AsInt(presult));
//	Py_DECREF(pValue);
//	// Clean up
//	Py_DECREF(pModule);
//	Py_DECREF(pName);
//	// Finish the Python Interpreter
//	Py_Finalize();
//
//	// clean 
//	delete[] procname;
//
//	return _PyLong_AsInt(presult);
//}


#endif GROCERAPP_MYPYFUNCTIONS_H

