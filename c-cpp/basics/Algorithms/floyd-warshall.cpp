// https://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm
#include <iostream>
using namespace std;

const int INF = 1e9;

typedef pair<int, int> pii;
int **graph, **dist, **path;

void init(int V) {
	dist = new int*[V];
	path = new int*[V];
	for (int i = 0; i < V; i++) {
		dist[i] = new int[V];
		path[i] = new int[V];
		for (int j = 0; j < V; j++) {
			dist[i][j] = graph[i][j];
			if (graph[i][j] != INF & i != j)
				path[i][j] = i;
			else
				path[i][j] = -1;
		}
	}
}

void floy_warshall(int V) {
	for (int k = 0; k < V; k++) { 
		for (int i = 0; i < V; i++) {
			for (int j = 0; j < V; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
					path[i][j] = path[k][j];
				}
			}
		}
	}
}

int main() {
	int V,E,u,v,w;
	cin >> V >> E;
	graph = new int*[V];
	for (int i = 0; i < V; i++) {
		graph[i] = new int[V];
		for (int j = 0; j < V; j++)
			if (i == j)
				graph[i][j] = 0;
			else 
				graph[i][j] = INF;
	}

	while (E--) {
		cin >> u >> v >> w;
		graph[u][v] = w;
	}

	init(V);
	floy_warshall(V);
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++)
			cout << path[i][j] << " ";
		cout << endl;
	}

	cout << endl;
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++)
			cout << dist[i][j] << " ";
		cout << endl;
	}
	cout << endl;

	return 0;
}