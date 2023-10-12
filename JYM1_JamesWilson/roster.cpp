#include "roster.h"
#include <iostream>
#include <string>
using namespace std;

//Constructor
Roster::Roster() {
	studentCounter = 0;
}

//Destructor
Roster::~Roster() {
	while (studentCounter > 0) {
		this->remove(this->classRosterArray[0]->GetStudentID());
	}
}

//Add student to classRosterArray
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {
	Student* student = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeprogram);
	classRosterArray[studentCounter] = student;
	++studentCounter;
}

//Remove student from classRosterArray
void Roster::remove(string studentID) {
	bool found = false;
	int foundI;
	//Find index where studentID exists in classRosterArray
	for (int i = 0; i < studentCounter; ++i) {
		if (classRosterArray[i]->GetStudentID() == studentID) {
			found = true;
			foundI = i;
			break;
		}
	}
	//If found, starting at that index, each element of classRosterArray
	//is replaced by the element of the next highest index
	if (found) {
		if (foundI < studentCounter - 1) {
			for (int i = foundI; i < studentCounter - 1; ++i) {
				classRosterArray[i]->SetStudentID(classRosterArray[i + 1]->GetStudentID());
				classRosterArray[i]->SetFirstName(classRosterArray[i + 1]->GetFirstName());
				classRosterArray[i]->SetLastName(classRosterArray[i + 1]->GetLastName());
				classRosterArray[i]->SetStudentEmail(classRosterArray[i + 1]->GetStudentEmail());
				classRosterArray[i]->SetStudentAge(classRosterArray[i + 1]->GetStudentAge());
				classRosterArray[i]->SetDaysArray(*(classRosterArray[i + 1]->GetDaysArrayPtr()), *(classRosterArray[i + 1]->GetDaysArrayPtr() + 1), *(classRosterArray[i + 1]->GetDaysArrayPtr() + 2));
				classRosterArray[i]->SetDegreeProgram(classRosterArray[i + 1]->GetDegreeProgram());
			}
		}
		//After each element above the found index has been shifted down one,
		//the last element of classRosterArray gets deleted, and
		//studentCounter gets reduced by one.
		delete classRosterArray[studentCounter - 1];
		--studentCounter;
	}
	else {
		cout << "ERROR: Student not found\n\n";
	}
}

//Call print function for each student
void Roster::printAll() {
	for (int i = 0; i < studentCounter; ++i) {
		classRosterArray[i]->Print();
	}
	cout << endl;
}

//Print an individual student's average course length
void Roster::printAverageDaysInCourse(string studentID) {
	bool found = false;
	int foundI;
	//Find index where studentID exists in classRosterArray
	for (int i = 0; i < studentCounter; ++i) {
		if (classRosterArray[i]->GetStudentID() == studentID) {
			found = true;
			foundI = i;
			break;
		}
	}
	if (found) {
		int average = (*(classRosterArray[foundI]->GetDaysArrayPtr()) + *(classRosterArray[foundI]->GetDaysArrayPtr() + 1) + *(classRosterArray[foundI]->GetDaysArrayPtr() + 2)) / 3;
		cout << "Average course length for " << classRosterArray[foundI]->GetFirstName() << " " <<
			classRosterArray[foundI]->GetLastName() << ": " << average << " days\n\n";
	}
	else {
		cout << "ERROR: Student not found";
	}
}

//Print all invalid emails
void Roster::printInvalidEmails() {
	bool isValid;
	bool invalidFound = false;
	cout << "Invalid Emails: " << endl;
	//This loop searches each student's email for invalid characters and the
	//absence of necessary characters
	for (int i = 0; i < studentCounter; ++i) {
		isValid = true;
		if (classRosterArray[i]->GetStudentEmail().find('@') == string::npos || classRosterArray[i]->GetStudentEmail().find('.') == string::npos) {
			isValid = false;
		}
		if (classRosterArray[i]->GetStudentEmail().find(' ') != string::npos) {
			isValid = false;
		}
		if (isValid == false) {
			invalidFound = true;
			cout << classRosterArray[i]->GetStudentEmail() << endl;
		}
	}
	if (invalidFound == false) {
		cout << "All emails are valid." << "\n\n";
	}
	else {
		cout << endl;
	}
}

//Print the information of students in a given degree program
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	bool found = false;
	string degreeProgramStrings[] = { "SECURITY", "NETWORK", "SOFTWARE" };
	//This loop finds which degree program matches the input
	for (int d = 0; d < 3; ++d) {
		if (degreeProgram == static_cast<DegreeProgram>(d)) {
			cout << "Students in " << degreeProgramStrings[d] << ":" << endl;
			//This loop finds indices in classRosterArray of students with input degreeProgram 
			//and prints out the information of these students
			for (int i = 0; i < studentCounter; ++i) {
				if (classRosterArray[i]->GetDegreeProgram() == degreeProgram) {
					found = true;
					classRosterArray[i]->Print();
				}
			}
			if (found == false) {
				cout << "No students in " << degreeProgramStrings[d] << "\n\n";
			}
			else {
				cout << endl;
			}
		}
	}
}