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

node* buildTree(){
	//base case
	int d;
	cin>>d;
	if(d==-1){
		return NULL;
	}
	//rec case
	node* root = new node(d);
	root->left = buildTree();
	root->right = buildTree();

	return root;
}

void print(node* root){
	//base case
	if(root==NULL){
		return;
	}
	//rec case
	cout<<root->data<<" ";
	print(root->left);
	print(root->right);
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

//printing in Postorder Traversal
void printPost(node* root){
	//base case
	if(root==NULL){
		return;
	}

	//rec case i.e print left, right, root
	printPost(root->left);
	printPost(root->right);
	cout<<root->data<<" ";
}

int main()
{
	node* root= buildTree();

	print(root);
	cout<<endl;

	printIn(root);
	cout<<endl;

	printPost(root);
	cout<<endl;

	return 0;
}