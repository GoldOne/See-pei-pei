#Student name Yi Jin 
#Student number 4370673
#Lab Monday 830AM-1030AM
a.out:	        main.o bignumber.o
		g++ -Wall -o a.out main.o bignumber.o
main.o:	        main.cpp llong.h
		g++ -Wall -c main.cpp
bignumber.o:	bignumber.cpp llong.h
		g++ -Wall -c bignumber.cpp
clean:
		rm -f main.o a.out bignumber.o
