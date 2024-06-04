#pragma once
#include <iostream>


template<typename T>
struct Node {
	T data;
	int id;
	Node(const T data, int id) : data(data), id(id) {}
	Node(const Node& other) : data(other.data), id(other.id) {}
	Node() {}
};

template <typename T>
class ArrayList {
private:

	Node<T>* mainList;
	int size = 10, ip = 0;
	const double RESIZE_TRESHHOLD = 0.89;

public:
	ArrayList() : mainList(nullptr) {
		mainList = new Node<T>[size];
	}

	~ArrayList() {
		delete[] mainList;
	}

	ArrayList(const ArrayList& other) : mainList(nullptr) {
		size = other.size;
		ip = other.ip;
		mainList = new Node<T>[size];
		for (int i = 0; i < ip; i++) {
			mainList[i] = other.mainList[i];
		}
	}

	ArrayList& operator=(const ArrayList& other) {
		if (this != &other) {
			delete[] mainList;
			size = other.size;
			ip = other.ip;
			mainList = new Node<T>[size];
			for (int i = 0; i < ip; i++) {
				mainList[i] = other.mainList[i];
			}
		}
		return *this;
	}

	void push(const T& data) {
		if (((double)(ip + 1) / size) > RESIZE_TRESHHOLD) {
			resize();
		}
		mainList[ip].data = data;
		mainList[ip].id = ip;
		ip++;
	}

	void resize() {
		size *= 2;
		Node<T>* newList = new Node<T>[size];
		for (int i = 0; i < ip; i++) {
			newList[i] = mainList[i];
		}
		delete[] mainList;
		mainList = newList;
		return;
	}

	void del(int index) {
		if (index < 0 || index >= ip) {
			std::cout << "Wrong index del" << std::endl;
			return;
		}
		Node<T>* newList = new Node<T>[size];
		int j = 0;
		for (int i = 0; i < ip; i++) {
			if (i == index) {
				continue;
			}
			newList[j] = mainList[i];
			newList[j].id = j;
			j++;
		}
		ip--;
		delete[] mainList;
		mainList = newList;
		return;
	}

	int getSize() {
		return ip;
	}

	T get(int i) {
		if (i >= 0 && i < ip) {
			return mainList[i].data;
		}
		return Node<T>().data;
	}

	void set(const T& data, int i) {
		mainList[i].data = data;
	}

	bool isEmpty() {
		return getSize() == 0;
	}

	bool contains(const T& data) {
		for (int i = 0; i < getSize(); i++) {
			if (data == mainList[i].data) {
				return true;
			}
		}
		return false;
	}

	//void finalResize() {
	//	Node<T>* newList = new Node<T>[ip];
	//	for (int i = 0; i < ip; i++) {
	//		newList[i] = mainList[i];
	//	}
	//	mainList = newList;
	//	size = ip;
	//	return;
	//}
};