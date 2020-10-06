#include<iostream>
#include<stack>
using namespace std;

void transfer(stack<int>&s1, stack<int>&s2, int n){
	for(int i=0; i<n; i++){
		s2.push(s1.top());
		s1.pop();
	}
}
void reverseStack(stack <int>&s1){
	//making another stack to copy transfer n-i-1 elements
	stack <int> s2;
	int n=s1.size();
	
	for(int i=0; i<n; i++){
		int x=s1.top();
		s1.pop();
		//tranfer al remaining items to array s2
		transfer(s1, s2, n-i-1);
		//now since s1 is empty put x1 back to stack 1
		s1.push(x);
		//now transfer all elements of s2 to s1
		transfer(s2, s1, n-i-1);
	}

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