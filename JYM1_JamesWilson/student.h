#ifndef STUDENTH
#define STUDENTH

#include "degree.h"
#include <string>
using namespace std;

class Student {
public:
    //Constructor
    Student(string ID, string first, string last, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram program);

    //Destructor
    ~Student();

    //Accessor functions
    string GetStudentID() const;
    string GetFirstName() const;
    string GetLastName() const;
    string GetStudentEmail() const;
    int GetStudentAge() const;
    const int* GetDaysArrayPtr() const;
    DegreeProgram GetDegreeProgram() const;

    //Mutator functions
    void SetStudentID(string inStudentID);
    void SetFirstName(string inFirstName);
    void SetLastName(string inLastName);
    void SetStudentEmail(string inStudentEmail);
    void SetStudentAge(int inStudentAge);
    void SetDaysArray(int inDays1, int inDays2, int inDays3);
    void SetDegreeProgram(DegreeProgram inDegree);

    //Print function
    void Print() const;

private:
    string studentID;
    string firstName;
    string lastName;
    string studentEmail;
    int studentAge;
    int daysArray[3];
    DegreeProgram degree;
};

#endif

