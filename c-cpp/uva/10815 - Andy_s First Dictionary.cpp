// https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1756
#include <iostream>
#include <set>
#include <string>
#include <cctype>
using namespace std;

struct Node {
	string data;
	Node *left;
	Node *right;
};

Node* insert(Node* node, string key) {
	if (node == NULL) {
		Node* tmp = new Node;
		tmp->data = key;
		tmp->left = tmp->right = NULL;
		return tmp;
	}
	if (key.compare(node->data) < 0) 
		node->left = insert(node->left, key);
	else if (key.compare(node->data) > 0)
		node->right = insert(node->right, key);

	return node;
}

void print_tree(Node *root) {
	if (root != NULL) {
		print_tree(root->left);
		cout << root->data << endl;
		print_tree(root->right);
	}
}

void solve_10815_set() {
	set<string> s;
	string buf;
	while (cin >> buf) {
		int size = buf.size();
		string word = "";
		for (int i = 0; i < size; i++) {
			char c = tolower(buf[i]);
			if (isalpha(c))
				word += c;
			else if (word != "") {
				s.insert(word);
				word = "";
			}
		}
		if (word != "")
			s.insert(word);	
	}

	for (set<string>::iterator it = s.begin(); it != s.end(); it++)
		cout << *it << endl;
}

void solve_10815_bst() {
	Node* root = NULL;
	string buf;
	while (cin >> buf) {
		int size = buf.size();
		string word = "";
		for (int i = 0; i < size; i++) {
			char c = tolower(buf[i]);
			if (isalpha(c))
				word += c;
			else if (word != "") {
				root = insert(root, word);
				word = "";
			}
		}
		if (word != "")
			root = insert(root, word);	

	}
	print_tree(root);
}

int main() {
	solve_10815_set();
	return 0;
}