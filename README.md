# CPP Project
## Computer Science
## Library Management Project
## CPP and File Handling
## 2021-22

# Library Management System

## Introduction
Library Management System is a software used to manage the catalog of a library. This system helps in keeping records of books available in the library, as well as the transactions related to issuing and returning books. It provides features that assist librarians in efficiently managing library resources and serving library users.

## Features

- Keep records of books available in the library.
- Maintain records of students in the library.
- Issue books to students and prevent multiple issuances of the same book.
- Enforce one book per student at a time.
- Validate book returns by ensuring the book was issued to the same student.
- Calculate fines for late returns.
- Admin view to see a summary of book issuance and returns.
- And much more.

## System Requirements

- Hardware: Keyboard and Monitor
- Software: DEV C++

## Data Files Used

- `student.dat`: Stores the data of students (class derived datatype: `student`)
- `book.dat`: Stores the data of books (class derived datatype: `book`)
- `summary.dat`: Stores the details of issued and deposited books (class derived datatype: `summary`)

## Header Files Used

Header File | Functions Used
------------|----------------
fstream     | `open()`, `close()`, `seekg()`, `seekp()`, `tellg()`, `read()`, `write()`
iostream    | `cin`, `cout`
stdio       | `gets()`, `remove()`, `rename()`
string      | `strcpy()`, `strcmpi()`
iomanip     | `setw()`
process     | `exit()`

## Classes Used

### Student

Access Modifiers | Name       | Details
-----------------|------------|---------------------------------------
private          | sno[6]     | Student number
private          | sname[15]  | Student name
private          | sbno[5]    | Student's book name (if issued)
private          | sbid[9]    | Student's book number (if issued)
private          | status     | Student's status: 1 if issued, 0 if not
public           | student()  | Constructor
public           | istudent() | Input student's details
public           | ostudent() | Show student's details
public           | mstudent() | Modify student's details
public           | retsno()   | Get student's number
public           | retsname() | Get student's name
public           | retsbno()  | Get student's book number
public           | getsbno()  | Set student's book number
public           | getsbid()  | Set student's book ID
public           | retsbid()  | Get student's book ID
public           | retstatus()| Get student's status
public           | statuson() | Set student's status to 1
public           | statusoff()| Set student's status to 0

### Book

Access Modifiers | Name       | Details
-----------------|------------|---------------------------------------
private          | bno[5]     | Book number
private          | bname[15]  | Book name
private          | bauthor[15]| Book author's name
private          | status     | Book's status: 1 if issued, 0 if not
public           | book()     | Constructor
public           | ibook()    | Input book's details
public           | obook()    | Show book's details
public           | mbook()    | Modify book's details
public           | retbno()   | Get book's number
public           | retbname() | Get book's name
public           | retstatus()| Get book's status
public           | statuson() | Set book's status to 1
public           | statusoff()| Set book's status to 0

### Summary

Access Modifiers | Name       | Details
-----------------|------------|---------------------------------------
public           | date[9]    | Date of action (issue or deposit)
public           | desc[10]   | Description of action
public           | sno[6]     | Student's number
public           | bno[5]     | Book's number
public           | sname[15]  | Student's name
public           | bname[15]  | Book's name
