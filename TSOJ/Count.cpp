#include<iostream>
int main() {
	std::string s;
	getline(std::cin,s);
	int arr[26] = { 0 };
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			arr[s[i] - 97]++;
		}
		if (s[i] >= 'A' && s[i] <= 'Z') {
			arr[s[i] - 65]++;
		}
	}
	for (int i = 0; i < 26 ; i++) {
		if (arr[i] == 0)
			continue;
		else {
			printf("%c: %d\n", i + 65, arr[i]);
		}
	}
}
