#include<iostream>
#define default_size 10
class SqList {
private:
	int *elem;
	int size;
	int capacity;
	void expand() {	//容量不足时会扩容
		if (size < capacity)
			return;
		int *old_elem = elem;
		elem = new int[capacity <<= 1];
		for (int i = 0; i < size; i++) {
			elem[i] = old_elem[i];
		}
		delete [] old_elem;
	}
public:
	SqList() : elem(new int[10]), size(0), capacity(default_size) {}
	~SqList() {
		delete [] elem;
	}
	void insert() {
		std::cout << "请确认要输入元素的个数:";
		int n;
		std::cin >> n;
		if (n + size >= capacity)
			expand();
		std::cout << "请依次输入插入元素: ";
		while (1 <= n--) {
			int val;
			std::cin >> val;
			elem[size++] = val;
		}
		std::cout << "元素插入完成,请继续您的操作!" << std::endl;
	}
	void insert_pos() {
		std::cout << "请输入要插入元素的位置:";
		int pos;
		std::cin >> pos;
		if (pos < 1 || pos > size + 1) {
			std::cout << "输入的位置不合法,请重新操作!" << std::endl;
			return;
		} else {
			if (size == capacity)
				expand();
			std::cout << "请输入要输入的元素: ";
			int val;
			std::cin >> val;
			for (int i = size; i >= pos; i--) {
				elem[i] = elem[i - 1];
			}
			elem[pos - 1] = val;
			size++;
			printf("在 %d 位置上插入元素 %d 成功!\n", pos, val);
		}
	}
	void remove() {
		std::cout << "请输入要删除元素的位置: ";
		int pos;
		std:: cin >> pos;
		if (pos < 1 || pos > size) {
			std::cout << "输入参数有误,请重新输入!" << std::endl;
			return;
		}
		while (pos < size) {
			elem[pos - 1] = elem[pos];
			pos++;
		}
		size--;
		std::cout << "元素删除成功,请继续操作!" << std::endl;
	}
	void print() {
		std::cout << "当前元素为: ";
		for (int i = 0; i < size; i++) {
			std::cout << elem[i] << " ";
		}
		std::cout << std::endl;
	}
	void length() {
		std::cout << "当前元素个数为: ";
		std::cout << size;
		std::cout << std::endl;
	}
};
void menu() {		//菜单
	std::cout << std::endl;
	std::cout << "==========================================" << std::endl;
	std::cout << "              顺序表操作菜单              " << std::endl;
	std::cout << "  1 : 批量的插入元素   2 : 按位置插入元素 " << std::endl;
	std::cout << "  3 : 删除某位置元素   4 : 打印表中的元素 " << std::endl;
	std::cout << "  5 : 统计元素的数量   0 : 销毁并退出程序 " << std::endl;
	std::cout << "==========================================" << std::endl;
	std::cout << "请输入您的操作: ";
}
int main() {
	int op = 1;
	SqList L;
	while (op) {
		menu();
		std::cin >> op;
		switch (op) {
			case 1: {
				L.insert();
			}
			break;
			case 2: {
				L.insert_pos();
			}
			break;
			case 3: {
				L.remove();
			}
			break;
			case 4: {
				L.print();
			}
			break;
			case 5: {
				L.length();
			}
			break;
			case 0: {
				std::cout << "顺序表已经销毁,程序结束!";
			}
			break;
			default:
				std::cout << "您输入的操作不合法,请重新选择操作!" << std::endl;
				op = 1;
				break;
		};
	}
}
