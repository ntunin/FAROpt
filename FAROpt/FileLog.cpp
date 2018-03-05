#include "stdafx.h"
#include "FileLog.h"
#include <iostream>

using namespace std;


FileLog::FileLog(string path) {
	file = new ofstream;
	file->open(path, std::ofstream::app);
}

void FileLog::print(double d) {
	unique_lock<mutex> lck(consoleMtx, defer_lock);
	lck.lock();
	(*file) << d;
	lck.unlock();
}


void FileLog::print(double d, int size) {
	unique_lock<mutex> lck(consoleMtx, defer_lock);
	lck.lock();
	std::stringstream s;
	s << d;
	std::string str = s.str();
	if ((int)d == d && str.length() < size) {
		str.append(".");
	}
	for (int i = 0; i < size && i < str.length(); i++) {
		(*file) << str[i];
	}
	for (int i = str.length(); i < size; i++) {
		(*file) << "0";
	}
	lck.unlock();
}

void FileLog::print(string &m) {
	unique_lock<mutex> lck(consoleMtx, defer_lock);
	lck.lock();
	(*file) << m;
	lck.unlock();
}

void FileLog::print(const char *m) {
	unique_lock<mutex> lck(consoleMtx, defer_lock);
	lck.lock();
	(*file) << m;
	lck.unlock();
}


void FileLog::print(ComplexMatrix &m) {
	unique_lock<mutex> lck(consoleMtx, defer_lock);
	lck.lock();
	for (int i = 0; i < m.length(); i++) {
		for (int j = 0; j < m.width(); j++) {
			(*file) << ((int)(m[i][j].Re() * 100000) / 100000.0);
			(*file) << "+";
			(*file) << ((int)(m[i][j].Im() * 100000) / 100000.0);
			(*file) << "i";
			if (i != m.length() - 1) {
				(*file) << "\t";
			}
		}
		cout << endl;
	}
	lck.unlock();
}

void FileLog::print(double **m, int size) {
	unique_lock<mutex> lck(consoleMtx, defer_lock);
	lck.lock();
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			(*file) << m[i][j];
			if (j != size - 1) {
				(*file) << "\t";
			}
		}
		(*file) << endl;
	}
	lck.unlock();
}


void FileLog::print(ComplexVector &v) {
	unique_lock<mutex> lck(consoleMtx, defer_lock);
	lck.lock();
	for (int i = 0; i < v.length(); i++) {
		(*file) << v[i].Re();
		(*file) << "\t";
		(*file) << v[i].Im();
		(*file) << "\t";
	}
	lck.unlock();
}

void FileLog::print(double *v, int size) {
	unique_lock<mutex> lck(consoleMtx, defer_lock);
	lck.lock();
	for (int i = 0; i < size; i++) {
		(*file) << v[i];
		if (i != size - 1) {
			(*file) << "\t ";
		}
	}
	lck.unlock();
}

void FileLog::reset() {
	(*file) << "\n\n=============================\n\n";
}

FileLog::~FileLog()
{
	file->close();
}
