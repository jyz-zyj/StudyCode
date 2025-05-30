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
	void visit_pre() {	//先序遍历
		Node(T) root = _root;
		stack<Node(T)> s;
		while (true) {
			while (root) {
				std::cout << root->data;
				if (root->Rchild)
					s.push(root->Rchild);
				root = root->Lchild;
			}
			if (s.empty())
				break;
			root = s.pop();
		}
	}
	void visit_in() {	//中序遍历
		stack<Node(T)> s;
		Node(T) root = _root;
		while (true) {
			while (root) {
				s.push(root);
				root = root->Lchild;
			}
			if (s.empty())
				break;
			root = s.pop();
			std::cout << root->data;
			root = root->Rchild;
		}
	}
	void visit_pos() {
		stack<Node(T)> s;
		Node(T) root = _root;
		s.push(root);
		while (!s.empty()) {
			if (s.top() != root->parent) {	//如果不是父节点，则为其右兄弟，需要先遍历其右兄弟，再回到父节点
				while (Node(T)cur = s.top()) {
					if (cur->Lchild) {
						if (cur->Rchild)
							s.push(cur->Rchild);
						s.push(cur->Lchild);
					} else {
						s.push(cur->Rchild);
					}
				}
				s.pop();
			}
			root = s.pop();
			std::cout << root->data;
		}
	}
	void insertAsLeftTree(BinTree<T>& y, Node(T) x) {
		x->Lchild = y._root;
		x->Lchild->parent = x;
	}
	void insertAsRightTree(BinTree<T>& y, Node(T) x) {
		x->Rchild = y._root;
		x->Rchild->parent = x;
	}
	Node(T) LeftChild(Node(T) root) {
		return root->Lchild;
	}
	Node(T) RightChild(Node(T) root) {
		return root->Rchild;
	}
};
