#pragma once
#include <iostream>
#include <string>
#include "degree.h"

class Student {

private:
	string studentId;
	string firstName;
	string lastName;
	string email;
	int age;
	int daysToCompleteCourse[3];
	DegreeProgram degreeProgram;

public:
	Student(); //parameterless constructor
	~Student(); //destructor
	Student(string studentId, string firstName, string lastName, string email, int age, int daysToCompleteCourse[], DegreeProgram degreeProgram); //constructor

	// getters - accessors
	string getStudentId();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int* getDaysToCompleteCourse();
	DegreeProgram getDegreeProgram();

	//setters - mutators
	void setStudentId(string studentId);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmail(string email);
	void setAge(int age);
	void setDaysToCompleteCourse(int daysToCompleteCourse[]);
	void setDegreeProgram(DegreeProgram degreeProgram);

	void print(); //prints all the data for the student object



};
