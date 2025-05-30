#include<bits/stdc++.h>
using namespace std;
void mergesort(vector<int>& nums, int lo, int mi, int hi) {
	int *a = new int[mi - lo];
	int *b = new int[hi - mi];
	for (int i = 0; i < mi - lo; i++) {
		a[i] = nums[lo + i];
	}
	for (int i = 0; i < hi - mi; i++) {
		b[i] = nums[mi + i];
	}
	int i = 0, j = 0, k = 0;
	while (j < mi - lo && k < hi - mi) {
		if (a[j] <= b[k])
			nums[lo + i++] = a[j++];
		else
			nums[lo + i++] = b[k++];
	}
	while (j == mi - lo && k < hi - mi) {
		nums[lo + i++] = b[k++];
	}
	while (k == hi - mi && j < mi - lo) {
		nums[lo + i++] = a[j++];
	}
}
void merge(vector<int>& nums, int lo, int hi) {
	if (hi - lo < 2) return;
	int mi = (lo + hi) >> 1;
	merge(nums, lo, mi);
	merge(nums, mi, hi);
	mergesort(nums, lo, mi, hi);
}
