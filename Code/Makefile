CC = g++
DEBUG = -g
CFLAGS = -Wall -c -std=c++11 $(DEBUG)
LFLAGS = -Wall -std=c++11 $(DEBUG)
OBJS = air_animal.o animal.o cage.o cell.o driver.o facility.o gui.o habitat.o land_animal.o VirtualZoo.o water_animal.o zoo.o

run: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o run
air_animal.o: air_animal.cpp air_animal.h animal.h renderable.h
	$(CC) $(CFLAGS) air_animal.cpp
animal.o: animal.cpp animal.h renderable.h
	$(CC) $(CFLAGS) animal.cpp
cage.o: cage.cpp cage.h animal.h renderable.h habitat.h cell.h
	$(CC) $(CFLAGS) cage.cpp
cell.o: cell.cpp cell.h renderable.h animal.h
	$(CC) $(CFLAGS) cell.cpp
driver.o: driver.cpp driver.h animal.h renderable.h cage.h habitat.h cell.h facility.h Cell.h Renderable.h zoo.h gui.h
	$(CC) $(CFLAGS) driver.cpp
facility.o: facility.cpp facility.h Cell.h renderable.h animal.h
	$(CC) $(CFLAGS) facility.cpp
gui.o: gui.cpp gui.h
	$(CC) $(CFLAGS) gui.cpp
habitat.o: habitat.cpp habitat.h cell.h renderable.h animal.h
	$(CC) $(CFLAGS) habitat.cpp
land_animal.o: land_animal.cpp land_animal.h animal.h renderable.h
	$(CC) $(CFLAGS) land_animal.cpp
VirtualZoo.o: VirtualZoo.cpp driver.h animal.h renderable.h cage.h habitat.h cell.h facility.h Cell.h Renderable.h zoo.h gui.h
	$(CC) $(CFLAGS) VirtualZoo.cpp
water_animal.o: water_animal.cpp water_animal.h animal.h renderable.h
	$(CC) $(CFLAGS) water_animal.cpp
zoo.o: zoo.cpp zoo.h cell.h renderable.h animal.h cage.h habitat.h
	$(CC) $(CFLAGS) zoo.cpp
clean:
	rm -f *.o
exec:
	ulimit -t 3; ulimit -v 16384; /main