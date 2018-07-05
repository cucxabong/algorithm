// http://lightoj.com/volume_showproblem.php?problem=1041
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <functional>
#include <map>
using namespace std;

const int INF = 1e9;

map<string, vector<pair<string, int> > > graph;
map<string, int> dist;
map<string, bool> visited;

struct option {
	bool operator() (const pair<string, int> &a, const pair<string, int> &b) const {
		return a.second > b.second;
	}
};

void init() {
	dist.clear();
	visited.clear();
	map<string, vector<pair<string, int> > >::iterator it;
	for (it = graph.begin(); it != graph.end(); it++) {
		dist[it->first] = INF;
		visited[it->first] = false;
	}
}

void Prims(string src) {
	priority_queue<pair<string, int>, vector<pair<string, int> >, option> pq;
	pq.push(make_pair(src, 0));
	dist[src] = 0;
	while (!pq.empty()) {
		string u = pq.top().first;
		pq.pop();
		visited[u] = true;
		for (int i = 0; i < graph[u].size(); i++) {
			string v = graph[u][i].first;
			int w = graph[u][i].second;
			if (!visited[v] && dist[v] > w) {
				dist[v] = w;
				pq.push(make_pair(v, w));
			} // end for
		} // end while
	}
}

int main() {
	int tc;
	cin >> tc;
	int count = 0;
	while (count < tc) {
		graph.clear();

		count++;
		int E;
		int sum = 0;
		bool reachable = true;
		cin >> E;
		string u,v;
		int w;
		for (int i = 0; i < E; i++) {
			cin >> u >> v >> w;
			graph[u].push_back(make_pair(v, w));
			graph[v].push_back(make_pair(u, w));
		}

		init();
		Prims(graph.begin()->first);
		map<string, int>::iterator it;
		for (it = dist.begin(); it != dist.end(); it++) {
			if (it->second == INF) {
				reachable = false;
				break;
			}
			sum += it->second;
		}
		cout << "Case " << count << ": ";
		if (!reachable)
			cout << "Impossible"; 
		else
			cout << sum;
		cout << endl;
	}

	return 0;
}
