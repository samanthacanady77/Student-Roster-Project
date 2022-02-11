#include "students.h"

/* Student class, Requirement D */

/* parameterless constructor, Requirement D,2,d */

Student::Student() {

	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	for (int i = 0; i < daysCoursesArraySize; i++) {
		this->daysToCompleteCourses[i] = 0;
	}
	/* does this work? */

	this->degreeProgram = SECURITY;

}

/* constructor Requirement D,2,d */

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysToCompleteCourses[], DegreeProgram degreeProgram) {

	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < daysCoursesArraySize; i++)
		this->daysToCompleteCourses[i] = 0;
	this->degreeProgram = degreeProgram;

}
/* not yet defined destructor */

Student::~Student() {}

/* getters, Requirement D,2,a */

string Student::getStudentID() { return this->studentID; }
string Student::getFirstName() { return this->firstName; }
string Student::getLastName() { return this->lastName; }
string Student::getEmailAddress() { return this->emailAddress; }
int Student::getAge() { return this->age; }
int* Student::getDaysToCompleteCourses() { return this->daysToCompleteCourses; }
DegreeProgram Student::getDegreeProgram() { return this->degreeProgram; }

/* setters, Requirement D,2,b */

void Student::setStudentID(string studentID) { this->studentID = studentID; }
void Student::setFirstName(string firstName) { this->firstName = firstName; }
void Student::setLastName(string lastName) { this->lastName = lastName; }
void Student::setEmailAddress(string emailAddress) { this->emailAddress = emailAddress; }
void Student::setAge(int age) { this->age = age; }
void Student::setDaysToCompleteCourses(int daysToCompleteCourses[]) {

	for (int i = 0; i < daysCoursesArraySize; i++) {

		this->daysToCompleteCourses[i] = daysToCompleteCourses[i];

	}
}
void Student::setDegreeProgram(DegreeProgram degreeP) { this->degreeProgram = degreeP; }


/* print functionality, Requirement D,2,e */

void Student::print() {

	cout << this->getStudentID() << ", ";
	cout << this->getFirstName() << ", ";
	cout << this->getLastName() << ", ";
	cout << this->getEmailAddress() << ", ";
	cout << this->getAge() << ", ";
	cout << this->getDaysToCompleteCourses()[0] << ", ";
	cout << this->getDaysToCompleteCourses()[1] << ", ";
	cout << this->getDaysToCompleteCourses()[2] << " ";
	/* check this to make sure it works!!!!!*/
	cout << degreeProgramsArray[this->getDegreeProgram()];
	cout << "\n ";
}