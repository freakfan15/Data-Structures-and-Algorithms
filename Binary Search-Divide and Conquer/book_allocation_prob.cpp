/*Book allocation- Hackerblocks
https://hack.codingblocks.com/app/practice/1/1365/problem
*/
#include<iostream>
#include<algorithm>
#include<climits>
using  namespace std;

bool canAllocate(int a[], int n, int m, int min_pages){
	int studentsUsed=1;
	int pagesRead =0;
	for(int i=0; i<n; i++){
		if(pagesRead +a[i]>min_pages){
			//give remaining pages to next student
			studentsUsed++;
			pagesRead=a[i];
			if(studentsUsed>m){
				return false;
			}
		}
		else{
			//when the pagesRead are less than min_pages
			pagesRead+=a[i];
		}
	}
	return true;
}

int main(){

	
	int t;
	cin>>t;
	int n,m;
	cin>>n>>m;
	while(t--){
		int a[100];
		for(int i=0; i<n; i++){
			cin>>a[i];
		}
		int s=a[n-1];

		int sum=0;
		for(int i=0; i<n; i++){
			sum=sum+a[i];
		}
		int e=sum;

		int ans=INT_MAX;
		while(s<=e){
			int mid=(s+e)/2;
			bool bookAlloc =canAllocate(a,n,m,mid);
			if(bookAlloc){
				ans=min(ans,mid);
				e=mid-1;
			}
			else{
				//if it is not possible to divide at mid no of pages
				//means we need to inc the no of pages			
				s=mid+1;
			}
			
		}

		cout<<ans<<endl;
	}

	return 0;
}