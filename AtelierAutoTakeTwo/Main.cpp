#include <iostream>
#include <string>
#include <conio.h>

using namespace std;


/*template<typename T,typename P>
void add(T head, P object)
{
	T *aux = head;
	if (!head->ths)
	{

	}
	else
	{
		while (aux->next != NULL)
		{
			aux = aux->next;
		}
		aux->next = new T();
		aux = aux->next;
		aux->next = NULL;
		aux->ths = object;
	}
};*/
template<typename T>
void del(T head) {

};


template<typename T>
struct LST {
	T *ths=NULL;
	LST *next=NULL;
};

template<typename T>
struct LSTc {
	T *ths = NULL;
	int count = 0;
	LST *next = NULL;
};

class Material{
private:
	char name[256];
	int cost;
	static LST<Material> *mtls;
public:
	Material(char nume[256], int cst) {
		strcpy_s(name, nume);
		cost = cst;
		add(mtls, this);
	}
	static void regMat(char nume[256],int cst) {
		Material(nume, cst);
	}
	~Material() {}
	static Material *getMaterial(char s_str[256])
	{
		LST<Material> *iter = mtls;
		if (iter->ths->isName(s_str))
		{
			return iter->ths;
		}
		while (iter->next)
		{
			if (iter->ths->isName(s_str))
			{
				return iter->ths;
			}
		}
		return NULL;
	}
	void add(LST<Material> *head, Material *mtl)
	{
		LST<Material> *aux = head;
		if (aux==NULL)
		{
			aux = new LST<Material>;
			aux->ths = mtl;
			aux->next = new LST<Material>;
			aux->next->next = NULL;
			aux->next->ths = NULL;
		}
		else
		{
			while (aux->next != NULL)
			{
				aux = aux->next;
			}
			aux->next = new LST<Material>;
			aux = aux->next;
			aux->next = NULL;
			aux->ths = mtl;
		}
	}
	bool isName(char test[256]) { if (!strcmp(test, name)) { return true; } return false;}
	//bool operator!=(const int& val) { if (cost == val)return false; return true; }
};
LST<Material> *Material::mtls = NULL;

class Problem {
public:
	char name[256];
	int manopera;
	LSTc<Material> *materials = new LSTc<Material>;
	Problem() {};
	Problem(char nume[256],int manopera,char mats[256], LST<Problem> *head){
		int i = 0, siz = strlen(mats),auxi=0;
		char aux[256];
		while (i <= siz)
		{
			if (mats[i] != ',') {
				aux[auxi] = mats[i];
				auxi++;
			}
			else
			{
				aux[auxi + 1] = '\n';
				add(materials, Material::getMaterial(aux));
				auxi=0;
			}
			i++;
		}
		strcpy_s(name, nume);
		add(head, this);
	}
	~Problem() {};
	void add(LSTc<Material> *head, Material *target) {
			LSTc<Material> *aux = head;
			if (aux== NULL)
			{
				aux = new LSTc<Material>;
				aux->ths = target;
				aux->next = new LSTc<Material>;
				aux->next->next = NULL;
				aux->next->ths = NULL;
			}
			else
			{
				while (aux->next != NULL)
				{
					aux = aux->next;
				}
				aux->next = new LSTc<Material>;
				aux = aux->next;
				aux->next = NULL;
				aux->ths = target;
			}
	}
	virtual void add(LST<Problem> *head, Problem *target)
	{
		LST<Problem> *aux = head;
		if (aux == NULL)
		{
			aux = new LST<Problem>;
			aux->ths = target;
			aux->next = new LST<Problem>;
			aux->next->next = NULL;
			aux->next->ths = NULL;
		}
		else
		{
			while (aux->next != NULL)
			{
				aux = aux->next;
			}
			aux->next = new LST<Problem>;
			aux = aux->next;
			aux->next = NULL;
			aux->ths = target;
		}
	}
};

class Component {
public:
	
};

template<class T>
class ComponentA : public Component{
public:
	static LST<Problem> *problem;
	virtual void add_problem(char text[256],int hours, char mats[256])
	{
		Problem::Problem(text,hours, mats, problem);
	}
};
template<typename T>
LST<Problem> *ComponentA<T>::problem = new LST<Problem>;

class Brake: public ComponentA<Brake> {

};
class Engine: public ComponentA<Engine> {
};
class Direction: public ComponentA<Direction> {

};
class Chassis: public ComponentA<Chassis> {

};
class Emissions: public ComponentA<Emissions> {

};

class Vehicle{
public:
	Brake brakes[2];
	Direction directie;
};

class bike : public Vehicle {
public:

};

class car : public Vehicle {
public:
	Engine motor;
	Chassis caroserie;
	Emissions noxe;
	int year;
	car() {};
	~car() {};
};

class moto : public Vehicle {
public:
	Engine motor;
	Emissions noxe;
	int year;
	moto() {};
	~moto() {};
};





int main()
{

	//init
	Material::regMat("surub", 2);
	Material::regMat("cupru", 5);
	Material::regMat("ulei", 10);
	Material::regMat("aluminiu", 6);
	Material::regMat("fier", 5);


	

	//Material dox("cui", 5);
	car Bemveu_fa;
	Bemveu_fa.motor.add_problem("Rupere curea",5,"cui");


	_getch();
	return 0;
}