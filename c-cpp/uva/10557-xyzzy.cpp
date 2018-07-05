/*
https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1498
*/

#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

struct doorway {
	int source;
	int target;
};

bool bfs(int source, int target, bool *vis, vector<doorway> graph)
{
	queue<int> q;
	q.push(source);
	vis[source] = true;
	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		for (int i = 0; i < graph.size(); i++) {
			int u,v;
			u = graph[i].source;
			v = graph[i].target;
			if (tmp == u && !vis[v]) {
				vis[v] = true;
				q.push(v);
			}
		}
	}

	return vis[target];
}

bool check_winnable(vector<doorway> graph, int size, int start, int end, int *dist, int* energy) 
{
	int u, v, w;
	bool *vis;
	vis = new bool[size+1];

	dist[start] = 100;

	for (int i = 1; i <= size - 1; i++) {
		for (int j = 0; j < graph.size(); j++) {
			u = graph[j].source;
			v = graph[j].target;
			if (dist[u] > 0 && dist[v] < dist[u] + energy[v]) {
				dist[v] = dist[u] + energy[v];
			}
		}
	}

	if (dist[end] > 0)
		return true;

	for (int i = 0; i < graph.size(); i++) {
		u = graph[i].source;
		v = graph[i].target;

		if (dist[u] > 0 && dist[v] < dist[u] + energy[v]) {
			for (int j = 1; j <= size; j++) {
				vis[j] = false;
			}

			if (bfs(u, end, vis, graph)) {
				return true;
			}
		}
	}

	return false;
}

int main() 
{
	int n;					// The number of rooms
	vector<doorway> graph;
	int *dist;
	int *energy;

	cin >> n;
	while (n != -1) {
		dist = new int[n+1];
		energy = new int[n+1];
		graph.clear();

		for (int i = 1; i <= n; i++) {
			int eg, m, r;
			dist[i] = 0;

			cin >> eg >> m;
			energy[i] = eg;

			for (int j = 0; j < m; j++) {
				cin >> r;
				doorway tmp;
				tmp.source = i;
				tmp.target = r;
				graph.push_back(tmp);
			}
		}

		bool winnable = check_winnable(graph, n, 1, n, dist, energy);

		if (winnable) {
			cout << "winnable" << endl;
		} else {
			cout << "hopeless" << endl;
		}

		delete[] dist;
		delete[] energy;
		cin >> n;
	}
	
	return 0;
}