#include"BinanyTree.h"
int main(){
	BinTree<int> tree;
	Node(int) root = tree.insertAsRoot(1);
	root->insertAsLchild(2);
	root->insertAsRchild(3);
	tree.visit_pos();
}
