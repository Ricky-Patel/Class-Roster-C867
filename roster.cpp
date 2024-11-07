#include <iostream>
#include <string>
#include "roster.h"
using namespace std;
Roster::~Roster() {
	// this destructor is called at the end of program to release the dynamically allocated memory used by classRosterArray
	for (int i = 0; i < numberOfStudents; i++) {
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}

}
void Roster::parse(string studentData) {
	// parse through student data to break up each element/string in the studentData array into student variables

	int findComma = studentData.find(",");
	string studentId = studentData.substr(0, findComma);

	int startNextStr = findComma + 1;
	findComma = studentData.find(",", startNextStr);
	string firstName = studentData.substr(startNextStr, findComma - startNextStr);

	startNextStr = findComma + 1;
	findComma = studentData.find(",", startNextStr);
	string lastName = studentData.substr(startNextStr, findComma - startNextStr);

	startNextStr = findComma + 1;
	findComma = studentData.find(",", startNextStr);
	string email = studentData.substr(startNextStr, findComma - startNextStr);

	startNextStr = findComma + 1;
	findComma = studentData.find(",", startNextStr);
	int age = stoi(studentData.substr(startNextStr, findComma - startNextStr));

	startNextStr = findComma + 1;
	findComma = studentData.find(",", startNextStr);
	int daysInCourse1 = stoi(studentData.substr(startNextStr, findComma - startNextStr));

	startNextStr = findComma + 1;
	findComma = studentData.find(",", startNextStr);
	int daysInCourse2 = stoi(studentData.substr(startNextStr, findComma - startNextStr));

	startNextStr = findComma + 1;
	findComma = studentData.find(",", startNextStr);
	int daysInCourse3 = stoi(studentData.substr(startNextStr, findComma - startNextStr));

	startNextStr = findComma + 1;
	findComma = studentData.find(",", startNextStr);
	string degreeProgramConvert = studentData.substr(startNextStr, findComma - startNextStr);

	DegreeProgram degreeProgram = SECURITY; //intial value to be replaced below by parsed substring

	if (degreeProgramConvert == "SECURITY") {
		degreeProgram = SECURITY;
	}
	else if (degreeProgramConvert == "NETWORK") {
		degreeProgram = NETWORK;
	}
	else {
		degreeProgram = SOFTWARE;
	}

	// the below function call to add actually creates a new student object and saves it to the classRosterArray
	add(studentId, firstName, lastName, email, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);


}

void Roster::add(string studentId, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {

	int daysArray[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	//using finalIndex lets us add the student in order ++finalIndex = 0, 1, 2, 3, 4 for a total of 5 students
	classRosterArray[++finalIndex] = new Student(studentId, firstName, lastName, email, age, daysArray, degreeProgram);
}

void Roster::printAll() {
	//here we call the print function from student.cpp. the print function is using getters/accessors to print the private student data
	// Roster::finalIndex lets us control the array size and how many times we iterate. since we will be removing a student in this program
	for (int i = 0; i <= Roster::finalIndex; i++) {
		classRosterArray[i]->print();
	};
	cout << endl;
}

void Roster::printInvalidEmails() {
	//loop through all student emails to find invalid emails. print the invalid emails
	//valid emails contain @, ".", and no spaces 
	cout << "Displaying invalid emails: " << endl;
	cout << "\n";

	string email = "";
	for (int i = 0; i <= Roster::finalIndex; i++) {

		email = classRosterArray[i]->getEmail();

		bool atIsFound = email.find("@") != string::npos;
		bool periodIsFound = email.find(".") != string::npos;
		bool spaceIsFound = email.find(" ") != string::npos;

		if (!atIsFound || !periodIsFound || spaceIsFound) {
			cout << email << " is invalid." << endl;
		}
	}
	cout << endl;

}

void Roster::printAverageDaysInCourse(string studentId) {
	// we are looping through classRosterArray in main.cpp to pass the studentId string to this function
	// here we loop through classRosterArray to find the matching studentId to access the the days array and print the avg days in course
	for (int i = 0; i <= Roster::finalIndex; i++) {
		if (studentId == classRosterArray[i]->getStudentId()) {
			int day1 = classRosterArray[i]->getDaysToCompleteCourse()[0];
			int day2 = classRosterArray[i]->getDaysToCompleteCourse()[1];
			int day3 = classRosterArray[i]->getDaysToCompleteCourse()[2];

			int avgDays = (day1 + day2 + day3) / 3;

			cout << "Student ID: ";
			cout << studentId << ", " << "average days in course is: ";
			cout << avgDays << endl;
		}
	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	// prints out all students matching a specified degree program. The enum DegreeProgram is an int so we use DegreeIntToString
	// to turn the int into the correct string. we cannot print out the DegreeProgram as an enum since it will just be 0, 1, or 2
	// and not readable to the user
	cout << "Showing students in degree program: " << DegreeIntToString(degreeProgram) << endl;
	cout << "\n";
	for (int i = 0; i <= Roster::finalIndex; i++) {
		if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
			classRosterArray[i]->print();
		}
	};

	cout << "\n";
}

void Roster::remove(string studentId) {
	// here we will remove the student with the studentId that is passed
	cout << "\n";
	bool studentExists = false; // start with false since we want to make sure the student exists before doing anything
	for (int i = 0; i <= Roster::finalIndex; i++) {
		if (classRosterArray[i]->getStudentId() == studentId) {
			studentExists = true;
			if (i < numberOfStudents - 1) {
				// we can usually just swap the tail to the location where we are removing the student and pass the student to the tail
				// then decrease the finalIndex to artifically make the array smaller, but the student Ids are sorted so we have to also 
				// move the element between the student location and tail up to keep our sorted order
				// NOTE: we cannot actually make the array smaller since it is a fixed size and it is not a vector.
				// so we must hide the removed student from the user
				Student* toEndofArray = classRosterArray[i];
				Student* newEndofArray = classRosterArray[numberOfStudents - 1];
				classRosterArray[i] = classRosterArray[numberOfStudents - 2];
				classRosterArray[numberOfStudents - 2] = newEndofArray;
				classRosterArray[numberOfStudents - 1] = toEndofArray;
			}
			// this lets changes the final index of our array that is used to iterate in the above functions from 4 to 3. This lets us hide the removed 
			// student in [4]
			Roster::finalIndex--;
		}
	}
	if (studentExists) {
		this->printAll();
	}
	else {
		cout << "The student with the ID: " << studentId << " was not found." << endl;
	}
}
