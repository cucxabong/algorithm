#include <iostream>
#include <queue>
#include <map>
using namespace std;

map<string,int> bfs(map<string, vector<string> > contestant, string start) {
	queue<string> q;
	map<string, int> dist;
	map<string, bool> vis;

	for (map<string, vector<string> >::iterator it = contestant.begin(); it != contestant.end(); it++) {
		vis[it->first] = false;
		dist[it->first] = -1;
	}

	map<string, vector<string> >::iterator it;
	it = contestant.find(start);
	if (it != contestant.end()) {
		q.push(start);
		vis[start] = true;
		dist[start] = 0;
	}

	while (!q.empty()) {
		string u = q.front();
		q.pop();

		for (int i = 0; i < contestant[u].size(); i++) {
			if (!vis[contestant[u][i]]) {
				dist[contestant[u][i]] = dist[u] + 1;
				vis[contestant[u][i]] = true;
				q.push(contestant[u][i]);
			}
		}
	}
	return dist;
}

int main() {
	int n;
	string s1, s2, s3;
	map<string, vector<string> > contestant;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s1 >> s2 >> s3;
		contestant[s1].push_back(s2);
		contestant[s1].push_back(s3);

		contestant[s2].push_back(s1);
		contestant[s2].push_back(s3);

		contestant[s3].push_back(s1);
		contestant[s3].push_back(s2);
	}

	map<string, int> dist = bfs(contestant, "Isenbaev");
	
	for (map<string, int>::iterator it = dist.begin(); it != dist.end(); it++) {
		if (it->second == -1)
			cout << it->first << " undefined" << endl;
		else
			cout << it->first << " " << it->second << endl;
	}
	return 0;
}