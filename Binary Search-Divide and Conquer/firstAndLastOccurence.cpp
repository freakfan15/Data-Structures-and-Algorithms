#include<iostream>
using namespace std;

int first_occurence(int a[], int n, int key){
	int s=0;
	int e=n-1;
	int ans =-1;

	while(s<=e){
		int m=(s+e)/2;
		if(a[m]==key){
			ans=m;
			e=m-1;
		}
		else if(a[m]>key){
			e=m-1;
		}
		else{
			s=m+1;
		}
	}
	return ans;
}

int last_occurence(int a[], int n, int key){
	int s=0;
	int e=n-1;
	int ans =-1;

	while(s<=e){
		int m=(s+e)/2;
		if(a[m]==key){
			ans=m;
			s=m+1;
		}
		else if(a[m]>key){
			e=m-1;
		}
		else{
			s=m+1;
		}
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	int a[] = {1,2,3,3,3,4,5};
	int n = sizeof(a)/sizeof(int);

	int key;
	cin>>key;
	if(first_occurence(a, n, key) == -1){
		cout<<key<<" not present"<<endl;
	}
	else{
		cout<<"First occurence sof "<<key<<" is "<<first_occurence(a,n,key);
	}

	if(last_occurence(a, n, key) == -1){
		cout<<key<<" not present"<<endl;
	}
	else{
		cout<<endl<<"Last occurence sof "<<key<<" is "<<last_occurence(a,n,key);
	}

	return 0;
}