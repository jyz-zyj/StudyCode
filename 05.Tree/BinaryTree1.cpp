#include<iostream>
using namespace std;
template<typename T> class stack {
private:
	T *_elem;
	int _size;
	int default_size = 20;
public:
	stack() {
		_elem = new T[default_size];
		_size = 0;
	}
	~stack() {
		delete []_elem;
	}
	void push(T const e) {
		_elem[_size] = e;
		_size++;
	}
	T pop() {
		_size--;
		return _elem[_size];

	}
	T top() {
		return _elem[_size - 1];
	}
	bool empty() {
		if (_size == 0)
			return true;
		return false;
	}
};
template<typename T> struct Node {
	T data;
	Node *parent, *LChild, *RChild;
	Node() {
		parent = nullptr, LChild = nullptr, RChild = nullptr;
	}
	Node(T e) {
		parent = nullptr, LChild = nullptr, RChild = nullptr;
		data = e;
	}
	Node(T e, Node<T>* x) {
		parent = x, LChild = nullptr, RChild = nullptr;
		data = e;
	}
	Node* insertAsLC(T e) {
		return LChild = new Node(e, this);
	}
	Node* insertAsRC(T e) {
		return RChild = new Node(e, this);
	}
};
template<typename T> class BinTree {
private:
	int _size;
	Node<T>* _root;
public:
	BinTree() : _size(0), _root(NULL) {}
	~BinTree() {
	}
	int size() {
		return _size;
	}
	Node<T>* insertAsRoot(T const e) {
		_size = 1;
		return _root = new Node<T>(e);
	}
	Node<T>* insertAsLChild(Node<T>* x, T const e) {
		_size++;
		x->insertAsLC(e);
		return x->LChild;
	}
	Node<T>* insertAsRChild(Node<T>* x, T const e) {
		_size++;
		x->insertAsRC(e);
		return x->RChild;
	}
	void pre_visit(Node<T>* x) {
		if (!x)
			return;
		cout << x->data << " ";
		pre_visit(x->LChild);
		pre_visit(x->RChild);
	}
	void in_visit(Node<T>* x) {
		if (!x)
			return;
		in_visit(x->LChild);
		cout << x->data << " ";
		in_visit(x->RChild);
	}
	void post_visit(Node<T>* x) {
		if (!x)
			return;
		post_visit(x->LChild);
		post_visit(x->RChild);
		cout << x->data << " ";
	}
	void visit_pre1(Node<T>* x) {
		stack<Node<T>*> s;
		s.push(x);
		while (!s.empty()) {
			x = s.pop();
			cout << x->data << " ";
			if (x->RChild) s.push(x->RChild);
			if (x->LChild) s.push(x->LChild);
		}
	}
	void visit_pre2(Node<T>* x) {
		stack<Node<T>*> s;
		while (true) {
			while (x) {
				cout << x->data << " ";
				if (x->RChild)
					s.push(x->RChild);
				x = x->LChild;
			}
			if (s.empty())
				break;
			x = s.pop();
		}
	}
	void visit_in1(Node<T>* x) {
		stack<Node<T>*> s;
		while (true) {
			while (x) {
				s.push(x);
				x = x->LChild;
			}
			if (s.empty())
				break;
			x = s.pop();
			cout << x->data << " ";
			x = x->RChild;
		}
	}
	void visit_in2(Node<T>* x) {
		stack<Node<T>*> s;
		while (true) {
			if (x) {
				s.push(x);
				x = x->LChild;
			} else if (!s.empty()) {
				x = s.pop();
				cout << x->data << " ";
				x = x->RChild;
			} else {
				break;
			}
		}
	}
	void visit_post(Node<T>* x) {
		stack<Node<T>*> s;
		if (x) s.push(x);
		while (!s.empty()) {
			if (s.top() != x->parent) {
				while (Node<T>* r = s.top()) {
					if (r->LChild) {
						if (r->RChild) {
							s.push(r->RChild);
						}
						s.push(r->LChild);
					} else {
						s.push(r->RChild);
					}
				}
				s.pop();
			}
			x = s.pop();
			cout << x->data << " ";
		}
	}
	int depth(Node<T>* x) {
		int dep = 0;
		while (x != _root) {
			x = x->parent;
			dep++;
		}
		return dep;
	}
	int leaves(Node<T>* x){
		if( !x )
			return 0;
		if( !x->LChild && !x->RChild)
			return 1;
		return leaves(x->LChild) + leaves(x->RChild);
	}
	void creat_tree(Node<T>* root){
		char s;
		cin >> s;
		if(s=='#')
			root = nullptr;
		else
			root = new Node<T>(s);
		creat_tree(root->LChild);
		creat_tree(root->RChild);
		_size++;
	}
};

int main() {
	BinTree<int> tree;
	Node<int> * root = nullptr;
	tree.creat_tree(root);
	tree.pre_visit(root);
}
