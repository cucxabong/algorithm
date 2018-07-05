/* 
Reference: https://en.wikipedia.org/wiki/Prim%27s_algorithm
*/
#include <iostream>
#include <queue>
using namespace std;

const int INF = 1e9;
typedef pair<int, int> pii;

vector<pii> *graph;

struct comp {
	bool operator() (const pii &a, const pii &b) {
		return a.second > b.second;
	}
};

void init(int *&dist, int *&path, bool *&visited, int V) {
	dist = new int[V];
	path = new int[V];
	visited = new bool[V];

	for (int i = 0; i < V; i++) {
		dist[i] = INF;
		path[i] = -1;
		visited[i] = false;
	}
}

void prim(int *&dist, int *&path, bool *&visited, int V) {
	priority_queue<pii, vector<pii>, comp > pq;

	int src = 0;
	dist[src] = 0;
	pq.push(make_pair(src, 0));
	while (!pq.empty()) {
		int u = pq.top().first;
		visited[u] = true;
		pq.pop();
		for (int i = 0; i < graph[u].size(); i++) {
			int v = graph[u][i].first;
			int w = graph[u][i].second;
			if (!visited[v] && dist[v] > w) {
				dist[v] = w;
				pq.push(make_pair(v, w));
				path[v] = u;
			}
		}
	}
}
/*
Sample Input
6 9
0 1 2
0 3 9
1 2 3
1 3 8
1 4 5
1 5 1
2 5 5
3 4 3
4 5 7
*/

int main() {
	int *dist, *path;
	bool *visited;
	int V,E,u,v,w;

	cin >> V >> E;

	dist = new int[V];
	path = new int[V];
	visited = new bool[V];
	graph = new vector<pii>[V];

	init(dist, path, visited, V);

	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(v, w));
		graph[v].push_back(make_pair(u, w));
	}

	prim(dist, path, visited, V);

	for (int i = 0; i < V; i++)
		cout << dist[i] << " ";
	cout << endl;
	for (int i = 0; i < V; i++)
		cout << path[i] << " ";
	cout << endl;

	return 0;
}