// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2498
#include <iostream>
#include <map>
#include <string>
using namespace std;


int *friends;
int *parents;


int findSet(int u) {
	while (u != parents[u])
		u = parents[u];
	return u;
}

void unionSet(int u, int v) {
	int up = findSet(u);
	int vp = findSet(v);
	if (up != vp) {
		friends[up] += friends[vp];
		friends[vp] = 0;
		parents[vp] = up;
	}
	cout << friends[up] << endl;
}

int main() {
	int t,n,x,y;
	int count = 0;
	string a,b;
	map<string, int> people;
	cin >> t;
	while (t--) {
		cin >> n;
		friends = new int[2*n];
		parents = new int[2*n];

		for (int i = 0; i < n; i++) {
			cin >> a >> b;
			x = people[a];
			if (x == 0) {
				people[a] = ++count;
				x = count;
				friends[x] = 1;
				parents[x] = x;
			}

			y = people[b];
			if (y == 0) {
				people[b] = ++count;
				y = count;
				friends[y] = 1;
				parents[y] = y;
			}

			unionSet(x,y);
		}

		delete[] friends;
		delete[] parents;
		people.clear();
		count = 0;

	}

	return 0;
}