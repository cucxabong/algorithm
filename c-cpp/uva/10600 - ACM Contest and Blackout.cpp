#include <iostream>
#include <queue>
using namespace std;


#define MAX_VERTICES 105
#define INF 1e9
vector<pair<int, int> > graph[MAX_VERTICES];
vector<int> dist(MAX_VERTICES, INF);
int path[MAX_VERTICES];
bool visited[MAX_VERTICES];
int V;

void init_graph() {
	for (int i = 0; i < MAX_VERTICES; i++) {
		graph[i].clear();
	}
	V = 0;
}

void init() {
	for (int i = 0; i < MAX_VERTICES; i++) {
		path[i] = -1;
		visited[i] = false;
	}

	dist.assign(MAX_VERTICES, INF);
}

pair<int, bool> isSPT() {
	int unreachable = 0;
	int cost = 0;
	for (int i = 1; i <= V; i++) {
		if (path[i] == -1)
			unreachable++;
		cost += dist[i];
		if (unreachable > 1)
			break;
	}

	return make_pair(cost, (unreachable == 1));
}

struct option {
	bool operator() (const pair<int, int> &a, const pair<int, int> &b) const {
		return a.second > b.second;
	}
};

int Prim(int src, int a, int b) {
	priority_queue<pair<int,int>, vector<pair<int, int> >, option> pq;
	pq.push(make_pair(src, 0));
	dist[src] = 0;
	
	while (!pq.empty()) {
		int u = pq.top().first;
		pq.pop();
		visited[u] = true;
		for (int i = 0; i < graph[u].size(); i++) {
			int v = graph[u][i].first;
			int w = graph[u][i].second;
			
			// Ignore edge (a, b)
			if ((u == a && v == b) || (v == a && u == b)) {
				
			} else {
				if (!visited[v] && dist[v] > w) {
					dist[v] = w;
					pq.push(make_pair(v,w));
					path[v] = u;
				}
			}
		}
	}

	// Checking if we have a valid Spanning Tree
	// & return total weight of this tree (if valid)
	// else return weight of -1
	pair<int, bool> res = isSPT();
	if (res.second)
		return res.first;
	else
		return -1;
}

int main() {
	int E, T;
	int u,v,w;
	pair<int, int> res;

	cin >> T;

	while (T--) {
		init_graph();
		cin >> V >> E;
		for (int i = 0; i < E; i++) {
			cin >> u >> v >> w;
			graph[u].push_back(make_pair(v, w));
			graph[v].push_back(make_pair(u, w));
		}

		pair<int, int> res;

		init();
		// First MST
		res.first = Prim(1, 0, 0);
	
		int path_mst[MAX_VERTICES];

		// Saving path[] of first MST
		for (int i = 1; i <= V; i++)
			path_mst[i] = path[i];

		res.second = INF;
		// sequentially mark each edge in MST as deleted 
		for (int i = V; i > 0; i--) {
			int tmp;
			init();

			// Temporary mark 1 each edge in MST as deleted (ignore it in Prim)
			if (path_mst[i] != -1)
				tmp = Prim(1, i, path_mst[i]);

			if (tmp > 0 && tmp < res.second)
				res.second = tmp;
		}

		// Print out first & second minimum spanning tree
		cout << res.first << " " << res.second << endl;
	}

	return 0;
}