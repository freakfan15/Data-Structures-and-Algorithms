#include<iostream>
#include<algorithm>
using namespace std;

bool compare(int a, int b){
	return a>b; //for sorting in descending order
}
int main(int argc, char const *argv[])
{
	int a[100];

	int n;
	cout<<"Enter number of elements: ";
	cin>>n;

	cout<<"Enter elements: ";
	for(int i=0; i<n; i++){
		cin>>a[i];
	}

	//effecient that bubble sort, quick sort, insertion sort  etc
	sort(a, a+n, compare); //no need to pass compare fn if sorting in ascending order

	cout<<"Elements in sorted order are :";
	for(int i=0; i<n; i++){
		cout<<a[i]<<", ";
	}

	return 0;
}