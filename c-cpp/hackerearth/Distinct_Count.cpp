// https://www.hackerearth.com/practice/data-structures/trees/binary-search-tree/practice-problems/algorithm/distinct-count/
#include <iostream>
#include <set>
using namespace std;

int main()
{
	int T, X, N, tmp;
	set<int> A;
	cin >> T;
	while (T--) {
		cin >> N >> X;
		for (int i = 0; i < N; i++) {
			cin >> tmp;
			A.insert(tmp);
		}

		if (A.size() < X)
			cout << "Bad" << endl;
		else if (A.size() == X)
			cout << "Good" << endl;
		else
			cout << "Average" << endl;
		A.clear();

	}

	return 0;
}