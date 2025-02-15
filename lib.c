#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_BORROWS 100

// Structure for Book Information
typedef struct {
    int book_id;
    char title[50];
    char author[50];
    int is_borrowed; // 0 - Available, 1 - Borrowed
    char borrowed_by[50]; // Student Name
} Book;

// Structure to Store Borrow History
typedef struct {
    char student_name[50];
    int book_id;
    int is_returned; // 0 - Borrowed, 1 - Returned
} BorrowRecord;

// Global Variables
Book library[MAX_BOOKS];
BorrowRecord borrow_history[MAX_BORROWS];
int book_count = 0, borrow_count = 0;

// Function to Add a Book (Librarian)
void addBook() {
    if (book_count < MAX_BOOKS) {
        printf("Enter Book ID: ");
        scanf("%d", &library[book_count].book_id);
        printf("Enter Book Title: ");
        scanf(" %[^\n]", library[book_count].title);
        printf("Enter Author Name: ");
        scanf(" %[^\n]", library[book_count].author);
        library[book_count].is_borrowed = 0;
        strcpy(library[book_count].borrowed_by, "None");
        book_count++;
        printf("Book Added Successfully!\n");
    } else {
        printf("Library is Full!\n");
    }
}

// Function to Borrow a Book (Student)
void borrowBook(char student_name[]) {
    int book_id, i;
    printf("Enter Book ID to Borrow: ");
    scanf("%d", &book_id);

    for (i = 0; i < book_count; i++) {
        if (library[i].book_id == book_id && library[i].is_borrowed == 0) {
            library[i].is_borrowed = 1;
            strcpy(library[i].borrowed_by, student_name);
            
            // Store in Borrow History
            strcpy(borrow_history[borrow_count].student_name, student_name);
            borrow_history[borrow_count].book_id = book_id;
            borrow_history[borrow_count].is_returned = 0;
            borrow_count++;

            printf("Book Borrowed Successfully!\n");
            return;
        }
    }
    printf("Book Not Available!\n");
}

// Function to Return a Book (Student)
void returnBook(char student_name[]) {
    int book_id, i;
    printf("Enter Book ID to Return: ");
    scanf("%d", &book_id);

    for (i = 0; i < book_count; i++) {
        if (library[i].book_id == book_id && library[i].is_borrowed == 1 && strcmp(library[i].borrowed_by, student_name) == 0) {
            library[i].is_borrowed = 0;
            strcpy(library[i].borrowed_by, "None");

            // Update Borrow History
            for (int j = 0; j < borrow_count; j++) {
                if (borrow_history[j].book_id == book_id && strcmp(borrow_history[j].student_name, student_name) == 0) {
                    borrow_history[j].is_returned = 1;
                    break;
                }
            }

            printf("Book Returned Successfully!\n");
            return;
        }
    }
    printf("Invalid Book ID or You Didn't Borrow This Book!\n");
}

// Function to Display Books
void displayBooks() {
    printf("\nLibrary Books:\n");
    printf("ID\tTitle\t\tAuthor\t\tStatus\t\tBorrowed By\n");
    for (int i = 0; i < book_count; i++) {
        printf("%d\t%s\t%s\t%s\t%s\n", library[i].book_id, library[i].title, library[i].author, 
               library[i].is_borrowed ? "Borrowed" : "Available",
               library[i].borrowed_by);
    }
}

// Function to Display Student Borrow Status
void displayStudentStatus(char student_name[]) {
    printf("\nYour Borrow History:\n");
    printf("Book ID\tStatus\n");
    for (int i = 0; i < borrow_count; i++) {
        if (strcmp(borrow_history[i].student_name, student_name) == 0) {
            printf("%d\t%s\n", borrow_history[i].book_id, 
                   borrow_history[i].is_returned ? "Returned" : "Borrowed");
        }
    }
}

// Function to Display Borrowed Books (For Librarian)
void displayBorrowedBooks() {
    printf("\nBorrowed Books List:\n");
    printf("Book ID\tStudent Name\n");
    for (int i = 0; i < book_count; i++) {
        if (library[i].is_borrowed == 1) {
            printf("%d\t%s\n", library[i].book_id, library[i].borrowed_by);
        }
    }
}

// Librarian Login
int librarianLogin() {
    char password[20];
    printf("Enter Librarian Password: ");
    scanf("%s", password);
    if (strcmp(password, "lib123") == 0) {
        printf("Librarian Login Successful!\n");
        return 1;
    }
    printf("Incorrect Password!\n");
    return 0;
}

// Student Login (No ID Required)
void studentLogin() {
    char student_name[50];
    printf("Enter Your Name: ");
    scanf(" %[^\n]", student_name);
    printf("Welcome, %s!\n", student_name);

    int choice;
    while (1) {
        printf("\nStudent Menu\n");
        printf("1. Borrow Book\n");
        printf("2. Return Book\n");
        printf("3. Display Books\n");
        printf("4. View My Borrow Status\n");
        printf("5. Logout\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: borrowBook(student_name); break;
            case 2: returnBook(student_name); break;
            case 3: displayBooks(); break;
            case 4: displayStudentStatus(student_name); break;
            case 5: return;
            default: printf("Invalid Choice!\n");
        }
    }
}

// Main Function
int main() {
    int choice, user_type;
    
    while (1) {
        printf("\nWho are you?\n");
        printf("1. Librarian\n");
        printf("2. Student\n");
        printf("3. Exit\n");
        printf("Enter Choice: ");
        scanf("%d", &user_type);

        if (user_type == 1) {  // Librarian Section
            if (!librarianLogin()) continue;
            
            while (1) {
                printf("\nLibrarian Menu\n");
                printf("1. Add Book\n");
                printf("2. Display Books\n");
                printf("3. View Borrowed Books\n");
                printf("4. Logout\n");
                printf("Enter Choice: ");
                scanf("%d", &choice);

                switch (choice) {
                    case 1: addBook(); break;
                    case 2: displayBooks(); break;
                    case 3: displayBorrowedBooks(); break;
                    case 4: goto main_menu;
                    default: printf("Invalid Choice!\n");
                }
            }

        } else if (user_type == 2) {  // Student Section
            studentLogin(); // No ID required

        } else if (user_type == 3) {  // Exit
            printf("Exiting System. Goodbye!\n");
            return 0;
        } else {
            printf("Invalid Option! Try Again.\n");
        }

        main_menu:; // Label to return to main menu
    }

    return 0;
}
