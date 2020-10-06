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

void insertAtHead(node* &head, int d){
	if (head==NULL)
	{
		head= new node(d);
		return;
	}

	 node* n=new node(d);
	 n->next=head;
	 head=n;
}

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

//fn to count the length of the linked list
int length(node*head){
	int cnt=0;
	while(head!=NULL){
		cnt++;
		head=head->next;
	}
	return cnt;
}

void insertAtMiddle(node* &head, int data, int p){
	//corner case
	if(head==NULL or p==0){
		insertAtHead(head, data);
	}
	else if(p>length(head)){
		insertAtTail(head,data);
	}
	else{
		//take p-1 jumps
		int jump=1;
		node*temp=head;
		while(jump<=p-1){
			temp=temp->next;
			jump++;
		}
		//now we are the the pth node after taking p-1 jumps
		node* n=new node(data);
		n->next=temp->next;
		temp->next=n;
	}
}
void print(node* head){
	while(head!=NULL){
		cout<<head->data<<"->";
		head=head->next;
	}
	cout<<endl;

}

void deleteHead(node* &head){
	if(head==NULL){
		return;
	}
	node* temp=head->next;
	delete head;
	head=temp;
}

void deleteAt(node* &head, int p){
	if(head==NULL){
		return;
	}
	//taking p-1 jumps to reach at position p
	int jump=1;
	node* temp=head;
	while(jump<=p-1 and temp!=NULL){
		temp=temp->next;
		jump++;
	}
	//now temp points at the node previous to the pth node
	//storing the node to be deleted in node n
	node* n=temp->next;
	//linking temp node to the node after the deleted node
	temp->next=n->next;
	delete n;
	
}

int main(int argc, char const *argv[])
{
	node*head= NULL;
	insertAtHead(head,3);
	insertAtHead(head,2);
	insertAtHead(head,1);
	insertAtHead(head,0);

	print(head);

	insertAtMiddle(head, 5, 3);
	insertAtTail(head, 10);

	print(head);

	deleteHead(head);

	print(head);

	deleteAt(head, 3);
	print(head);

	return 0;
}