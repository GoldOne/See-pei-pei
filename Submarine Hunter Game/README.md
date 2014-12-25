Submarine Hunter Game
================

This program is intended to provide basic experience in writing Client-Server programs which uses BSD Sockets & TCP. After having completed this program you should know how to write simple client-server applications with both iterative and concurrent servers.

Your task is to write a C/C++ Client-Server "submarine hunter" computer game system which uses BSD Sockets & TCP. The client server concurrency model to be used is a simple one-process-per-client model handled by a forking server. Each process spawned on the server-side is to handle each connecting client. The UNIX OS is based on the subdivision of tasks (processes) and their sharing of the CPU resources. As such, through time-slicing and blocking on I/O requests multiple processes share the use of CPU resources creating the illusion of concurrency. The "submarine hunt" game system is a very simple 2 player game where the objective is to sink the opposing submarine. Typically the game system will comprise of a server and a client program. The server program (described bellow) will constitute a computer player. The client program (described bellow) will be the interface of the human player to play a game session against the computer opponent. Consequently, each client connection will be handled by a new forked instance of the server, thus allowing multiple players on any machines to play a game against the server's computer players (ie Client Handlers). 
This program should be implemented in 4 or 5 steps:
1. Non-Distributed Game - First get your game coding and logic working correctly by writing a single process submarine game program. Make sure you design your program so that it can easily be separated into client and server parts.
2. Iterative Server - Once you have your game working correctly, write client and serial server programs that incorporate the appropriate sections of your game code.
3. Forking Server - Convert your serial server into a one-process-per-client forking server.
4. Artificial Intelligence  - Implement strategic game playing into your server according to the suggested algorithm. You can modify this if you wish by devising you own game strategy. But this must be sensible.
A brief description of the sub hunter game and some details on implementing the above steps are provided below:

Playing the Submarine Hunter Game
A typical game output screen shot should appear as follows:
+ + + + + + +                              SCORES
+ + + + + + +                         Player        Computer
+ + + P + + +                            0                   1
+ p + + + + +
+ + + + + + +                         P = Player's Position
+ + + + c + +                          p = Player's Torpedo
+ + + + + + +                         c = Computer's Torpedo
(f)ire (l)eft (r)ight (u)p (d)own (s)urrender
Enter your move =>
where::
  '+' symbol indicates water
  'P' indicates the current position of the human player
  'c' indicates the coordinates of the computer player's last torpedo
  'p' indicates the human player's last torpedo coordinates.
The computer player will not be visible to the user, however the user will be notified if the computer player was hit. The (x,y) coordinate system will be used to specify locations where the top left hand corner is (0,0) bottom right hand corner is (n,n). For further information of the game output: PC and UNIX executables of the single process game are provided in the files SubHuntPC.exe and SubHuntUNIX.exe. The objective of the "sub hunt" game is to sink the opposing submarine. With each turn, the user has the choice of either moving the sub one cell up, down, left or right, OR firing a torpedo at the computer's sub. If the user chooses to fire at the computer's sub the user is asked to enter the torpedo's target coordinates. If the computer's sub happens to be positioned at the target coordinates the user scores one point. Likewise, with each move, the computer randomly chooses to move its sub or take random shots at the user's sub. The game ends when either player's score reaches 5 or the user chooses to surrender. (Note: the user always makes the first move.)
Step 1: An example algorithm of a single process sub hunter game program is shown below. Example UNIX and PC executables of this algorithm are provided in the files SubHuntUNIX.exe and SubHuntPC.exe. To get started on this step it is suggested you copy the algorithm below into a file called SubHunt.cpp and convert it into a C++ program that produces the same output as the executables above. You can make changes to this algorithm if you wish to decompose it into appropriate functions or to make it easier to convert into a client-server application.
Step 2: For this step you are to take the code you developed for step 1 and distribute it into a client and server program. You may use the client-server program and wrapper functions in the Example1 folder. To help you get started a possible algorithm for a client-server version of the game program is shown below. Note the communications protocol (ie packing and unpacking the information) required between the client and server is left up to you.
Step 3. Modify your server program so that instead of being an iterative server the server is a concurrent forked server. This should enable more than one game to be played at the same time with the server by different users. The lecture notes and the client-server program in the Example2 folder may assist you with this task.
Step 4. Incorporate some strategic game playing into the server's moves by implementing the "Server AI" algorithm shown above. You can improve on this if you wish.