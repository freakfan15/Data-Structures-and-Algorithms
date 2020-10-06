#include<iostream>
using namespace std;

class node{
public:
	int data;
	node* next;
	node(int d){
		data=d;
		next=NULL;
	}
};

void insertAtHead(node*&head, int d){
	if(head==NULL){
		head=new node(d);
		return;
	}

	//if head if not null
	node*n=new node(d);
	n->next=head;
	head=n;
}

node* take_input(){
	int d;
	cin>>d;
	node* head=	NULL;
	while(d!=-1){
		insertAtHead(head, d);
		cin>>d;
	}
	return head;
}

void print(node* head){
	while(head!=NULL){
		cout<<head->data<<"->";
		head=head->next;
	}
	cout<<endl;
}

int main()
 {
	node* head=take_input();
	print(head);
	

	return 0;
}