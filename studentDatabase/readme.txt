Student Database Management System in C
=======================================

Overview:
---------
This application manages student records, providing options to add, edit, delete, search, display, and save records.
The database is persistent, ensuring that data is retained between sessions using file handling.

---------------------------------------
1. Compilation:
   Use the following command to compile the program:
     - On Windows: `mingw32-make`
     - On Linux: `make`

2. Execution:
   Run the application after compilation:
     $ ./student_DB

---------------------------------------
3. Menu Options:
   Upon execution, the application provides the following options:

   a/A: Add a New Student Record
     - Add a student with the following details:
         * Student ID (e.g., V24HE2A1)
         * Name
         * Date of Birth (DOB)
         * Percentage (Matriculation, Inter/Diploma, Graduation)
         * Contact Number
         * Email ID
     - Note: Duplicate Student IDs are not allowed.

   p/P: Print Records
     - Display all the student records currently in the database.

   s/S: Save the Database
     - Save the current records to a file (`student_DB.txt`).

   d/D: Delete a Record
     - Delete a specific record using the Student ID.

   e/E: Edit a Record
     - Modify details of an existing record via the following sub-menu:
         1. Edit Name
         2. Edit Date of Birth
         3. Edit Percentage
         4. Edit Contact Number
         5. Edit Email ID
         6. Display Updated Data.

   f/F: Find a Student
     - Search for a student by ID, Name, or other attributes.

   r/R: Reverse Records
     - Reverse the order of currently displayed records without altering the database file.

   q/Q: Quit
     - Exit the application. All data is automatically saved to the file.

---------------------------------------
4. File Handling:
   - All records are stored in `student_DB.txt`.
   - The database is loaded into memory upon program startup and saved back to the file during exit.

---------------------------------------
5. Features and Implementation:
   - Dynamic Memory Allocation:
       * Student records are managed efficiently using `malloc()` and `free()`.
   - File Operations:
       * Functions like `save()` and `syncFile()` handle saving and synchronizing the in-memory database with the file.
   - Error Handling:
       * The application prevents duplicate Student IDs and validates input for data integrity.
   - Modular Design:
       * Each functionality (e.g., add, edit, delete) is implemented in a separate source file, ensuring clean and maintainable code.

---------------------------------------
6. Cleanup:
   - To remove compiled files and reset the build environment, run:
       $ mingw32-make clean

---------------------------------------
7. Folder Structure:
   v24he2M14/
   ├── edit/
   │   ├── edit.c               // Functions to edit student records.
   │   ├── myEditLib.c          // Additional utility functions for editing records.
   │   ├── edit.h               // Header file with declarations for editing functions.
   ├── input/
   │   ├── input.c              // Functions for handling input from the user.
   │   ├── input.h              // Header file with declarations for input functions.
   ├── delete/
   │   ├── delete.c             // Functions to delete student records from the database.
   │   ├── delete.h             // Header file with declarations for delete functions.
   ├── file_operations/
   │   ├── save.c               // Functions to save the current database to a file.
   │   ├── syncFile.c           // Functions to load existing data from the file.
   │   ├── file.h               // Header file for file operations.
   ├── find/
   │   ├── find.c               // Functions to search for specific student records.
   │   ├── find.h               // Header file with declarations for search functions.
   ├── print/
   │   ├── print.c              // Functions to display student records.
   │   ├── print.h              // Header file for printing-related functions.
   ├── mylib/
   │   ├── myLib.c              // General utility functions for the project (e.g., validation).
   │   ├── myLib.h              // Centralized header file with global structures and macros for utility functions.
   ├── reverse/
   │   ├── reverse.c            // Functions to reverse the order of records in the current display.
   │   ├── reverse.h            // Header file for reverse-related functions.
   │
   ├── main.c                   // Main program handling menu and function calls.
   ├── main.h                   // Header file with shared declarations for `main.c`.
   ├── readme.txt               // Documentation explaining how to compile, execute, and use the app.
   ├── student_DB.txt           // Persistent storage for student records between sessions.
   └── Makefile                 // Build automation using `make`.

---------------------------------------
8. Example Usage:
   - Adding a New Student Record:
    
    a/A: Add a new student record
    ...
    Enter your choice: a
   
     - Add a student with the following details:
         * Enter Student ID: V24HE2A1
         * Enter Name: Akash
         * Enter DOB (dd/mm/yyyy): 12/05/2001
         * Enter your birth date (Day, between 1 and 31) : 12
         * Enter your birth month (Month, between 1 and 12) : 05
         * Enter your birth year (e.g., 1999) : 
         * Enter Marks (Matriculation, Inter, Graduation): 85.5 87.0 78.5
         * Enter your SSC percentage :  85.50
         * Enter your diploma/Intermediate percentage :  87.51                       // Note :choose Intermediate/diploma then enter your percentage
         * Enter your degree percentage : 78.00
         * Enter your 10-digit contact number: 9876543210
         * Enter Email ID: akash@example.com
     - Note: Student ID is automatically created.
   - Record added successfully.

---------------------------------------
9. Notes for Linux Users:
   - Update the `Makefile` as follows:
     a.out : main.o edit.o input.o delete.o file_operations.o find.o reverse.o print.o mylib.o
             gcc -o a.out main.o edit.o input.o delete.o file_operations.o find.o reverse.o print.o mylib.o
     main.o : main.c
             gcc -c main.c
     edit.o : edit/edit.c
             gcc -c edit/edit.c
     input.o : input/input.c
             gcc -c input/input.c
     delete.o : delete/delete.c
             gcc -c delete/delete.c
     file_operations.o : file_operations/save.c file_operations/syncFile.c
             gcc -c file_operations/save.c file_operations/syncFile.c
     find.o : find/find.c
             gcc -c find/find.c
     reverse.o : reverse/reverse.c
             gcc -c reverse/reverse.c
     print.o : print/print.c
             gcc -c print/print.c
     mylib.o : mylib/myLib.c
             gcc -c mylib/myLib.c

   - Then, compile using:
       $ make
---------------------------------------
Enjoy using the Student Database Management System!
