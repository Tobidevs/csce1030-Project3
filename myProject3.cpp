#include <iostream>
#include <string>
#include "getNumber.h"
#include <fstream>
#include <cstdlib>
using namespace std;

const int teacherTests = 5;
enum choices {add = 1, remove_std, display, search_std, results, quit};
ofstream stdFileOf;
ifstream stdFileIf;
// Student Struct
struct Student {
    string name;
    int stdId;
    int numOfTests;
    int* stdScore = new int[numOfTests];
    int stdAvg;
};
// Get student count
int getNumber() {
    ifstream fin;
    fin.open("student.dat");
    if (fin.fail()) {
        cout << "File error." << endl;
        exit(1);
    }
    int count = 0;
    string line;
    while(!fin.eof()) {
        getline(fin, line);
        ++count;
    }
    fin.close();
    cout << "Number of students = " << count << endl;
    return(count);
}
// Check if student file is open
void fileCheck() {
    if (!stdFileOf.is_open()) {
        cout << "Error opening the file!\n";
        exit(EXIT_FAILURE);
    } else {
        cout << "Student file opened.\n";
    }
}
// Add student to file
void add_student() {
    stdFileOf.open("student.dat", ios::app);
    fileCheck();
    Student tempStudent;
    string tempFirstName;
    string tempLastName;

    // get values from user
    cout << "Enter student first name: ";
    cin >> tempFirstName;
    cout << "Enter student last name: ";
    cin >> tempLastName;
    cout << "Enter Student ID: ";
    cin >> tempStudent.stdId;
    cout << "Enter number of tests taken by the student: ";
    cin >> tempStudent.numOfTests;
    printf("Enter tests scores of the student \n");
    for (int i = 0; i < tempStudent.numOfTests; ++i) {
        cout << "Enter Score " << (i + 1) << ": ";
        cin >> tempStudent.stdScore[i];
    }
    // write all the values into student.dat
    stdFileOf << tempFirstName << "," << tempLastName << ",";
    stdFileOf << tempStudent.stdId << "," << tempStudent.numOfTests << ",";
    for (int i = 0; i < tempStudent.numOfTests; ++i) {
        stdFileOf << tempStudent.stdScore[i] << ",";
    }
    cout << "Student instance created. Exiting...\n";
    stdFileOf.close();
}
// Remove student from file
void remove_student(int stdID) {
    int numOfStudents = getNumber();
    Student tempStudent[numOfStudents];
    Student* studentarr = new Student[numOfStudents];
    string lastName, firstName;
    int studentID, numOfGrades;
    stdFileIf.open("student.dat");

    // Read file
    for (int i = 0; i < numOfStudents; i++) {
        getline(stdFileIf, firstName, ',');
        getline(stdFileIf, lastName, ',');
        stdFileIf >> tempStudent[i].stdId;
        stdFileIf.ignore();
        stdFileIf >> tempStudent[i].numOfTests;
        stdFileIf.ignore();
        for (int j = 0; j < tempStudent[i].numOfTests; ++j) {
            stdFileIf >> tempStudent[i].stdScore[j];
            stdFileIf.ignore();
        }
        
    }
    stdFileIf.close();
}

int main() {
    int userInt;
    int userId;
    bool menuRepeat = true; 

    while (menuRepeat) {

        // Display menu
        printf("\n---------------- Student Database ----------------\n\n");
        printf("1. Add a new student record\n");
        printf("2. Remove an existing student record\n");
        printf("3. Display all records\n");
        printf("4. Search for student using Student ID\n");
        printf("5. Export the results to a disk file\n");
        printf("6. Quit the program\n");
        printf("Enter choice: ");
        scanf("%d", &userInt);

        // Display menu functionality
        switch (userInt) {
            case add: {
                add_student();
                break;
            }
            case remove_std: {
                cout << "Enter the Student ID: ";
                cin >> userId;
                remove_student(userId);
                break;
            }
            case display: {
                // Placeholder for display functionality
                cout << "Display all records functionality\n";
                break;
            }
            case search_std: {
                cout << "Enter the Student ID: ";
                cin >> userId; // Use cin for input
                // Placeholder for search functionality
                cout << "Search student functionality\n";
                break;
            }
            case results: {
                // Placeholder for exportResults functionality
                cout << "Export results functionality\n";
                break;
            }
            case quit: {
                cout << "Goodbye!\n";
                menuRepeat = false; // Exit the loop
                break;
            }
            default: {
                cout << "Invalid Response! Please try again.\n";
                break;
            }
        }
    }

    return 0;
}