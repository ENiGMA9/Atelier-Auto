#ifndef MATERIAL_H
#include "Material.h"
#endif

#include <iostream>


Material::Material(char nume[32],short unsigned int cst) {
	strcpy(name, nume);
	cost = cst;
};
List<Material> Material::mats;


void Material::AddMaterial(char nume[32], short unsigned int cst) {

	mats.add(new Material(nume, cst));
}


Material::Material() {
}
/*
Material::~Material() {

};*/

Material *Material::find(char input[32]) {
	List<Material> *iter = &mats;
	//List<Material> *lst;
	input = _strlwr(input);
	int stahp = 0;
	if (iter->ths)
	{
		do {
			if (strcmp(input, _strlwr(iter->ths->name)) == 0) {
				return iter->object();
			}
		//	lst = iter;
			if (iter->next) { iter = iter->next; }else{
				stahp = 1;
			}

		} while (stahp == 0);
	}
	else
	{
		if (iter->next)
		{
			iter = iter->next;
			do {
				if (strcmp(input, _strlwr(iter->ths->name)) == 0) {
					return iter->object();
				}
			//	lst = iter;
				if (iter->next) { iter = iter->next; }else{
					stahp = 1;
				}

			} while (stahp == 0);
		}
		else return 0;
		//throw "Material doesn't exist.";
	}

	return 0;
}