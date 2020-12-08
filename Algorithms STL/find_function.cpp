#include<iostream>
#include<algorithm>
using namespace std;

int main(){

	int arr[]={1, 3, 10, 21, 50};
	int n= sizeof(arr)/sizeof(int);

	//if we want to search an item in the array we can use the find fn in following way

	int key;
	cout<<"Enter  element you want to search: ";
	cin>>key;
	auto it= find(arr, arr+n, key);

	int index= it-arr;
	if(index==n){
		cout<<"Element not found";
	}
	else{
		cout<<"Index of "<<key<<" is "<<index<<endl;
	}

	return 0;
}