#!/bin/bash
PROG=trafficsim 
OBJS=main.o
CC=g++
		
$(PROG) : $(OBJS) 
	$(CC) $^ -o $@ 

clean:
	rm -rf $(OBJS)

realclean:
	rm -rf $(PROG) $(OBJS) core

%.o : %.cpp
	$(CC) -c $< -o $@ 
