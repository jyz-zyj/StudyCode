#include<iostream>
//总和最大区段
int max(int a, int b) {
	if (a > b)
		return a;
	return b;
}
int GS_1(int A[], int n) {
	int ans = A[0];
	for (int lo = 0; lo < n; lo++) {
		for (int sum = 0,  hi = lo; hi < n; hi++) {
			sum += A[hi];
			if (sum > ans)
				ans = sum;
		}
	}
	return ans;
}
int GS_2(int A[], int lo, int hi) {	//分而治之
	if (hi - lo < 2)
		return A[lo];
	int mi = (lo + hi) >> 1;
	int gs_l = A[mi - 1], l_sum = 0;
	for (int i = mi - 1; lo <= i; i--) {
		l_sum += A[i];
		if (l_sum > gs_l) {
			gs_l = l_sum;
		}
	}
	int gs_r = A[mi], r_sum = 0;
	for (int i = mi; i < hi; i++) {
		r_sum += A[i];
		if (r_sum > gs_r) {
			gs_r = r_sum;
		}
	}
	return max(gs_l + gs_r, max(GS_2(A, lo, mi), GS_2(A, mi, hi)));
}
int GS_3(int A[], int n) {
	int ans = A[0], i = n, sum = 0;
	while (i-->0) {
		sum += A[i];
		if (sum > ans) {
			ans = sum;
		}
		if (sum <= 0) {
			sum = 0;
		}
	}
	return ans;
}
int main() {
	int arr[] = {1, -2, 7, 2, 6, -9, 5, 6, -12, -8, 13, 0, -3, 1, -2, 8, 0, -5, 3};
	std::cout << GS_1(arr, 19);
	std::cout << GS_2(arr, 0, 19);
	std::cout << GS_3(arr, 19);

	return 0;
}
