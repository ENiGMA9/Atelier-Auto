#ifndef VEHICLE_H
#include "Vehicle.h"
#endif


void Vehicle::damage() {
	motor.damage(tag);
	frane.damage(tag);
	directie.damage(tag);
	caroserie.damage(tag);
	noxe.damage(tag);
};

void Vehicle::diagnose() {
	motor.diagnose();
	frane.diagnose();
	directie.diagnose();
	caroserie.diagnose();
	noxe.diagnose();
};

void Vehicle::operator=(const Vehicle &v)
{
	tag=v.tag;
	strcpy(name, v.name);
	year = v.year;
}