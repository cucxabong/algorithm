//https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1167
#include <string>
#include <iostream>
using namespace std;

struct Node {
	string name;
	int count;
	Node* left;
	Node* right;
};

Node* insert(Node* node, string s) {
	if (node == NULL) {
		//cout << "Insert " << s << endl;
		Node *tmp = new Node;
		tmp->name = s;
		tmp->count = 1;
		tmp->left = tmp->right = NULL;
		return tmp;
	}

	int c = s.compare(node->name);
	if (c == 0) {
		node->count++;
	} else if (c < 0) {
		node->left = insert(node->left, s);
	} else {
		node->right = insert(node->right, s);
	}

	return node;
}

void inorder_traversal(Node* node, int sum) {
	if (node != NULL) {
		inorder_traversal(node->left, sum);
		printf("%s %.4f\n", node->name.c_str(), (double)node->count*100/sum);
		inorder_traversal(node->right, sum);
	}
}

int main() {
	int t, sum;
	string s;
	cin >> t;
	cin.ignore(2);

	while (t--) {
		//cin.ignore();
		sum = 0;
		Node *root = NULL;
		while(getline(cin, s)) {
			if (s.size() != 0) {
				sum++;
				root = insert(root, s);
			} else 
				break;
		}
		inorder_traversal(root, sum);
		if (t > 0)
			cout << endl;
	}

	return 0;
}