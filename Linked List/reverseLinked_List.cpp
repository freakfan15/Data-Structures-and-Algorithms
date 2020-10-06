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

//overloading left shift operator for giving output
ostream& operator<<(ostream &os, node*head){
	print(head);
	return os;
}
//overloading right shift operator to taek input in ll through cin
istream& operator>>(istream &is, node*&head){
	head=take_input();
	return is;
}

void reverse(node*&head){
	node* C=head;
	node*P=NULL;
	node* N;

	while(C!=NULL){
		//saving the next node
		N=C->next;
		//making the current node point to prev
		C->next=P;
		//updating P and C i.e taking them one step forward
		P=C;
		C=N; 
	}
	head=P;
}

int main()
{
	node* head;
	

	cin>>head;

	reverse(head);
	cout<<head<<endl;

	return 0;
}	