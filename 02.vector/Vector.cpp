#include<iostream>
template <typename T> class Vector {
#define rank int
#define default_size 10
private:
	T * _elem;
	rank _size = 0;
	rank _capacity = 0;
public:
	Vector() : _elem(new T[default_size]), _size(0), _capacity(default_size) {}
	Vector(const T *A, int lo, int hi) {
		_elem = new T[hi - lo];
		int pos = hi - lo;
		for (int i = 0; i < pos; i++) {
			_elem[i] = A[lo++];
			_size++;
		}
	}
	~Vector() {
		delete [] _elem;
	}
	void mergesort(rank lo, rank hi) {
		if (hi - lo < 2)	return;
		rank mi = (lo + hi) >> 1;
		mergesort(lo, mi);
		mergesort(mi, hi);
		merge(lo, mi, hi);
	}
	void merge(rank lo, rank mi, rank hi) {
		T * A = new T[mi - lo];
		T * B = new T[hi - mi];
		for (int i = 0; i < mi - lo; i++) {
			A[i] = _elem[lo + i];
		}
		for (int i = 0; i < hi - mi; i++) {
			B[i] = _elem[mi + i];
		}
		rank i = 0, j = 0, k = 0;
		while (j < mi - lo && k < hi - mi) {
			if (A[j] <= B[k]) {
				_elem[lo + i] = A[j];
				i++, j++;
			} else {
				_elem[lo + i] = B[k];
				i++, k++;
			}
		}
		while (j == mi - lo && k < hi - mi) {
			_elem[lo + i++] = B[k++];
		}
		while (k == hi - mi && j < mi - lo) {
			_elem[lo + i++] = A[j++];
		}
	}
	void print() {
		for (int i = 0; i < _size; i++) {
			std::cout << _elem[i] << " ";
		}
	}
};
int main() {
	int arr[10] = {10, 7, 5, 8, 4, 2, 3, 6, 1, 9};
	Vector<int> vec(arr, 0, 10);
	vec.mergesort(0, 10);
	vec.print();
}
