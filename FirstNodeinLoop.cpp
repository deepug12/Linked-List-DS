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

// void deleteNode(Node* &tail, int value){

// 	if(tail == NULL){
// 		cout<<"Node is empty\n";
// 		return;
// 	}
// 	else{

// 		Node* prev = tail;
// 		Node* curr = prev -> next;

// 		while(curr -> data != value){
// 			prev = curr;
// 			curr = curr -> next;
// 		}

// 		prev -> next = curr -> next;

// 		if(curr == prev){
// 			tail = NULL;
// 		}

// 		else if(tail == curr){
// 			tail = prev;
// 		}
// 		curr -> next = NULL;
// 		delete curr;
// 	}
// }
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
// bool IsCircular(Node* head){
	

// 	if(head == NULL){
// 		return true;
// 	}
// 	Node* temp = head -> next;
// 	while(temp != NULL and temp != head){
// 		temp = temp -> next;
// 	}
// 	if(temp == NULL){
// 		return false;
// 	}
// 	return true;
// }
// bool detectCycle(Node* head){
// 	if(head == NULL){
// 		return false;
// 	}
// 	map<Node*, bool> visited;
// 	Node* temp = head;
// 	while(temp != NULL){
		

// 		if(visited[temp] == true){
// 			cout<<"Cycle is present at: "<<temp -> data<<'\n';
// 			return true;
// 		}
// 		visited[temp] = true;
// 		temp = temp -> next;
// 	}
// 	return false;
// }
Node* floydDetectloop(Node* head){
	if(head == NULL){
		return NULL;
	}

	Node* fast = head;
	Node* slow = head;
	while(slow != NULL and fast != NULL){
		fast = fast -> next;
		if(fast != NULL){
			fast = fast -> next;
		}
		slow = slow -> next;
		if(slow == fast){
			cout<<"Present at : "<<slow -> data <<'\n';
			return slow;
		}
	}
	return NULL;
}
Node* getStartingNodeinLoop(Node* head){
	if(head == NULL){
		return NULL;
	}
	Node* intersection = floydDetectloop(head);
	Node* slow = head;
	while(slow != intersection){
		slow = slow -> next;
		intersection = intersection -> next;

	}
	return slow;
}
int main(){


	Node* tail = NULL;

	insertNode(tail, 5, 3);
	// print(tail);

	insertNode(tail, 3, 5);
	// print(tail);

	insertNode(tail, 5, 9);
	// print(tail);

	insertNode(tail, 9, 12);
	// print(tail);

	// if(IsCircular(tail)) cout<<"Linked List is circular\n";
	// else cout<<"Linked list is not circular\n";

	// if(floydDetectloop(tail) != NULL) cout<<"Cycle is present\n";
	// else cout<<"Cycle is not present\n";
	
	Node* ans = getStartingNodeinLoop(tail);
	cout<<"Value of first Node in a loop is :"<< ans -> data <<'\n';

	return 0;
}
