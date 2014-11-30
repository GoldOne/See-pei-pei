#Student name Yi Jin 
#Student number 4370673
#Lab Monday 830AM-1030AM
#Please read the head file first before you read other cpps!!!
a.out:		main.o mainmenu.o searchmenu.o importdata.o transint.o gpa.o exportdata.o displaymenu.o gpasearch.o utils.o namesearch.o subjectsearch.o display.o delete.o edit.o exdata.o imdata.o valid.o options.o
		g++ -Wall -o a.out main.o mainmenu.o searchmenu.o importdata.o transint.o gpa.o exportdata.o displaymenu.o gpasearch.o utils.o namesearch.o subjectsearch.o display.o delete.o edit.o exdata.o imdata.o valid.o options.o
importdata.o:	importdata.cpp database.h
		g++ -Wall -c importdata.cpp
mainmenu.o:	mainmenu.cpp database.h
		g++ -Wall -c mainmenu.cpp
searchmenu.o:	searchmenu.cpp database.h
		g++ -Wall -c searchmenu.cpp
main.o:		main.cpp database.h
		g++ -Wall -c main.cpp
transint.o:	transint.cpp database.h
		g++ -Wall -c transint.cpp
gpa.o:		gpa.cpp database.h
		g++ -Wall -c gpa.cpp
exportdata.o:	exportdata.cpp database.h
		g++ -Wall -c exportdata.cpp
displaymenu.o:  displaymenu.cpp database.h
		g++ -Wall -c displaymenu.cpp
gpasearch.o:	gpasearch.cpp database.h
		g++ -Wall -c gpasearch.cpp
utils.o:	utils.cpp database.h
		g++ -Wall -c utils.cpp
namesearch.o:	namesearch.cpp database.h
		g++ -Wall -c namesearch.cpp
subjectsearch.o:	subjectsearch.cpp database.h
			g++ -Wall -c subjectsearch.cpp	
display.o:	display.cpp database.h
		g++ -Wall -c display.cpp
delete.o:	delete.cpp database.h
		g++ -Wall -c delete.cpp
edit.o:		edit.cpp database.h
		g++ -Wall -c edit.cpp
exdata.o:	exdata.cpp database.h
		g++ -Wall -c exdata.cpp
imdata.o:	imdata.cpp database.h
		g++ -Wall -c imdata.cpp
valid.o:	valid.cpp database.h
		g++ -Wall -c valid.cpp
options.o:	options.cpp database.h
		g++ -Wall -c options.cpp
clean:		
		rm -f	main.o mainmenu.o searchmenu.o importdata.o transint.o gpa.o exportdata.o displaymenu.o gpasearch.o utils.o namesearch.o subjectsearch.o display.o a.out delete.o edit.o exdata.o imdata.o valid.o options.o

