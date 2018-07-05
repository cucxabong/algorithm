// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1338
#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

#define INF 1e9
#define MAX_BUILDING 755

double graph[MAX_BUILDING][MAX_BUILDING];
vector<pair<int, int> > Points(MAX_BUILDING);
double dist[MAX_BUILDING];
bool visited[MAX_BUILDING];
int N;

double distance_calculate(pair<int,int> a, pair<int, int> b) {
	int x,y;
	x = a.first - b.first;
	y = a.second - b.second;

	return sqrt(x*x + y*y);
}

void init() {
	Points.clear();
	for (int i = 1; i <= N; i++) {
		dist[i] = INF;
	}
}

struct option {
	bool operator () (const pair<int, double> &a, const pair<int, double> &b) {
		return a.second > b.second;
	}
};

double Prim(int src) {
	priority_queue<pair<int, double>, vector<pair<int, double> >, option > pq;
	
	pq.push(make_pair(src, 0.0));
	dist[src] = 0;

	while (!pq.empty()) {
		int u = pq.top().first;
		pq.pop();
		visited[u] = true;
		for (int i = 1; i <= N; i++)
			if (!visited[i] && dist[i] > graph[u][i]) {
				dist[i] = graph[u][i];
				pq.push(make_pair(i, graph[u][i]));
			}
	}

	double cost = 0.0;
	for (int i = 1; i <= N; i++)
	{
		cost += dist[i];
	}

	return cost;
}

int main() {

	int u,v,M;
	while (cin >> N) {
		init();
		for (int i = 1; i <= N; i++) {
			cin >> u >> v;
			Points[i] = make_pair(u, v);
			visited[i] = false;
		}

		// Calculate distance between building
		for (int i = 1; i <= N; i++) {
			for (int j = i + 1; j <= N; j++) {
				double tmp = distance_calculate(Points[i], Points[j]);
				graph[i][j] = graph[j][i] = tmp;
			}
		}

		cin >> M;
		for (int i = 0; i < M; i++) {
			cin >> u >> v;
			graph[u][v] = graph[v][u] = 0;
		}

		printf("%.2f\n", Prim(1));
	}
	return 0;
}