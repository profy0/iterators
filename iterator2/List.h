#include <vector>
#include <exception>
#include <list>
using namespace std;

#pragma once


class List
{
public:
	list <int> lt;
	list<int>::iterator top;
public:
	friend class ListIterator;

	List(size_t aSize) {
		lt.resize(aSize);
		top = lt.begin();
	}

	virtual ~List() {}
	
	bool append(int a) {
		if (lt.end() == top) {
			return false;
		}
		*top = a;
		top++;
		return true;
	}

	bool remove() {
		if (lt.size() != 0) return false;
		lt.pop_back();
		top--;
		return true;
	}

};

class ListIterator {
protected:
	friend class List;
	const List &pList;
	list<int>::iterator current;
public:
	ListIterator(const List &aPList) : pList(aPList) {
		
	}
	virtual bool operator--() = 0;
	virtual int operator*() = 0;
};

class ListIteratorStep : public ListIterator {
private:
	int step;
public:
	friend class List;
	ListIteratorStep(const List &aPList, int aStep = 1) : ListIterator(aPList) {
		step = aStep - 1;
		current = pList.top;
	}

	bool operator--() override {
		if (current == pList.lt.begin()) return false;
		current--;
		bool bad = true;
		for (auto i = 0; i < step; i++) {
			if (i != 2 && current == pList.lt.begin()) {
				bad = false;
				break;
			}
			current--;
		}
		return bad;
	}

	int operator*() override {
		return *current;
	}
};

class ListIteratorPredicate : public ListIterator {
private:
	void* predicate;
public:
	friend class List;
	ListIteratorPredicate(const List &aplist, void* apredicate) : ListIterator(aplist) {
		predicate = apredicate;
		current = pList.top;
	}
	bool operator--() override {
		if (current == pList.lt.begin()) return false;
		current--;
		bool bad = 1;
		while((int)predicate%2==0) { // если предикат четный то стек не выводится, если нечетный то выводится
			if (current == pList.lt.begin()) {
				bad = false;
				break;
			}
			current--;
		}
		return bad;
	}
	int operator*() override {
		return *current;
	}
};

class ListIteratorValue : public ListIterator
{
private:
	int value;
public:
	friend class List;
	ListIteratorValue(const List &aPList, int aValue) : ListIterator(aPList) {
		value = aValue;
		current = pList.top;
	}

	bool operator--() override {	
		if (current == pList.lt.begin()) return false;
		current--;
		bool bad = 1;
		while (*current != value) {
			if (current == pList.lt.begin()) {
				bad = false;
				break;
			}
			current--;
		}
		return bad;
	}
	int operator*() override {
		return *current;
	}
};