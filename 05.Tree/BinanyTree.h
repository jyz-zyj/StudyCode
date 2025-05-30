#include"BinNode.h"
#include"Stack.h"
#include<iostream>
template<typename T>class BinTree {
private:
	int _size;
	Node(T) _root;
	int updateHeight(Node(T) x);
	void updateHeightAbove(Node(T) x);
public:
	BinTree() : _size(0), _root(nullptr) {}
	~BinTree() {
	}
	int size() {
		return _size;
	}
	bool empty() {
		return !_root;
	}
	Node(T) insertAsRoot(T e) {
		_size = 1;
		return _root = new BinNode<T>(e);
	}
	Node(T) insertAsLchild(Node(T) x, T e) {
		_size++;
		x->insertAsLchild(e);
		updateHeightAbove(x);
		return x->Lchild;
	}
	Node(T) insertAsLchild(T e, Node(T) x) {
		_size++;
		x->insertAsRchild(e);
		updateHeightAbove(x);
		return x->Rchild;
	}
	void visit_pos() {
		Node(T) root = _root;
		stack<Node(T)> s;
		while (true) {
			while (root) {
				std::cout << root->data;
				if (root->Rchild)
					s.push(root->Rchild);
				root = root->Lchild;
			}
			if (!s.empty())
				break;
			root = s.pop();
		}
	}
};
