#include <iostream>
using namespace std;

struct node {
	int data;
	node* left;
	node* right;
};

struct node* newNode(int data){
     node* node = new struct node;
     node->data = data;
     node->left = NULL;
     node->right = NULL;
 
     return(node);
}

void preOrder(node *root) {
	if (root) {
		cout << root->data << " ";
		preOrder(root->left);
		preOrder(root->right);
	
	}
}

void inOrder(node *root) {
	if (root) {
		inOrder(root->left);
		cout << root->data << " ";
		inOrder(root->right);
	}
}

void postOrder(node *root) {
	if (root) {
		postOrder(root->left);
		postOrder(root->right);
		cout << root->data << " ";
	}
}

int main() {

 	struct node *root  = newNode(1);
     root->left = newNode(2);
     root->right = newNode(3);
     root->left->left = newNode(4);
     root->left->right = newNode(5); 

     preOrder(root);
     cout << "\n";
     inOrder(root);
     cout << "\n";
     postOrder(root);


	return 0;
}