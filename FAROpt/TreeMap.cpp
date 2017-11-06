#include "stdafx.h"
#include "TreeMap.h"

using namespace std;

template<class T> 
TreeMap<T>::TreeMap() {

}


template<class T> 
TreeMap<T>::~TreeMap() {
	this->remove(this->root);
}

template<class T> 
void TreeMap<T>::remove(typename TreeMap<T>::TreeElem *elem) {
	if (!elem) {
		return;
	}
	this->remove(elem->left);
	this->remove(elem->left);
	if (elem->left) {
		delete elem->left;
		elem->left = NULL;
	}
	if (elem->right) {
		delete elem->right;
		elem->right = NULL;
	}
}


template<class T>
TreeMap<T>::TreeElem::TreeElem(string key, T &t) {
	this->t = t;
	this->key = key;
}

template<class T>
void TreeMap<T>::set(string &key, T &t) {
	if (this->root) {
		this->insert(key, t, this->root);
	} else {
		this->root = new TreeElem(key, t);
	}
}

template<class T>
void TreeMap<T>::insert(std::string &key, T &value, typename TreeMap<T>::TreeElem *elem) {
	if (!elem) {
		return;
	}
	if (key < elem->key) {
		if (elem->left) {
			this->insert(key, value, elem->left);
		}
		else {
			elem->left = new TreeElem(key, value);
		}
	} else {
		if (elem->right) {
			this->insert(key, value, elem->right);
		}
		else {
			elem->right = new TreeElem(key, value);
		}
	}
}

template<class T>
T *TreeMap<T>::get(string &key) {
	return this->search(key, this->root);
}

template<class T>
T *TreeMap<T>::search(std::string &key, typename TreeMap<T>::TreeElem *elem) {
	if (!elem) {
		return NULL;
	}
	if (key < elem->key) {
		this->search(key, elem->left);
	} else if (key > elem->key) {
		this->search(key, elem->right)
	} else {
		return elem;
	}
}