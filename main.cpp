#include "Roster.h"
#include <iostream>

int main()
{
	const string studentData[] =
	{
		"A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",

		/* personal information in final item of Student Data, Requirement A */

		"A5,Samantha,Canady,scana13@wgu.edu,26,20,30,35,SOFTWARE"
	};



	const int numStudents = 5;
	Roster classRoster;

	/*print all functionality*/
	for (int i = 0; i < numStudents; i++) {
		classRoster.parse(studentData[i]);

	}
	cout << "Students: " << endl;
	classRoster.printAll();
	cout << " \n ";

	/*print Invalid Emails*/

	classRoster.printInvalidEmails();
	cout << "\n ";
	/*broke
	classRoster.printAverageDaysInCourse(classRosterArray->studentID);
	*/

	/*print by degree program functional*/
	classRoster.printByDegreeProgram(SOFTWARE);
	/*removes entry and reprints, BROKE */
	classRoster.remove("A3");
	classRoster.printAll();

}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
