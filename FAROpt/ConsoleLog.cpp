#include "stdafx.h"
#include "ConsoleLog.h"
#include <mutex> 
#include <iostream>

using namespace std;

mutex mtx;

ConsoleLog::ConsoleLog()
{
}


void ConsoleLog::print(string &m) {
	unique_lock<mutex> lck(mtx, defer_lock);
	lck.lock();
	std::cout << m << endl;
	lck.unlock();
}

void ConsoleLog::print(const char *m) {
	unique_lock<mutex> lck(mtx, defer_lock);
	lck.lock();
	std::cout << m << endl;
	lck.unlock();
}


void ConsoleLog::print(ComplexMatrix &m) {
	unique_lock<mutex> lck(mtx, defer_lock);
	lck.lock();
	for (int i = 0; i < m.length(); i++) {
		for (int j = 0; j < m.width(); j++) {
			cout.width(8);
			cout << ((int)(m[i][j].Re() * 100000) / 100000.0);
			cout << "+";
			cout.width(8);
			cout << ((int)(m[i][j].Im() * 100000) / 100000.0);
			cout << "i";
			if (i != m.length() - 1) {
				cout << ", ";
			}
		}
		cout << endl;
	}
	lck.unlock();
}

void ConsoleLog::print(double **m, int size) {
	unique_lock<mutex> lck(mtx, defer_lock);
	lck.lock();
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << ((int)(m[i][j] * 100000) / 100000.0);
			if (j != size - 1) {
				cout << ", ";
			}
		}
		cout << endl;
	}
	lck.unlock();
}


void ConsoleLog::print(ComplexVector &v) {
	unique_lock<mutex> lck(mtx, defer_lock);
	lck.lock();
	for (int i = 0; i < v.length(); i++) {
		cout.width(8);
		cout << ((int)(v[i].Re()*10000)/10000);
		cout << "+";
		cout.width(8);
		cout << ((int)(v[i].Im() * 10000) / 10000);
		cout << "i";
		if (i != v.length() - 1) {
			cout << ", ";
		}
	}
	lck.unlock();
}

void ConsoleLog::print(double *v, int size) {
	unique_lock<mutex> lck(mtx, defer_lock);
	lck.lock();
	for (int i = 0; i < size; i++) {
		cout << v[i];
		if (i != size - 1) {
			cout << ", ";
		}
	}
	lck.unlock();
}

ConsoleLog::~ConsoleLog()
{
}
