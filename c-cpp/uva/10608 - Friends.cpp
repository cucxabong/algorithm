// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1549
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 30001;

vector<int> friends;
vector<int> parents;

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
		parents[vp] = up;	
	}
}

int main() {
	int t,n,m;
	int a,b;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		friends.clear();
		parents.clear();
		friends.resize(n+1, 1);
		parents.resize(n+1);

		for (int i = 1; i <= n; i++) {
			parents[i] = i;
		}

		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			unionSet(a, b);
		}

		int mx = friends[0];
		for (int i = 1; i <= n; i++)
			if (mx < friends[i])
				mx = friends[i];
		cout << mx << endl;
	}

	return 0;
}