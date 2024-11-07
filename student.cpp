#include <iostream>
#include <string>
#include "student.h"

using namespace std;

Student::Student() {
	this->studentId = "";
	this->firstName = "";
	this->lastName = "";
	this->email = "";
	this->age = 0;
	for (int i = 0; i < 3; i++) this->daysToCompleteCourse[i] = 0;
	this->degreeProgram = DegreeProgram::NETWORK;
}

Student::Student(string studentId, string firstName, string lastName, string email, int age, int daysToCompleteCourse[], DegreeProgram degreeProgram) {
	this->studentId = studentId;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	for (int i = 0; i < 3; i++) this->daysToCompleteCourse[i] = daysToCompleteCourse[i];
	this->degreeProgram = degreeProgram;
}

Student::~Student() {
	// we are not dynamically allocating any memory here.
	// The daysToCompleteCourse array was given a fixed size of 3 so there is no need for a destructor.
} 

//getter functions: each of the below functions lets us access the private student data but only through use of the function
string Student::getStudentId() {
	return this->studentId;
}

string Student::getFirstName() {
	return this->firstName;
}

string Student::getLastName() {
	return this->lastName;
}

string Student::getEmail() {
	return this->email;
}

int Student::getAge() {
	return this->age;
}

int* Student::getDaysToCompleteCourse() {
	return this->daysToCompleteCourse;
}

DegreeProgram Student::getDegreeProgram() {
	return degreeProgram;
}

//setters: the below functions let us set the data for the private student data

void Student::setStudentId(string studentId) {
	this->studentId = studentId;
}

void Student::setFirstName(string firstName) {
	this->firstName = firstName;
}

void Student::setLastName(string lastName) {
	this->lastName = lastName;
}

void Student::setEmail(string email) {
	this->email = email;
}

void Student::setAge(int age) {
	this->age = age;
}

void Student::setDaysToCompleteCourse(int daysToCompleteCourse[]) {
	for (int i = 0; i < 3; i++) this->daysToCompleteCourse[i] = daysToCompleteCourse[i];
}

void Student::setDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
}

void Student::print() {
	// this function will be called to print student data. 
	// getter functions are used so the user is not directly accessing the private student data
	cout << this->getStudentId(); cout << "\t";
	cout << this->getFirstName(); cout << "\t";
	cout << this->getLastName(); cout << "\t";
	cout << this->getAge(); cout << "\t";
	cout << "{" << this->daysToCompleteCourse[0]; cout << ", ";
	cout << this->daysToCompleteCourse[1]; cout << ", ";
	cout << this->daysToCompleteCourse[2]; cout << "}\t";
	cout << DegreeIntToString(this->degreeProgram); cout << endl;

}

