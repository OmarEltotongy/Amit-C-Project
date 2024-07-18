Here is a README file for your project:

---

# AMIT-C Programming Project

## Description

This project implements a simple student database management system using C. The system allows for adding, deleting, and retrieving student records. Each student record includes the student's ID, year, and grades for three courses.

## Author

Omar Eltoutongy

## Date

17/7/2024

## Files

1. `amit_c_project.c`: The main file that initializes the program and ensures a minimum number of students in the database before allowing further operations.
2. `SDB.c`: Contains the functions for managing the student database.
3. `SDB.h`: Header file with the declarations and definitions used in the database functions.
4. `SDB_APP.c`: The application interface allowing users to interact with the database through a menu-driven interface.
5. `STD.h`: Contains standard type definitions used throughout the project.

## Features

- **Add Entry**: Add a new student record to the database.
- **Delete Entry**: Delete a student record from the database based on student ID.
- **Read Entry**: Retrieve and display the details of a student record using the student ID.
- **List Students**: List all student IDs currently in the database.
- **Check Existence**: Check if a student ID exists in the database.
- **Database Full**: Check if the database is full.
- **Get Used Size**: Get the number of student records currently in the database.

## Functions

### `amit_c_project.c`

- `int main(void)`: Initializes the program, ensures a minimum number of students, and calls the `SDB_APP` function.

### `SDB.c`

- `bool SDB_IsFull()`: Checks if the database is full.
- `uint8 SDB_GetUsedSize()`: Returns the number of student records in the database.
- `bool SDB_AddEntry()`: Adds a new student record to the database.
- `void SDB_DeletEntry(uint32 id)`: Deletes a student record based on the student ID.
- `bool SDB_ReadEntry(uint32 id)`: Retrieves and displays the details of a student record using the student ID.
- `void SDB_GetList(uint8 * count, uint32 * list)`: Retrieves the list of all student IDs.
- `bool SDB_IsIdExist(uint32 id)`: Checks if a student ID exists in the database.

### `SDB_APP.c`

- `void SDB_APP()`: Provides a menu-driven interface for the user to interact with the database.
- `void SDB_action(uint8 choice)`: Executes the corresponding database function based on user input.

## Usage

1. Clone the repository.
2. Compile the code using a C compiler.
3. Run the executable.

### Sample Compilation and Execution

```sh
gcc amit_c_project.c SDB.c SDB_APP.c -o amit_c_project
./amit_c_project
```

Upon running the program, follow the on-screen instructions to interact with the database.

