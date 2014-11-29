Database for student
===========

In this task, you are going to develop a database program to store information related to the students of a university. Information to be stored related to a student
Each student record in the database contains the following information.
Name
at most 30 char (cannot contain the newline character, can contain anything else but not NULL)
ID
a unique identifier a positive integer of 7 digits (cannot be NULL)
Course
4 digit course code, a space, then at most 80 char
e.g. 1612 Master of Computer Studies (cannot be NULL)
List of Subjects
each subject consists of the following information:
1. year (4 digits)
2. session (one char A/S for autumn/ spring)
3. code (7 characters)
4. credit (2 digits, i.e., if the credit point is 6, it will be represented a 06)
5. Mark (0 to 100 or e or w)
e enrolled, w means withdraw
You may assume each student can be associated with at most 30 subjects
GPA
the system should be able to calculate the GPA automatically based on credit and mark of the subject list of the student
GPA is defined as:
Sum of {credit of all subjects multiplied by their scores} divided by Sum of {credits of all subjects}
All subjects here means subjects that is not of the status e and w.

A sample data file (a plain text file) is given below to illustrate the format.
The ###START### and ###END### are used to mark the starting and ending of the file, while ###RECORD### is used to illustrate the starting of a new record.

###START### 
###RECORD### 
John Ng 
1234567 
1612 Master of Computer Studies 
2012SCSCI12406w 
2013ACSCI1240644 
2013SCSCI1240699 
###RECORD### Alice Peterson 
2412347 
0790 Bachelor of Engineering - Bachelor of Computer Science 
2013ACSCI2050670 
###END###

Your database program supports the following commands (the should be shown in the first level menu)
Main Menu
Showing the current number of records
q
Quit the program
i
import data from text file
// the function asks for a file name and import all records from the file
// IF record with duplicated ID exists, your program should display the information of both records and ask the user to choose one
e
export data to text file
// the function asks for a file name and output all records to this file
// IF the file already exists, your program should ask if the user would like to overwrite the file or cancel
s
Display the search menu. Details of the search menu are described below.

You can assume the maximum size of your database is 1000. The import function will take in the maximum allowable records, return to the main menu and display the number of imported records.

Search Menu
The following commands are supported in the search menu
Showing the current number of records
r
return to main menu
n
Name search (case insensitive)
the function asks for a name (support one single wild card *) * means everything, e.g. *n means any name that ends with the letter n and that A*n means any name that starts with A and ends with n
s
Subject Search (case sensitive)
return a list of students taking the subject matching the search criteria
promote the user for year, session and code
for each input, the user can use the wild card *
g
Search by GPA, the input format is a symbol <, > or = followed by a floating point number.
for =, any result within 1 point of the specified GPA is considered a match
That is, if the user want to search for students with GPA = 5.5, it will display all students whose GPA is from 4.5 to 6.5 (inclusive)
NOTES
For command n, s and g, if the search do not return any record, your program should display ¡°no record found¡± and stay in the search menu. Otherwise, your program should show the display menu described below.

Display Menu
The following commands are supported in the search menu
Display the current record and the total number of records satisfying the search criteria
r
return to main menu
s
return to search menu
n
Go to the next record (this option is available only when the next record exists)
p
Go to the previous record (this option is available only when the previous record exists)
e
Edit the current record.
Upon completion, it shows the old and edited record and ask the user for confirmation.
After that, it returns to the search menu.
For all options, if the user just press enter, it means keeping the existing value.
If the newly entered ID is not unique, it gives an error and ask the user to re-enter the value.
d
Delete the current record.
Ask the user to confirm the deletion. If confirmed, it deletes the record and return to the main menu.

All commands are case sensitive. If the user enters an invalid input, your system should prompt the user to re-enter. You can assume the user will never enter anything longer than 100 characters
