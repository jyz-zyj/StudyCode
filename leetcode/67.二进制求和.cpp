#include<iostream>
using namespace std;
void reverse(string& s){
	int n = s.length()-1;
	int i = 0;
	while(i<=n){
		char t = s[i];
		s[i] = s[n];
		s[n] = t;
	}
}
int main(){
	string s = "abc";
	reverse(s);
	cout << s;
	return 0;
}
