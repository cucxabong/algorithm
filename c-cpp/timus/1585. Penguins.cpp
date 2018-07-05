// http://acm.timus.ru/problem.aspx?num=1585
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	int n;
	map<string, int> penguins;
	string s;

	penguins["Emperor Penguin"] = 0;
	penguins["Macaroni Penguin"] = 0;
	penguins["Little Penguin"] = 0;

	cin >> n;
	cin.ignore();
	while (n--) {
		getline(cin, s);
		penguins[s] += 1;
	}

	string res = penguins.begin()->first;
	int count = penguins.begin()->second;
	for (map<string, int>::iterator it = penguins.begin(); it != penguins.end(); it++)
		if (it->second > count) {
			res = it->first;
			count = it->second;
		}

	cout << res;
}