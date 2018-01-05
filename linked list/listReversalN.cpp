#include <iostream>
using namespace std;

/*
reverse every n of list: 
ex) 1 -> 2 -> 3 -> 4 -> 5 -> 6

new list should be: 
3 -> 2 -> 1 -> 6 -> 5 -> 4 -> 

@return The head of new list: 
*/

struct Node
{	
	int data;
	Node* next;
	
};

/*
Insert node at end of list
@param head Head of the linked list
@return void
*/
Node* insertNode(Node* head, int data) {
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = nullptr;

	if (!head)
		head = newNode;
	else {
		Node* tempNode = head; // keep the original reference to head
		while(tempNode->next) {
			tempNode = tempNode->next;
		}
		tempNode->next = newNode;
	}

	return head;
}

/*
Print contents of the linked list
@param head Pointer to head of list
*/
void printList(Node* head) {
	if (!head) {
		cout << "List is empty, cannot print" << endl;
		return;
	}

	while(head->next) {
		cout << head->data << " ";
		head = head->next;
	}
}

int main() {
	// create empty head node: 
	Node* head = nullptr;
	insertNode(head, 4);
	insertNode(head, 5);
	printList(head);

}