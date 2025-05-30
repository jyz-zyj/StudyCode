#define Node(T) BinNode<T>*
typedef enum {
	RB_RED,
	RB_BLACK
} RBcolor;
template<typename T> struct BinNode {
	T data;
	BinNode* parent;
	BinNode* Lchild;
	BinNode* Rchild;
	int height;
	int npl;
	RBcolor color;
	BinNode(): parent(nullptr), Lchild(nullptr), Rchild(nullptr), height(0), npl(1), color(RB_RED) {}
	BinNode(T e, BinNode<T>* p = nullptr, BinNode<T>* lc = nullptr, BinNode<T>* rc = nullptr) :
		data(e), parent(p), Lchild(lc), Rchild(rc), height(0), npl(1), color(RB_RED) {}
	Node(T) insertAsLchild(T const e) {
		return Lchild = new BinNode(e, this);
	}
	Node(T) insertAsRchild(T const e) {
		return Rchild = new BinNode(e, this);
	}
};

