/*
This program collects user data like the students name, the courses they have taken the 
past semester and the grade for each class, and calculates their semester GPA. 

    TMRW's agenda :
    - organize user info into a table ( or adjacent ) */
  


#include <fstream>
#include <iostream>
using namespace std;

const int COURSES_LENGTH = 10;
const int CREDITS_LENGTH = 10;
const int GRADES_LENGTH = 10;
        
int main()
{
    //variables
    string userName;
    string filename = "file1.txt";
    string courseName = "abc";
    
    ofstream outputFile;
    
    int courseGrade = 0;
    int numCredits = 0;
    int totalCredits = 0;
    int numCourses = 0;
    
    double sumQualityPts = 0.0;
    double gpa = 0.0;
    double qualityPts = 0.0;
    
    bool choice = true;



    //arrays will have 0 in first value, then from 1, the actual values will be there 
    string courses [COURSES_LENGTH];
    int credits [CREDITS_LENGTH] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int grades [GRADES_LENGTH] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    
    
    
    //opens a file, where all user information will be stored. 
    outputFile.open(filename);
    
    // user input + storing in file 
    if (outputFile)
    {
        cout << "Please enter your name : ";
        getline (cin, userName);
        outputFile << "Student Name : " << userName << "\n";

        cout << "Please enter the number of courses : ";
        cin >> numCourses;
        outputFile << "Number of Courses : " << numCourses << "\n";
        
        cin.ignore(1000, '\n');



        int i = 0;
        
        while (numCourses > i)
        {
            cout << "\nPlease enter your Course Name ( or stop to finish ) : ";
            getline(cin, courseName);

            outputFile << "Course Name : " << courseName << "\n";
            
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


            courses[i] = courseName;
            credits[i] = numCredits;
            grades[i] = courseGrade;
            i++;


        }
        //calculating GPA 
        gpa = sumQualityPts / totalCredits; 
        //cout << "\nQuality Points : " << sumQualityPts;
        cout << "\nTotal Credits : " << totalCredits;
        cout << "\nSemester GPA : " << gpa << endl;
        outputFile << "\nSemester GPA : " << gpa << endl;

        cout << "Credits array : ";
        // to print all of the users credit numbers 
        for (int c = 0; c < CREDITS_LENGTH; c++)
        {
            if (credits[c] != 0)
            {
                cout << credits [c] << ", ";
            }
        }

        cout << "Grades array : ";
        // To print all of the users entered grades
        for (int g = 0; g < GRADES_LENGTH; g++)
        {
            if (grades[g] != 0)
            {
                cout << grades [g] << ", ";
            }
        }
        
         cout << "Courses array : ";
         // To print all of their courses names
        for (int k = 0; k < COURSES_LENGTH; k++)
        {
            if (k < numCourses )
            {
                cout << courses[k] << " ";
            }
        }
        
        outputFile.close();
    }
    else
    {
        cout << "Could not open file" << filename;
    }
}