// http://lightoj.com/volume_showproblem.php?problem=1224
#include <string>
#include <iostream>
#include <map>
using namespace std;

#define MAX 4
struct node {
	struct node *child[MAX];
	int len;
	int count;
};

map<char, int> m;

struct node* newNode(int len) {
	struct node *Node = new struct node;
	Node->len = len;
	Node->count = 0;

	for (int i = 0; i < MAX; i++) {
		Node->child[i] = NULL;
	}

	return Node;
}

void addWord(struct node *root, string s) {
	struct node *temp = root;
	int ch;
	for (int i = 0; i < s.size(); i++) {
		ch = m[s[i]];
		if (temp->child[ch] == NULL) {
			temp->child[ch] = newNode(i+1);
		}

		temp->child[ch]->count++;
		temp = temp->child[ch];
	}
}

int find_result(struct node *n) {
	int res = n->count * n->len;
	for (int i = 0; i < MAX; i++) {
		if (n->child[i] != NULL) {
			res = max(res, find_result(n->child[i]));
		}
	}

	return res;
}

int main() {
	int T, n;
	string s;
	m['A'] = 0;
	m['C'] = 1;
	m['G'] = 2;
	m['T'] = 3;
	
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> n;
		struct node *root = newNode(0);
		for (int j = 0; j < n; j++) {
			cin >> s;
			addWord(root, s);
		}
		cout << "Case " << i << ": " << find_result(root) << endl;
	}

	return 0;
}