#include<iostream>
using namespace std;

class node{
public:
	int data;
	node* left;
	node* right;

	//node constructor
	node(int d){
		data=d;
		left=NULL;
		right=NULL;
	}
};

//this fn accepts the old root node and data and returns the new root node
node* insertInBST(node* root, int d){
	//base case
	if(root==NULL){
		return new node(d);
	}

	//rec case
	if(d<=root->data){
		root->left=insertInBST(root->left, d);
	}
	else{
		root->right=insertInBST(root->right, d);
	}
	return root;
}

node* build(){
	//read a list of numbers till -1 and also these numbers will be inserted into bst
	int d;
	cin>>d;

	node* root=NULL;

	while(d!=-1){
		root= insertInBST(root, d);
		cin>>d;
	}

	return root;
}

bool search(node* root, int key){
	if(root==NULL){
		return false;
	}
	if(root->data == key){
		return true;
	}
	if(key<=root->data){
		return search(root->left, key);
	}
	else{
		return search(root->right, key);
	}
}

//printiting in InOrder traversal
void printIn(node* root){
	//base case
	if(root==NULL){
		return;
	}

	//rec case i.e print left, root, right
	printIn(root->left);
	cout<<root->data<<" ";
	printIn(root->right);
}

int main(int argc, char const *argv[])
{
	node* root= build();
	// take ur input as 5 3 7 1 6 8 -1
	/*       5
	       3    7
	     1     6 8 */
	//inorder traversal prints bst in sorted order
	printIn(root);
	cout<<endl;

	int key;
	cin>>key;

	if(search(root, key))
		cout<<"Present"<<endl;
	else
		cout<<"Not present"<<endl;

	return 0;
}