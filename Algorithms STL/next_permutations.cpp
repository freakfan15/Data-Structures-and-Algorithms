#include<iostream>
#include<algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	int arr[1000];

	int test;
	cin>>test;

	while(test--){
		int n;
		cin>>n;
		for(int i=0; i<n; i++){
			cin>>arr[i];
		}
		next_permutation(arr, arr+n);
		for(int i=0; i<n; i++){
			cout<<arr[i]<<" ";
		}
	}

	return 0;
}
