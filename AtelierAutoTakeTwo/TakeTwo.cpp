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

class Car: public Vehicle {
public:
	Car() { tag = 'c';strcpy(name,"Masina"); }
};

class Mbike: public Vehicle {
public:
	Mbike(){ tag='m';strcpy(name, "Motocicleta");
	}
};

class Bike: public Vehicle {
public:
	Bike(){tag='b';strcpy(name, "Bicicleta");
	}
};


int main() {
	//INIT
	Material("Cupru", 5);
	Material("Fier", 3);
	Material("Suruburi", 2);
	Material("Ulei", 10);
	Material("placuta1", 5);
	Material("placuta2", 4);
	Material("placuta3", 6);
	Material("placuta4", 7);
	Material("Disc", 15);
	Material("Lant", 5);
	Material("Motor", 40);
	Material("Roata", 10);
	Material("Aripa", 5);
	Material("Capota", 5);
	Material("Vopsea", 5);
	Material("Bara", 5);

	Brakes("Placute fata uzate", "cm", 1, "placuta1:r1;placuta2:r1;suruburi:r5");
	Brakes("Placute spate uzate", "cm", 1, "placuta3:r1;placuta4:r1;suruburi:r5");
	Brakes("Disc uzat", "cm", 1, "disc:r2;suruburi:r5");
	Brakes("Discuri uzate", "c", 2, "disc:r4;suruburi:r5");
	Brakes("Lant tocit", "b", 1, "lant:1;suruburi:r5");
	Brakes("Lant lipsa", "b", 1, "lant:1;suruburi:r5");
	Brakes("Defect capital", "cmb", 0);

	Engine("Nivel ulei scazut", "cm", 1, "ulei:1;suruburi:r5");
	Engine("Carburator murdar", "c", 2, "suruburi:r5");
	Engine("Motor topit", "cm", 5, "motor:1;suruburi:r5");
	Engine("Defect capital", "cm", 0);

	Direction("Ghidon stramb", "mb", 1, "suruburi:r5");
	Direction("Roata stramba", "cmb", 1,"roata:1;suruburi:r5");
	Direction("Defect capital", "cmb", 0);
	
	Emissions("Vehiculul arde ulei", "cm", 2, "ulei:1;suruburi:r5");
	Emissions("Vehiculul este anterior anului 2000", "cm", 0, "suruburi:r5");
	Emissions("Defect capital", "cm", 0);

	Chassis("Caroserie corodata de rugina", "c", 8, "vopsea:1;suruburi:r5");
	Chassis("Caroserie stramba", "c", 3, "aripa:r2;bara:r1;capota:r1;suruburi:r5");
	Chassis("Defect capital", "c", 0);

	int choice = 1;
		printf("Se primeste un vehicul:");
		srand(time(NULL));
		choice = rand() % 3 + 1;
		switch (choice)
		{case 1:
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
		printf("Total:%d",Atelier::TOTAL_COST);
		_getch();
	return 0;
}
