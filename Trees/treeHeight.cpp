#include <iostream>
#include <algorithm>
using namespace std;


class Node {
public: 
	int data;
	Node* left;
	Node* right;
	Node(int d): data(d), left(nullptr), right(nullptr) {}; // one line constructor 
};

class Tree {
public: 
	// insert new node in tree
	Node* insert(Node* root, int data) {
		if (root == nullptr) {
			return new Node(data); // creating new node
		} else {
			Node* curr;
			if (data <= root->data) {
				curr = insert(root->left, data);
				root->left = curr;
			} else {
				curr = insert(root->right, data);
				root->right = curr;
			}
			return root;
		}
	}

	// get height of tree
	int height(Node* root) {
		if (!root) {
			return -1;
		}
		return 1 + max(height(root->left), height(root->right));
	}

	// print out top view of tree
	// helper function
	void goRight(Node* n) {
		if (n->right) {
			goRight(n->right);
		}
		cout << n->data << " ";
	}

	// helper function
	void goLeft(Node* n) {
		if (n->left) {
			goLeft(n->left);
		}
		cout << n->data << " ";
	}

	void topView(Node* root) {
		if (root->left) {
			goLeft(root->left);
		}
		cout << root->data << " ";
		if (root->right) {
			goRight(root->right);
		}
	}

};
	
int main() {
	Tree t1;
	Node* root = nullptr;
	int t; 
	int data;

	cin >> t;

	while(t-- > 0) {
		cin >> data;
		root = t1.insert(root, data);
	}

	int height = t1.height(root);
	cout << "height is: " << height << endl;
	cout << " ---------------------------------  \n";
	t1.topView(root);


	return 0;
} 