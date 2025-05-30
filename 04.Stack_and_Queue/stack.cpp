#include<iostream>
#define rank int
#define default_size 10
template<typename T>
class Stack {
private:
	T * _elem;
	rank _size;
	rank _capacity;
	void expand() {
		if (_size < _capacity)
			return;
		int *old_elem = _elem;
		_elem = new int[_capacity <<= 1];
		for (int i = 0; i < _size; i++) {
			_elem[i] = old_elem[i];
		}
		delete [] old_elem;
	}
public:
	Stack() : _elem(new T[default_size]), _size(0), _capacity(default_size) {}
	~Stack() {
		delete [] _elem;
	}
	bool empty() {
		if (_size == 0)
			return 1;
		return 0;
	}
	void push(T e) {
		expand();
		_elem[_size++] = e;
	}
	bool pop() {
		if (_size == 0)
			return 0;
		else {
			_size--;
			return 1;
		}
	}
	T top() {
			return _elem[_size - 1];
	}
	void print() {
		for (int i = _size-1; i >= 0 ; i--) {
			std::cout << _elem[i] << " ";
		}
		std::cout << std::endl;
	}
	void conversion(int num,int e){
		if(num == 0){
			push(0);
			return;
		}
		while(num!=0){
			push(num%e);
			num/=e;
		}
	}
	void clear(){
		_size = 0;
	}
};
void menu() {		//菜单
	std::cout << std::endl;
	std::cout << "=========================================" << std::endl;
	std::cout << "              栈操作菜单                 " << std::endl;
	std::cout << "  1 : 栈中插入元素   2 : 查看栈顶元素    " << std::endl;
	std::cout << "  3 : 删除栈顶元素   4 : 查询是否为空    " << std::endl;
	std::cout << "  5 : 数据进制转换   0 : 销毁退出程序    " << std::endl;
	std::cout << "=========================================" << std::endl;
	std::cout << "请输入您的操作: ";
}
int main() {
	Stack<int> stack;
	int op = 1;
	while (op) {
		menu();
		int e;
		std::cin >> op;
		if(op == 1){
			std::cout << "请输入要入栈的元素: ";
			std::cin >> e;
			stack.push(e);
			std::cout << "元素入栈成功,请继续操作!" << std::endl;
		} else if (op == 2){
			if(stack.empty()){
				std::cout << "当前栈为空,请重新操作!" << std::endl;
			}
			else{
				std::cout << "当前栈顶元素为: " << stack.top() << std::endl;
			}
		} else if(op == 3){
			if(stack.empty()){
				std::cout << "当前栈为空,请重新操作!" << std::endl;
			}
			else{
				if(stack.pop()){
					std::cout << "栈顶元素删除成功,请继续操作!" << std::endl;
				}
			}
		} else if(op == 4){
			if(stack.empty()){
				std::cout << "当前栈为空,请继续操作!" << std::endl;
			} else{
				std::cout << "当前栈非空,请继续操作!" << std::endl;	
			}
		} else if(op == 5){
			int e;
			while(1){
				std::cout << "请输入小于10的非负整数做为进制数: ";
				std::cin >> e;
				if(e<=0 || e>10){
					std::cout << "输入不合法请重新输入!" << std::endl;
					continue;
				}else{
					std::cout << "请输入带转换的数字: ";
					int num;
					std::cin >> num;
					stack.conversion(num,e);	//进制转换依次入栈
					stack.print();				//逆序输出
					stack.clear();				//清空栈
					break;
				}
			}
		} else if(op == 0){
			std::cout << "栈已经销毁,程序结束!" << std::endl;
		}
	}
}
