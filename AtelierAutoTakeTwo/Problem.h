#ifndef MATERIAL_H
#include "Material.h"
#endif

#ifndef PROBLEM_H
#define PROBLEM_H


class MatObj{
public:
	Material *mat;
	int count = 0;
	MatObj(Material *mt, int val)
	{
		count = val;
		mat = mt;
	}
	MatObj() {};
};


class Problem {
private:
	char name[256];
	char flags[64];
	int manhours = 0;
	List<MatObj> mList;
	virtual void getMaterials(char src[256]);
public:
	Problem(char nume[256], char flg[64], int manhours, char materials[256]);
	Problem();
	~Problem();
	virtual void print();
	virtual bool hasTag(const char z);
};

#endif