/*
http://www.spoj.com/problems/TRVCOST/
*/
#include <iostream>
#include <vector>
#include <climits>
#include <queue>
using namespace std;

#define Edges 501
#define INF INT_MAX

const int sz = 505;
vector<pair<int,int> > a[sz];
int dis[sz];


void init() {
	for (int i = 0; i < sz; i++) {
		dis[i] = INF;
	}
}

class prioritize { public: bool operator()(pair<int, int> &p1, pair<int, int> &p2) { return p1.second > p2.second; }};

void Dijkstra(int source) {
	init();
	priority_queue<pair<int, int>, vector<pair<int, int> >, prioritize> pq;
	pq.push(make_pair(source, dis[source]=0));

	while (!pq.empty()) {
		int u = pq.top().first;

		pq.pop();

		for (int i = 0; i < a[u].size(); i++) {
			int v = a[u][i].first, w = a[u][i].second;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				pq.push(make_pair(v, dis[v]));
			}
		}
	}
}

int main() {
	int N, A, B, W, U, Q;
	int *q;

	cin >> N;

	for (int i; i < N; i++) {
		cin >> A >> B >> W;
		a[A].push_back(make_pair(B, W));
		a[B].push_back(make_pair(A, W));
	}

	cin >> U >> Q;
	q = new int[Q];
	for (int i = 0; i < Q; i++) {
		cin >> q[i];
	}

	Dijkstra(U);
	for (int i = 0; i < Q; i++) {
		if (dis[q[i]] == INF) {
			cout << "NO PATH" << endl;
		} else {
			cout << dis[q[i]] << endl;
		}
	}

	return 0;
}