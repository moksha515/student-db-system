/* This program collects user data like the students name, the courses they have taken the 
past semester and the grade for each class, and calculates their semester GPA. */

#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
using namespace std;

//Tomorrow's AGENDA : 


/*
  GPA : edit to account for credits of the course
  (need to user to enter num of credits for each )
  edit so that you can get access to each 
  individual course name and course grade and can pull the value 
*/

int main()
{
    //variables
    string userName;
    string filename = "file1.txt";
    string courseName = "abc";
    
    ofstream outputFile;
    
    int courseGrade, numCourses;
    double sumOfGrades, gpa;
    
    bool choice = true;
    
    
    //opens a file, where all user information will be stored. 
    outputFile.open(filename);
    
    // user input + storing in file 
    if (outputFile)
    {
        cout << "Please enter your name : ";
        getline (cin, userName);
        outputFile << "Student Name : " << userName << "\n";
        
        while (choice)
        {
            cout << "\nPlease enter your Course Name ( or stop to finish ) : ";
            getline(cin, courseName);
            if (courseName == "stop")
            {
                break;
            }
            outputFile << "Course Name : " << courseName << "\n";
            numCourses++;
            
            
            cout << "\nPlease enter the grade you got in that course : ";
            cin >> courseGrade;
            outputFile << "Course Grade : " << courseGrade << "\n";
            
            sumOfGrades += courseGrade;
            
            // This clears the newline character so the next getline() works correctly
            cin.ignore(1000, '\n');
        }
        //calculating GPA 
        gpa = sumOfGrades / numCourses;
        outputFile << "\nSemester GPA : " << gpa << endl;
        outputFile.close();
    }
    else
    {
        cout << "Could not open file" << filename;
    }
}

