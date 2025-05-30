#include<bits/stdc++.h>
int BinSearchC(std::vector<int>& arr, int lo, int hi, int e) {
	while (lo < hi) {
		int mi = (lo + hi) >> 1;
		if (arr[mi] > e)
			hi = mi;
		else
			lo = mi + 1;
	}
	return lo - 1;		//lo是超过e的最小元素,lo-1即为不大于e的最大元素
}
int main() {
	std::vector<int> arr(10, 0);
	for (size_t i = 0; i < arr.size(); i++) {
		arr[i] += i + 5;
	}
	for (auto n : arr)
		std::cout << n << " ";
	std::cout << BinSearchC(arr, 0, 10, 8);
}
