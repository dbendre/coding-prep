#include <iostream>
#include <string>
using namespace;


/*
Huffman coding assigns variable length codewords to
fixed length input characters based on their frequencies
More frequent characters are assigned shorter codewords
and less frequent words are assigned longer codewords
Huffman tree is made for the input string characters are
decoded based on their position in the tree. We add
'0' to the codeword when we move left in the binary
tree and a '1' when we move right in the binary tree. 
We assign codes to the leaf nodoes which represent the
input characters. 

Read the string left to right until leaf w/ code is
encountered. Output value, then return to root and continue. 

NOTE: Huffman encoding is prefix free encoding technique

*/

class Node {
public: 
	int freq;
	char data;
	Node* left;
	Node* right;

	Node node(int d): data(d), left(nullptr), right(nullptr) {};
};

class Huffman {
public: 
	decode_huff(Node* root, string s) {
		Node* temp = root;
		for (int i = 0; i < s.length(); i++) {
			int index = s[i] - '0';
			if (index == 0) {
				temp = temp->left;
				if (!(temp->left) && !(temp->right)) {
					cout << temp->data;
					temp = root;
				}
			} else if (index == 1){
				temp->right;
				if (!(temp->left) && !(temp->right)) {
					cout << temp->data;
					temp = root;
				}
			}
		}
	}
}

int main() {
	return 0;
}