CC = g++
DEBUG = -g
CFLAGS = -Wall -c -std=c++11 $(DEBUG)
LFLAGS = -Wall -std=c++11 $(DEBUG)
OBJS = animal.o cage.o cell.o driver.o gui.o VirtualZoo.o  zoo.o

main: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o main
animal.o: animal.cpp animal.h
	$(CC) $(CFLAGS) animal.cpp
cage.o: cage.cpp cage.h animal.h cell.h
	$(CC) $(CFLAGS) cage.cpp
cell.o: cell.cpp cell.h animal.h
	$(CC) $(CFLAGS) cell.cpp
driver.o: driver.cpp driver.h animal.h cage.h cell.h zoo.h gui.h
	$(CC) $(CFLAGS) driver.cpp
gui.o: gui.cpp gui.h
	$(CC) $(CFLAGS) gui.cpp
VirtualZoo.o: VirtualZoo.cpp driver.h animal.h cage.h cell.h zoo.h gui.h
	$(CC) $(CFLAGS) VirtualZoo.cpp
zoo.o: zoo.cpp zoo.h cell.h animal.h cage.h
	$(CC) $(CFLAGS) zoo.cpp
clean:
	rm *.o *~ main
exec:
	ulimit -t 3; ulimit -v 16384; /main