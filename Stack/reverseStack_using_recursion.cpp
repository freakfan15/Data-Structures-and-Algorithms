#include<iostream>
#include<stack>
using namespace std;

void insertBottom(stack<int> &s, int x){
	//base ecase
	if(s.empty()){
		s.push(x);
		return;
	}
	//rec case
	int data=s.top();
	s.pop();
	insertBottom(s, x);
	s.push(data);
}

void reverseStack(stack<int> &s){
	//base case
	if(s.empty()){
		return;
	}
	//store top element in a var
	int x=s.top();
	s.pop();
	//rec case
	reverseStack(s);
	insertBottom(s, x);

}

int main()
{
	
	stack <int> s1;
	for(int i=1; i<=4; i++){
		s1.push(i);
	}

	//fn call
	reverseStack(s1);
	//print
	while(!s1.empty()){
		cout<<s1.top()<<" ";
		s1.pop();
	}


	return 0;
}