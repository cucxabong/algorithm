//http://lightoj.com/volume_showproblem.php?problem=1129
#include <iostream>
#include <string>
using namespace std;

const int MAX_CHILD = 10;

struct Node {
	int prefix;
	bool isWord;
	Node *child[MAX_CHILD];
};

struct Node* createNode() {
	struct Node *tmp = new Node();
	tmp->prefix = 0;
	tmp->isWord = false;
	for (int i = 0; i < MAX_CHILD; i++)
		tmp->child[i] = NULL;

	return tmp;
}

void insert(struct Node *root, string s) {
	struct Node *tmp = root;
	for (int i = 0; i < s.size(); i++) {
		int dgt = s[i] - '0';
		if (!tmp->child[dgt]){
			tmp->child[dgt] = createNode();
		}

		tmp->child[dgt]->prefix++;
		tmp = tmp->child[dgt];
	}

	tmp->isWord = true;
	tmp->prefix--;
}

bool isConsistency(struct Node *root) {
	if (root != NULL) {
		if ((root->prefix > 0) && root->isWord)
			return false;

		for (int i = 0; i < MAX_CHILD; i++) {
			bool res = isConsistency(root->child[i]);
			if (!res)
				return res;
		}
	}

	return true;
}

void clear(struct Node *root) {
	if (root) {
		for (int i = 0; i < MAX_CHILD; i++)
			clear(root->child[i]);
		delete root;
		root = NULL;
	}
}

int main() {
	int t, n;
	string s;
	cin >> t;
	for (int i = 0; i < t; i++) {
		struct Node *root = new Node();
		cin >> n;
		while (n--) {
			cin >> s;
			insert(root, s);
		}

		cout << "Case " << (i + 1) << ": ";
		if (isConsistency(root))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

		clear(root);
	}

	return 0;
}