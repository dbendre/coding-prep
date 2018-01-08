#include <iostream>
using namespace std;
#include <stack>

/*
Creating Linked List Node
*/
class Node {
public:
	int data;
	Node* next;	
	Node* prev;

	Node(int d): data(d), next(nullptr), prev(nullptr) {} // constructor
};



/*
Function to insert a node at the tail of a linked list.
@param head, pointer to head of list
@param data, data value to be assined to node
@return void
Time Complexity: O(N), N is number of elements in the list
*/
Node* insertTail(Node* head, int data) {
		Node* newNode = new Node(data);
	if (!head) { // if head doesn't exist
		head = newNode;
	} else {
		Node* tempHead = head;
		while (tempHead->next) {
			tempHead = tempHead->next;
		}
		tempHead->next = newNode;
	}
	return head;
}

Node* insertHead(Node* head, int data) {
	Node* newNode = new Node(data); // constructor
	
	if (!head) {
		head = newNode; // if head doesn't exist, the newNode is head
	} else {
		Node* tempHead = head;
		newNode->next = tempHead;
		head = newNode;
	}

	return head;	
}

/*
Function to get value of the node at the given postion.
@param head, pointer to head node of list
@param pos, position from the last node (tail) of list
@return data, data value of the desired node
*/
int getNode(Node* head, int pos) {
	int count = 0;
	Node* temp = head;

	while (temp) {
		count++;
		temp = temp->next;
	}

	count -= pos;
	while (--count > 0) {
		head = head->next;
	}

	return head->data;
}

/*
Function to insert linked list node at any position in list
@param head, pointer to head node of list
@param data, data to insert
@param pos, position to insert node
@return head, pointer to head node of list
*/
Node* insertNth(Node* head, int data, int pos) {
	Node* newNode = new Node(data);
	Node* tempHead = head, *prev = nullptr;
	int count = 0;

	while (count < pos && tempHead) {
		count++;
		prev = tempHead;
		tempHead = tempHead->next;
	} // get to correct position

	if (count != pos) {
		cout << "Not enough nodes" << endl;
	} else {
		if (!prev) {
			newNode->next = head;
			head = newNode; // inserting at beginning
		} else {
			newNode->next = tempHead;
			prev->next = newNode; // insert in middle
		}
	}
	return head;
}

/*
Function to insert a node into a sorted doubly linked list
@param head, pointer to head node of list
@param data, data of node to insert into list
@return head, head pointer to updated list
*/
Node* sortedInsert(Node* head, int data) {
	if (!head) {// empty list 
		Node* temp = new Node(data);
		return temp; // return the single node
	}

	// node exists, need to find location to insert
	Node* tempHead = head;
	while (tempHead) {
		if (tempHead->data >= data) {
			Node *n = new Node(data);
			n->prev = tempHead->prev;
			n->next = tempHead;
			tempHead->prev = n;
			if (!(n->prev)) {
				return n; // n is at the beginning of list
			} else {
				(n->prev)->next = n;
				return head;
			} 
		}
		if (!tempHead->next) {
			Node* n = new Node;
			n->data = data;
			n->prev = tempHead;
			n->next = nullptr;
			tempHead->next = n;
			break;
		}
		tempHead = tempHead->next;
	}
	return head;
}

/*
Function to find merge point of 2 linked lists
@param headA, pointer to head of list A
@param headB, pointer to head of list B
@return data, data value of node where lists merge
*/
int findMergeNode(Node* headA, Node* headB) {
	// get count of number of nodes in list: 
	int countA = 0, countB = 0;
	Node* tempA = headA, *tempB = headB;
	while (tempA) {
		tempA = tempA->next;
		countA++;
	}
	while (tempB) {
		tempB = tempB->next;
		countB++;
	}
	while(countA > countB) {
		headA = headA->next;
		countA--;
	}

	while(countB > countA) {
		headB = headB->next;
		countB--;
	}

	while(headA) {
		if (headA == headB)
			return headA->data;

		headA = headA->next;
		headB = headB->next;
	}

	return -1;
}

int findMerge2(Node *headA, Node *headB) { // efficient af O(N+M), length of list
	Node* tempA = headA, *tempB = headB;

	while (tempA != tempB) {
		if (!tempA->next)
			tempA = headB;
		else 
			tempA = tempA->next;

		if (!tempB->next)
			tempB = headA;
		else
			tempB = tempB->next;
	}

	return tempB->data;
}


/*
Function to merge 2 sorted lists. 
@param headA, pointer to head of list A
@param headb, pointer to head of list B
@return head, pointer to head of merged list
Time Complexity = O(M+N) where M is length of list A, N is length of list B
*/
Node* mergeList(Node* headA, Node* headB) {
	// Note: You can use recursion!
	Node* tempNode = nullptr;
	if (!headA && !headB)
		return NULL;

	if (!headA)
		return headB;
	else if (!headB)
		return headA;

	if (headA->data <= headB->data){
		tempNode = headA;
		tempNode->next = mergeList(headA->next, headB);
	} else {
		tempNode = headB;
		tempNode->next = mergeList(headA, headB->next);
	}

	return tempNode;
}

/*
Function to delete duplicate value nodes from a sorted linked list
@param head, pointer to head node of list
@return head, pointer to head of modified list
*/
Node* removeDuplicates(Node* head) {
	Node* tempHead = head;
	if(!tempHead)
		return NULL;

	while(tempHead->next) {
		if (tempHead->data == tempHead->next->data) {
			tempHead->next = tempHead->next->next;
		} else {
			tempHead = tempHead->next;
		}
	}

	return head;
}

/*
Function to detect linked list cycle: 
@param head, pointer to head node of list
@return bool, 1 is cycle, 0 is no cycle
*/
bool detectCycle(Node* head) {
	if (!head)
		return 0; // no cycle

	Node* tortoise = head, *hare = head;
	while(tortoise && tortoise->next) {
		tortoise = tortoise->next;
		hare = hare->next->next;
		if (!tortoise || !hare) {
			return 0; // if nodes don't exist (end of list), return false
		} else if (tortoise == hare) {
			return 1; // if they are the same node, return true
		}
	}
	return 0;
}

/*
Function to delete a node in the linked list
@param head, pointer to head node of list
@param pos, position in list of node to delete
@return head, pointer to head of modified list
Note: this uses the tortoise - hare algorithm of cycle detection
*/
Node* deleteNode(Node* head, int pos) {
	Node* tempHead = head, *prev = nullptr;
	int count = 0; 

	while (count < pos && tempHead) {
		count++;
		prev = tempHead;
		tempHead = tempHead->next;
	} // get into position

	if (count != pos) {
		cout << "There is no node to delete!" << endl;
	} else {
		if (!prev) { // deleting first node;
			head = head->next;
		} else {
			prev->next = tempHead->next;
			delete tempHead; // free space from that node
		}
	}

	return head;
}

/*
Function to print contents of the linked list.
@param head, pointer to head node of the list
@return void
*/
void printList(Node *head) {
	if (!head) {
		cout << "List is empty" << endl;
	} else {
		while (head) {
			cout << head->data << "->";
			head = head->next;
		}
		cout << "NULL" << endl;
	}
}

/*
Function to reverse the linked list in-place using a stack.
@param head, pointer to head node of the list
@return head, pointer to head node of reversed list
*/
Node* reverse(Node *head) {

	if (!head) {

		head = nullptr;
		return head;
	}

	stack<Node*> nodeStack;
	while(head) { // insert all elements in the stack
		nodeStack.push(head);
		head = head->next;
	}

	head = nodeStack.top();
	nodeStack.pop();
	Node* tempHead = head;

	while(!(nodeStack.empty())) {
		Node* newNode = nodeStack.top();
		tempHead->next = newNode;
		tempHead = tempHead->next;
		nodeStack.pop();
	}

	tempHead->next = nullptr; // needed this condition

	return head;
}

/*
Function to reverse linked list using pointers only (hackerrank solution)
@param head, pionter to head node of list
@return temp, new head of list
*/
Node* reverseWithPointer(Node* head) {
	if (!head || !head->next) // if empty list or one item in list
		return head;

	// 1 2 3
	// cout << "head before recursion: " << head->data << endl;
	Node* temp = reverseWithPointer(head->next);
	// cout << "head after recursion: " << head->data << endl;
	head->next->next = head;
	head->next = NULL;

	return temp;
}

/*
Reversing a doubly linked list using recursion
@param head, pointer to head node of list
@return head, pointer to head node of reversed list
// LMAO THIS ACTUALLY WORKS ON THE FIRST TRY
*/
Node* reverseDouble(Node* head) {
	if (!head || !head->next)
		return head; // return original head pointer if list is empty or has 1 node

	Node* temp = reverseDouble(head->next);
	head->next->next = head;
	head->next = nullptr;
	head->prev = head;

	return temp;
}

/*
Reversing a doubly linked list iteratively
@param head, pointer to head node of list
@return head, pointer to head node of reversed list

*/
Node* reverseDoubleIterative(Node* head) {
	Node* temp = nullptr;
	Node* current = head;

	while(current) {
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;
		current = current->prev;
	}

	if (temp) {
		head = temp->prev;
	}

	return head;
}

/*
Print contents of linked list in reverse order
@param head, pointer to head node of linked list
@return void
*/
void reversePrint(Node* head) {
	if (!head) {
		// cout << "NULL";
		return; // if list is empty, return
	}

	reversePrint(head->next); // recurse on next element in list
	cout << head->data << " "; // print data of node
}

/*
Function to reverse every N nodes of a list
@param head, pointer to head of list
@param n, number of nodes in a group to reverse
@return head, pointer ot head of list
*/
Node* reverseN(Node* head, int n) { // 1 2 3 4 5 6
	Node* tempHead = head;
	Node* prev = nullptr, *next = nullptr; // prev and next keep track of the other nodes
	int count = 0;

	while (tempHead && count < n) {
		next = tempHead->next; 
		tempHead->next = prev; 
		prev = tempHead;
		tempHead = next; 
		count++;
	}

	if (next) { // call reverseN on next set of n nodes
		head->next = reverseN(next, n);
	}

	return prev; 
}

int compareList(Node* h1, Node* h2) {
	// super simple code: 
	while (h1 && h2 && h1->data == h2->data) {
		h1 = h1->next;
		h2 = h2->next;
	}

	return (h1 == h2);
}

int main() {
	Node* head = new Node(1);
	head = insertTail(head, 2);
	head = insertTail(head, 3);
	// head = insertTail(head, 4);
	// head = insertTail(head, 5);
	// head = insertHead(head, 4);
	// head = insertHead(head, 7);
	// head = insertHead(head, 6);
	// head = insertHead(head, 1);
	// head = insertHead(head, 5);
	// head = insertHead(head, 9);
	// head = insertTail(head, 6);
	// head = insertNth(head, 11, 2);


	cout << "Original List: " << endl;
	printList(head);

	// cout << "reversing with pointers: " << endl;
	head = reverseWithPointer(head);
	printList(head);

	// cout << "After deleteing: " << endl;
	// head = deleteNode(head, 2);
	// printList(head);

	// cout << "Print in reverse: " << endl;
	// reversePrint(head);
	// head = reverse(head);

	// cout << "Reversed List: " << endl;
	// printList(head);

	// head = reverseN(head, 3);

	// cout << "Reverse N List: " << endl;
	// printList(head);

	return 0;
}