Molecules2
===========

In this task, you are going to write a program that conducts analysis on a large input data set. The problem is defined as follows. In an experiment a beam of molecules is observed along a straight line.

The information recorded for each molecule in the experiment include:
position a double which represent its distance from the original in nm (nanometer) speed a double in m/s (meter per second) Energy energy that it carries in mj (micro joule) fingerprint a sequence of 8 characters from the set {a-z, A-Z, 0-9} which identifies a molecules. Note that due to accuracy issue of the experiment setup, two molecules may be observed at the same position.
The data to be processed could be huge (more than 10 millions) and thus you have to use a binary search tree as the underlying data structure.
Experimental Error: It is discovered that each molecule can be identified by a sequence of 8 characters (e.g. ACACDDEF) and that no two molecules should have the same fingerprint (just like human beings). However, in the experiment, the machine in the laboratory may produce
data of molecules of the same fingerprint. The researchers thus conclude that the machine is not 100% accurate. To prevent the experiment result from being affected, the data of molecules of the same fingerprint has to be discarded before a report is generated.
Definition 1: A molecule is lonely if there is no adjacent molecules that is within 100 nm.
Your task is to report information related to lonely molecules in the experiment. Remember, the report generated should depend on the molecules that have unique fingerprint. That is, your program should ignore all the input data the contains the same fingerprint.

A Sample data file is given below
#
23.6
3.3
28
ABCDABCD
34.5
2.4
22
ABCD1234
1230.6
3.3
28
ABCD1234
450.5
2.4
22
ABCD1234
#

All data file starts with a symbol # and ends with another symbol #. In the above file, information of 4 molecules are recorded. For example, the first molecule is at the position 23.6 nm with a speed of 3.3 ms and energy of 28 mj. The fingerprint of the first molecule
is ABCDABCD. Since the second, third and fourth molecules share the same fingerprint; they should not be used in the report generation. Thus, the first molecule will be regarded as a lonely molecule. (Since the second molecule will not be used in the report generation.)

Your program contains the following user interface.
I Import data from a data file. Prompt the user for the name of a file for import.
N Display the number of molecules imported (including those that are to be
discarded)
R Generate a report to the display. A report contains the following information:
1. total number of molecules (excluding those that have been discarded)
2. number of lonely molecules
3. average speed of the lonely molecules
4. average energy of the lonely molecules
q quit the program

There is no upper limit on the total number of molecules. The user may repeatedly import the same or different data files before issuing the command R. The user could also issue command R before and after importing another file. You can safely assume all the files are error-free.

All commands are case sensitive. If the user enters an invalid input, your system should prompt the user to re-enter. You can assume the user will never enter anything longer than 100 characters.