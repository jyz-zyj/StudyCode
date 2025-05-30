template<typename T>class stack {
private:
	int _size;
	int _capacity;
	T* data;
public:
	stack(): _size(0), _capacity(20), data(new T[_capacity]) {}
	~stack() {
		delete[] data;
	}
	void push(T e) {
		data[_size] = e;
		_size++;
	}
	T top() {
		return data[_size - 1];
	}
	T pop() {
		_size--;
		return data[_size];
	}
	bool empty() {
		return !_size;
	}
};
