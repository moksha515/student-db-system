/*
This program collects user data like the students name, the courses they have taken the 
past semester and the grade for each class, and calculates their semester GPA. 

Agenda :
- ask for target GPA & calculate grades to get to target --> display GPA --> ask for target GPA --> display all Grades  -> display grades for target GPA 
*/
  

#include <fstream>
#include <iostream>
#include <iomanip>
#include <cctype>
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
    string courseGrade;
    
    ofstream outputFile;

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
    string grades [GRADES_LENGTH];
    
    
    
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
        
        outputFile << setw (12) << "Course Name:\t";
        outputFile << setw(16) << "Course Credits: \t"; 
        outputFile << setw(14) << "Course Grade: " << "\n";
        

        int i = 0;
        
        while (numCourses > i)
        {
            cout << "\nPlease enter your Course Name : ";
            getline(cin, courseName);

            
            
            cout << "\nPlease enter how many credits the Course is : ";
            cin >> numCredits;
            
            totalCredits += numCredits;
            
            cin.ignore(1000, '\n');
            

            
            
            cout << "\nPlease enter the grade you got in that course ( as a Letter : A- / B+, etc): ";
            getline (cin, courseGrade);
            
            char baseGrade = courseGrade[0];
            

            switch (baseGrade)
            {
                case 'A' : 
                    qualityPts = 4.0;
                    break;
                case 'B' :
                    qualityPts = 3.0;
                    break;
                case 'C' :
                    qualityPts = 2.0;
                    break;
                case 'D' : 
                    qualityPts = 1.0;
                    break;
                case 'F' : 
                    qualityPts = 0.0;
                    break;
                default : 
                    cout << "Please re-enter grade as a letter from A-F ";
                    cout << "\nPlease enter the grade you got in that course : ";
                    cin >> courseGrade;
            }

            if (courseGrade.length() > 1)
            {
                char modifier = courseGrade[courseGrade.length()-1];
                if (modifier == '+')
                {
                    qualityPts += 0.3;
                }
                else if ( modifier == '-')
                {
                    qualityPts -= 0.3;
                }
            }


            
            sumQualityPts += (numCredits * qualityPts);
            
            
            // This clears the newline character so the next getline() works correctly
            //cin.ignore(1000, '\n');
            
            
            outputFile << setw(9) << courseName << "\t";
            outputFile << setw(12) << numCredits << "\t\t";
            outputFile << setw(11) << courseGrade << "\n";
            
            
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
            cout << grades [g] << " ";
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
    
    return 0;
}

//new functions 