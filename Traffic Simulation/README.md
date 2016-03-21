Traffic Simulation
==============

###Important
Your program should compile to produce a program named `trafficsim` using the command:

    make

Your program must run using the command:

    trafficsim <roadsfile> <carsfile> <congestion factor>

###Traffic Network

You are to use **discrete event based** simulation techniques to model a road network. The network consists of numbered intersections and the roads between them. So an intersection is a node in a graph, and a road is an edge between two intersections. 

Each car can enter the network at any intersection, with any other intersection as its destination. Cars travel along roads to reach their destination and then exit the network. The path by which a car travels is selected to minimise the estimated total travel time to the destination. 

The amount of time required to travel on a road is determined as the car enters that road. It depends on the length of the road, and the number of cars currently on the road. For this simulation we will make a simplifying assumption that each additional car on the road increases the travel time by a constant proportion. So, for each section of road:

travel time=(length of road=base speed of car)\*(1+congestion factor\*(number of cars on road=length of road))

We will assume that the base speed of every car is the same: 90km/h or 1500m/min. The congestion factor is a 
oating point value, which is provided as a command line argument to allow us to simulate different levels of congestion.

Two methods for planning the path are to be evaluated:

1. Drivers have a map and listen to the radio traffic report at the start of their journey. The path is planned upon entering the network, based on the network status at the time of entry.
2. Drivers use a traffic enabled GPS and revise their route upon reaching each intersection. They take the cheapest route available at every intersection. The path is planned upon entering the network, based on the network status at the time of entry, and replanned at each intersection, based on the network status when the intersection is reached.

###Input

Your program should take the names of 2 input files, one which represents the road network, and another which represents the arriving cars.

####roads

The first line in the roads file contains the number of intersections *n*. This is followed by *n* lines, containing the intersection label (an integer) and the *x* and *y* coordinate in metres (2 foating point numbers). The next line contains the number of roads *e*. This is followed by *e* lines, containing the road label (an integer), the endpoints of the road (2 intersection labels) and the length of the road in metres (a foating point number).

Note that the length of a road may be greater than (but never less than) the euclidean distance between the two intersections that the road connects.

####cars

The cars file contains all the cars for the simulation, sorted in increasing order of entry time. Each car appears on its own line, which consists of the entry time, the starting intersection, and the destination intersection. Entry times are in the format HH:MM:SS, potentially ranging from 00:00:00 to 23:59:59.

###Output

We want to be able compare the two methods of route planning for a given road network, traffic pattern and congestion factor. When your program is run, it should run two simulations, both using the given input files and congestion factor. The first simulation should use traffic report based planning. The second should use GPS based planning.

For each simulation your program should report:
+ the total time simulated (from the entry of the first car to the exit of the last car)
+ the average speed for a car travelling through the network (calculating this is tricky, so here's some
help.)

Assume there are c cars. Let car *i* have a trip time (time of exit - time of entry) of ti and a travelled distance of di. This car then has an average speed of si=di/ti. We compute the average speed, s, based on the proportion of time spent in the simulation relative to all cars, as follows:

![f](https://github.com/GoldOne/See-pei-pei/blob/master/fig_bed/average%20speed.png)
+  the entry time, starting intersection and destination intersection for the trip with the longest time;
the time taken for that trip and the time that trip would have taken in an uncongested (empty)
network.