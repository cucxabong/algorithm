// https://www.hackerrank.com/challenges/no-prefix-set/problem
#include <iostream>
using namespace std;

const int MAX_LETTERS = 'j' - 'a' + 1;

struct Node {
	int prefix;
	bool is_word;
	struct Node *child[MAX_LETTERS];
};

struct Node* create_node() {
	struct Node *tmp = new Node();
	tmp->prefix = 1;
	tmp->is_word = false;
	for (int i = 0; i < MAX_LETTERS; i++)
		tmp->child[i] = NULL;

	return tmp;
}

bool insert(struct Node *root, string s) {
	struct Node *tmp = root;
	int ch;
	for (int i = 0; i < s.size(); i++) {
		ch = s[i] - 'a';
 		if (tmp->child[ch] == NULL) {
 			tmp->child[ch] = create_node();
 		} else {
 			tmp->child[ch]->prefix++;
 			if (tmp->child[ch]->is_word)
 				return false;
 		}
 		tmp = tmp->child[ch];
	}

	tmp->is_word = true;
	if (tmp->prefix > 1)
		return false;

	return true;
}

int main() {
	int n;
	string s, res;
	bool good = true;
	res = "";
	cin >> n;
	struct Node *root = new Node();
	while(n--) {
		cin >> s;
		if (!insert(root, s) && good) {
			res = s;
			good = false;
		}
	}

	if (good)
		cout << "GOOD SET" << endl;
	else 
		cout << "BAD SET" << endl << res << endl;

	return 0;
}