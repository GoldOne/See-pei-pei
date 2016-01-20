CPU Scheduler
===========

###Aim

This program is aimed at providing understanding on the concept of CPU scheduling by writing a simulator that simulates the scheduling of various scheduling algorithms and the average turnaround and waiting time.

####Step1

You are to write a program that simulates a Round Robin (RR) scheduler. Your simulator should receive process information from a file that is provided to the program via the command line argument. e.g.

    $ scheduler input.txt

The input file has the following format:
```cpp
<No. of Processes>
<Time slice>
<P0 arrival time> <P0 burst Time>
<P1 arrival time> <P1 burst Time>
<P2 arrival time> <P2 burst Time>
. . .
```
(Note: All items <> are ints and times are in milliseconds)

Your program should check for valid input (i.e. sensible values, the arrival times are in increasing order, no arrival time the same and all times are multiples of the time slice). If invalid input is detected, the program should print an appropriate error message and exit. 

When valid input is received your program should buffer the input values in an appropriate
struct array named JobQueue (or similar) and calculate the minimum and maximum arrival times. Your program should then simulate running these processes in a Round Robin (RR) CPU scheduler and record stats as well as a Gantt chart of the running processes.

To do this, after reading and buffering the input, your program should go into a for loop: from min arrival time to max arrival time and increment the loop counter (current time) by the time slice amount each iteration. Each iteration requires checking the JobQueue for an arriving processes (i.e. arrival time equals current time) and placing it in the tail of ready queue (STL list). Your loop should also check the CPU (struct), increment the execution time of the process in the CPU, move processes between the CPU and ready queue when the time slice is up, and increment the execution time and waiting times of processes in the CPU and ready queue respectively. Declare appropriate fields in the process stuct to facilitate recording the necessary information.

Your program should display the Gantt chart, burst times, waiting times and the turnaround times for the processes as well as their averages. The output should be formatted to appear like shown below where Xms is the time slice, XXXXXX are the times in ms and BT = Burst Time, WT = Waiting Time and TT = Turnaround Time.
```cpp
                                            Round Robin (Xms)

                                    Gantt Chart: 00112233001130

                                              BT        WT         TT
                                    P0:     XXXXXX    XXXXXX     XXXXXX
                                    P1:     XXXXXX    XXXXXX     XXXXXX
                                    P2:     XXXXXX    XXXXXX     XXXXXX
                                    P3:     XXXXXX    XXXXXX     XXXXXX
                                    Average:          XXXXXX     XXXXXX
```

To simplify the output you can assume no more than 10 processes are used in the simulator and each digit in the Gantt chart represents the process number that occupied the CPU for that time slice. If the CPU is idle display a бо-бо (dash).

When you are sure your RR algorithm is working correctly commence Step 2.

####Step2

Modify your scheduler to also simulate a multilevel feedback-queue scheduler. Your multilevel feedback-queue scheduler should have the following specification:

1. This scheduler has three queues, numbered from 0 to 2.
2. New processes are always queued into queue-0.
3. The scheduler first executes all processes in queue-0. (Queue-0's time quantum is one time slice.)
4. If a process in the queue-0 does not complete its execution in one time slice, the scheduler moves the process to the end (tail) of queue-1.
5. If queue-0 is empty, the scheduler will execute the process at the head of queue-1. (Queue 1's time quantum is two times the time slice value).
6. If a new process arrives in queue-0 when a process from queue-1 is being executed, the queue-1 process in the CPU is pre-empted and added to the head of queue-1 so that it will be first out of queue-1 when queue-1 execution resumes. However, when this occurs this process only receives a time quantum equal to one time slice, instead of two.
7. If a process in queue-1 does not complete its execution for queue 1's time quantum, (i.e. two time slices), the scheduler then moves this process to queue 2.
8. If both queue-0 and queue-1 are empty, the scheduler executes processes in queue-2. Queue-2's time quantum is four times the time slice value).
9. Likewise, if a new process arrives in queue-0 or queue-1 when a process from queue- 2 is being executed, the queue-2 process in the CPU is pre-empted and added to the head of queue-2 so that it will be first out of queue-2 when queue-2 execution resumes. However, when this occurs this process only receives a time quantum equal to two time slices, instead of four.
10. If a process in queue-2 does not complete its execution for queue 2's time quantum, (i.e., four time slices), the scheduler puts it back to the end (tail) of queue-2.

Your output from this should appear below the output of the above with the same format.