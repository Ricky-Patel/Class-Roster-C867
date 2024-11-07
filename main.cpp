#include <iostream>
#include <string>
#include "roster.h"

using namespace std;

int main() {

	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Ricky,Patel,Ricky2024@gmail.com, 31,20,13,25,SOFTWARE" 
	};

	const int numStudents = 5;
	Roster classRoster;

	for (int i = 0; i < numStudents; i++) classRoster.parse(studentData[i]);


	cout << "C867-Scripting & Programming: Applications" << endl;
	cout << "Language: C++" << endl;
	cout << "Student ID: 011500144" << endl;
	cout << "Name: Ricky Patel" << endl;

	cout << "\n";

	cout << "Displaying all students:" << endl;
	classRoster.printAll();

	classRoster.printInvalidEmails();

	for (int i = 0; i < numStudents; i++) {
		string studentId = classRoster.classRosterArray[i]->getStudentId();
		classRoster.printAverageDaysInCourse(studentId);
	}

	cout << "\n";

	classRoster.printByDegreeProgram(SOFTWARE);

	cout << "Removing A3:" << endl;
	classRoster.remove("A3");

	cout << "Removing A3 again" << endl;
	classRoster.remove("A3");


	cout << "DONE." << endl;
}
