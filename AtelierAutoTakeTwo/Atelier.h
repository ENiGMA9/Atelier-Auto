#ifndef VEHICLE_H
#include "Vehicle.h"
#endif

#ifndef ATELIER_H
#define ATELIER_H
class Atelier {
private:
	static Vehicle cVehicle;
public:
	static int TOTAL_COST;
	static int MANHOUR_COST;
	Atelier();
	~Atelier();
	static void receive(Vehicle obj);
	//static void damage();
	static void diagnose();
};
#endif