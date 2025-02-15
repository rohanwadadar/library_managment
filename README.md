# Library Management System in C

## Overview
The **Library Management System** is a simple C-based project that helps manage library operations efficiently. It allows librarians to add books, and students to borrow and return books. The system is implemented using **structures** in C to store details of students, librarians, and books.

## Features
### Librarian
- Add new books to the library.
- View all books and their availability status.
- Track which books are borrowed and by whom.

### Student
- Borrow books by entering a Book ID.
- Return borrowed books.
- View the status of borrowed books.

## Functionalities
1. **User Selection:** Choose between Librarian and Student mode.
2. **Book Management:** Librarians can add books to the system.
3. **Borrowing Books:** Students can borrow books without needing an ID.
4. **Returning Books:** Students can return books, and the system updates book status accordingly.
5. **Status Tracking:**
   - If a student borrows a book, it is marked as "Borrowed by [Student Name]."
   - If a student returns a book, it is marked as "Available."
   - Librarians can view the current borrowing status of books.

## Installation & Compilation
1. Download the source code.
2. Compile using **GCC**:
   ```bash
   gcc library_management.c -o library
   ```
3. Run the program:
   ```bash
   ./library
   ```

## Code Structure
- **Structure Definitions:**
  - `Book`: Stores book details (ID, title, author, status, borrowed_by).
- **Functions:**
  - `addBook()`: Adds books to the library.
  - `borrowBook()`: Allows students to borrow books.
  - `returnBook()`: Allows students to return books.
  - `displayBooks()`: Displays book list with status.
- **Main Function:**
  - Takes user input to choose between **Librarian** and **Student**.
  - Calls respective functions based on user actions.

## Example Usage
```
Are you a:
1. Librarian
2. Student
Enter your choice: 2

Enter your name: John
Enter Book ID to Borrow: 101
Book Borrowed Successfully!

Viewing Books:
101 - "C Programming" by Dennis Ritchie (Borrowed by John)
102 - "Data Structures" by Mark Weiss (Available)
```

## Future Enhancements
- Implement a **file-based database** to save records persistently.
- Add **user authentication** for librarians.
- Implement **due date tracking** for borrowed books.

## License
This project is open-source and available for educational purposes.

## Author
- **Rohan Wadadar** | Aspiring Software Developer

