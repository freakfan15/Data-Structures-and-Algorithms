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
int idx=0;
bool linearSearch(node*head, int key){
	
	while(head!=NULL){
		if(head->data==key){

			return true;

		}
		idx++;
		head=head->next;
	}
	return false;
}

//implementing search fn recursively
bool recSearch(node*head, int key){
	//base case
	if(head==NULL){
		return false;
	}
	//rec case
	if(head->data==key){
		return true;
	}
	else{
		return recSearch(head->next, key);
	}
}


int main(int argc, char const *argv[])
{
	node* head=NULL;

	//inserting elemnts
	
	for(int i=1; i<=5; i++){
		
		insertAtHead(head, i);
	}

	if(linearSearch(head, 3)){
		cout<<"element is present at index "<<idx<<endl;
	}
	else{
		cout<<"element is not present"<<endl;
	}

	if(recSearch(head, 10)){
		cout<<"element is present"<<endl;
	}
	else{
		cout<<"element is not present"<<endl;
	}
	return 0;
}