#include "Component.h"
#include <stdlib.h>
	

template class Component<Brakes>;
template class Component<Engine>;
template class Component<Chassis>;
template class Component<Direction>;
template class Component<Emissions>;


template<typename T>
List<Problem> Component<T>::problems;

template<class T>
void Component<T>::add(char nume[256], char flg[64], int mnhrs, char materials[256]){
	Problem aux(nume, flg, mnhrs, materials);
	this->problems.add(&aux);
};

template<class T>
void Component<T>::damage(char flag)
{
	int i = rand() % 10+1;
	if (i>3) {
		i = rand() % 20 + 1;
		Problem *aux = nullptr;
		if (tagIsValid(flag)) {
			aux = getNthWithTag(i, flag);
		}
		if(aux)
		{
			actualProblems.add(aux);
		}
		
	}

};

template<class T>
bool Component<T>::tagIsValid(char flag)
{
	List<Problem> *iter = &this->problems;
	List<Problem> *first = &this->problems;
	while (iter)
	{
		if (iter->object()->hasTag(flag))
		{
			return true;
		}
		iter = iter->next;
	}
	return false;
};

template<class T>
Problem *Component<T>::getNthWithTag(int n, char z)
{
	List<Problem> *frst = &this->problems;
	List<Problem> *iter = &this->problems;
	int ok = 0;
	int i = 1;
	int stallCounter = 0;
	while (i < n)
	{
		if (iter->next)
		{
			ok = 0;
			while (!ok)
			{
				if (iter->object()->hasTag(z))
				{
					//return iter->object();
					ok = 1;
					stallCounter = 1;
				}
				else
				{
					if (iter->next)
					{
						iter = iter->next;
					}
					else
					{
							iter = frst;
					}
				}
			}
			i++;
		}
		else
		{
			i = n;
		}
	}
	return iter->object();
};

template<class T>
void Component<T>::diagnose()
{
	if(actualProblems.object())
	{
		actualProblems.object()->print();
	}	
};

Brakes::Brakes(char nume[256], char flg[64], int mnhrs, char materials[256])
{
	Problem *aux = new Problem(nume, flg, mnhrs, materials);
	this->problems.add(aux);
};

Engine::Engine(char nume[256], char flg[64], int mnhrs, char materials[256])
{
	Problem *aux = new Problem(nume, flg, mnhrs, materials);
	this->problems.add(aux);
};

Direction::Direction(char nume[256], char flg[64], int mnhrs, char materials[256])
{
	Problem *aux = new Problem(nume, flg, mnhrs, materials);
	this->problems.add(aux);
};

Emissions::Emissions(char nume[256], char flg[64], int mnhrs, char materials[256])
{
	Problem *aux = new Problem(nume, flg, mnhrs, materials);
	this->problems.add(aux);
};

Chassis::Chassis(char nume[256], char flg[64], int mnhrs, char materials[256])
{
	Problem *aux = new Problem(nume, flg, mnhrs, materials);
	this->problems.add(aux);
};

