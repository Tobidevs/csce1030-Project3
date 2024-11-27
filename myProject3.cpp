#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

const int teacherTests = 5;
enum choices {add = 1, remove_std, display, search_std, results, quit};
ofstream stdFile;

struct Student {
    string name;
    int stdId;
    int numOfTests;
    int* stdScore = new int[numOfTests];
    int stdAvg;
};

void add_student() {
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
    stdFile << tempFirstName << "," << tempLastName << ",";
    stdFile << tempStudent.stdId << "," << tempStudent.numOfTests << ",";
    for (int i = 0; i < tempStudent.numOfTests; ++i) {
        stdFile << tempStudent.stdScore[i] << ",";
    }
}

int main() {
    int userInt;
    int userId;
    bool menuRepeat = true; 
    stdFile.open("student.dat");

    while (menuRepeat) {

    // Display menu
    printf("1. Add a new student record\n");
    printf("2. Remove an existing student record\n");
    printf("3. Display all records\n");
    printf("4. Search for student using Student ID\n");
    printf("5. Export the results to a disk file\n");
    printf("6. Quit the program\n");
    printf("Enter choice: ");
    scanf("%d", &userInt);



        switch (userInt) {
            case add: {
                add_student();
                break;
            }
            case remove_std: {
                cout << "Enter the Student ID: ";
                scanf("%d", &userId); // Use cin for input
                // Placeholder for remove_student functionality
                cout << "Remove student functionality\n";
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