#include "student.h"
#include <iostream>
#include <string>
using namespace std;

//Constructor
Student::Student(string ID, string first, string last, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram program) {
	studentID = ID;
	firstName = first;
	lastName = last;
	studentEmail = email;
	studentAge = age;
	daysArray[0] = daysInCourse1;
	daysArray[1] = daysInCourse2;
	daysArray[2] = daysInCourse3;
	degree = program;
}

//Destructor
Student::~Student() {
	//Destructor for the Student class is unnecessary because it does not use dynamically allocated memory
}
//Accessor functions
string Student::GetStudentID() const {
	return studentID;
}
string Student::GetFirstName() const {
	return firstName;
}
string Student::GetLastName() const {
	return lastName;
}
string Student::GetStudentEmail() const {
	return studentEmail;
}
int Student::GetStudentAge() const {
	return studentAge;
}
const int* Student::GetDaysArrayPtr() const {
	return &daysArray[0];
}
DegreeProgram Student::GetDegreeProgram() const {
	return degree;
}

//Mutator functions
void Student::SetStudentID(string inStudentID) {
	studentID = inStudentID;
}
void Student::SetFirstName(string inFirstName) {
	firstName = inFirstName;
}
void Student::SetLastName(string inLastName) {
	lastName = inLastName;
}
void Student::SetStudentEmail(string inStudentEmail) {
	studentEmail = inStudentEmail;
}
void Student::SetStudentAge(int inStudentAge) {
	studentAge = inStudentAge;
}
void Student::SetDaysArray(int inDays1, int inDays2, int inDays3) {
	daysArray[0] = inDays1;
	daysArray[1] = inDays1;
	daysArray[2] = inDays2;
}
void Student::SetDegreeProgram(DegreeProgram inDegree) {
	degree = inDegree;
}

//Print function
void Student::Print() const {
	string degreeProgramStrings[] = { "SECURITY", "NETWORK", "SOFTWARE" };
	cout << this->GetStudentID() <<
		" \t First Name: " << this->GetFirstName() <<
		" \t Last Name: " << this->GetLastName() <<
		" \t Age: " << this->GetStudentAge() <<
		" \t daysInCourse: {" << *(this->GetDaysArrayPtr()) <<
		", " << *(this->GetDaysArrayPtr() + 1) << ", " <<
		*(this->GetDaysArrayPtr() + 2) << "}" <<
		" \t Degree Program: ";
	for (int d = 0; d < 3; ++d) {
		if (this->GetDegreeProgram() == static_cast<DegreeProgram>(d)) {
			cout << degreeProgramStrings[d] << endl;
		}
	}
}