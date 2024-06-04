#pragma once
#include <iostream>
#include <memory>
#include <initializer_list>

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
	std::unique_ptr<Node<T>[]> mainList;
	int size = 10, ip = 0;
	const double RESIZE_THRESHOLD = 0.89;

public:
	ArrayList(int capacity = 10) : mainList(std::make_unique<Node<T>[]>(capacity)), size(capacity) {}

	ArrayList(const ArrayList& other) : ArrayList(other.size) {
		std::copy(other.mainList.get(), other.mainList.get() + other.ip, mainList.get());
		ip = other.ip;
	}

	ArrayList(ArrayList&& other) noexcept : mainList(std::move(other.mainList)), size(other.size), ip(other.ip) {
		other.size = 0;
		other.ip = 0;
	}

	ArrayList& operator=(ArrayList other) {
		swap(*this, other);
		return *this;
	}

	void push(const T& data) {
		if (((double)(ip + 1) / size) > RESIZE_THRESHOLD) {
			resize();
		}
		mainList[ip].data = data;
		mainList[ip].id = ip;
		ip++;
	}

	void emplace(T&& data) {
		if (((double)(ip + 1) / size) > RESIZE_THRESHOLD) {
			resize();
		}
		mainList[ip].data = std::move(data);
		mainList[ip].id = ip;
		ip++;
	}

	void resize() {
		size *= 2;
		auto newList = std::make_unique<Node<T>[]>(size);
		std::copy(mainList.get(), mainList.get() + ip, newList.get());
		mainList = std::move(newList);
	}

	void del(int index) {
		if (index < 0 || index >= ip) {
			std::cout << "Wrong index del" << std::endl;
			return;
		}
		for (int i = index; i < ip - 1; i++) {
			mainList[i] = mainList[i + 1];
			mainList[i].id = i;
		}
		ip--;
	}

	int getSize() const {
		return ip;
	}

	T get(int i) const {
		if (i >= 0 && i < ip) {
			return mainList[i].data;
		}
		throw std::out_of_range("Index out of range");
	}

	T& at(int i) {
		if (i >= 0 && i < ip) {
			return mainList[i].data;
		}
		throw std::out_of_range("Index out of range");
	}

	const T& at(int i) const {
		if (i >= 0 && i < ip) {
			return mainList[i].data;
		}
		throw std::out_of_range("Index out of range");
	}

	void set(const T& data, int i) {
		mainList[i].data = data;
	}

	bool isEmpty() const {
		return getSize() == 0;
	}

	bool contains(const T& data) const {
		for (int i = 0; i < getSize(); i++) {
			if (data == mainList[i].data) {
				return true;
			}
		}
		return false;
	}

	T& operator[](int i) {
		return mainList[i].data;
	}

	const T& operator[](int i) const {
		return mainList[i].data;
	}

	auto begin() {
		return std::make_move_iterator(mainList.get());
	}

	auto end() {
		return std::make_move_iterator(mainList.get() + ip);
	}

	friend void swap(ArrayList& first, ArrayList& second) noexcept {
		using std::swap;
		swap(first.mainList, second.mainList);
		swap(first.size, second.size);
		swap(first.ip, second.ip);
	}
};
