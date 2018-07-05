// https://www.hackerrank.com/contests/womens-codesprint-2/challenges/minimum-loss
#include <iostream>
#include <climits>
using namespace std;

typedef long long int lli;
lli min_loss = LLONG_MIN;


struct Node {
	lli data;
	Node *left;
	Node *right;
};

// Complexity: O(logn)
// n: The number of current node of tree
Node* insert(Node *node, lli x) {
	if (node == NULL) {
		Node *tmp = new Node;
		tmp->data = x;
		tmp->left = tmp->right = NULL;
		return tmp;
	} else if (x < node->data) {
		lli tmp = x - node->data;
		if (tmp > min_loss)
			min_loss = tmp;
		node->left = insert(node->left, x);
	} else if (x > node->data) {
		node->right = insert(node->right, x);
	}

	return node;
}

int main() {
	Node *root = NULL;
	int n;
	lli tmp;
	cin >> n;
	// O(nlogn)
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		root = insert(root, tmp);
	}
	
	cout << -1*min_loss << endl;
}