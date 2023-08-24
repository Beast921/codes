#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node *left, *right;
};

Node* newNode(int data)
{
	Node* temp = new Node();
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

void printLeftBoundary(Node* root)
{
	while (root) {
		if (root->left || root->right) {
			cout << root->data << " ";
		}
		if (root->left) {
			root = root->left;
		}
		else {
			root = root->right;
		}
	}
}

void printRightBoundary(Node* root)
{
	if (!root) {
		return;
	}
    if (root->right) {
        printRightBoundary(root->right);
    }
    else {
        printRightBoundary(root->left);
    }
    if (root->left || root->right) {
        cout << root->data << " ";
    }
}

void printLeaves(Node* root)
{
	if (!root) {
		return;
	}
	printLeaves(root->left);
	if (!root->left && !root->right) {
		cout << root->data << " ";
	}
	printLeaves(root->right);
}

void printBoundary(Node* root)
{
	if (!root) {
		return;
	}
	cout << root->data << " ";
	printLeftBoundary(root->left);
	printLeaves(root->left);
	printLeaves(root->right);
	printRightBoundary(root->right);
}

int main()
{
	Node* root = newNode(20);
	root->left = newNode(8);
	root->left->left = newNode(4);
	root->left->right = newNode(12);
	root->left->right->left = newNode(10);
	root->left->right->right = newNode(14);
	root->right = newNode(22);
	root->right->right = newNode(25);
	root->right->right->right = newNode(28);

	printBoundary(root);

	return 0;
}