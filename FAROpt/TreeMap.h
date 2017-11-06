#pragma once
#include<string>

template <class T>
class TreeMap {
private: 
	class TreeElem {
	public:
		TreeElem(std::string key, T &t);
	private:
		TreeElem *left;
		TreeElem *right;
		T t;
		std::string key;
	};

	TreeElem *root;

	void remove(TreeElem *elem);
	void insert(std::string &key, T& value, TreeElem *elem);
	T *search(std::string &key, TreeElem *elem);
	
public:
	TreeMap();
	~TreeMap();

	void set(std::string &key, T& value);
	T *get(std::string &key);
};

