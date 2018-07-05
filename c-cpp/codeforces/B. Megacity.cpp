//http://codeforces.com/problemset/problem/424/B
#include <iostream>
#include <cmath>
using namespace std;

struct Node {
	double r;
	int population;
	Node *left;
	Node *right;
};

Node* insert(Node *node, double r, int population) {
	if (node == NULL) {
		Node* tmp = new Node;
		tmp->r = r;
		tmp->population = population;
		tmp->left = tmp->right = NULL;
		return tmp;
	}

	if (r < node->r) {
		node->left = insert(node->left, r, population);
	} else if (r > node->r) {
		node->right = insert(node->right, r, population);
	} else {
		node->population += population;
	}

	return node;
}

void inorder_traversal(Node *node) {
	if (node != NULL) {
		inorder_traversal(node->left);
		cout << node->r << ": " << node->population << endl;
		inorder_traversal(node->right);
	}
}

double find_node(Node *node, int &population) {
	double res = -1;
	if (node != NULL) {
		res = find_node(node->left, population);
		if (res != -1)
			return res;

		population -= node->population;
		if (population <= 0) {
			return node->r;
		}

		res = find_node(node->right, population);
	}

	return res;
}

int main() {
	int n, s;
	int x,y,s1;
	double r;

	Node *root = NULL;
	cin >> n >> s;
	while (n--) {
		cin >> x >> y >> s1;
		r = sqrt(x*x + y*y);
		root = insert(root, r, s1);
	}

	int left = 1e6 - s;
	r = find_node(root, left);
	if (r == -1)
		cout << "-1" << endl;
	else 
		printf("%.7f\n", r);

	return 0;
}
