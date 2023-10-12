#ifndef ROSTERH
#define ROSTERH

#include <string>
#include "student.h"
using namespace std;

class Roster {
public:

    int studentCounter;
    Student* classRosterArray[5];

    //Constructor
    Roster();

    //Destructor
    ~Roster();

    //Functions
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
};

#endif
