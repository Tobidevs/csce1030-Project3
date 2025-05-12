#include "oaa0167Project3_header.h"

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
        userInt = getValidInt("Enter choice: ");
        

        // Display menu functionality
        switch (userInt) {
            case add: {
                add_student();
                break;
            }
            case remove_std: {
                userId = getValidInt("Enter the Student ID: ");
                remove_student(userId);
                break;
            }
            case display: {
                display_student();
                break;
            }
            case search_std: {
                userId = getValidInt("Enter the Student ID: ");
                search_students(userId);
                break;
            }
            case results: {
                export_results();
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
