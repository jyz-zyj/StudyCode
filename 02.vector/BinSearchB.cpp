#include<iostream>
int BinSearchB(int arr[], int lo, int hi, int e) {
	while (1 < hi - lo) {
		int mi = (lo + hi) >> 1;
		if (arr[mi] > e) {
			hi = mi;
		} else
			lo = mi;
	}
	return e < arr[lo] ? lo - 1 : lo;
}
int main() {
	int arr[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
	std::cout << BinSearchB(arr, 0, 10, 18);

}
