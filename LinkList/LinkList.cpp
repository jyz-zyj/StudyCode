#include<iostream>
class LinkList {
private:
	struct Node {
		int data;
		Node* next;
		Node(const int val = int()) : data(val), next(nullptr) {}
	};
	Node* head;
	int length;
public:
	LinkList() : head(new Node()), length(0) {} 	//构造函数,初始化head为空,链表length为0
	~LinkList() {	//析构函数,释放所有节点
		Node* cur = head;
		while (cur != nullptr) {
			Node* nxt = cur->next;
			delete cur;
			cur = nxt;
		}
	}
	void insert_head(const int val) {    //头插法插入新节点
		Node* cur = new Node(val);
		cur->next  = head->next;
		head->next = cur;
		length++;
	}
	void insert_tail(const int val) {		//尾插法插入新节点
		Node* cur = head;
		while (cur->next != nullptr) {
			cur = cur->next;
		}
		Node* nxt = new Node(val);
		cur->next = nxt;
		length++;
	}
	bool remove_val(const int val) {	  //删除值为val的节点
		if (!head->next)
			return false;
		Node* cur = head->next;
		Node* pre = head;
		while (cur != nullptr) {
			if (cur->data == val) {
				pre->next = cur->next;
				delete cur;
				length--;
				return true;
			}
			pre = cur;
			cur = cur -> next;
		}
		return false;
	}
	bool remove_pos(int pos) {		//删除位置为pos的节点
		if (pos < 1 || pos > length)
			return false;
		Node* cur = head->next;
		Node* pre = head;
		while (1 < pos--) {
			pre = cur;
			cur = cur -> next;
		}
		pre->next = cur->next;
		delete cur;
		length--;
		return true;
	}
	void print() {		//打印链表中所有节点
		Node* cur = head->next;
		while (cur != nullptr) {
			std::cout << cur->data << "  ";
			cur = cur->next;
		}
		std::cout << std::endl;
	}
	void reverseList() {  //链表逆置
		if (head->next == nullptr) return;  // 空链表直接返回
		
		Node *pre = nullptr;
		Node *cur = head->next;
		while (cur != nullptr) {
			Node *nxt = cur->next;
			cur->next = pre;
			pre = cur;
			cur = nxt;
		}
		head->next = pre;  // 保持头节点不变，仅修改其next指针
	}
};
void menu() {		//菜单
	std::cout << std::endl;
	std::cout << "==========================================" << std::endl;
	std::cout << "               链表操作菜单               " << std::endl;
	std::cout << "  1 : 头插法插入节点   2 : 尾插法插入节点 " << std::endl;
	std::cout << "  3 : 按照值删除节点   4 : 按位置删除节点 " << std::endl;
	std::cout << "  5 : 打印链表的节点   6 : 链表元素的逆置 " << std::endl;
	std::cout << "            0 : 销毁并退出程序            " << std::endl;
	std::cout << "==========================================" << std::endl;
	std::cout << "请输入您的操作: ";
}

int main() {
	int op = 1;
	LinkList L;
	while (op) {
		menu();
		std::cin >> op;
		switch (op) {
			case 1: {
				std::cout << "请输入要插入的值:";
				int val;
				std::cin >> val;
				L.insert_head(val);
				std::cout << "插入成功,请继续您的操作!" << std::endl;
			}
			break;
			case 2: {
				std::cout << "请输入要插入的值:";
				int val;
				std::cin >> val;
				L.insert_tail(val);
				std::cout << "插入成功,请继续您的操作!" << std::endl;
			}
			break;
			case 3: {
				std::cout << "请输入要删除的值:";
				int val;
				std::cin >> val;
				if (L.remove_val(val)) {
					std::cout << "删除成功!请继续您的操作!" << std::endl;
				} else {
					std::cout << "您要删除的值不存在,请重新选择!" << std::endl;
				}
			}
			break;
			case 4: {
				std::cout << "请输入要删除的位置:";
				int pos;
				std::cin >> pos;
				if (L.remove_pos(pos)) {
					std::cout << "删除成功!请继续您的操作!" << std::endl;
				} else {
					std::cout << "您要删除的位置不合法,请重新选择!" << std::endl;
				}
			}
			break;
			case 5: {

				std::cout << "当前链表存储的值 : ";
				L.print();
				std::cout << "请继续您的操作!" << std::endl;
			}
			break;
			case 6: {
				
				std::cout << "当前链表存储的值 : ";
				L.print();
				L.reverseList();
				std::cout << "链表逆置后的值 : ";
				L.print();
				std::cout << "请继续您的操作!" << std::endl;
			}
			break;
			case 0: {
				std::cout << "链表已经销毁,程序结束!";
			}
			break;
			default:
				std::cout << "您输入的操作不合法,请重新选择操作!" << std::endl;
				op = 1;
				break;
		}
	}
}
