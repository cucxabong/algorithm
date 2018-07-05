#include <iostream>
#include <string>
using namespace std;

int *parents;

int find_set(int i) {
	while (i != parents[i])
		i = parents[i];
	return i;
}

bool is_connected(int i, int j) {
	return (find_set(i) == find_set(j)) ? true : false;
}

void union_set(int i, int j) {
	int pi, pj;
	pi = find_set(i);
	pj = find_set(j);
	if (pi != pj) {
		parents[pj] = pi;
	}
}

int main() {
	int tc;
	int n;
	char ops;
	int c1, c2;
	string s;
	int successful, unsuccessful;
	scanf("%d\n\n", &tc);
	while (tc--) {
		successful = 0;
		unsuccessful = 0;

		scanf("%d\n", &n);
		parents = new int[n+1];
		for (int i = 1; i <= n; i++)
			parents[i] = i;

		while (getline(cin, s) && !s.empty()) {
			sscanf(s.c_str(), "%c %d %d", &ops, &c1, &c2);
			if (ops == 'c') {
				union_set(c1, c2);
			} else if (ops == 'q') {
				if (is_connected(c1, c2))
					successful++;
				else
					unsuccessful++;
			}
		}
		cout << successful << "," << unsuccessful << endl;
		if (tc > 0)
			cout << endl;

		delete[] parents;
		parents = NULL;

	}
}