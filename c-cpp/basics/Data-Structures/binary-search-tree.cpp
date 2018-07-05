#include <cstddef>
#include <iostream>

struct node {
	int data;
	node *left;
	node *right;
};


node* insert(node *root, int x) {
	if (root == NULL) {
		node *n = new node;
		n->data = x;
		n->left = n->right = NULL;
		return n;
	} else if (x < root->data) {
		root->left = insert(root->left, x);
	} else {
		root->right = insert(root->right, x);
	}

	return root;
}

void create(node *root, int a[], int n) {
	for (int i = 0; i < n; i++)
		root = insert(root, a[i]);
}


node* search(node *root, int x) {
	if (root == NULL || root->data == x)
		return root;
	else if (x < root->data)
		return search(root->left, x);
	else
		return search(root->right, x);
}

node* min_node(node* n) {
	node *current = n;
	while (current->left != NULL)
		current = current->left;
	return current;
}


node* remove(node *root, int x) {
	if (root == NULL)
		return root;
	if (x < root->data)
		root->left = remove(root->left, x);
	else if (x > root->data)
		root->right = remove(root->right, x);
	else {
		if (root->left == NULL) {
			node *tmp = root->right;
			delete root;
			return tmp;
		} else if (root->right == NULL) {
			node *tmp = root->left;
			delete root;
			return tmp;
		} else {
			node *tmp = min_node(root->right);
			root->data = tmp->data;
			root->right = remove(root->right, tmp->data);
		}
	}

	return root;
}

void traversal_inorder(node *root) {
	if (root != NULL) {
		traversal_inorder(root->left);
		std::cout << root->data << " ";
		traversal_inorder(root->right);
	}
}

int size(node *root) {
	if (root != NULL)
		return (size(root->left) + 1 + size(root->right));
	return 0;
}

void delete_tree(node *root) {
	if (root != NULL) {
		delete_tree(root->left);
		delete_tree(root->right);
		delete(root);
	}
}
