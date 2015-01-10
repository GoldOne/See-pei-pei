Pearl's Fashion Supplies
=================

Objectives
Implement a branch and bound algorithm solution to an NP-hard problem common in industry.
Choose and implement an appropriate data structure.
Consider the time and space complexity of a branch and bound solution.
Consider improvements to branch and bound.

Important
Your program should compile to produce a program named pfs using the command: make
Your program must run using the command:
pfs <inputfile>
where <inputfile> is a le in the format described in the input section.

Pearl's Fashion Supplies
Pearl owns a fully automated jacket factory which makes jackets to order. The factory consists of 3 machines: machine A cuts, machine B sews, machine C presses. Depending on the particular jacket being made, we may require dierent amounts of time on each machine. We will call these times aji , bji and cji respectively for each jacket ji.
Each machine can only process one jacket at a time, one jacket can only be processed on one machine at a time, but transfer between machines is assumed to be instantaneous. All jackets go through each machine in the same sequence, but the total time required depends on which sequence is used. For example, there is currently an order for 4 jackets, which require the following times (in minutes).

ji 1 2 3 4
aji 13 7 26 2
bji 3 12 9 6
cji 12 16 7 1

Calculating the time for a sequence
Beginning at time 0, we can calculate the time required to make a particular sequence of jackets. If the rst r jackets in the sequence are Jr = j1; j2; :::; jr, where r <= n, we can calculate the time that the rth jacket will nish on each machine.
The nish time for the jacket jr on machine x is simply start time + processing time.
nish(x; jr) = start(x; jr) + xjr
The start time for a jacket is determined based on previously calculated times. Specically, jr cannot start processing on machine x until:
 The jacket jr has nished processing on the previous1 machine x ?? 1 and
 the previous2 jacket jr??1 has nished processing on machine x.
So we must use the maximum of these two times as the start time.
For example, if the jackets are made in the sequence 1; 2; 3; 4 the start and nish times for each jacket ji are as follows:
ji 1 2 3 4
start(A; ji) 0 13 20 46
nish(A; ji) 13 20 46 48
start(B; ji) 13 20 46 55
nish(B; ji) 16 32 55 61
start(C; ji) 16 32 55 62
nish(C; ji) 28 48 62 63

For 4 jackets, there are 4! possible sequences. If we use the sequence above, the jackets will be nished in 63 mins. However, if the jackets are instead made in the sequence 2, 3, 1, 4, then the jackets will be nished in 62 minutes. If we use the sequence 2, 1, 4, 3 the jackets will take 64 minutes, while any sequence which starts 1,3 will take at least 72 minutes! Clearly, it will be possible to process many more orders if the best sequence for each order can be established.

Task
You are to write a program which nds the optimal sequence for making n jackets, given their processing times on each of 3 machines, using branch and bound. An optimal sequence is one for which the nish time for the entire order is less than or equal to all other possible nish times.
Input
The input le will contain the number of jackets n to be processed, then a line for each machine (in the order A, B, C). Each line will contain the processing times (in whole minutes) for each jacket (from 1 to n) on that machine, separated by whitespace. A sample input le matching this example is provided in input.txt.
Output
You should output
1. the sequence of jackets with the optimal time
2. the optimal time
3. the number of nodes which you created during your search

Calculating the lower bound for a sequence
Once we know the nishing time for jacket jr in the sequence Jr, we can calculate a lower bound estimate for doing all n jackets. We do this by assuming that each machine nishes processing Jr and then immediately processes all remaining jackets with no waiting time, then the nal jacket is processed on any subsequent machines.
There are 3 cases, one for each machine. The lower bound for all n jackets is whichever of these takes the longest.
 All jackets in the sequence Jr are nished on machine A, the rest nish on machine A with no waiting and the nal jacket is processed immediately on machines B and C.
 All jackets in the sequence Jr are nished on machine B, the rest nish on machine B with no waiting and the nal jacket is processed immediately on machine C.
 All jackets in the sequence Jr are nished on machine C, the rest, including the nal jacket, nish on machine C with no waiting.
Of course, we don't know what the nal jacket jn will be, so we assume that it is the one which takes the minimum total processing time on the subsequent machines.