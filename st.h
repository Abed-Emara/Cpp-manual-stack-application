#include <iostream>
using namespace std;

template <class T>

class stack {
	int capacity;
	int elements;
	T* array_stack;

public:

	stack(int e, int c) {
		elements = e;
		capacity = c;
		array_stack = new T[c];
		for (int i = 0; i < elements; i++) {
			cout << "enter element num " << i + 1 << ": ";
			cin >> array_stack[i];
		}
	}
		
	~stack() {
		delete[]array_stack;
		array_stack = nullptr;
	}
		
	void push(T newValue) {
		if (capacity == elements) {
			Expand();
		}
		array_stack[elements++] = newValue;
	}

	T pop() {
		int tmp;
		if (elements == 0) {
			throw runtime_error("<!> Stack is Empty <!>");
		}
		else {
			elements--;
			tmp = array_stack[elements];
		}
		if (capacity > (elements + 5)) {
			Shrink();
		}
		return tmp;
	}
	
	void Expand() {
		if (capacity == 0)
			this->capacity++;
		else
			this->capacity *= 2;
		T* new_arr = new T[capacity];
		for (int i = 0; i < elements; i++) {
			new_arr[i] = array_stack[i];
		}
		delete[]array_stack;
		array_stack = new_arr;
	}
	
	int getElements() {
		return elements;
	}
	
	void Shrink() {
		if (capacity <= 5)return;
		this->capacity -= 5;
		T* new_arr = new T[capacity];
		for (int i = 0; i < elements; i++) {
			new_arr[i] = array_stack[i];
		}
		delete[]array_stack;
		array_stack = new_arr;
	}
};

