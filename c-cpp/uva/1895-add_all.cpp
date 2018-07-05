/*
Problem URL: https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1895
*/

#include <iostream>
#include <queue>
using namespace std;

void add_all() {
	int n, v, cost, sum;
	cost = 0;

	priority_queue<int, vector<int>, greater<int> > q;

	cin >> n;
	if (n == 0) {
		exit(0);
	}

	for (int i = 0; i < n; i++) {
			cin >> v;
			q.push(v);
	}

	while (q.size() > 1) {
		sum = q.top();
		q.pop();
		sum += q.top();
		q.pop();

		cost += sum;
		q.push(sum);
	}
	cout << cost << endl;
}
/*
int main() {
	while (true) {
		add_all();
	}
	return 0;
}
*/
