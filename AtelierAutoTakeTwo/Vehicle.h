#ifndef LIST_H
#include "List.h"
#endif
#ifndef COMPONENT_H
#include "Component.h"
#endif

#ifndef VEHICLE_H
#define VEHICLE_H

class Vehicle {
public:
	char name[32];
	char tag;
	int year;
	Engine motor;
	Brakes frane;
	Direction directie;
	Chassis caroserie;
	Emissions noxe;
	Vehicle();
	virtual void damage();
	virtual void diagnose();
	void operator=(const Vehicle &v);
};

#endif