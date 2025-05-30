#include<iostream>
int arr[105] = {0, 1, 0};
int fib_1(int n) {
	if (n < 2)
		return n;
	return fib_1(n - 1) + fib_1(n - 2);
}
int fib_2(int n) {
	int x = 1, y = 0;
	while (n--) {
		y = y + x;
		x = y - x;
	}
	return y;
}
int fib_3(int n) {
	if (n < 2){
		std::cout << "懒惰抄袭:" << n <<"的值" <<std::endl;
		return n;
	}
	if (arr[n] != 0){
		std::cout << "懒惰抄袭:" << n <<"的值" <<std::endl;
		return arr[n];
	}
	else {
		arr[n] = fib_3(n - 1) + fib_3(n - 2);
		std::cout << "勤快计算:" << n <<"的值" <<std::endl;
	}
	return arr[n];
}
int main() {
	std::cout << fib_3(10);
	std::cout << std::endl;
}

