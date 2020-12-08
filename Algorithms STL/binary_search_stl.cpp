#include<iostream>
#include<algorithm>
using namespace std;

int main(){

	int arr[]={20, 30, 40, 40, 40, 50, 60};
	int n= sizeof(arr)/sizeof(int);

	//if we want to search an item in the array we can use the find fn in following way

	int key;
	cout<<"Enter element you want to search: ";
	cin>>key;
	
	bool present = binary_search(arr, arr+n, key);

	if(present){
		cout<<"Present"<<endl;
	}
	else{
		cout<<"Absent!"<<endl;
	}

	//lb gives the index of element just >=key
	auto lb = lower_bound(arr, arr+n, key);
	cout<<"Lower bound of "<<key<<" is "<<(lb-arr)<<endl;  //lb-arr to give the difference if address as lb only gives the adress of that key element
	
	//up gives the index of element > key (means the i+1 index if i is the index on which key occurs for the last time)
	auto ub = upper_bound(arr, arr+n, key);
	cout<<"Upper bound of "<<key<<" is "<<(ub-arr)<<endl;

	//finding the frequency of repetition of the key
	cout<<"Occurence Freq of "<<key<<" is: "<<(ub-lb)<<endl;

	return 0;
}