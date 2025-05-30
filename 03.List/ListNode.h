#include<iostream>
#define Rank int
template<typename T> struct ListNode;
template<typename T> using ListNodePosi = ListNode<T>*;
// 错误:template<typename T> typedef ListNode<T>* ListNodePosi;
// 当定义一个模板别名的时候,应该使用using关键字而不是typedef,  typedef 不能直接用于定义模板别名;
template<typename T> struct ListNode {
	T data;					//数据
	ListNodePosi<T> pred;	//前驱
	ListNodePosi<T> succ;	//后继
	ListNode() {}	//针对head和tail的构造
	ListNode(T const& e, ListNodePosi<T> p = nullptr, ListNodePosi<T> s = nullptr)
		: data(e), pred(p), succ(s) {}	//默认构造器
	ListNodePosi<T> insertPred(T const& e) {
		ListNodePosi<T> cur = new ListNode(e, pred, this);	//这里的pred和succ是隐式访问 等同于this->pred,this->succ
		pred->succ = cur;
		pred = cur;
		return cur;
	}	//紧靠当前节点之前插入新节点
	ListNodePosi<T> insertSucc(T const& e) {
		ListNodePosi<T> cur = new ListNode(e, this, succ);
		succ->pred = cur;
		succ = cur;
		return cur;
	}   //仅靠当前节点之后插入新节点
};

