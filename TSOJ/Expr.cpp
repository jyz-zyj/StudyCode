#include<iostream>
int main(){
	long long A,B;
	std::cin >> A;
	char op;
	op = getchar();
	while(op == ' '){
		op = getchar();
	}
	std::cin >> B;
	if(op == '+')
		std::cout << A+B;
	if(op == '-')
		std::cout <<  A-B;
	if(op == '*')
		std::cout <<  A*B;	
	return 0;
}
