// https://www.hackerrank.com/challenges/contacts/problem
#include <iostream>
#include <string>
using namespace std;

const int ALPHA_LETTERS = 26;


struct Node {
	int partial_count;
	Node *child[ALPHA_LETTERS];
};

struct Node* create_node() {
	struct Node *tmp = new Node();
	tmp->partial_count = 1;
	for (int i = 0; i < ALPHA_LETTERS; i++)
		tmp->child[i] = NULL;

	return tmp;
}

void add(struct Node *root, string s) {
	struct Node *tmp = root;
	int ch;
	for (int i = 0; i < s.size(); i++) {
		ch = s[i] - 'a';
		if (!tmp->child[ch]) {
			tmp->child[ch] = create_node();
		} else {
			tmp->child[ch]->partial_count++;
		}
		tmp = tmp->child[ch];
	}
}

int find(struct Node *root, string s) {
	int ch;
	struct Node *tmp = root;
	for (int i = 0; i < s.size(); i++) {
		ch = s[i] - 'a';
		if (!tmp->child[ch])
			return 0;
		
		tmp = tmp->child[ch];
	}

	return tmp->partial_count;
}

int main() {
	int n;
	string op, arg;
	cin >> n;
	struct Node *root = new Node();
	while (n--) {
		cin >> op >> arg;
		if (op.compare("add") == 0) {
			add(root, arg);
		}
		else
			cout << find(root, arg) << endl;
	}

	return 0;
}