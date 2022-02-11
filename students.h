#pragma once
#include "degree.h"
#include <iostream>

using namespace std;

/* Student class, Requirement D */

class Student {

public:
	const static int daysCoursesArraySize = 3;

	/* variables under Student class, Requirement D, #1 */

private:

	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysToCompleteCourses[daysCoursesArraySize];
	DegreeProgram degreeProgram;

public:

	/* getters, Requirement D,2,a */

	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getDaysToCompleteCourses();
	DegreeProgram getDegreeProgram();

	/* setters, Requirement D,2,b */

	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setDaysToCompleteCourses(int daysToCompleteCourses[]);
	void setDegreeProgram(DegreeProgram degreeP);

	/* constructors and destructor, Requirement D,2,d */

	Student();
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysToCompleteCourses[], DegreeProgram degreeProgram);
	~Student();

	/* print functionality, Requirement D,2,e */

	void print();

};

