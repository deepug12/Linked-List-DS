#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node* next;

	Node(int d){
		this -> data = d;
		this -> next = NULL;
	}

	~Node() {
        int value = this -> data;
        //memory free
        if(this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout <<"Memory is free for node with data : "<< value <<'\n';
    }
};
void insertNode(Node* &tail, int element, int d){
	if(tail == NULL){
		Node* newNode = new Node(d);
		tail = newNode;

		newNode -> next = newNode;
	}
	else{

		Node* curr = tail;

		while(curr -> data != element){
			curr = curr -> next;

		}

		Node* temp = new Node(d);
		temp -> next = curr -> next;
		curr -> next = temp;
	}
}

void deleteNode(Node* &tail, int value){

	if(tail == NULL){
		cout<<"Node is empty\n";
		return;
	}
	else{

		Node* prev = tail;
		Node* curr = prev -> next;

		while(curr -> data != value){
			prev = curr;
			curr = curr -> next;
		}

		prev -> next = curr -> next;

		if(curr == prev){
			tail = NULL;
		}

		else if(tail == curr){
			tail = prev;
		}
		curr -> next = NULL;
		delete curr;
	}
}
void print(Node* tail){

	Node* temp = tail;

	if(tail == NULL){
		cout<<"List is Empty\n";
		return;
	}
	do {
		cout<< tail -> data<<"->";

		tail = tail -> next;

	} while(tail != temp);

	cout<<"NULL"<<'\n';
}
// int getLength(Node* head){

// 	int len = 0;

// 	Node* temp = head;
// 	while(temp != NULL){
// 		len++;
// 		temp = temp -> next;
// 	}
// 	return len;
// }
// void insetAtPosition(Node* &tail, Node* &head, int position, int d){

// 	// Agar Node ko first me insert krna hai toh
// 	if(position == 1){
// 		InsertAtHead(tail, head,  d);
// 		return;
// 	}
// 	Node* temp = head;
// 	int cnt = 1;

// 	while(cnt < position-1){
// 		temp = temp -> next;
// 		cnt++;
// 	}

// 	// Inserting at Last Position
// 	if(temp -> next == NULL){
// 		InsertAtTail(tail, head,  d);
// 		return;
// 	}
// 	Node* nodeToInsert = new Node(d);

// 	nodeToInsert -> next = temp -> next;
// 	temp -> next -> prev = nodeToInsert;

// 	temp -> next = nodeToInsert;
// 	nodeToInsert -> prev = temp;
// }
// void deleteNode(int position, Node* & head) { 

//     //deleting first or start node
//     if(position == 1) {
//         Node* temp = head;
//         temp -> next -> prev = NULL;
//         head = temp -> next;
//         //memory free start ndoe
//         temp -> next = NULL;
//         delete temp;
//     }
//     else
//     {
//         //deleting any middle node or last node
//         Node* curr = head;
//         Node* prev = NULL;

//         int cnt = 1;
//         while(cnt < position) {
//             prev = curr;
//             curr = curr -> next;
//             cnt++;
//         }
//         curr -> prev = NULL;
//         prev -> next = curr -> next;
//         curr -> next = NULL;

//         delete curr;

//     }
// }

int main(){

	// Node* head = NULL;
	Node* tail = NULL;

	insertNode(tail, 5, 3);
	print(tail);

	insertNode(tail, 3, 5);
	print(tail);

	insertNode(tail, 5, 9);
	print(tail);

	insertNode(tail, 9, 12);
	print(tail);


	deleteNode(tail, 3);
	print(tail);

	return 0;
}
