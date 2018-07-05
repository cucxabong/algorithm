// Bellman-Ford implemetation in C++
#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> pii;

const int INF = 1e9;

bool bellman_ford(vector<pii> *graph, int* &dist, int* &path, const int V, const int src) {

	// Initialization
	bool res = true;

	dist[src] = 0;
	path[src] = -1;

	for (int i = 1; i < V; i++) {
		for (int j = 0; j < V; j++) {
			for (int k = 0; k < graph[j].size(); k++) {
				int v = graph[j][k].first;
				int w = graph[j][k].second;
				if (dist[j] != INF && dist[v] > w + dist[j]) {
					dist[v] = dist[j] + w;
					path[v] = j;
				}
			}			
		}
	}
	
	// Checking for negative-weight cycles
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < graph[i].size(); j++) {
			int v = graph[i][j].first;
			int w = graph[i][j].second;
			if (dist[i] != INF && dist[v] > w + dist[i]) {
				res = false;
				break;
			}
		}
	}

	return res;
}

/*
	// Sample Input
6 10
0 1 1
1 2 5
1 3 -2
1 5 7
2 5 -1
3 0 2
3 2 -1
3 4 4
4 3 3
5 4 1
*/
int main() {
	int V, E;
	int u,v,w;
	vector<pii> *graph;
	int *dist, *path;

	cin >> V >> E;
	graph = new vector<pii>[V];
	dist = new int[V];
	path = new int[V];
	
	for (int i; i < V; i++) {
		dist[i] = INF;
		path[i] = -1;
	}

	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(v, w));
	}

	bellman_ford(graph, dist, path, V, 0);

	// Print out path array
	for (int i = 0; i < V; i++)
		cout << path[i] << " ";

	cout << endl;
	// Print out dist array
	for (int i = 0; i < V; i++)
		cout << dist[i] << " ";
	cout << endl;


	for (int i = 0; i < V; i++)
		graph[i].clear();

	delete[] dist;
	delete[] path;
	delete[] graph;

	return 0;
}