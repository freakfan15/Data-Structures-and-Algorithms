/*Book allocation- Hackerblocks
https://hack.codingblocks.com/app/practice/1/1057/problem
*/
#include<iostream>
#include<algorithm>
#include<climits>
using  namespace std;

bool canPaint(int a[], int n, int k, int curr_min){
	int paintersUsed=1;
	int unitsPainted =0;
	for(int i=0; i<n; i++){
		if(unitsPainted +a[i]>curr_min){
			//give remaining pages to next student
			paintersUsed++;
			unitsPainted=a[i];
			if(paintersUsed>k){
				return false;
			}
		}
		else{
			//when the pagesRead are less than min_pages
			unitsPainted+=a[i];
		}
	}
	return true;
}

int main(){
	
	
		int n,k;
		cin>>k>>n;
		int a[11];
		int Max = 0;
		for(int i=0; i<n; i++){
			cin>>a[i];
		}

		int sum=0;
		for(int i=0; i<n; i++){
			Max = max(Max, a[i]);
			sum=sum+a[i];
		}
		int s=Max;
		int e=sum;

		int ans=INT_MAX;
		while(s<=e){
			int mid=(s+e)/2;
			bool possible =canPaint(a,n,k,mid);
			if(possible){
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
	

	return 0;
}