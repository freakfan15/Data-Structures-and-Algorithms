#include<iostream>
#include<climits>
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
//fucntion to check if given tree is BST or not
bool isBST(node* root, int minV= INT_MIN, int maxV= INT_MAX){
	if(root==NULL){
		return true;
	}
	if(root->data >=minV and root->data<=maxV and isBST(root->left, minV, root->data) and isBST(root->right, root->data, maxV)){
		return true;
	}
	return false;
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

	if(isBST(root)){
		cout<<"BST"<<endl;
	}
	else{
		cout<<"Not a BST"<<endl;
	}

	return 0;
}