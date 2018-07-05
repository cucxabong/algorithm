/*
https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1927
*/
#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

#define INF INT_MAX

void init(int *des, vector<pair<int, int> > *conn, int n, int m) {
	for (int i = 0; i < n; i++) {
		des[i] = INF;
		conn[i].clear();
	}

	int u, v, cost;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> cost;
		conn[u].push_back(make_pair(v, cost));
		conn[v].push_back(make_pair(u, cost));
	}
}

class prioritize {
public:
	bool operator()(pair<int, int> &p1, pair<int, int> &p2) {
		return p1.second > p2.second;
	}
};


void delay_time(int src, int dst, vector<pair<int,int> > conn[], int des[]) {
	priority_queue<pair<int, int>, vector<pair<int, int> >, prioritize> pq;
	pq.push(make_pair(src, des[src]=0));
	while (!pq.empty()) {
		int u = pq.top().first;
		if (u == dst) {
			break;
		}
		pq.pop();

		for (int i = 0; i < conn[u].size(); i++) {
			int v = conn[u][i].first;
			int w = conn[u][i].second;
			if (des[v] > des[u] + w) {
				des[v] = des[u] + w;
				pq.push(make_pair(v, des[v]));
			}
		}
	}
}

int main() {
	int N;
	int n, m, S, T;
	int cs = 0;
	int *des;
	vector<pair<int, int> > *conn;
	
	cin >> N;

	while (N--) {
		cs++;
		cin >> n >> m >> S >> T;
		des = new int[n];
		conn = new vector<pair<int, int> >[n];
		init(des, conn, n, m);
		delay_time(S, T, conn, des);
		cout << "Case #" << cs << ": ";
		if (des[T] == INF) {
			 cout << "unreachable" << endl;
		} else {
			cout << des[T] << endl;
		}

	}
	return 0;
}