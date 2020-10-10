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

void print(node* head){
	while(head!=NULL){
		cout<<head->data<<"->";
		head=head->next;
	}
	cout<<endl;

}

node* take_input(){
	int d;
	cin>>d;
	node* head=NULL;
	while(d!=-1){
		insertAtTail(head, d);
		cin>>d;
	}
	return head;
}

node* merge(node* a, node* b){
	//base case
	if(a==NULL){
		return b;
	}
	else if(b==NULL){
		return a;
	}

	//rec case
	node* c;
	if(a->data < b->data){
		c=a;
		c->next=merge(a->next, b);
	}
	else{
		c=b;
		c->next=merge(a, b->next);
	}
	return c;
}

int main(int argc, char const *argv[])
{
	node* a=take_input();
	node* b=take_input();

	print(a);
	print(b);

	cout<<"After merge: ";
	print(merge(a, b));
	
	return 0;
}



