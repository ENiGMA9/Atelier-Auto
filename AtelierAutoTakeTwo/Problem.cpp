#ifndef PROBLEM_H
#include "Problem.h"
#endif
#include <string.h>
#include <stdlib.h>
#include <time.h>

#ifndef ATELIER_H
#include "Atelier.h"
#endif

Problem::Problem(char nume[256], char flg[64], int mnhrs, char materials[256]) {
	strcpy_s(name, nume);
	strcpy_s(flags, flg);
	manhours = mnhrs;
	getMaterials(materials);
};

Problem::Problem() {

}

Problem::~Problem() {

};

void Problem::getMaterials(char src[256]) {
	int n = strnlen(src,256),z=0,v=0,last;
	char aux[32];
	MatObj *ax;
	for (int i = 0;i < n;i++)
	{
		if (src[i] != ':')
		{
			aux[z] = src[i];
			z++;
		}
		else
		{
			aux[z] = '\0';
			z = 0;
			last = i;
			v = 0;
			if (src[i+1] == 'r') {
				i+=2;
				while (i <= n && src[i] != ';')
				{
					v = v*(i - last) + src[i] - '0';
					i++;
				}
				v = rand() % v + 1;
			}
			else
			{
				while (src[i] != ';' || src[i] == '\0')
				{
					v = v * 10 + src[i] - '0';
					i++;
				}
			}
			ax = new  MatObj(Material::find(aux), v);
			mList.add(ax);
			
		}
	}
};


void Problem::print() {
	if (manhours != 0) {
		printf("Problema: %s,", name);
		printf(" ore de lucru: %i,", manhours);
		printf(" materiale necesare:\n");
		List<MatObj> *iter = &mList;
		while (iter){
			printf("Material: %s, ", iter->ths->mat->name);
			printf("%d lei/buc, ", iter->ths->mat->cost);
			printf("buc:%d, ", iter->ths->count);
			printf("pret total: %d\n", iter->ths->count*iter->ths->mat->cost);
			Atelier::TOTAL_COST += iter->ths->count*iter->ths->mat->cost;
			Atelier::TOTAL_COST += Atelier::MANHOUR_COST * manhours;
			iter = iter->next;
		};
		printf("\n");
	}
	else
	{
		printf("Problema capitala\n");
	}
};

bool Problem::hasTag(const char z){
	if (strchr(flags, z))
	{
		return true;
	}
	return false;
}
