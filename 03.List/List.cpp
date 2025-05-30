#include"ListNode.h"
template<typename T> class List {
private:
	Rank _size;				//规模
	ListNodePosi<T> header;	//头节点
	ListNodePosi<T> trailer;	//尾节点
private:
	void init() {	//构造函数调用init进行初始化
		header = new ListNode<T>;
		trailer = new ListNode<T>;
		header->pred = nullptr;
		header->succ = trailer;
		trailer->pred = header;
		trailer->succ = nullptr;
		_size = 0;
	}
	int clear() { //清空所有节点
		int old_size = _size;
		while (0 < _size) {
			remove(header->succ);
		}
		return old_size;
	};

public:
	List() {		//构造函数
		init();
	}
	~List() {		//析构函数,先删除所有节点,再删除头尾节点
		clear();
		delete header;
		delete trailer;
	}
	ListNodePosi<T> first() {
		return header->succ;
	}
	ListNodePosi<T> last() {
		return trailer->pred;
	}
	T& operator[](Rank r) {
		ListNodePosi<T> cur = first();
		while (r-->0)
			cur = cur->succ;
		return cur->data;
	}
	ListNodePosi<T> find(T const&e, int n, ListNodePosi<T> p) {
		ListNodePosi<T> cur = p->pred;
		while (n-- > 0) {
			if (cur->data == e)
				return cur;
			else
				cur = cur->pred;
		}
		return nullptr;
	}
	ListNodePosi<T> find(T const& e) {
		return find(e, _size, trailer);
	}
	ListNodePosi<T> search(T const&e, int n, ListNodePosi<T> p) {
		while (n-->0) {
			if ((p = p->pred)->data <= e) {
				break;
			}
			return p;
		}
	}
	ListNodePosi<T> search(T const&e) {
		return search(e, _size, trailer);
	}
	ListNodePosi<T> insertAsFrist(T const& e) {
		_size++;
		return header->insertSucc(e);
	}
	ListNodePosi<T> insertAsLast(T const& e) {
		_size++;
		return trailer->insertPred(e);
	}
	ListNodePosi<T> insertA(T const&e, ListNodePosi<T> p) {
		_size++;
		return p->insertSucc(e);
	}
	ListNodePosi<T> insertB(T const&e, ListNodePosi<T> p) {
		_size++;
		return p->insertPred(e);
	}
	void print() {
		ListNodePosi<T> cur = first();
		while (cur != trailer) {
			std::cout << cur->data << " ";
			cur = cur->succ;
		}
		std::cout << std::endl;
	}
	void print(ListNodePosi<T> p) {
		std::cout << p->data;
		std::cout << std::endl;
	}
	int size() {
		return _size;
	}
	void copyNodes(ListNodePosi<T> p, int n) {
		init();
		while (n--) {
			insertAsLast(p->data);
			p = p->succ;
		}
	}
	T remove(ListNodePosi<T> p) {
		p->pred->succ = p->succ;
		p->succ->pred = p->pred;
		T e = p->data;
		_size--;
		delete p;
		return e;
	}
	int deduplicate() {	//无序去重
		if (_size < 2)
			return 0;
		int old_size = _size;
		ListNodePosi<T> p = header->succ;
		Rank r = 0;
		while (p != trailer) {
			ListNodePosi<T> q = find(p->data, r, p);
			q ? remove(q) : r++;
			p = p->succ;
		}
		return old_size - _size;
	}
	ListNodePosi<T> del(ListNodePosi<T> p) {
		ListNodePosi<T> q = p->succ;
		p->pred->succ = p->succ;
		p->succ->pred = p->pred;
		_size--;
		delete p;
		return q;
	}
	int uniquify() {
		int old_size = _size;
		ListNodePosi<T> p = first();
		ListNodePosi<T> q;
		while (trailer != (q = p->succ)) {  //当q==trailer时p处于末节点位置,刚好遍历了一遍;
			if (q->data == p->data) {
				remove(q);
			} else {
				p = q;
			}
		}
		return old_size - _size;
	}
};
int main() {
	List<int> L;
	L.insertAsLast(6);
	L.insertAsLast(7);
	L.insertAsLast(7);
	L.insertAsLast(7);
	L.insertAsLast(7);
	L.insertAsLast(7);
	L.insertAsLast(10);
	L.print();
	L.uniquify();
	L.print();

}
