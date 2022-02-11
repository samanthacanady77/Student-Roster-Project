#pragma once
#include "students.h"

/* Roster class, Requirement E */

class Roster
{
public:

	int lastIndex = -1;
	static const int numStudents = 5;

	/* array of pointers called Class Roster Array, Requirement E,2 */


	Student* classRosterArray[numStudents];

	void parse(string row);

	/* sets the instance variables from part D1 and updates the roster, Requirement E, 3, a */
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeP);

	/* removes students by student ID, Requirement E, 3, b */
	void remove(string studentID);

	/* prints everything, Requirement E, 3, c */

	void printAll();

	/* prints average days in course, Requirement E, 3, d */
	void printAverageDaysInCourse(string studentID);

	/*verifies emails, prints invalid ones, Requirement E, 3, e */
	void printInvalidEmails();

	/* prints by enumerated data type, Requirement E, 3, f */
	void printByDegreeProgram(DegreeProgram degreeP);


};