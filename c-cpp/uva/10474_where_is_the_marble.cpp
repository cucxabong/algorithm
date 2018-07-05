//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1415
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
	int N, Q;
	vector<int> marbles;
	int cs = 0;
	int tmp;

	while (true) {
		cin >> N >> Q;
		if (!N && !Q)
			break;
		marbles = vector<int>(N);
		for (int i = 0; i < N; i++)
			cin >> marbles[i];
		sort(marbles.begin(), marbles.end());
		vector<int>::iterator low;

		cout << "CASE# " << ++cs << ":"<< endl;
		while (Q--) {
			cin >> tmp;
			low = lower_bound(marbles.begin(), marbles.end(), tmp);
			if ((low - marbles.begin()) > marbles.size() || *low != tmp)
				cout << tmp << " not found" << endl;
			else
				cout << tmp << " found at " << low - marbles.begin() + 1 << endl;
				
				
		}
	}
	return 0;
}