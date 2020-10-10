#include<iostream>
using namespace std;

class node{
public:
	int data;
	node*next;
	//constructor
	node(int d){
		data=d;
		next=NULL;
	}

};

void insertAtTail(node*&head, int data){
	if(head==NULL){
		head=new node(data);
		return;
	}
	node*tail =head;
	while(tail->next!=NULL){
		tail=tail->next;
	}
	tail->next=new node(data);
	return;
}

bool detectCycle(node* head){
	node* slow=head;
	node* fast=head;

	while(fast!=NULL and fast->next!=NULL){
		fast=fast->next->next;
		slow=slow->next;

		if(fast==slow){
			return true;
		}
		
	}
	return false;
}

void print(node* head){
	while(head!=NULL){
		cout<<head->data<<"->";
		head=head->next;
	}
	cout<<endl;

}
