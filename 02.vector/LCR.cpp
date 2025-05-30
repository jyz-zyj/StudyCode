#if 1
#include<iostream>
#include<algorithm>
#include<vector>
int LCR(std::string A, std::string B) {	//最长公共子序列
	int x = A.length() + 1;
	int y = B.length() + 1;
	std::vector<std::vector<int >> arr(x, std::vector(y, 0));
	for(int i = 0; i+1< x; i++) {
		for(int j = 0; j+1 < y; j++) {
			{
				if(A[i] == B[j]) {
					arr[i+1][j+1] = arr[i][j] + 1;
				}
				else
					arr[i+1][j+1] = std::max(arr[i][j+1], arr[i+1][j]);
			}
		}
	}
	return arr[x-1][y-1];
}
int main() {
	std::cout << LCR("ABCDE", "CDE");
}
#endif
