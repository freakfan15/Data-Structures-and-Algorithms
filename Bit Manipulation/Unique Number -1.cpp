#include<iostream>
using namespace std;

/*Problem : There are 2N+1 numbers . out of which N numbers occur 2 times and only 1 unique number is there.
FInd that unique number.*/

int main(int argc, char const *argv[])
{

	int n;
	cin>>n;

	int no;
	int ans=0;
	//using bitwise XOR to solve the problem. We XOR all the elements together. So the all the numbers 
	//occuring twice get cancelled out.
	for(int i=0; i<n; i++){
		cin>>no;
		//cuz 0^x=x
		ans=ans^no;
	}

	cout<<ans<<endl;
	return 0;
}