#include <iostream>
#include "getNumber.h"

using namespace std;

const int numOfTests = 5;
enum choices {add = 1, remove, display, search, results, quit};

struct Student {
    string name;
    int stdId;
    int stdTests;
    int* stdScore = new int[numOfTests];
    int stdAvg;
};

int main() {

    int userInt;

    // Display menu
    printf("1. Add a new student record\n");
    printf("2. Remove an existing student record");
    printf("3. Display all records");
    printf("4. Search for student using Student ID");
    printf("5. Export the results to a disk file");
    printf("6. Quit the program");
    printf("Enter choice: ");
    scanf("%d", userInt);

    switch (userInt) {
        case add: {
            
            
        }

    }
}