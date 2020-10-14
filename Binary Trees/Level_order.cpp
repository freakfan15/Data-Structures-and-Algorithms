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

int height(node* root){
	//base case
	if(root == NULL){
		return 0;
	}
	//rec case
	int ls = height(root->left);
	int rs = height(root->right);

	return max(ls, rs) + 1; 
}

void  printkthLevel(node* root, int k){
	//base case
	if(root==NULL){
		return;
	}

	//rec case
	if(k==1){
		cout<<root->data<<" ";
		return;
	}
	printkthLevel(root->left, k-1);
	printkthLevel(root->right, k-1);
	return;
}

void printAllLevels(node* root){
	int H=height(root);

	for(int i=1; i<=H; i++){
		printkthLevel(root, i);
		cout<<endl;
	}
	return;
}

int main()
{
	node* root= buildTree();

	cout<<height(root)<<endl;

	printkthLevel(root, 3);
	cout<<endl;

	
	printAllLevels(root);

	return 0;
}