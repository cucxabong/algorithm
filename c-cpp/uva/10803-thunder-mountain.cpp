/*
https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1744
*/

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

#define INF 1e9

void floyd_warshall(vector<pair<int, int> >pos, vector<vector<double> > &dist) {
	double cost;

	// Init dist
	for (int i = 0; i < pos.size(); i++) {
		for (int j = 0; j < pos.size(); j++) {
			if (i == j)
				dist[i][j] = 0.0;
			else {
				cost = sqrt(pow(pos[i].first - pos[j].first, 2) + pow(pos[i].second - pos[j].second, 2));
				if (cost > 10.0) {
					dist[i][j] = INF;
				} else {
					dist[i][j] = cost;
				}
			}
		}
	}
	for (int k = 0 ; k < pos.size(); k++){
		for (int i = 0; i < pos.size(); i++) {
			for (int j = 0; j < pos.size(); j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
}

void print_worse_case(vector<vector<double> > dist, int cs) {
	double worse = 0.0;

	for (int i = 0; i < dist.size(); i++) {
		for (int j = 0; j < dist.size(); j++) {
			if (worse < dist[i][j]) {
				worse = dist[i][j];
			}
		}
	}

	cout << "Case #" << cs << ":" << endl;
	if (worse == INF) {
		cout << "Send Kurdy" << endl;
	} else 
		printf("%.4f\n", worse);

}

int main()
{
	int N;				// The number of test cases
	int towns;
	int x, y;
	int cs = 1;
	vector<pair<int, int> > pos;
	vector<vector<double> > dist;

	cin >> N;
	while (cs <= N) {
		cin >> towns;
		pos = vector<pair<int, int> >(towns);
		dist = vector<vector<double> >(towns, vector<double>(towns));

		for (int i = 0; i < towns; i++) {
			cin >> x >> y;
			pos[i] = make_pair(x, y);
		}

		floyd_warshall(pos, dist);
		print_worse_case(dist, cs);
		cs++;
		cout << endl;
	}
	return 0;
}