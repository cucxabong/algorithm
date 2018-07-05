// https://www.hackerearth.com/practice/data-structures/trees/binary-search-tree/practice-problems/algorithm/monk-and-his-friends/description/
#include <iostream>
#include <set>
#include <map>
#include <unordered_map>
using namespace std;

typedef long long int lli;

struct Node {
	lli data;
	Node *left;
	Node *right;
};


Node* insert(Node *node, lli data, bool &exist) {
	if (node == NULL) {
		exist = false;
		Node *tmp = new Node;
		tmp->data = data;
		tmp->left = tmp->right = NULL;
		return tmp;
	}
	if (data < node->data)
		node->left = insert(node->left, data, exist);
	else if (data > node->data)
		node->right = insert(node->right, data, exist);
	else 
		exist = true;
	return node;
}

// faster than using build-in set
void solve_bst() {
	int T, N, M;
	lli A;
	cin >> T;
	while (T--) {
		Node *root = NULL;
		cin >> N >> M;
		bool exist;
		for (int i = 0; i < N; i++) {
			cin >> A;
			root = insert(root, A, exist);
		}
		for (int i = 0; i < M; i++) {
			cin >> A;
			exist = false;
			root = insert(root, A, exist);
			if (exist)
				cout << "YES";
			else
				cout << "NO";
			if (i < M - 1)
				cout << endl;
		}

		if (T > 0)
			cout << endl;
	}
}

// faster than bst
void solve_unordered_map() {
	int T, N, M;
	lli A;
	pair<unordered_map<lli, bool>::iterator, bool> res;
	unordered_map<lli, bool> class_room;
	cin >> T;
	while (T--) {
		class_room.clear();
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			cin >> A;
			class_room.insert(make_pair(A, true));
		}
		for (int i = 0; i < M; i++) {
			cin >> A;
			res = class_room.insert(make_pair(A, true));
			if (!res.second)
				cout << "YES";
			else
				cout << "NO";
			if (i < M - 1)
				cout << endl;
		}
				if (T > 0)
			cout << endl;
	}
}

void solve_set() {
	pair<set<lli>::iterator, bool> res;
	int T, N, M;
	lli A;
	cin >> T;
	set<lli> class_room;
	while(T--) {
		class_room.clear();
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			cin >> A;
			class_room.insert(A);
		}
		for (int i = 0; i < M; i++) {
			cin >> A;
			res =class_room.insert(A);

			// If a value exists in the room
			if (!res.second)
				cout << "YES";
			else
				cout << "NO";
			
			if (i < M - 1)
				cout << endl;
		}
		if (T > 0)
			cout << endl;
	}
}

int main() {
	solve_unordered_map();
	return 0;
}