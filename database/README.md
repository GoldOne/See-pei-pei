Database for student
===========

In this task, you are going to develop a database program to store information related to the students of a university. Information to be stored related to a student


Each student record in the database contains the following information.
<table>
<tr>
<td>Name</td><td>at most 30 char (cannot contain the newline character, can contain anything else but not NULL)</td>
</tr>
<tr>
<td>ID</td><td>a unique identifier a positive integer of 7 digits (cannot be NULL)</td></tr>
<tr>
<td>Course</td><td>4 digit course code, a space, then at most 80 char</br>
e.g. 1612 Master of Computer Studies (cannot be NULL)</td></tr>
<tr>
<td>List of Subjects</td>
<td>each subject consists of the following information:</br>
1. year (4 digits)</br>
2. session (one char A/S for autumn/ spring)</br>
3. code (7 characters)</br>
4. credit (2 digits, i.e., if the credit point is 6, it will be represented a 06)</br>
5. Mark (0 to 100 or e or w)</br>
e enrolled, w means withdraw</br>
You may assume each student can be associated with at most 30 subjects</td></tr>
<tr>
<td>GPA</td>
<td>the system should be able to calculate the GPA automatically based on credit and mark of the subject list of the student</td></tr>
</table>


GPA is defined as:


Sum of {credit of all subjects multiplied by their scores} divided by Sum of {credits of all subjects}
All subjects here means subjects that is not of the status e and w.


A sample data file (a plain text file) is given below to illustrate the format.

The ###START### and ###END### are used to mark the starting and ending of the file, while ###RECORD### is used to illustrate the starting of a new record.

![Fig](http://i11.tietuku.com/65320303ae665ff2.png)

Your database program supports the following commands (the should be shown in the first level menu)


**Main Menu**
<table>
<tr>
<td> </td><td>Showing the current number of records</td></tr>
<tr><td>q</td><td>Quit the program</td></tr>
<tr><td>i</td><td>import data from text file</br>
// the function asks for a file name and import all records from the file</br>
// IF record with duplicated ID exists, your program should display the information of both records and ask the user to choose one</td></tr>
<tr><td>e</td><td>export data to text file</br>
// the function asks for a file name and output all records to this file</br>
// IF the file already exists, your program should ask if the user would like to overwrite the file or cancel</td></tr>
<tr><td>s</td><td>Display the search menu. Details of the search menu are described below.</td></tr></table>

You can assume the maximum size of your database is 1000. The import function will take in the maximum allowable records, return to the main menu and display the number of imported records.


**Search Menu**


The following commands are supported in the search menu
<table><tr>
<td> </td><td>Showing the current number of records</td></tr>
<tr><td>r</td><td>return to main menu</td></tr>
<tr><td>n</td><td>Name search (case insensitive)</br>
the function asks for a name (support one single wild card *)</br>
* means everything, e.g. *n means any name that ends with the letter n and that A*n means any name that starts with A and ends with n</td></tr>
<tr><td>s</td><td>Subject Search (case sensitive)</br>
return a list of students taking the subject matching the search criteria</br>
promote the user for year, session and code</br>
for each input, the user can use the wild card *</td></tr>
<tr><td>g</td><td>Search by GPA, the input format is a symbol <, > or = followed by a floating point number.</br>
for =, any result within 1 point of the specified GPA is considered a match</br>
That is, if the user want to search for students with GPA = 5.5, it will display all students whose GPA is from 4.5 to 6.5 (inclusive)</td></tr>
<tr><td>NOTES</td><td>For command n, s and g, if the search do not return any record, your program should display "no record found" and stay in the search menu. Otherwise, your program should show the display menu described below.</td></tr></table>


**Display Menu**


The following commands are supported in the search menu

<table><tr>
<td> </td><td>Display the current record and the total number of records satisfying the search criteria</td></tr>
<tr><td>r</td><td>return to main menu</td></tr>
<tr><td>s</td><td>return to search menu</td></tr>
<tr><td>n</td>Go to the next record (this option is available only when the next record exists)</td></tr>
<tr><td>p</td><td>Go to the previous record (this option is available only when the previous record exists)</td></tr>
<tr><td>e</td><td>Edit the current record.</br>
Upon completion, it shows the old and edited record and ask the user for confirmation.</br>
After that, it returns to the search menu.</br>
For all options, if the user just press enter, it means keeping the existing value.</br>
If the newly entered ID is not unique, it gives an error and ask the user to re-enter the value.</td></tr>
<tr><td>d</td><td>Delete the current record.</br>
Ask the user to confirm the deletion. If confirmed, it deletes the record and return to the main menu.</td></tr></table>

All commands are case sensitive. If the user enters an invalid input, yourem should prompt the user to re-enter. You can assume the user will never enter anything longer than 100 characters


In this task, you are going to enhance the functionality of the database program in
Recall that each student record in the database contains the following information.
Name at most 30 char (cannot contain the newline character, can contain anything
else but not NULL)
ID a unique identifier a positive integer of 7 digits (cannot be NULL)
Course 4 digit course code, a space, then at most 80 char
e.g. 1612 Master of Computer Studies (cannot be NULL)
List of
Subjects
each subject consists of the following information:
1. year (4 digits)
2. session (one char A/S for autumn/ spring)
3. code (7 characters)
4. credit (2 digits, i.e., if the credit point is 6, it will be represented a 06)
5. Mark (0 to 100 or e or w)
e enrolled, w means withdraw
You may assume each student can be associated with at most 30 subjects
GPA the system should be able to calculate the GPA automatically based on
credit and mark of the subject list of the student
GPA is defined as:
(Sum of {credit of all subjects multiplied by their scores} divided by Sum of {credits of all subjects})
multiplied by 6 divided by 100
All subjects here means subjects that is not of the status e and w.
I Import from a binary file. The format of a binary file is up to your decision.
E Export to a binary file. The format of the binary file is up to your decision. The only
requirement is that it has to be compatible with the Import from a binary file function.
C Validate course information. Check for any mismatch between course code and
course name. Display the conflicting records and ask the user to choose one of the
two options:
- ignore
- all records to one of these conflicting names
O Options. Choose the order of display according to the three sort keys from the three
fields: Name, ID and GPA
Records should always be displayed according to the sort key and order.
Default option is shown below:
First Sort Key: ID , ascending
Second Sort Key: Name, ascending
Third Sort Key: GPA, descending
Remark: it means that records should be ordered according to the first sort key. If
they have the same first sort key, they are ordered according to the second sort
key… (For easy implementation, it is possible for the user to set all three sort key to
the same field)
Records should always display according to the setting in this menu.
You can assume the maximum size of the database in this program is 100.
All commands are case sensitive. If the user enters an invalid input, your system should
prompt the user to re-enter. You can assume the user will never enter anything longer than
100 characters.
