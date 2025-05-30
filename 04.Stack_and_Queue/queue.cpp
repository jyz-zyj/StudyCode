#include<iostream>
template<typename T>
class Queue {
private:
	T * _elem;
	int _size;
	int _capacity;
	int front;
	int rear;
	void expand() {
		if (_size == _capacity) {
			T * old_elem = _elem;
			int old_capacity = _capacity;
			_capacity *= 2;
			_elem = new T[_capacity];
			for (int i = 0; i < _size; i++) {
				int pos = (i + front) % old_capacity;
				_elem[i] = old_elem[pos];
			}
			front = 0;
			rear = _size;
			delete old_elem;
		}
	}
public:
	Queue() : _size(0), _capacity(10), front(0), rear(0) {
		_elem = new T [_capacity];
	}
	~Queue() {
		delete _elem;
	}
	bool empty() {
		if (_size == 0)
			return 1;
		return 0;
	}
	bool full() {
		if (_size == _capacity)
			return 1;
		return 0;
	}
	void enqueue(T const &e) {
		expand();
		_elem[rear] = e;
		rear = (rear + 1) % _capacity;
		_size++;
	}
	T dequeue() {
		T e;
		e = _elem[front];
		front = (front + 1) % _capacity;
		_size--;
		return e;
	}
	void print() {
		for (int i = 0; i < _size; i++) {
			int pos = (i + front) % _capacity;
			std::cout << _elem[pos] << " ";
		}
		std::cout << std::endl;
	}
	T first(){
		return _elem[front];
	}
};
void menu() {		//菜单
	std::cout << std::endl;
	std::cout << "=========================================" << std::endl;
	std::cout << "            循环队列操作菜单             " << std::endl;
	std::cout << "  1 : 队列插入元素   2 : 查看队首元素    " << std::endl;
	std::cout << "  3 : 删除队首元素   4 : 查询是否为空    " << std::endl;
	std::cout << "  5 : 舞伴配对函数   0 : 销毁退出程序    " << std::endl;
	std::cout << "=========================================" << std::endl;
	std::cout << "请输入您的操作: ";
}
int main() {
	Queue<int> queue;
	int op = 1;
	int e;
	while(op){
		menu();
		std::cin >> op;
		if(op == 1){
			std::cout << "请输入要插入的数据: ";
			std::cin >> e;
			queue.enqueue(e);
			std::cout << "数据插入完成,请继续操作!" << std::endl;
		} else if(op == 2){
			if(queue.empty()){
				std::cout << "当前队列为空,请重新操作!" << std::endl;
			}
			else{
				std::cout << "队首数据为: " << queue.first() << " ,请继续操作!";
			}
		} else if(op == 3){
			if(queue.empty()){
				std::cout << "当前队列为空,请重新操作!" << std::endl;	
			} else{
				queue.dequeue();
				std::cout << "队首元素已删除,请继续操作!" << std::endl;	
			}
		} else if(op == 4){
			if(queue.empty()){
				std::cout << "当前队列为空,请继续操作!" << std::endl;	
			}else{
				std::cout << "当前队列非空,请继续操作!" << std::endl;
			}
		}
	}
}

