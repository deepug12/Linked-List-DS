#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node* prev;
	Node* next;

	Node(int d){
		this -> data = d;
		this -> prev = NULL;
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

void InsertAtHead(Node* &tail, Node* &head, int d){

	if(head == NULL){
		Node* temp = new Node(d);
		head = temp;
		tail = temp;
	}
	else{
		Node* temp = new Node(d);

		temp -> next = head;
		head -> prev = temp;
		head = temp;
	}
	

}
void InsertAtTail(Node* &tail, Node* &head, int d){

	if(tail == NULL){
		Node* temp = new Node(d);
		tail = temp;
		head = temp;
	}
	else{
		Node* temp = new Node(d);

		tail -> next = temp;
		temp -> prev = tail;
		tail = temp;
	}
	

}

void print(Node* &head){

	Node* temp = head;
	while(temp != NULL){
		cout<< temp -> data<<"->";
		temp = temp -> next;
	}
	cout<<"NULL"<<'\n';
}
int getLength(Node* head){

	int len = 0;

	Node* temp = head;
	while(temp != NULL){
		len++;
		temp = temp -> next;
	}
	return len;
}
void insetAtPosition(Node* &tail, Node* &head, int position, int d){

	// Agar Node ko first me insert krna hai toh
	if(position == 1){
		InsertAtHead(tail, head,  d);
		return;
	}
	Node* temp = head;
	int cnt = 1;

	while(cnt < position-1){
		temp = temp -> next;
		cnt++;
	}

	// Inserting at Last Position
	if(temp -> next == NULL){
		InsertAtTail(tail, head,  d);
		return;
	}
	Node* nodeToInsert = new Node(d);

	nodeToInsert -> next = temp -> next;
	temp -> next -> prev = nodeToInsert;

	temp -> next = nodeToInsert;
	nodeToInsert -> prev = temp;
}
void deleteNode(int position, Node* & head) { 

    //deleting first or start node
    if(position == 1) {
        Node* temp = head;
        temp -> next -> prev = NULL;
        head = temp -> next;
        //memory free start ndoe
        temp -> next = NULL;
        delete temp;
    }
    else
    {
        //deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }
        curr -> prev = NULL;
        prev -> next = curr -> next;
        curr -> next = NULL;


        delete curr;

    }
}

int main(){

	Node* head = NULL;
	Node* tail = NULL;

	print(head);

	cout << getLength(head) <<'\n';

	InsertAtHead(tail, head, 16);
	print(head);

	

	InsertAtTail(tail, head, 18);
	print(head);

	InsertAtTail(tail, head, 20);
	print(head);

	insetAtPosition(tail, head, 4, 22);
	print(head);

	// cout<<"Head is :) "<< head -> data <<'\n';
	// cout<<"Tail is :) "<< tail -> data <<'\n';
	
	deleteNode(1, head);
    print(head);

 //    cout << "head " << head -> data << endl;
 //    cout << "tail " << tail -> data << endl;


	return 0;


	
}
