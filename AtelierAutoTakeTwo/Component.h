#ifndef PROBLEM_H
#include "Problem.h"
#endif

#ifndef COMPONENT_H
#define COMPONENT_H


template<typename T>
class Component{
public:
	static List<Problem> problems;
	List<Problem> actualProblems;
	virtual void add(char nume[256], char flg[64], int mnhrs, char materials[256]= "\n");
	virtual void damage(char flag);
	virtual void diagnose();
	virtual Problem *getNthWithTag(int n, char z);
	virtual bool tagIsValid(char flag);
	static void AddProblem(char nume[256], char flg[64], int mnhrs, char materials[256] = "\n");
};

class Brakes: public Component<Brakes> {
public:
	Brakes() {};
	//~Brakes();
};

class Engine: public Component<Engine> {
public:
	Engine() {};
	//~Engine();
};

class Direction: public Component<Direction> {
public:

	Direction() {};
	//~Direction();

};

class Emissions: public Component<Emissions> {
public:
	Emissions() {};
	//~Emissions();
};

class Chassis : public Component<Chassis> {
public:

	Chassis() {};
	//~Chassis();
};
#endif