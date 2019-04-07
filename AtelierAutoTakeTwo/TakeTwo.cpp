#include "Material.h"
#include "Problem.h"
#include "List.h"
#include "Component.h"
#include "Atelier.h"
#include "Vehicle.h"
#include <conio.h>
#ifndef _INC_TIME
#include <time.h>
#endif

class Car : public Vehicle {
public:
	Car() { tag = 'c'; strcpy(name, "Masina"); }
};

class Mbike : public Vehicle {
public:
	Mbike() {
		tag = 'm'; strcpy(name, "Motocicleta");
	}
};

class Bike : public Vehicle {
public:
	Bike() {
		tag = 'b'; strcpy(name, "Bicicleta");
	}
};


int main() {
	//INIT
	Material::AddMaterial("Cupru", 5);
	Material::AddMaterial("Fier", 3);
	Material::AddMaterial("Suruburi", 2);
	Material::AddMaterial("Ulei", 10);
	Material::AddMaterial("placuta1", 5);
	Material::AddMaterial("placuta2", 4);
	Material::AddMaterial("placuta3", 6);
	Material::AddMaterial("placuta4", 7);
	Material::AddMaterial("Disc", 15);
	Material::AddMaterial("Lant", 5);
	Material::AddMaterial("Motor", 40);
	Material::AddMaterial("Roata", 10);
	Material::AddMaterial("Aripa", 5);
	Material::AddMaterial("Capota", 5);
	Material::AddMaterial("Vopsea", 5);
	Material::AddMaterial("Bara", 5);

	Brakes::AddProblem("Placute fata uzate", "cm", 1, "placuta1:r1;placuta2:r1;suruburi:r5");
	Brakes::AddProblem("Placute spate uzate", "cm", 1, "placuta3:r1;placuta4:r1;suruburi:r5");
	Brakes::AddProblem("Disc uzat", "cm", 1, "disc:r2;suruburi:r5");
	Brakes::AddProblem("Discuri uzate", "c", 2, "disc:r4;suruburi:r5");
	Brakes::AddProblem("Lant tocit", "b", 1, "lant:1;suruburi:r5");
	Brakes::AddProblem("Lant lipsa", "b", 1, "lant:1;suruburi:r5");
	Brakes::AddProblem("Defect capital", "cmb", 0);

	Engine::AddProblem("Nivel ulei scazut", "cm", 1, "ulei:1;suruburi:r5");
	Engine::AddProblem("Carburator murdar", "c", 2, "suruburi:r5");
	Engine::AddProblem("Motor topit", "cm", 5, "motor:1;suruburi:r5");
	Engine::AddProblem("Defect capital", "cm", 0);

	Direction::AddProblem("Ghidon stramb", "mb", 1, "suruburi:r5");
	Direction::AddProblem("Roata stramba", "cmb", 1, "roata:1;suruburi:r5");
	Direction::AddProblem("Defect capital", "cmb", 0);

	Emissions::AddProblem("Vehiculul arde ulei", "cm", 2, "ulei:1;suruburi:r5");
	Emissions::AddProblem("Vehiculul este anterior anului 2000", "cm", 0, "suruburi:r5");
	Emissions::AddProblem("Defect capital", "cm", 0);

	Chassis::AddProblem("Caroserie corodata de rugina", "c", 8, "vopsea:1;suruburi:r5");
	Chassis::AddProblem("Caroserie stramba", "c", 3, "aripa:r2;bara:r1;capota:r1;suruburi:r5");
	Chassis::AddProblem("Defect capital", "c", 0);

	int choice;
	printf("Se primeste un vehicul:");
	srand(time(NULL));
	choice = rand() % 3 + 1;
	switch (choice)
	{
	case 1:
		Atelier::receive(Car::Car());
		break;
	case 2:
		Atelier::receive(Mbike::Mbike());
		break;
	case 3:
		Atelier::receive(Bike::Bike());
		break;
	default:
		Atelier::receive(Car::Car());
		break;
	}
	Atelier::diagnose();
	printf("Total:%d", Atelier::TOTAL_COST);
	_getch();
	return 0;
}
