// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=316&page=show_problem&problem=1552
#include <iostream>
using namespace std;

int solve_10611_tallest(int *chimps, int left, int right, int k) {
	if (left <= right) {
		int mid = left + (right - left)/2;
		if ((mid == right || chimps[mid+1] >= k) && chimps[mid] < k) {
			return mid;
		} else if (chimps[mid] >= k)
			return solve_10611_tallest(chimps, left, mid - 1, k);
		else 
			return solve_10611_tallest(chimps, mid + 1, right, k);
	}

	return -1;
}

int solve_10611_shortest(int *chimps, int left, int right, int k) {
	if (left <= right) {
		int mid = left + (right - left)/2;
		if ((mid == left || chimps[mid-1] <= k) && chimps[mid] > k)
			return mid;
		else if (chimps[mid] <= k) 
			return solve_10611_shortest(chimps, mid + 1, right, k);
		else
			return solve_10611_shortest(chimps, left, mid - 1, k);
	}

	return -1;
}

int main() 
{
	int N, Q, key;
	int *chimps;

	cin >> N;
	chimps = new int[N];
	for (int i = 0; i < N; i++)
		cin >> chimps[i];

	cin >> Q;
	while (Q--) {
		cin >> key;
		int tallest = solve_10611_tallest(chimps, 0, N-1, key);
		int shortest = solve_10611_shortest(chimps, 0, N-1, key);

		if (tallest == -1) 
			cout << "X ";
		else 
			cout << chimps[tallest] << " ";

		if (shortest == -1)
			cout << "X";
		else
			cout << chimps[shortest];
		cout << endl;
	}


	delete[] chimps;

	return 0;
}