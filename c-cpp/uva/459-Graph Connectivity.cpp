// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=400
#include <iostream>
#include <string>
using namespace std;

int *parents;

void init(int s) {
	parents = new int[s];
	for (int i = 0; i < s; i++)
		parents[i] = i;
}

int find_set(int s) {
	while (s != parents[s])
		s = parents[s];
	return s;
}

bool union_set(int s1, int s2) {
	int s1_p = find_set(s1);
	int s2_p = find_set(s2);
	if (s1_p != s2_p) {
		parents[s2_p] = s1_p;
		return true;
	}

	return false;
}


int main() {
	int tc;
	string s;
	int ans;
	int a,b;

	scanf("%d\n\n", &tc);
	while(tc--) {
		getline(cin, s);
		ans = s[0] - 'A' + 1;
		init(ans);

		while(getline(cin, s) && !s.empty()) {
			a = s[0] - 'A';
			b = s[1] - 'A';

			if (union_set(a, b))
				ans--;
		}

		cout << ans << endl;
		if (tc > 0) {
			cout << endl;
		}
	}
	
	return 0;
}