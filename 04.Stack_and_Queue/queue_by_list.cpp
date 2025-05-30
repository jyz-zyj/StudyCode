#include<iostream>
template<typename T>
class Queue_by_list{
private:
	struct Node {
		T data;
		Node* pred;
		Node* succ;
		Node(T const& e,Node* p = nullptr,Node *s = nullptr) : data(e), pred(p), succ(s) {}
	};
	Node* header;
	Node* trailer;
	int _size;
public:
	void init() {
		header = new Node(T());
		trailer = new Node(T());
		header->succ = trailer;
		header->pred = trailer->pred;
		trailer->pred = header;
		trailer->succ = header->succ;
		_size = 0;
	}
	Queue() {
		init();
	}
	~Queue(){
		
	}
	void enqueue(T const& e) {
		Node* cur = new Node(e, trailer->pred, trailer);
		trailer->pred->succ = cur;
		trailer->pred = cur;
		_size++;
	}
	void print() {
		Node* cur = header->succ;
		while (cur != trailer) {
			std::cout << cur->data << " ";
			cur = cur->succ;
		}
		std::cout << std::endl;
	}
	T front(){
		return header->succ->data;
	}
	T dequeue(){
		Node* cur = header->succ;	
		header->succ = cur->succ;
		cur->succ->pred = header;
		_size--;
		T e = cur->data;
		delete cur; 
		return e;
	}
	int size(){
		return _size;
	}

};
int main() {
	Queue<int> queue;
	queue.enqueue(5);
	queue.enqueue(6);
	queue.enqueue(7);
	queue.dequeue();
	queue.print();
	std::cout << queue.size();
	return 0;
}
