#pragma once
#include <iostream>
using namespace std;

// security = 0, network = 1, software = 2
enum DegreeProgram { SECURITY, NETWORK, SOFTWARE };
// the below string array shows the relationship between int value of DegreeProgram and index value.
// this lets us make the int value also equal to the string in the array with the int value as its index.
static const string degreeProgramStrings[] = { "SECURITY", "NETWORK", "SOFTWARE" };

// the below function will use the above relationship to convert the DegreeProgram to a string to be used to show the user
// what the degree program is in a readable way
static const string DegreeIntToString(DegreeProgram degreeProgram) {
	if (degreeProgram == 0) {
		return "SECURITY";
	}
	else if (degreeProgram == 1) {
		return "NETWORK";
	}
	else {
		return "SOFTWARE";
	}
}