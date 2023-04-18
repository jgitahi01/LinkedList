CFLAGS = -O
CC = g++

list: driver.o itemType.o listType.o
	$(CC) $(CFLAGS) -o list driver.o itemType.o listType.o

driver.o: driver.cpp
	$(CC) $(CFLAGS) -c driver.cpp

itemType.o: itemType.cpp
	$(CC) $(CFLAGS) -c itemType.cpp

listType.o: listType.cpp
	$(CC) $(CFLAGS) -c listType.cpp

clean:
	rm -f core *.o
