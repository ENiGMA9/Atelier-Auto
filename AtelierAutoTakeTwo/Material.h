#ifndef LIST_H
#include "List.h"
#endif

#ifndef MATERIAL_H
#define MATERIAL_H
#include <string>

class Material {
public:
	static List<Material> mats;
	char name[32];
	short unsigned int cost;
	Material(char nume[32], short unsigned int cst);
	Material();
	//Material();
	//~Material();
	static Material *find(char input[32]);
};
#endif