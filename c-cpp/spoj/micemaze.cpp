/*
http://www.spoj.com/problems/MICEMAZE/
*/
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

#define INF INT_MAX

class prioritize {
public:
	bool operator()(pair<int, int> &p1, pair<int, int> &p2) {
		return p1.second > p2.second;
	}
};

void init(int *dis, int vertices) {
	for (int i = 1; i < vertices; i++) {
		dis[i] = INF;
	}
}


void dijkstra(int src, vector<pair<int, int> > *conn, int *dis) {
	priority_queue<pair<int, int>, vector<pair<int, int> >, prioritize> pq;
	pq.push(make_pair(src, dis[src] = 0));

	while (!pq.empty()) {
		int u = pq.top().first;

		pq.pop();

		for (int i = 0; i < conn[u].size(); i++) {

			int v = conn[u][i].first;
			int w = conn[u][i].second;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				pq.push(make_pair(v, dis[v]));
			}
		}
	}
}

int main() {
	int cells, exit_cell, timer, edges;
	int *dis;
	vector<pair<int, int> > *conn;
	int count = 0;

	cin >> cells >> exit_cell >> timer >> edges;
	dis = new int[cells+1];
	conn = new vector<pair<int, int> >[cells+1];

	int u, v, cost;
	for (int i = 0; i < edges; i++) {
		cin >> u >> v >> cost;
		//conn[u].push_back(make_pair(v, cost));
		conn[v].push_back(make_pair(u, cost));
	}

	init(dis, cells+1);
	// Running dijkstra 1 time from exit_cell to other cells
	// on reverse graph
	// Complexity: O(VlogE)
	dijkstra(exit_cell, conn, dis);
	for (int i = 1; i <= cells; i++) {
		if (dis[i] <= timer) {
			count++;
		}
	}

	cout << count << endl;

	return 0;
}