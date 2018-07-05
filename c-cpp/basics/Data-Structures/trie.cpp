// Trie structure implementation using C++
#include <string>
using namespace std;

const ALPHABET_CHARACTERS 26

struct Node {
	bool isWord;
	Node *child[ALPHABET_CHARACTERS];
};

Node* createNode() {
	struct Node* n = new Node();
	n->isWord = false;
	for (int i = 0; i < ALPHABET_CHARACTERS; i++)
		n->child[i] = NULL;

	return n;
}

void insert(struct Node *root, string s) {
	struct Node *tmp = root;
	for (int i = 0; i < s.size(); i++) {
		int ch = s[i] - 'a';
		if (!tmp->child[ch]) {
			tmp->child[ch] = createNode();
		}

		tmp = tmp->child[ch];
	}

	tmp->isWord = true;
}

bool search(struct Node *root, string s) {
	struct Node *tmp = createNode();
	for (int i = 0; i < s.size(); i++) {
		int ch = s[i] - 'a';
		if (!tmp->child[ch])
			return false;
		tmp = tmp->child[ch];
	}

	return tmp->isWord;
}

bool isEmpty(struct Node *n) {
	for (int i = 0; i < ALPHABET_CHARACTERS; i++)
		if (n->child[i])
			return false;
	return true;
}

void delete(struct Node *root, string s) {
	struct Node *tmp = root;
	for (int i = 0; i < s.size(); i++) {
		int ch = s[i] - 'a';
		if (!tmp->child[ch])
			return;

		tmp = tmp->child[ch];
	}

	tmp->isWord = false;
}