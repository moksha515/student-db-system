/*
This program collects user data like the students name, the courses they have taken the 
past semester and the grade for each class, and calculates their semester GPA. 


    in far, far future -- can put in university name && program can search up how many credits it takes and accounts
    ( so user does not have to manually input this )


    TMRW's agenda : 
    - edit so that you can get access to each 
      individual course name and course grade and can pull the value --> put all values into an array
    - organize user info into a table ( or adjacent ) */
  


#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    //variables
    string userName;
    string filename = "file1.txt";
    string courseName = "abc";
    
    ofstream outputFile;
    
    int courseGrade = 0;
    int numCourses = 0;
    int numCredits = 0;
    int totalCredits = 0;
    
    double sumQualityPts = 0.0;
    double gpa = 0.0;
    double qualityPts = 0.0;
    
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
            
            cout << "\nPlease enter how many credits the Course is : ";
            cin >> numCredits;
            outputFile << "Number of Credits : " << numCredits << "\n";
            totalCredits += numCredits;
            
            
            cout << "\nPlease enter the grade you got in that course : ";
            cin >> courseGrade;
            
            while (courseGrade > 100 || courseGrade < 0)
            {
                cout << "Please re-enter grade as a number 0 - 100. ";
                cout << "\nPlease enter the grade you got in that course : ";
                cin >> courseGrade;
            }
            
            outputFile << "Course Grade : " << courseGrade << "\n";
            
            if ( courseGrade > 89)
            {
                qualityPts = 4.0; // A 
            }
            else if ( courseGrade > 79)
            {
                qualityPts = 3.0; // B 
            }
            else if ( courseGrade > 69)
            {
                qualityPts = 2.0; // C 
            }
            else if ( courseGrade > 59)
            {
                qualityPts = 1.0; // D
            }
            else
            {
                qualityPts = 0.0; // F
            }
            
            sumQualityPts += (numCredits * qualityPts);
            
            
            // This clears the newline character so the next getline() works correctly
            cin.ignore(1000, '\n');
        }
        //calculating GPA 
        gpa = sumQualityPts / totalCredits; 
        //cout << "\nQuality Points : " << sumQualityPts;
        cout << "\nTotal Credits : " << totalCredits;
        cout << "\nSemester GPA : " << gpa << endl;
        outputFile << "\nSemester GPA : " << gpa << endl;
        
        outputFile.close();
    }
    else
    {
        cout << "Could not open file" << filename;
    }
}