// DSA - Quiz 01
#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
	Node* prev;
};

void delNode(Node*& head, int targetVal){
	if (head == nullptr)
	return;
	
	Node* curr = head; //temp Node ptr
	
	while (curr!=nullptr && curr->data!=targetVal){
		curr = curr->next;
	}
	if (curr==nullptr){
		cout<<"Not found"<<endl;
	}
	
	if (curr == head){
		head = curr->next;
	}
	if (curr->prev!=nullptr){
		curr->prev->next = curr->next;
	}
	if (curr->next != nullptr) {
        curr->next->prev = curr->prev;
    }
    delete curr;
}

void display(Node* head){
	Node* temp = head;
	while (temp!=nullptr){
		cout<<temp->data;
		if (temp->next!=nullptr){
			cout<<" <-> ";
		}
		temp = temp->next;
	}
	cout<<" -> nullptr" <<endl;
}
int main() {
Node* n1 = new Node{10, nullptr, nullptr};
Node* n2 = new Node{50, nullptr, n1};
Node* n3 = new Node{40, nullptr, n2};
Node* n4 = new Node{20, nullptr, n3};

n1->next = n2;
n2->next = n3;
n3->next = n4;

Node* head = n1; // Set the head of the list

cout << "Original Doubly Linked List:\n";
display(head);

cout << "\nDeleting node 20...\n";
delNode(head, 20);

cout << "\nModified Doubly Linked List:\n";
display(head);

// Clean up memory
while (head != nullptr) {
    Node* temp = head;
    head = head->next;
    delete temp;
}

return 0;
}