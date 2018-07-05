// Simple Binary Search Implementation
#include <iostream>
using namespace std;

// Iterative version
int binary_search_interative(int A[], int N, int key) {
	int left, right;
	left = 0;
	right = N-1;
	while (left <= right) {
		int mid = left + (right - left)/2;
		if (key == A[mid])
			return mid;
		else if (key < A[mid])
			right = mid - 1;
		else
			left = mid + 1;
	}

	return -1;
}

// Recursive version
int binary_search(int A[], int key, int left, int right) {
	if (left > right)
		return -1;

	int mid = left + (right - left)/2;
	if (key == A[mid])
		return mid;
	else if (key < A[mid])
		return binary_search(A, key, left, mid - 1);
	else
		return binary_search(A, key, mid + 1, right);

	return -1;
}

// Searching for the rightmost matching value
int binary_search_last(int A[], int N, int key) {
	int left, right;
	int tmp = -1;
	left = 0;
	right = N - 1;
	while (left <= right) {
		int mid = left + (right - left)/2;
		if (key == A[mid]) {
			tmp = mid;
			left = mid + 1;
		} else if (key < A[mid])
			right = mid - 1;
		else 
			left = mid + 1;
	}

	return tmp;
}

// Searching for the leftmost matching value
int binary_search_first(int A[], int N, int key) {
	int left, right;
	int tmp = -1;
	left = 0;
	right = N - 1;
	while (left <= right) {
		int mid = left + (right - left)/2;
		if (key == A[mid]) {
			tmp = mid;
			right = mid - 1;
		} else if (key < A[mid])
			right = mid - 1;
		else
			left = mid + 1;
	}

	return tmp;
}

// Find the first value that do not lower than key
int lower_bound(int A[], int N, int key) {
	int left, right;
	int tmp = -1;
	left = 0;
	right = N - 1;
	while (left <= right) {
		int mid = left + (right - left)/2;
		if (key <= A[mid]) {
			tmp = mid;
			right = mid - 1;
		} else
			left = mid + 1;
	}

	return tmp;
}

// Find the first value that greater than key
int upper_bound(int A[], int N, int key) {
	int left, right, tmp;
	tmp = -1;
	left = 0;
	right = N - 1;
	while (left <= right) {
		int mid = left + (right - left)/2;
		if (key < A[mid]) {
			tmp = mid;
			right = mid - 1;
		} else
			left = mid + 1;
	}
	return tmp;
}

int main() {
	int A[] = {6, 33, 33, 33, 33,33,33,33, 43, 51, 53, 64, 72, 84, 93, 95, 96, 97};
	int idx, idx2;
	idx = lower_bound(A, 18, 33);
	idx2 = upper_bound(A, 18, 33);
	cout << idx << " - " << idx2 << endl;
}