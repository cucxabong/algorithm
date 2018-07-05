/*
http://www.spoj.com/problems/SHPATH/en/
*/
#include <iostream>
#include <map>
#include <queue>
#include <climits>
#include <string>
using namespace std;

#define INF INT_MAX

class prioritize {
public:
	bool operator()(pair<int, int> &p1, pair<int, int> &p2) {
		return p1.second > p2.second;
	}
};



map<string, int> cities;
vector<pair<int, int> > *conn;
int *dis;
bool *vis;

void init(int n) {
	dis = new int[n+1];
	vis = new bool[n+1];
	conn = new vector<pair<int, int> >[n+1];
}

void shpath(int s, int d) {
	priority_queue<pair<int, int>, vector<pair<int, int> >, prioritize > pq;
	pq.push(make_pair(s, dis[s] = 0));

	while (!pq.empty()) {
		int u = pq.top().first;
		pq.pop();
		vis[u] = true;
		if (u == d) {
			break;
		}
		for (int i = 0; i < conn[u].size(); i++) {
			int v = conn[u][i].first;
			int w = conn[u][i].second;

			if (!vis[v] && dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				pq.push(make_pair(v, dis[v]));
			}
		}
	}
}

int main() {
	int tc, n, idx, p, nr, cost, r;
	string name, name1, name2;
	cin >> tc;
	while (tc--) {
		cin >> n;
		init(n);
		for (int i = 1; i <= n; i++) {
			cin >> name;
			cities[name] = i;
			cin >> p;
			for (int j = 0; j < p; j++) {
				cin >> nr >> cost;
				conn[i].push_back(make_pair(nr, cost));
			}
		}

		cin >> r;
		for (int i = 0; i < r; i++) {
			for (int i = 0; i <= n; i++) {
				dis[i] = INF;
				vis[i] = false;
			}

			cin >> name1 >> name2;
			shpath(cities[name1], cities[name2]);
			cout << dis[cities[name2]] << endl;
		}
	}
	return 0;
}
