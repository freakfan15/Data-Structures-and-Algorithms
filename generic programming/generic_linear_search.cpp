// creating a generic linear search function which can search in any type of dataype 

#include<iostream>
using namespace std;

template<typename T>
int search(T a[], int n,  T key){
	for(int i=0; i<n; i++){
		if(a[i]==key){
			return i;
		}
	}

	return n;
}

int main(int argc, char const *argv[])
{
	
	float a[]={1.1, 1.2, 1.3};
	int n=sizeof(a)/sizeof(float);
	float key=1.3;

	cout<<search(a, n, key)<<endl;

	return 0;
}