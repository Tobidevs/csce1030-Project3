#include "oaa0167Project3_header.h"
ofstream stdFileOf; // Define the global file objects
ifstream stdFileIf;

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
// find minimum
int find_minimum (int stdarr[], int numOfTests) {
    int min = stdarr[0];
    if (numOfTests < teacherTests) {
        return 0;
    }

    // find the minimum in stdarr
    for (int i = 0; i < numOfTests; ++i) {
        if (stdarr[i] < min) {
            min = stdarr[i];
        }
    }
    return min;
}
// Check if student file is open
void fileCheck() {
    if (stdFileOf.is_open() || stdFileIf.is_open()) {
        cout << "Student file opened.\n";
    } else {
        cout << "Error opening the file!\n";
        exit(EXIT_FAILURE);
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

    tempStudent.stdScore = new int[tempStudent.numOfTests];
    for (int i = 0; i < tempStudent.numOfTests; ++i) {
        cout << "Enter Score " << (i + 1) << ": ";
        cin >> tempStudent.stdScore[i];
    }
    // write all the values into student.dat
    stdFileOf << endl << tempFirstName << "," << tempLastName << ",";
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
    bool foundMatch = false;
    Student* studentarr = new Student[numOfStudents];
    string lastName[numOfStudents];
    string firstName[numOfStudents];
    stdFileIf.open("student.dat");
    fileCheck();

    // Read file
    for (int i = 0; i < numOfStudents; ++i) {
        getline(stdFileIf, firstName[i], ',');
        getline(stdFileIf, lastName[i], ',');
        stdFileIf >> studentarr[i].stdId;
        stdFileIf.ignore();
        stdFileIf >> studentarr[i].numOfTests;
        stdFileIf.ignore();
        studentarr[i].stdScore = new int[studentarr[i].numOfTests];
        for (int j = 0; j < studentarr[i].numOfTests; ++j) {
            stdFileIf >> studentarr[i].stdScore[j];
            stdFileIf.ignore();
        }
        // save first and last name to student arr
        studentarr[i].name = firstName[i] + " " + lastName[i];

        // see if student id matches system
        if (stdID == studentarr[i].stdId) {
            foundMatch = true;
        }
    }
    stdFileIf.close();
    
    // rewrite studentarr contexts into student.dat 
    if (foundMatch) {
        stdFileOf.open("student.dat");
        fileCheck();
        for (int i = 0; i < numOfStudents; i++) {
            if (stdID != studentarr[i].stdId) {
                stdFileOf << firstName[i] << ',' << lastName[i] << ',' << studentarr[i].stdId << ',' << studentarr[i].numOfTests << ',';
                for (int j = 0; j < studentarr[i].numOfTests; j++) {
                    stdFileOf << studentarr[i].stdScore[j] << ',';
                }
            }
        }
        cout << "Successfully removed student " << stdID << ". Exiting..." << endl;
        stdFileOf.close();
    } else {
        cout << "Student ID not found in system.";
    }
    // Release allocated memory
    for (int i = 0; i < numOfStudents; i++) {
        delete[] studentarr[i].stdScore;
    }
    delete[] studentarr;
}
// display students 
void display_student() {
    stdFileIf.open("student.dat");
    fileCheck();
    int numOfStudents = getNumber();
    Student* studentarr = new Student[numOfStudents];
    string lastName[numOfStudents];
    string firstName[numOfStudents];

    // Read file
    for (int i = 0; i < numOfStudents; ++i) {
        getline(stdFileIf, lastName[i], ',');
        getline(stdFileIf, firstName[i], ',');
        stdFileIf >> studentarr[i].stdId;
        stdFileIf.ignore();
        stdFileIf >> studentarr[i].numOfTests;
        stdFileIf.ignore();
        studentarr[i].stdScore = new int[studentarr[i].numOfTests];
        for (int j = 0; j < studentarr[i].numOfTests; ++j) {
            stdFileIf >> studentarr[i].stdScore[j];
            stdFileIf.ignore();
        }
        // save first and last name to student arr
        studentarr[i].name = lastName[i] + "," + firstName[i];
    }

    // Display context of studentarr
    cout << "--------------------------------------------------\n";
    for (int i = 0; i < numOfStudents; ++i) {
        cout << setw(30) << left << studentarr[i].name;
        cout << setw(15) << left << studentarr[i].stdId;
        for (int j = 0; j < studentarr[i].numOfTests; ++j) {
            cout << setw(5) << left << studentarr[i].stdScore[j];
        }
    }
    stdFileIf.close();
    // Release allocated memory
    for (int i = 0; i < numOfStudents; i++) {
        delete[] studentarr[i].stdScore;
    }
    delete[] studentarr;
};
// search students
void search_students(int stdID) {
    stdFileIf.open("student.dat");
    fileCheck();
    int numOfStudents = getNumber();
    Student* studentPtr;
    studentPtr = new Student;
    bool foundMatch = false;
    string firstName;
    string lastName;

    for (int i = 0; i < numOfStudents; ++i) {
        getline(stdFileIf, firstName, ',');
        getline(stdFileIf, lastName, ',');
        stdFileIf >> studentPtr->stdId;
        stdFileIf.ignore();
        stdFileIf >> studentPtr->numOfTests;
        stdFileIf.ignore();
        studentPtr->stdScore = new int[studentPtr->numOfTests];
        for (int j = 0; j < studentPtr->numOfTests; ++j) {
            stdFileIf >> studentPtr->stdScore[j];
            stdFileIf.ignore();
        }
        // save first and last name to student arr
        studentPtr->name = firstName + " " + lastName;

        if (stdID == studentPtr->stdId) {
            foundMatch = true;
            cout << "--------------------------------------------------";
            cout << setw(30) << left << studentPtr->name;
            cout << setw(15) << left << studentPtr->stdId;
            for (int i = 0; i < studentPtr->numOfTests; ++i) {
                cout << setw(5) << left << studentPtr->stdScore[i];
            }
            delete[] studentPtr->stdScore;
            break;
        }

        // Free stdScore memory after each iteration
        delete[] studentPtr->stdScore;
    }

    if (!foundMatch) {
        cout << "Student not found in system.";
    }
    stdFileIf.close();
    // Release allocated memory
    delete studentPtr;
}
// Export results
void export_results() {
    stdFileIf.open("student.dat");
    fileCheck();
    int numOfStudents = getNumber();
    Student* studentarr = new Student[numOfStudents];
    string lastName[numOfStudents];
    string firstName[numOfStudents];
    int min;

    // Read file
    for (int i = 0; i < numOfStudents; ++i) {
        getline(stdFileIf, firstName[i], ',');
        getline(stdFileIf, lastName[i], ',');
        stdFileIf >> studentarr[i].stdId;
        stdFileIf.ignore();
        stdFileIf >> studentarr[i].numOfTests;
        stdFileIf.ignore();
        studentarr[i].stdScore = new int[studentarr[i].numOfTests];
        for (int j = 0; j < studentarr[i].numOfTests; ++j) {
            stdFileIf >> studentarr[i].stdScore[j];
            stdFileIf.ignore();
        }
        // save first and last name to student arr
        studentarr[i].name = firstName[i] + " " + lastName[i];
    }
    stdFileIf.close();

    stdFileOf.open("averages.dat");
    fileCheck();
    for (int i = 0; i < numOfStudents; ++i) {
        for (int j = 0; j < studentarr[i].numOfTests; ++j) {
            studentarr[i].stdAvg += studentarr[i].stdScore[j];
        }
        // find min value and adjust score if necessary
        min = find_minimum(studentarr[i].stdScore, studentarr[i].numOfTests);
        if (min != 0) {
        studentarr[i].stdAvg = (studentarr[i].stdAvg - min) / 4;
        } else { 
        studentarr[i].stdAvg /= studentarr[i].numOfTests;
        }

        stdFileOf << left;
        stdFileOf << setw(15) << studentarr[i].stdId;
        stdFileOf << setw(5) << fixed << setprecision(1) << studentarr[i].stdAvg << endl;
    }
    cout << "Results successfully exported to averages.dat.";
    stdFileOf.close();

    // Release allocated memory
    for (int i = 0; i < numOfStudents; i++) {
        delete[] studentarr[i].stdScore;
    }
    delete[] studentarr;
}