Molecules
===========

In an experiment a beam of molecules is observed along a straight line.

The information recorded for each molecule in the experiment include:
position a double which represent its distance from the original in nm (nanometer)
speed a double in ms (meter per second)
Energy energy that it carries in mj (micro joule)
Note that due to observation error, two molecules may be observed at the same position.
Definition 1: A molecule is lonely if there is no adjacent molecules that is within 100 nm.
Your task is to report information related to lonely molecules in the experiment.
A Sample data file is given below
#
23.6
3.3
28
34.5
2.4
22
1230.6
3.3
28
450.5
2.4
22
#
All data file starts with a symbol # and ends with another symbol #. In the above file,
information of 4 molecules are recorded. For example, the first molecule is at the position
23.6 with a speed of 3.3 and an energy of 28.
As another example, there are 2 molecules out of these lonely molecules out of these 4
molecules.
Your program contains the following user interface.
I Import data from a data file. Prompt the user for the name of a file for import.
N Display the number of molecules imported
R Generate a report to the display. A report contains the following information:
1. total number of molecules
2. number of lonely molecules
3. average speed of the lonely molecules
4. average energy of the lonely molecules
q quit the program

There is no upper limit on the total number of molecules. The user may repeatedly import the
same or different data files before issuing the command R. The user could also issue
command R before and after importing another file. You can safely assume all the files are
error-free.
All commands are case sensitive. If the user enters an invalid input, your system should
prompt the user to re-enter. You can assume the user will never enter anything longer than
100 characters.