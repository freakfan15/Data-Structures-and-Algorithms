#include<iostream>
#include<stack>
using namespace std;

bool isBalanced(char *ch){
	stack<int> s;
	for(int i=0; ch[i]!='\0'; i++){
		if(ch[i]=='('){
			s.push(ch[i]);
		}
		else if (ch[i]==')'){
			if(s.empty() or s.top()!='('){
				return false;
			}
			s.pop();
		}

	}
	return s.empty();
}
int main(){

	char ch[100]="((a+b) + (a-b))";

	cout<<isBalanced(ch);


	return 0;
}