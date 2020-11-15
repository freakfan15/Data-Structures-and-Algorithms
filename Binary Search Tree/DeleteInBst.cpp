#include<iostream>
using namespace std;

class node{
public:
	int data;;
	node* left;
	node* right;
	//constructor
	node(int d){
		data=d;
		left=NULL;
		right=NULL;
	}
	
};

//this fn accepts the old root node and data and returns the new root node
node* insertInBST (node* root, int d){
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

node* deleteInBst(node* root, int key){
	if(root==NULL){
		return NULL;
	}
	else if(key < root->data){
		root->left = deleteInBst(root->left, key);
		return root;
	}
	else if(key == root->data){
		//we found the key, now we have 3 cases
		//1. node with 0 child
		if(root->left == NULL and root->right == NULL){
			delete root;
			return NULL;
		}
		//2. node with 1 child
		else if(root->left!=NULL and root->right==NULL){
			node* temp= root->left;
			delete root;
			return temp;
		}
		else if(root->left==NULL and root->right!=NULL){
			node* temp=root->right;
			delete root;
			return temp;
		}
		//3. node with 2 child
		else{
			//storing the right sub-tree in the replacement node.
			node* replace = root->right;
			//finding the inorder successor in the right sub-tree
			while(replace->left!=NULL){
				replace = replace->left;
			}

			//now change the data of the the root node to the data of the replace node
			root->data = replace->data;
			//finally delete the replacement node in the right sub-tree
			root->right = deleteInBst(root->right, replace->data);

			return root;
		}
	}
	else{
		root->right = deleteInBst(root->right, key);
		return root;
	}
}

int main(int argc, char const *argv[])
{
	node* root= build();

	//inorder traversal prints bst in sorted order
	printIn(root);

	deleteInBst(root, 5);
	cout<<endl;

	printIn(root);

	return 0;
}