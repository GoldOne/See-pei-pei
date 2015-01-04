Disk Scheduling Algorithm
===========

Aim
The main aim of this program is to become more familiar with hard disk file system scheduling concepts. We will do this by writing a program to simulate head movement with FCFS (First Come First Served), SSTF (Shortest Seek Time First), SCAN, CSCAN (Circular SCAN), LOOK and CLOOK (Circular LOOK) Scheduling algorithms.

In class we examined various disk scheduling algorithms all of which have various advantages and disadvantages depending on load and conditions. For this assignment you are to write a program that simulates the head movement of the hard disk with different disk scheduling algorithms, namely: FCFS, SSTF, SCAN, CSCAN, LOOK and CLOOK.

Your program should prompt for the starting cylinder, the current head direction (i.e. ¡®L¡¯ or ¡®l¡¯ if the direction is toward cylinders less than the starting position and ¡®G¡¯ or ¡®g¡¯ if the direction is toward cylinders greater than the starting cylinder), and the cylinder request queue (i.e. all the cylinders to be read in the order requested).

For each algorithm your program should compute and display the head movement (i.e. the order in which the cylinders are visited based on the current algorithm), the total head movement (in cylinders) based on the current algorithm and the max and min waiting time for the disk requests. You can assume: The disk has 200 cylinders commencing from 0 to 199. All disk
requests are queued and waiting for the disk scheduler. The disk¡¯s seek time is 0.8ms per cylinder and the rotational latency is 3ms average. With CSCAN and CLOOK the 'L' direction causes flyback from cylinder 0 (or min request) to 199 (or max request) and visa versa the ¡®G¡¯ direction. For FCFS and SSTF the head direction is ignored.

An example interaction is shown below. (Note: bold text indicates user input. The output shown is for format purposes only. i.e. it is not correct.)

Cylinder Start: 53
Head Direction: g
Cylinder Queue: 98 183 37 122 14 124 65 67
FCFS Head Movement: 53=>98=>183=>37=>122=>14=>124=>65=>67
FCFS Total Movement: 640 cylinders
FCFS Min Waiting Time: 55ms

FCFS Max Waiting Time: 220ms
FCFS Ave Waiting Time: 110ms
SSTF Head Movement: 53=>65=>67=>37=>14=>98=>122=>124=>183
SSTF Total Movement: 640 cylinders
SSTF Min Waiting Time: 35ms
SSTF Max Waiting Time: 260ms
SSTF Ave Waiting Time: 120ms
.....
.....
BEST TO WORST ALGORITHMS (min to max)
Total Cylinders: SSTF LOOK CLOOK SCAN CSCAN FCFS
Max Waiting Time: LOOK CLOOK SSTF CSCAN SCAN FCFS
Ave Waiting Time: SSTF LOOK CLOOK SCAN CSCAN FCFS

You can assume all input (except head direction) are integers. When invalid input is detected the whole line of input should be requested again. (One suggestion is to read the whole line with getline() and extract the integers with sscanf() or a stringstream).
