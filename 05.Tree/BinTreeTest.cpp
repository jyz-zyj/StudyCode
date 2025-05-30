#include"BinanyTree.h"
int main() {
	BinTree<int> tree;
	BinTree<int> tree2;
	BinTree<int> tree3;
	Node(int) root1 = tree.insertAsRoot(1);
	root1->insertAsLchild(2);
	root1->insertAsRchild(3);
	Node(int) root2 = tree2.insertAsRoot(4);
	Node(int) root3 = tree3.insertAsRoot(5);
	tree.insertAsLeftTree(tree2, root1->Lchild);
	tree.insertAsRightTree(tree3, root1->Lchild);
	tree.visit_pre();
}
