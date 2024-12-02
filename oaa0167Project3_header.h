#ifndef oaa0167PROJECT3_HEADER_H
#define oaa0167PROJECT3_HEADER_H

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <iomanip>

using namespace std;

const int teacherTests = 5;
enum choices {add = 1, remove_std, display, search_std, results, quit};
extern ofstream stdFileOf; // Declare extern for global file objects
extern ifstream stdFileIf;

struct Student {
    string name;
    int stdId;
    int numOfTests;
    int* stdScore;
    double stdAvg;
};

// Function declarations
int getNumber();
int find_minimum(int stdarr[], int numOfTests);
void fileCheck();
void add_student();
void remove_student(int stdID);
void display_student();
void search_students(int stdID);
void export_results();

#endif // EUIDPROJECT3_HEADER_H
