#include<iostream>
using namespace std;

int binary_search(int a[], int n, int key){
	int s=0;
	int e=n-1;

	while(s<=e){
		int m=(s+e)/2;
		if(a[m]==key){
			return m;
		}
		else if(a[m]>key){
			e=m-1;
		}
		else{
			s=m+1;
		}
	}
	return -1;
}

int main(int argc, char const *argv[])
{
	int a[] = {1,2,3,4,5};
	int n = sizeof(a)/sizeof(int);

	int key;
	cin>>key;
	if(binary_search(a, n, key) == -1){
		cout<<key<<" not present"<<endl;
	}
	else{
		cout<<"Index of "<<key<<" is "<<binary_search(a,n,key);
	}

	return 0;
}