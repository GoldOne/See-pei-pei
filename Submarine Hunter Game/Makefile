SHELL=/bin/sh
CC=CC
INCLUDES=
LIBS=-lsocket -lnsl -lresolv
CFLAGS=-g $(INCLUDES)

.SUFFIXES:
.SUFFIXES: .cpp $(SUFFIXES)

.cpp.o:
	$(CC) $(CFLAGS) -c $<

.cc.o:
	$(CC) $(CFLAGS) -c $<

TARGETS=server client

all: $(TARGETS)

clean:
	rm -f *.o $(TARGETS)

wrappers.o: wrappers.h
server.o: wrappers.h
client.o: wrappers.h

server: server.o wrappers.o
	$(CC) -o $@ server.o wrappers.o $(LIBS)

client: client.o wrappers.o
	$(CC) -o $@ client.o wrappers.o $(LIBS)