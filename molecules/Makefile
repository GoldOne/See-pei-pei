#Student name Yi Jin 
#Student number 4370673
#Lab Monday 830AM-1030AM
a.out:		main.o import.o report.o
		g++ -Wall -o a.out main.o import.o report.o
main.o:		main.cpp molecules.h
		g++ -Wall -c main.cpp
import.o:	import.cpp molecules.h
		g++ -Wall -c import.cpp
report.o:	report.cpp molecules.h
		g++ -Wall -c report.cpp
clean:		
		rm -f	main.o a.out import.o report.o
