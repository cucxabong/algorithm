/*
https://www.urionlinejudge.com.br/judge/en/problems/view/1655
*/
#include <iostream>
#include <vector>
using namespace std;

struct triad {
	int src;
	int dst;
	double prob;
};


void find_route(vector<triad> graph, int sz, double *dist, int src, int dst)
{
	dist[src] = 1.0;
	int u,v,w;
	for (int i = 2; i <= sz; i++) {
		for (int j = 0; j < graph.size(); j++) {
			u = graph[j].src;
			v = graph[j].dst;
			w = graph[j].prob;
			if (dist[u] > 0.0 && dist[v] < (double)dist[u]*w/100) {
				dist[v] = (double)dist[u]*w/100;
			}
		}
	}
}

int main() {
	int n, m, a, b, p;
	vector<triad> graph;
	double *dist;

	while (true) {
		cin >> n;
		if (n == 0) 
			break;

		dist = new double[n+1];
		for (int i = 1; i <= n; i++) {
			dist[i] = 0.0;
		}

		cin >> m;
		triad tmp;
		for (int i = 0; i < m; i++) {
			cin >> a >> b >> p;
			tmp.src = a;
			tmp.dst = b;
			tmp.prob = p;
			graph.push_back(tmp);
			tmp.src = b;
			tmp.dst = a;
			graph.push_back(tmp);
		}

		find_route(graph,n, dist, 1, n);
		printf("%.6f percent\n", dist[n]*100);

		delete[] dist;
		graph.clear();
	}
	
	return 0;
}