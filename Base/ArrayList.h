// Include necessary headers for the implementation
#pragma once
#include <iostream>
#include <memory>
#include <initializer_list>

// Define a Node template struct to hold data and id
template<typename T>
struct Node {
    T data; // The data stored in the node
    int id;  // The unique identifier for the node

    // Constructor for initializing the node with data and id
    Node(const T data, int id) : data(data), id(id) {}

    // Copy constructor for creating a copy of the node
    Node(const Node& other) : data(other.data), id(other.id) {}

    // Default constructor
    Node() {}
};

// Define the ArrayList class template with type T
template <typename T>
class ArrayList {
private:
    // Unique pointer to an array of Node<T> objects
    std::unique_ptr<Node<T>[]> mainList;

    // The current size of the array list
    int size;

    // The index of the last element in the array list
    int ip;

    // The threshold for resizing the array list
    const double RESIZE_THRESHOLD;

public:
    // Default constructor with capacity set to 10
    ArrayList(int capacity = 10)
        : mainList(std::make_unique<Node<T>[]>(capacity)), size(capacity), ip(0), RESIZE_THRESHOLD(0.89) {}

    // Copy constructor for creating a deep copy of another ArrayList
    ArrayList(const ArrayList& other)
        : ArrayList(other.size) {
        std::copy(other.mainList.get(), other.mainList.get() + other.ip, mainList.get());
        ip = other.ip;
    }

    // Move constructor for transferring ownership of another ArrayList's resources
    ArrayList(ArrayList&& other) noexcept
        : mainList(std::move(other.mainList)), size(other.size), ip(other.ip) {
        other.size = 0;
        other.ip = 0;
    }

    // Copy assignment operator for swapping resources with another ArrayList
    ArrayList& operator=(ArrayList other) {
        swap(*this, other);
        return *this;
    }

    // Push function for adding an element to the array list
    void push(const T& data) {
        if (((double)(ip + 1) / size) > RESIZE_THRESHOLD) {
            resize();
        }
        mainList[ip].data = data;
        mainList[ip].id = ip;
        ip++;
    }

    // Emplace function for moving an element to the array list
    void emplace(T&& data) {
        if (((double)(ip + 1) / size) > RESIZE_THRESHOLD) {
            resize();
        }
        mainList[ip].data = std::move(data);
        mainList[ip].id = ip;
        ip++;
    }

    // Resize function for doubling the size of the array list
    void resize() {
        size *= 2;
        auto newList = std::make_unique<Node<T>[]>(size);
        std::copy(mainList.get(), mainList.get() + ip, newList.get());
        mainList = std::move(newList);
    }

    // Delete function for removing an element at the given index
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

    // Get size function for retrieving the current size of the array list
    int getSize() const {
        return ip;
    }

    // Get function for retrieving the element at the given index
    T get(int i) const {
        if (i >= 0 && i < ip) {
            return mainList[i].data;
        }
        throw std::out_of_range("Index out of range");
    }

    // At function for retrieving a reference to the element at the given index
    T& at(int i) {
        if (i >= 0 && i < ip) {
            return mainList[i].data;
        }
        throw std::out_of_range("Index out of range");
    }

    // Const at function for retrieving a const reference to the element at the given index
    const T& at(int i) const {
        if (i >= 0 && i < ip) {
            return mainList[i].data;
        }
        throw std::out_of_range("Index out of range");
    }

    // Set function for setting the value of the element at the given index
    void set(const T& data, int i) {
        mainList[i].data = data;
    }

    // Is empty function for checking if the array list is empty
    bool isEmpty() const {
        return getSize() == 0;
    }

    // Contains function for checking if the array list contains a specific element
    bool contains(const T& data) const {
        for (int i = 0; i < getSize(); i++) {
            if (data == mainList[i].data) {
                return true;
            }
        }
        return false;
    }

    // Overloaded index operator for retrieving a reference to the element at the given index
    T& operator[](int i) {
        return mainList[i].data;
    }

    // Overloaded const index operator for retrieving a const reference to the element at the given index
    const T& operator[](int i) const {
        return mainList[i].data;
    }

    // Begin function for retrieving a move iterator pointing to the first element
    auto begin() {
        return std::make_move_iterator(mainList.get());
    }

    // End function for retrieving a move iterator pointing to one past the last element
    auto end() {
        return std::make_move_iterator(mainList.get() + ip);
    }

    // Friend swap function for swapping the resources of two ArrayList objects
    friend void swap(ArrayList& first, ArrayList& second) noexcept {
        using std::swap;
        swap(first.mainList, second.mainList);
        swap(first.size, second.size);
        swap(first.ip, second.ip);
    }
};
