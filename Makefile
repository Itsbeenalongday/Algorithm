CC = gcc
CFLAGS = -W -Wall
C = algorithm.c
OBJECTS = algorithm.o
TARGET = algorithm

clean : 
	rm *.o $(TARGET)

test :
	$(CC) -c -o $(OBJECTS) $(C)       
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS) -lm 
	./$(TARGET)

