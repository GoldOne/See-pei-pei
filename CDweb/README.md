CDweb
===========

The company CDWeb wants a program to maintain their warehouse inventory of CDs which
they sell by the World Wide Web. They have determined that the information required for each
CD is:
a) an identification number (a unique integer value);
b) the title (a string e.g. Are you with me);
c) the recording artist (a string e.g. The Potbelleez);
e) the duration in minutes and seconds (two non negative integer values);
f) the list price (a real number);
g) the number currently held in stock (a non-negative integer value);
h) the genre – the database only supports specified genres. These are:
Pop, Dance, R&B, Soul, Alternative, Sound Track, Spoken, Easy
Listening, Rock, Trance, Dance/ Electric & Hip Hop/Rap.
Determine a suitable struct to store such information in a program.
Once you have done that, your job is to implement this online CD store by developing the
following functionality in a program.
• Load an existing set of CD records from a text-based data file into memory. The name of
the data file should be declared as a constant in the program file. Your data file should be
named CDdata.txt.
• Display the data for a specified identification number (all information in the record).
• Add a new CD title to the database, prompting the user for all the above information (in
the above order) for the new record.
• Modifying the stock level of a title by a certain (positive or negative) change given the
identification number. A change that causes the stock level to go below zero should be
reported, but the stock level set to zero.
• Delete the inventory item from the database given a specified identification number.
• Store the current in-memory content of the database onto the same datafile in the same
format. The writing of the file should only be done if changes have been made to the
database loaded from the file.
• Display a list of all CD’s (containing all details) by a certain artist or genre. When
performing the search case can be ignored. To differentiate between the searches the user
should be asked to enter either the string artist for an artist search or genre for a
genre search. This is to be obtained before doing the actual search.
• Summarise the current inventory by listing the number of titles, titles with 0 stock, and
reporting the total retail value of the stock.
You are to use the CDsample.txt as the basis for your file structure. Do not deviate from it.
You can assume strings do not exceed more then 256 characters.
Assume that the maximum number of titles in the collection is 200.
You are to do appropriate error checking and where appropriate print error message. When
obtaining input from the keyboard for your program, if a user enters an invalid value do not retry obtaining the information – simply print an error message, return to the main menu and await the next command. Any residual data in the buffer should be cleared.
A suitable main function is available on the web site as CDmain.cpp. You are to put all your
implementation into other source files. You can have as many auxiliary source files and header
files as you like – you should think about this carefully.
Choose your own file names and function names but do not alter the operation of the main
function as your implementation will be tested with a fixed command sequence. You can
however change anything outside of main in CDmain.cpp.
An input script will be published shortly for your convenience. Suitable comments should be
added to the main program.
