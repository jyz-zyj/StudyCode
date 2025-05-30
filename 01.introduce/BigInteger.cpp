#include<bits/stdc++.h>
using namespace std;
//大数加法
class Solution {
public:
	string addStrings(string num1, string num2) {
		int i = num1.length() - 1;
		int j = num2.length() - 1;
		int add = 0;
		string ans = "";
		while (i >= 0 || j >= 0 || add != 0) {
			int x = i >= 0 ? num1[i] - '0' : 0;
			int y = j >= 0 ? num2[j] - '0' : 0;
			int res = x + y + add;
			ans.push_back('0' + res % 10);
			add = res / 10;
			i--;
			j--;
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};
//大数乘法

