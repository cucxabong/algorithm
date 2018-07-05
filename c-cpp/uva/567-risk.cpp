// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=508

#include <iostream>
using namespace std;

void floyd_warshall(int graph[21][21]) {
	for (int k = 1; k <= 20; k++)
		for (int i = 1; i <= 20; i++)
			for (int j = 1; j <= 20; j++) {
				if (graph[i][j] == 0 || graph[i][j] > graph[i][k] + graph[k][j]) {
					if (graph[i][k] && graph[k][j])
						graph[i][j] = graph[i][k] + graph[k][j];
				}
			}
}


int main()
{
	int X, N, A, B, c, ts;
	ts = 0;
	while(cin >> X) {
		int graph[21][21] = {};
		for (int i = 1; i <= 19; i++) {
			if (i != 1)
				cin >> X;

			for (int j = 0; j < X; j++) {
				cin >> c;
				graph[i][c] = 1;
				graph[c][i] = 1;
			}
		}

		// Getting the number of pairs
		floyd_warshall(graph);

		printf("Test Set #%d\n", ++ts);
		cin >> N;
		while (N--) {
			cin >> A >> B;
			printf("%2d to %2d: %d\n", A, B, graph[A][B]);
		}
		printf("\n");
	}


	return 0;
}