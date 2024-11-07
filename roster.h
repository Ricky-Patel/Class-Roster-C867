#pragma once
#include "student.h"

class Roster {
private:
	int finalIndex = -1;
	const static int numberOfStudents = 5;



public:
	Student* classRosterArray[numberOfStudents]; // and array of student objects saved after parsing through the studentData
	void parse(string studentData); // used to break up the studentData into the classRosterArray

	// add is used to add student objects to the Roster
	void add(string studentId, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);

	void remove(string studentId); // removes the student with the studentId that is passed in
	void printAll(); //prints all the student data in the Roster
	void printAverageDaysInCourse(string studentId); // prints the avg days in course for the student Id that is passed in
	void printInvalidEmails(); // prints invalid emails that do not contain "@", ".", or DO contain a space
	void printByDegreeProgram(DegreeProgram); // prints students with the same degree program

	~Roster(); // destructor
	// NOTE: since we are not specifying a parameterless constructor one will be provided for us. 
	// we do not need to specify a parameterless constructor unless we specify a contructor with a parameter.
	// Roster will be created with the parameterless constructor then use the add function to add the data to it. 

};