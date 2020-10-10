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

//making function to merge two sorted linked list
node* merge(node* a, node* b){
	//base case
	//retuning c->next=b(now b is the head of the smaller ll and not from the starting)
	if(a==NULL){
		return b;
	}
	//similar for a
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

//making mergeSort fn
node* mergeSort(node* &head){
	//base case
	if(head==NULL or head->next==NULL){
		return head;
	}

	//breaking the ll about midpoint
	node* mid=midPoint(head);
	node* a=head;
	node* b=mid->next;
	mid->next=NULL;

	//rec sort two parts
	a=mergeSort(a);
	b=mergeSort(b);

	//merge the two sorted LL
	node* c=merge(a, b);



}

void print(node* head){
	while(head!=NULL){
		cout<<head->data<<"->";
		head=head->next;
	}
	cout<<endl;

}

int main(int argc, char const *argv[])
{
	node* head=NULL;

	int d;
	cin>>d;
	while(d!=-1){
		insertAtTail(head, d);
		cin>>d;
	}

	print(head);

	print(mergeSort(head));



	return 0;
}