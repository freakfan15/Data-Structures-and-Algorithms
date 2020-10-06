#include<iostream>
#include<string>
#include<vector>
#include<stack> // using C++ STL of stack

using namespace std;

bool isPalindrome(stack<char> &s, string str){
	
	for(int i=0; i<str.length(); i++){
		if(s.top()==str[i]){
			s.pop();
		}
		else{
			return false;
		}
	}
	return true;
}

int main(){
	stack <char> s;
	string str;
	cin>>str; 

	int len=str.length();
	//storing in stack
	for(int i=0; i<len; i++){
		s.push(str[i]);
	}

	//checking
	if(isPalindrome(s, str)){
		cout<<str<<" is a Palindrome"<<endl;
	}
	else{
		cout<<str<<" is not a palindrome"<<endl;
	}
}