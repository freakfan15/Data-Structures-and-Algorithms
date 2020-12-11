#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	//applying rotate function i.e rotate(start, middle, end);

	//Applying on arrays
	int a[]= {10,20,30,40,50};
	int n=sizeof(a)/sizeof(int);

	rotate(a, a+2, a+n);

	for(int i=0; i<n; i++){
		cout<<a[i]<<", ";
	}
	cout<<endl;
	//Applying the same for vectors
	vector<int> v{10,20,30,40,50};
	rotate(v.begin(), v.begin()+3, v.end());

	for(auto it:v){
		cout<<it<<", ";
	}
	cout<<endl;
	//next permutations finds the permutation that is just greater than the current arrangement
	vector<int> v1{3,2,1};
	next_permutation(v1.begin(), v1.end());

	for(int x:v1){
		cout<<x<<" ";
	}
	return 0;
}