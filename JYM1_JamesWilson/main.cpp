#include "degree.h"
#include "student.h"
#include "roster.h"
#include <iostream>
#include <string>
using namespace std;

int main() {

	const unsigned int NUM_STUDENTS = 5;
	int age, daysArray[3], start, comma, i;
	string ID, first, last, email, stringToInt;
	string degreeProgramStrings[] = { "SECURITY", "NETWORK", "SOFTWARE" };
	Roster classRoster;
	DegreeProgram program;
	DegreeProgram SECURITY = DegreeProgram::SECURITY;
	DegreeProgram NETWORK = DegreeProgram::NETWORK;
	DegreeProgram SOFTWARE = DegreeProgram::SOFTWARE;
	const string studentData[NUM_STUDENTS] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,James,Wilson,jwi3581@wgu.edu,25,14,32,60,SOFTWARE"
	};

	//Parse out student information and populate classRosterArray with pointers to student objects
	for (i = 0; i < NUM_STUDENTS; ++i) {
		//Parse ID
		start = 0;
		comma = studentData[i].find(',', start);
		ID = studentData[i].substr(start, comma - start);
		start = comma + 1;

		//Parse first name
		comma = studentData[i].find(',', start);
		first = studentData[i].substr(start, comma - start);
		start = comma + 1;

		//Parse last name
		comma = studentData[i].find(',', start);
		last = studentData[i].substr(start, comma - start);
		start = comma + 1;

		//Parse email
		comma = studentData[i].find(',', start);
		email = studentData[i].substr(start, comma - start);
		start = comma + 1;

		//Parse age
		comma = studentData[i].find(',', start);
		stringToInt = studentData[i].substr(start, comma - start);
		age = std::stoi(stringToInt);
		start = comma + 1;

		//Parse array of days
		comma = studentData[i].find(',', start);
		stringToInt = studentData[i].substr(start, comma - start);
		daysArray[0] = std::stoi(stringToInt);
		start = comma + 1;
		comma = studentData[i].find(',', start);
		stringToInt = studentData[i].substr(start, comma - start);
		daysArray[1] = std::stoi(stringToInt);
		start = comma + 1;
		comma = studentData[i].find(',', start);
		stringToInt = studentData[i].substr(start, comma - start);
		daysArray[2] = std::stoi(stringToInt);
		start = comma + 1;

		//Parse degree program
		stringToInt = studentData[i].substr(start, studentData[i].length() - start);
		for (int d = 0; d < 3; ++d) {
			if (stringToInt == degreeProgramStrings[d]) {
				program = static_cast<DegreeProgram>(d);
			}
		}
		//Add student to classRosterArray
		classRoster.add(ID, first, last, email, age, daysArray[0], daysArray[1], daysArray[2], program);
	}

	cout << "Course Title: Scripting and Programming - Applications - C867" << endl;
	cout << "Programming Language Used: C++" << endl;
	cout << "WGU Student ID: 006688775" << endl;
	cout << "Name: James Wilson\n\n";

	classRoster.printAll();
	classRoster.printInvalidEmails();
	for (i = 0; i < classRoster.studentCounter; ++i) {
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->GetStudentID());
	}
	classRoster.printByDegreeProgram(SOFTWARE);
	classRoster.remove("A3");
	classRoster.printAll();
	classRoster.remove("A3");
}