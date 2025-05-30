#include<iostream>
int BinSearchA(int arr[], int lo, int hi, int e) {
	while (lo < hi) {
		int mi = (lo + hi) >> 1;
		if (arr[mi] > e) {
			hi = mi;
		} else if (arr[mi] < e) {
			lo = mi + 1;
		} else
			return mi;
	}
	return -1;
}
int main() {
	int arr[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
	std::cout << BinSearchA(arr, 0, 10, 17);

}
