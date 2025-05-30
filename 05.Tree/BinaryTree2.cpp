#include<iostream>
using namespace std;
template<typename T> class Stack {
private:
	T * _elem;
	int _size;
	int default_capicity;
public:
	Stack(): _size(0), default_capicity(20) {
		_elem = new T[default_capicity];
	}
	~Stack() {
		delete[] _elem;
	}
	void push(T const e) {
		_elem[_size] = e;
		_size++;
	}
	T top() {
		return _elem[_size - 1];
	}
	T pop() {
		return _elem[--_size];
	}
	bool empty() {
		if (_size == 0)
			return true;
		return false;
	}
};
template<typename T> struct Node {
	Node *parent,*Lchild,*Rchild;
	T data;
	Node() {}
	Node(T e, Node<T>* p = nullptr, Node<T>* lc = nullptr, Node<T>* rc = nullptr) {
		data = e;
		parent = p;
		Lchild = lc;
		Rchild = rc;
	}
	void insert_Lchild(T const e) {
		Lchild = new Node<T>(e, this);
	}
	void insert_Rchild(T const e) {
		Rchild = new Node<T>(e, this);
	}
};
template<typename T> class Tree {
private:
	Node<T> * _root;
	int _size;
	int max(int a, int b) {
		if (a >= b)
			return a;
		return b;
	}
	int _depth(Node<T>* root) {
		if (root == nullptr)
			return 0;
		return max( _depth(root->Lchild), _depth(root->Rchild)) + 1;
	}
	int _leaves(Node<T>* root) {
		if (root == nullptr)
			return 0;
		if (root->Rchild == nullptr && root->Lchild == nullptr)
			return 1;
		return _leaves(root->Lchild) + _leaves(root->Rchild);
	}
public:
	Tree() {
		_root = nullptr;
		_size = 0;
	}
	~Tree() {
		clear(_root);
	}
	void clear(Node<T>* root) {
		if (root == nullptr)
			return;
		clear(root->Lchild);
		clear(root->Rchild);
		delete root;
	}
	void insert_LChild(Node<T>* root, T const e) {
		root->insert_Lchild(e);
	}
	void insert_RChild(Node<T>* root, T const e) {
		root->insert_Rchild(e);
	}
	void build_tree() {
		char s;
		cin >> s;
		if (s != '#') {
			_root = new Node<T>(s);
			insert(_root);
		}
	}
	void insert(Node<T>* root) {
		char s;
		cin >> s;
		if (s != '#') {
			root->insert_Lchild(s);
			insert(root->Lchild);
		}
		cin >> s;
		if (s != '#') {
			root->insert_Rchild(s);
			insert(root->Rchild);
		}
	}
	void visit_pre() {
		Node<T> * root = _root;
		Stack<Node<T>*> s;
		while (true) {
			while (root) {
				cout << root->data << ' ';
				if (root->Rchild)
					s.push(root->Rchild);
				root = root->Lchild;
			}
			if (s.empty())
				break;
			root = s.pop();
		}
		cout << endl;
	}
	void visit_in() {
		Stack<Node<T>*> s;
		Node<T>* root = _root;
		while (true) {
			while (root) {
				s.push(root);
				root = root->Lchild;
			}
			if (s.empty())
				break;
			root = s.pop();
			cout << root->data << ' ';
			root = root->Rchild;
		}
		cout << endl;
	}
	void visit_pos() {
		Stack<Node<T>*> s;
		Node<T>* root = _root;
		s.push(root);
		while (!s.empty()) {
			if (root->parent != s.top()) {
				while (Node<T>* root = s.top()) {
					if (root->Lchild) {
						if (root->Rchild)
							s.push(root->Rchild);
						s.push(root->Lchild);
					} else {
						s.push(root->Rchild);
					}
				}
				s.pop();
			}
			root = s.pop();
			cout << root->data << ' ';
		}
		cout << endl;
	}
	int depth() {
		return _depth(_root);
	}
	int leaves() {
		return _leaves(_root);
	}
};
void menu() {		//菜单
	std::cout << "===================================" << std::endl;
	std::cout << "           二叉树操作菜单          " << std::endl;
	std::cout << "    1 : 建二叉树   2 : 先序遍历    " << std::endl;
	std::cout << "    3 : 中序遍历   4 : 后序遍历    " << std::endl;
	std::cout << "    5 : 统计深度   6 : 统计叶数    " << std::endl;
	std::cout << "           0 ：退出程序            " << std::endl;
	std::cout << "请输入您的操作: ";
}
int main() {
	Tree<char> tree;
	int op = 1;
	while (op) {
		menu();
		cin >> op;
		if (op == 1) {
			cout << "请按先序顺序构建树：";
			tree.build_tree();
			cout << "树已经构建完成!" << endl;
		} else if (op == 2) {
			cout << "先序遍历为：";
			tree.visit_pre();
		} else if (op == 3) {
			cout << "先序遍历为：";
			tree.visit_in();
		} else if (op == 4) {
			cout << "先序遍历为：";
			tree.visit_pos();
		} else if (op == 5) {
			cout << "当前树的深度为：" << tree.depth() << endl;
		} else if (op == 6) {
			cout << "当前叶节点数量为：" << tree.leaves() << endl;
		} else if ( op == 0) {
			cout << "程序结束!" << endl;
		} else {
			cout << "输入错误,请重新操作!" << endl;
		}
	}
	return 0;
}
