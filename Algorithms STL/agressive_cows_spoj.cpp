#include<iostream>
#include<algorithm>
using namespace std;

bool canPlacecows(int a[], int n, int cows, int min_sep){
	//placing the first element onn 0th position
	int last_cow = a[0];

	int cnt = 1;
	for(int i=1; i<n; i++){
		if(a[i] - last_cow>=min_sep){
			last_cow = a[i];
			cnt++;
			if(cnt==cows){
				return true;
			}
		}

	}
	return false;
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;

	while(t--){
		int n, cows;
		cin>>n>>cows;

		int a[100000];
		for(int i=0; i<n; i++){
			cin>>a[i];
		}
		sort(a,a+n);
		int s=0; 
		int e= a[n-1] -a[0];

		int ans=0;
		while(s<=e){
			int mid=(s+e)/2;
			bool cowRakhPaye= canPlacecows(a, n, cows, mid);
			if(cowRakhPaye){
				ans=mid;
				s=mid+1;
			}
			else{
				e=mid-1;
			}
		}

		cout<<ans<<endl;
	}

	return 0;
}