/*
http://www.lightoj.com/volume_showproblem.php?problem=1074
*/
#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;

#define MAX 201
#define INF INT_MAX

struct triad {
	int source;
	int target;
	int weight;
};
vector<int> dist(MAX, INF);
vector<triad> graph;
int n, m;
int busyness[MAX];


bool bellman_ford(int s, vector<triad> &graph) 
{
	int u, v, w;

	dist[s] = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < m; j++) {
			u = graph[j].source;
			v = graph[j].target;
			w = graph[j].weight;
			if (dist[u] != INF && (dist[u] + w < dist[v])) {
				dist[v] = dist[u] + w;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		u = graph[i].source;
		v = graph[i].target;
		w = graph[i].weight;
		if (dist[u] != INF && (dist[u] + w < dist[v])) {
			return false;
		}
	}

	return true;
}

int calculate_cost(int i, int j) {
	return pow(busyness[j] - busyness[i], 3);
}

int main() 
{
	int T, cs, u, v, q, qc;
	cin >> T;
	cs = 1;

	while (cs <= T) {
		// Initial
		graph.clear();
		for (int i = 0; i < MAX; i++) {
			dist[i] = INF;
			busyness[i] = 0;
		}

		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> busyness[i];
		}
		cin >> m;
		triad tmp;
		for (int i = 0; i < m; i++) {
			cin >> u >> v;
			tmp.source = u;
			tmp.target = v;
			tmp.weight = calculate_cost(u, v);
			graph.push_back(tmp);
		}
		// Run Bellman Ford
		bellman_ford(1, graph);
		cin >> q;

		// Output
		cout << "Case " << cs << ":" << endl;
		for (int i = 0; i < q; i++) {
			cin >> qc;
			if ((dist[qc] == INF) || (dist[qc] < 3)) {
				cout << "?" << endl;
			} else {
				cout << dist[qc] << endl;
			}
		}

		cs++;
	}
	return 0;
}