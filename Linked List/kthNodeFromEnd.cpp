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

//kth node from the end
node* SearchFromEnd(node*head, int k){
	if(head==NULL and head->next==NULL){
		if(k==0 or k==1){
			return head;
		}
		cout<<"element not found";
	}

	node* slow=head;
	node* fast=head;

	//taking k-1 jumps to reach kth node form the front
	for(int i=1; i<k; i++){
		fast=fast->next;
	}
	while(fast->next!=NULL){
		fast=fast->next;
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

	node* x=SearchFromEnd(head, 3); //x=kth node form the end

	cout<<"Node is: "<<x->data<<endl;


	return 0;
}