
# Variables to control Makefile operation

CC = g++
CFLAGS = -Wall -g

lowest-common-ancestor: lowest-common-ancestor.o
	$(CC) $(CFLAGS) -o lowest-common-ancestor lowest-common-ancestor.o

lowest-common-ancestor.o: lowest-common-ancestor.cpp
	$(CC) $(CFLAGS) -c lowest-common-ancestor.cpp

clean:
	rm -rf lowest-common-ancestor lowest-common-ancestor.o
