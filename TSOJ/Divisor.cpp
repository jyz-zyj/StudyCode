#include<iostream>
int main(){
	int A,B;
	std::cin >> A >> B;
	while(B){
		int C = A%B;
		A = B;
		B = C;
	}
	std::cout << A;
	return 0;
}
