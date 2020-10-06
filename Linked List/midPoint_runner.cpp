//mid point runner technique
//we take a fast pointer and a slow pointer. Fast(speed)=2x, slow(speed)=x. So, by the time
//fast reaches the end, slow reahes the midpoint
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

//mid-point
node* midPoint(node*&head){
	//check for one node or zero node
	if(head==NULL and head->next==NULL){
		return head;
	}
	node *fast=head->next;
	node* slow=head;

	while(fast!=NULL and fast->next!=NULL){
		fast=fast->next->next;
		slow=slow->next;
	}
	return slow;
}


int main()
{
	node* head=NULL;

	int data;
	cin>>data;
	while(data!=-1){
		insertAtTail(head, data);
		cin>>data;
	}

	node* mid=midPoint(head);

	cout<<"Mid-point is: "<<mid->data<<endl;


	return 0;
}