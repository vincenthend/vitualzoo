#ifndef FACILITY_H
#define FACILITY_H


#include

class Facility: public Cell{
	public:
		//ctor, dtor, cctor
	
	private:
		
	
};

/**
 * @class 	Road
 * Kelas Road, cellID bernilai 21
 * @param type
 * type entrance bernilai 1, exit bernilai 2, default 0
 */

class Road: public Facility{
	public:
		//ctor, dtor, cctor
		Road();
		Road(int x, int y);
		Road(int x, int y, int type);
		
	private:
		int type;
};

/**
 * @class 	Resto
 * Kelas Resto, cellID bernilai 22
 *
 */

class Resto: public Facility{
	public:
		//ctor, dtor, cctor
		Resto();
		Resto(int x, int y);
	
	private:
	
};

/**
 * @class 	Park
 * Kelas Park, cellID bernilai 23
 *
 */

class Park: public Facility{
	public:
		//ctor, dtor, cctor
		Park();
		Park(int x, int y);
	
	private:
	
};

#endif
