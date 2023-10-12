# Student-Roster-Application
This is a C++ program for managing a university's student system. It reads and manipulates student data, maintaining a roster of students within a course. The program includes two classes, Student and Roster.

------------------------------ Requirements ------------------------------

Degree Enumeration:

  -Create an enumerated data type DegreeProgram for degree programs (SECURITY, NETWORK, SOFTWARE).
  

Student Class:

  -Create the Student class with variables:
  
  -Student ID
  
  -First name
  
  -Last name
  
  -Email address
  
  -Age
  
  -Array of days to complete each course
  
  -Degree program
  
  -Implement getter and setter functions for each variable.
  
  -Implement a constructor and a print function.
  
  
Roster Class:
  
  -Create a Roster class with an array to store student data.
  
  -Add student objects to the roster by parsing data.
  
  
 Implement functions:
  
  -add to add students
  
  -remove to remove students by ID
  
  -printAll to display all student data
  
  -printAverageDaysInCourse to calculate and print average days in a course by student ID
  
  -printInvalidEmails to check and display invalid email addresses
  
  -printByDegreeProgram to print students by a specified degree program.
  

Main Function:

  -Demonstrate functionality by creating a main function:
  
  -Initialize a classRoster instance.
  
  -Add students to the roster.
  
  -Print course information.
  
  -Perform various operations including printing, calculating averages, and removing students.
  
  -Implement the destructor for memory management.

------------------------------ Files ------------------------------

  -degree.h: Contains the DegreeProgram enumeration.
  
  -student.h and student.cpp: Implement the Student class.
  
  -roster.h and roster.cpp: Implement the Roster class.
  
  -main.cpp: Contains the main function to demonstrate the program.

------------------------------ Note ------------------------------

This is an educational project and does not include third-party libraries.
