// Simple Dijkstra implementation in C++
#include <iostream>
#include <queue>
using namespace std;

const int INF = 1e9;

typedef pair<int, int> pii;

void init(int *&path, int *&dist, int v) {
	if (dist)
		delete dist;
	if (path)
		delete path;

	dist = new int[v];
	path = new int[v];

	for (int i = 0; i < v; i++) {
		dist[i] = INF;
		path[i] = -1;
	}
}

struct comp {
	bool operator() (const pii &a, const pii &b) {
		return a.second > b.second;
	}
};

void dijkstra(int *&path, vector<pii> *graph, int *&dist, const int v, const int src) {
	
	priority_queue<pii, vector<pii>, comp> pq;

	init(path, dist, v);
	dist[src] = 0;
	pq.push(make_pair(src, 0));
	while (!pq.empty()) {
		int u = pq.top().first;
		pq.pop();
		for (int i = 0; i < graph[u].size(); i++) {
			int v = graph[u][i].first;
			int w = graph[u][i].second;
			if (dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				path[v] = u;
				pq.push(make_pair(v, dist[v]));
			}
		}
	}
}
/*
	// Sample input
6 10
0 1 1
1 2 5
1 3 2
1 5 7
2 5 1
3 0 2
3 2 1
3 4 4
4 3 3
5 4 1
*/

int main() {
	vector<pii> *graph;
	int V, E, u, v, w;
	int *dist, *path;
	dist = NULL;
	path = NULL;
	cin >> V >> E;
	graph = new vector<pii>[V];
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(v, w));
	}

	dijkstra(path, graph, dist, V, 0);
	for (int i = 0; i < V; i++) {
		cout << path[i] << " ";
	}

	return 0;
}
