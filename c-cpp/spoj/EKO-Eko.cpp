//http://www.spoj.com/problems/EKO/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long int calculate_total_woods(int start, vector<int> &tree_heights) {
	long long int total = 0;
	int idx;
	vector<int>::iterator up;
	up = upper_bound(tree_heights.begin(), tree_heights.end(), start);
	idx = up - tree_heights.begin();

	if (idx < tree_heights.size())
		for (int i = idx; i < tree_heights.size(); i++)
			total += tree_heights[i] - start;

	return total;
}

int find_max_height(vector<int> &tree_heights, int left, int right, int desired_woods) {
	if (left <= right) {
		int mid = left + (right - left)/2;
		long long int total = calculate_total_woods(mid, tree_heights);
		long long int next = calculate_total_woods(mid + 1, tree_heights);
		//cout << mid << " : " << total << endl;

		if ((mid == right || next < desired_woods) && total >= desired_woods)
			return mid;
		else if (total < desired_woods)
			return find_max_height(tree_heights, left, mid - 1, desired_woods);
		else
			return find_max_height(tree_heights, mid + 1, right, desired_woods);
	}

	return -1;
}


int main()
{
	int M, N;
	vector<int> tree_heights;
	cin >> N >> M;
	tree_heights = vector<int>(N);
	for (int i = 0; i < N; i++)
		cin >> tree_heights[i];
	sort(tree_heights.begin(), tree_heights.end());
	cout << find_max_height(tree_heights, 0, 1000000000, M) << endl;
	return 0;
}