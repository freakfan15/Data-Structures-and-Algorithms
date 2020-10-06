//Circular LL
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

void insertAtHead(node*&head, int data){
	node* n= new node(data);
	node* temp = head;

	n->next=head;
	if(temp!=NULL){

		while(temp->next!=head){
			temp=temp->next;
		}
		temp->next=n;
	}
	else{
		n->next=n;
	}
	head=n;
}

void print(node*head){

	node* temp=head;

	while(temp->next!=head){
		cout<<temp->data<<"->";
		temp=temp->next;
	}
	cout<<temp->data<<endl;
	return;
}

//function to find if node is present or not
node* getNode(node* head, int data){
	node* temp=head;

	while(temp->next!=head){
		if(temp->data==data){
			return temp;
		}
		temp=temp->next;
	}
	//out of the loop pointing at the last node, so
	if(temp->data==data){
		return temp;
	}
	return NULL;
}

void deleteNode(node*&head, int data){

	node* del= getNode(head, data);

	if(del==NULL){
		return;
	}

	if(head==del){
		head=head->next;
	}

	node* temp=head;
	while(temp->next!=del){
		temp=temp->next;
	}
	temp->next=del->next;
	delete del;
}
int main(int argc, char const *argv[])
{
	node* head=NULL;


	int d;
	cin>>d;
	while(d!=-1){
		insertAtHead(head, d);
		cin>>d;
	}

	print(head);

	deleteNode(head, 3);
	print(head);

	return 0;
}