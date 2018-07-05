//http://acm.timus.ru/problem.aspx?space=1&num=2002
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// using unordered_map (faster than BST)
struct Node {
	string password;
	bool logged_in;
};

// Avarage: O(1)
void do_register(unordered_map<string, Node*> &users, string username, string password) {
	pair<unordered_map<string, Node*>::iterator, bool> res;
	Node *node = new Node;
	node->password = password;
	node->logged_in = false;

	res = users.insert(make_pair(username, node));

	// User exists
	if (!res.second) {
		cout << "fail: user already exists" << endl;
	} else {
		cout << "success: new user added" << endl;
	}
}

// Avarage: O(1)
void do_login(unordered_map<string, Node*> users, string username, string password) {
	unordered_map<string, Node*>::iterator it;
	it = users.find(username);
	if (it == users.end())
		cout << "fail: no such user" << endl;
	else {
		if (password.compare(it->second->password) != 0) {
			cout << "fail: incorrect password" << endl;
		} else {
			if (!it->second->logged_in) {
				it->second->logged_in = true;
				cout << "success: user logged in" << endl;
			} else {
				cout << "fail: already logged in" << endl;
			}
		}
	}
}

// Avarage: O(1)
void do_logout(unordered_map<string, Node*> users, string username) {
	unordered_map<string, Node*>::iterator it;
	it = users.find(username);
	if (it == users.end()) {
		cout << "fail: no such user" << endl;
	} else {
		if (!it->second->logged_in) {
			cout << "fail: already logged out" << endl;
		} else {
			it->second->logged_in = false;
			cout << "success: user logged out" << endl;
		}
	}
}

int main() {
	int n;
	string cmd, username, password;
	unordered_map<string, Node*> users;
	cin >> n;
	while (n--) {
		cin >> cmd;
		cin >> username;
		if (cmd.compare("register") == 0) {
			cin >> password;
			do_register(users, username, password);
		} else if (cmd.compare("login") == 0) {
			cin >> password;
			do_login(users, username, password);
		} else if (cmd.compare("logout") == 0) {
			do_logout(users, username);
		}
	}

	return 0;
}


// Using in-house version
/*
struct Node {
	string username;
	string password;
	bool logged_in;
	Node *left;
	Node *right;
};

pair<Node*, bool> insert(Node *node, string username, string password) {
	if (node == NULL) {
		Node *tmp = new Node;
		tmp->username = username;
		tmp->password = password;
		tmp->logged_in = false;
		tmp->left = tmp->right = NULL;
		return make_pair(tmp, true);
	}

	int c = username.compare(node->username);
	if (c == 0)
		return make_pair(node, false);

	pair<Node*, bool> res;
	bool b;
	if (c < 0) {
		res = insert(node->left, username, password);
		node->left = res.first;
		b = res.second;
	}
	else {
		res = insert(node->right, username, password);
		node->right = res.first;
		b = res.second;
	}

	return make_pair(node, b);
}

Node* search(Node *node, string username) {
	int c;
	if (node != NULL) {
		c = username.compare(node->username);
		if (c == 0)
			return node;
		if (c < 0)
			return search(node->left, username);
		else 
			return search(node->right, username);
	}

	return NULL;
}

Node* do_register(Node *node, string username, string password) {
	pair<Node*, bool> res = insert(node, username, password);
	if (res.second)
		cout << "success: new user added" << endl;
	else
		cout << "fail: user already exists" << endl;

	return res.first;
}


void do_login(Node *node, string username, string password) {
	Node *n = search(node, username);
	if (n == NULL) {
		cout << "fail: no such user" << endl;
		return;
	}

	if (password.compare(n->password) != 0) {
		cout << "fail: incorrect password" << endl;
		return;
	}

	if (!n->logged_in) {
		n->logged_in = true;
		cout << "success: user logged in" << endl;
		return;
	} else {
		cout << "fail: already logged in" << endl;
		return;
	}
}

void do_logout(Node *node, string username) {
	Node *n = search(node, username);
	if (n == NULL) {
		cout << "fail: no such user" << endl;
		return;
	}

	if (!n->logged_in) {
		cout << "fail: already logged out" << endl;
		return;
	} else {
		cout << "success: user logged out" << endl;
		n->logged_in = false;
	}
}

int main() {
	int n;
	string cmd, username, password;
	Node *root = NULL;
	cin >> n;
	while (n--) {
		cin >> cmd;
		cin >> username;
		if (cmd.compare("register") == 0) {
			cin >> password;
			root = do_register(root, username, password);
		} else if (cmd.compare("login") == 0) {
			cin >> password;
			do_login(root, username, password);
		} else if (cmd.compare("logout") == 0) {
			do_logout(root, username);
		}
	}

	return 0;
}
*/