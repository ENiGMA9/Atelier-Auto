#ifndef ATELIER_H
#include "Atelier.h"
#endif

#ifndef VEHICLE_H
#include "Vehicle.h"
#endif


#ifndef ATELIER_CPP
#define ATELIER_CPP
int Atelier::TOTAL_COST = 0;
int Atelier::MANHOUR_COST = 5;

Vehicle Atelier::cVehicle = Vehicle();

void Atelier::receive(Vehicle obj) {
	cVehicle = obj;
	printf("%s\n", cVehicle.name);
	cVehicle.damage();
};

/*void Atelier::damage() {

};*/

void Atelier::diagnose() {
	cVehicle.diagnose();
};
#endif