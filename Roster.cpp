#pragma once
#include "Roster.h"
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

/* Roster class, Requirement E */

void Roster::parse(string studentData) {
	/* parsing all the data, Requirement E, 2, A */
	size_t rhs = studentData.find(",");
	string tempID = studentData.substr(0, rhs);

	size_t lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string tempFirstN = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string tempLastN = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string tempEmailA = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string tempAgeString = studentData.substr(lhs, rhs - lhs);
	/* converts string to int */
	int tempAge = stoi(tempAgeString);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int tempDays1 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int tempDays2 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int tempDays3 = stoi(studentData.substr(lhs, rhs - lhs));

	/* parse Degree Program information */

	DegreeProgram degreeP = DegreeProgram::SECURITY;
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string tempDegree = studentData.substr(lhs, rhs - lhs);
	if (tempDegree == "NETWORK") {
		degreeP = DegreeProgram::NETWORK;
	}
	else if (tempDegree == "SOFTWARE") {
		degreeP = DegreeProgram::SOFTWARE;
	}

	/* adds student data to Class Roster Array, Requirement E, 2, b*/
	add(tempID, tempFirstN, tempLastN, tempEmailA, tempAge, tempDays1, tempDays2, tempDays3, degreeP);
}

/* adds student data to Class Roster Array, Requirement E, 2, b*/
/* sets the instance variables from part D1 and updates the roster, Requirement E, 3, a */
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int Age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	int daysInCourseArray[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, Age, daysInCourseArray, degreeProgram);

}

/* removes students by Student ID, Requirement E, 3, b */
void Roster::remove(string studentID) {
	cout << "Removing " << studentID << "." << endl;
	for (int i = 0; i < numStudents; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			Student* tempEntry = classRosterArray[i];

		}
	}
	cout << endl;
}

/* prints tab seperated list for all students with a loop, Requirement E, 3, c*/
void Roster::printAll() {
	for (int i = 0; i <= Roster::lastIndex; i++) {
		cout << classRosterArray[i]->getStudentID(); cout << "\tFirst Name: ";
		cout << classRosterArray[i]->getFirstName(); cout << "\tLast Name: ";
		cout << classRosterArray[i]->getLastName(); cout << "\tEmail Address: ";
		cout << classRosterArray[i]->getEmailAddress(); cout << "\tAge: ";
		cout << classRosterArray[i]->getAge(); cout << "\tdaysInCourse: {";
		cout << classRosterArray[i]->getDaysToCompleteCourses()[0]; cout << ", ";
		cout << classRosterArray[i]->getDaysToCompleteCourses()[1]; cout << ", ";
		cout << classRosterArray[i]->getDaysToCompleteCourses()[2]; cout << " }\t Degree Program: ";
		cout << degreeProgramsArray[classRosterArray[i]->getDegreeProgram()] << endl;
	}
}

/* print average days in course, Requirement E, 3, D */
void Roster::printAverageDaysInCourse(string studentID) {
	for (int i = 0; i <= Roster::lastIndex; i++) {

		double firstDays = classRosterArray[i]->getDaysToCompleteCourses()[0];
		double secondDays = classRosterArray[i]->getDaysToCompleteCourses()[1];
		double thirdDays = classRosterArray[i]->getDaysToCompleteCourses()[2];
		double averageDaysInCourse = (firstDays + secondDays + thirdDays) / 3.0;

		cout << "Student ID: " << classRosterArray[i]->getStudentID() << endl;
		cout << "Average Days in Course: " << averageDaysInCourse << endl;

	}
}
/* verifies emails, prints invalid ones, Requirement E, 3, e */
void Roster::printInvalidEmails() {
	cout << "Invalid Emails: " << endl;
	for (int i = 0; i <= Roster::lastIndex; i++) {
		string invalidEmailChecker = (classRosterArray[i]->getEmailAddress());
		if (invalidEmailChecker.find('@') == string::npos || (invalidEmailChecker.find('.') == string::npos || invalidEmailChecker.find(' ') == true)) {
			cout << invalidEmailChecker << endl;

		}
	}
}
/* prints by enumerated data type, Requirement E, 3, f */

void Roster::printByDegreeProgram(DegreeProgram degreeP) {
	cout << "Print by Degree Program: " << endl;
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (Roster::classRosterArray[i]->getDegreeProgram() == degreeP) {
			classRosterArray[i]->print();
		}
	}
	cout << endl;
}


