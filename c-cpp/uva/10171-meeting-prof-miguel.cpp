/*
https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1112
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 1e9
#define MAX_PLACE 26

int min(int a, int b) {
    return a < b ? a : b;
}

void floyd_warshall(vector<vector<int> > &dist)
{
	for (int k = 0; k < MAX_PLACE; k++) {
		for (int i = 0; i < MAX_PLACE; i++) {
			for (int j = 0; j < MAX_PLACE; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}
		}
	}
}

void print_output(vector<vector<int> > dist_y, vector<vector<int> > dist_m, int pos_y, int pos_m)
{
	int energy = INF;
	priority_queue<int, vector<int>, greater<int> > places;	

	for (int i = 0; i < MAX_PLACE; i++) {
		//cout << pos_m << " " << pos_y << endl;
		int sum = dist_m[pos_m][i] + dist_y[pos_y][i];
		//int sum = 0;
		if (energy > sum) {
			// Pop out all element in queue
			while (!places.empty())
				places.pop();

			energy = sum;
			places.push(i);
		} else if (energy == sum && energy != INF) {
			places.push(i);
		}
	}

	if (places.empty())
		cout << "You will never meet." << endl;
	else {
		cout << energy << " ";
		while (!places.empty()) {
			cout << char(places.top()+'A');
			if (places.size() > 1)
				cout << " ";

			places.pop();

		}
		cout << endl;
	}

}

int main()
{
	vector<vector<int> > dist_y;

	vector<vector<int> > dist_m;

	int N;				// The number of street in of cities
	int energy;
	char a,b,c,d;
	int x, y;

	while(true) {
		cin >> N;
		if (N == 0)
			break;
		
		// Alocate memory
		dist_y = vector<vector<int> >(MAX_PLACE, vector<int>(MAX_PLACE));

		dist_m = vector<vector<int> >(MAX_PLACE, vector<int>(MAX_PLACE));
		for (int i = 0; i < MAX_PLACE; i++) {
			for (int j = 0; j < MAX_PLACE; j++) {
				if (i == j) {
					dist_y[i][j] = 0;
					dist_m[i][j] = 0;
				} else {
					dist_y[i][j] = INF;
					dist_m[i][j] = INF;
				}
			}
		}

		// Loading graph from STDIN
		for (int i = 0; i < N; i++) {
			cin >> a >> b >> c >> d >> energy;
			x = c - 'A';
			y = d - 'A';

			if (a == 'Y') {
				dist_y[x][y] = min(dist_y[x][y], energy);
				if (b == 'B') {
					dist_y[y][x] = dist_y[x][y];
				}
			} else if (a == 'M') {
				dist_m[x][y] = min(dist_m[x][y],energy);
				if (b == 'B') {
					dist_m[y][x] = dist_m[x][y];
				}
			}
		}


		// Running floyd-warshall on 2 graphs
		floyd_warshall(dist_y);
		floyd_warshall(dist_m);

		// Get current position
		cin >> a >> b;
		print_output(dist_y, dist_m, a-'A', b-'A');


	}

	return 0;
}