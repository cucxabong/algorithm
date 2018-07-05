// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/trie-keyword-tree/practice-problems/algorithm/search-engine/
#include <string>
#include <iostream>
#include <map>
using namespace std;

#define MAX 26
struct node {
	int weight;
	struct node *child[MAX];
	int countLeaf;
};

struct node *newNode() {
	struct node *Node = new struct node;
	Node->countLeaf = 0;
	Node->weight = 0;

	for (int i = 0; i < MAX; i++) {
		Node->child[i] = NULL;

	}

	return Node;
}

void addWord(struct node *root, string s, int weight) {
	struct node *temp = root;
	int ch;
	for (int i = 0; i < s.size(); i++) {
		ch = s[i] - 'a';
		if (temp->child[ch] == NULL) {
			temp->child[ch] = newNode();
		}
		temp = temp->child[ch];
	}
	temp->countLeaf++;
	temp->weight = weight;
}

node* findWord(struct node *root, string s) {
	int ch;
	struct node *temp = root;
	for (int i = 0; i < s.size(); i++) {
		ch = s[i]-'a';
		if (temp->child[ch] == NULL)
			return NULL;
		temp = temp->child[ch];
	}
	return temp;
}

int findWeight(struct node *n) {
	int w = n->weight;
	for (int i = 0; i < MAX; i++)
	{
		if (n->child[i] != NULL) {
			int tmp = findWeight(n->child[i]);
			if (tmp > w)
				w = tmp;
		}
	}
	return w;
}

int main() {
	int n,q,w;
	string s;
	map<string, int> res;
	map<string, int>::iterator it;
	struct node* root = newNode();
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> s >> w;
		addWord(root, s, w);
	}

	for (int i = 0; i < q; i++) {
		cin >> s;
		it = res.find(s);
		if (it != res.end())
			cout << it->second << endl;
		else {
			struct node* tmp = findWord(root, s);
			if (tmp == NULL)
				res[s] = -1;
			else
				res[s] = findWeight(tmp);
			cout << res[s] << endl;
		}


	}
	return 0;
}