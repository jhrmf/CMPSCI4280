CC = g++
CFLAGS =
TARGET = P1
OBJS = main.o scanner.o token.o
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp scanner.h
	$(CC) $(CFLAGS) -c main.cpp
scanner.o: scanner.cpp scanner.h token.h
	$(CC) $(CFLAGS) -c scanner.cpp
token.o: token.cpp token.h
	$(CC) $(CFLAGS) -c token.cpp

clean:
	/bin/rm -f *.o $(TARGET)
