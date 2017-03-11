#ifndef LIST_H
#define LIST_H

template<class T>
class List {
private:
//	static int id_seed;
//	int id;

public:
	List<T> *next = nullptr;
	static List<T> *first, *last;
	T *ths = nullptr;
	List();
	~List();
	void add(T *object);
	void close();
	void foreach(void(*f) (T));
	//List<T> next(List<T> object);
	T *object();
	T *getAtN(int n);
	T *getNthWithTag(int n, char z[1]);
};
#endif
