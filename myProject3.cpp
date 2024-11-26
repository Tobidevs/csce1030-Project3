#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int numOfTests = 5;
enum choices {add = 1, remove_std, display, search_std, results, quit};

struct Student {
    string name;
    int stdId;
    int*  stdScore = new int[numOfTests];
    int stdAvg;
};

int main() {
    int userInt;
    int userId;
    bool menuRepeat = true; 

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
                // Placeholder for add_student functionality
                cout << "Add student functionality\n";
                break;
            }
            case remove_std: {
                cout << "Enter the Student ID: ";
                cin >> userId; // Use cin for input
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