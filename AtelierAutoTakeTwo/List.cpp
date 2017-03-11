#ifndef LIST_H
#include "List.h"
#endif

#ifndef PROBLEM_H
#include "Problem.h"
#endif

template<class T>
List<T> *List<T>::first;
template<class T>
List<T> *List<T>::last = first;
/*template<class T>
int List<T>::id_seed = 0;*/

/*emplate<class T>
List<T> List<T>::next(List<T> object)
{
	if (object->next) {
		return object->next;
	}
	else
	{
		return object;
	}
};*/

//Constructor implicit
template<class T>
List<T>::List()
{

};

//Destructor pentru deinitializarea corecta a tuturor listelor
template<class T>
List<T>::~List()
{
	List<T> *iter = first;
	List<T> *lst;
	if (iter) {
		do {
			lst = iter;
			iter = iter->next;
			delete(lst);
		} while (iter->next);
	}
	delete(iter);
};

//Adauga un nou element de tipul template-ului la o (lista nou creata)/(deja existenta)
template<class T>
void List<T>::add(T *object)
{
	List<T> *iter = this;
	if (iter->ths)
	{
		while (iter->next)
		{
			iter = iter->next;
		}
		iter->next = new List < T >;
		iter->next->ths = object;
		iter->next->next = nullptr;
	}
	else
	{
		iter->ths = object;
	}
};


//Inchide lista legand ultimul element de primul
template<class T>
void List<T>::close()
{
	last->next = first;
};

/*Aplica o functie f ce returneaza void si primeste un parametru
de tipul template-ului fiecarui element din lista unui tip
(2 liste declarate separat dar care au acelasi tip de continut vor fi "concatenate")*/
template<class T>
void List<T>::foreach(void(*f)(T))
{
	List<T> *iter = first;
	do {
		f(*iter->ths);
		if (iter->next)
		{
			iter = iter->next;
		}
		else
		{
			iter = first;
		}
	} while (iter != first);
};


template<class T>
T *List<T>::object() {
	return ths;
}

template<class T>
T *List<T>::getAtN(int n) {
	List<T> *frst = this;
	List<T> *iter = frst;
	int i = 1;
	while (i < n)
	{
		if (iter->next)
		{
			iter=iter->next;
		}
		else
		{
			iter = frst;
		}i++;
	}
	return iter->object();
};

template class List<Problem>;
template class List<Material>;
template class List<MatObj>;