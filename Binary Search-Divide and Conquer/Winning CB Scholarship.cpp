/*Problem link
https://hack.codingblocks.com/app/practice/1/300/problem
*/

#include<iostream>
using namespace std;
#define ll long long

//if no. of current required coupons is less than total coupons avaialble
		//                                               + total coupons we can get from taking y coupons from each bad performer
bool canGiveScholarship(ll n, ll m, ll x, ll y, ll mid){

	if(mid*x <= m +(n-mid)*y){
			return true;
	}
	else{
		return false;
	}
}

int main()
{
	ll n,m,x,y;
	cin>>n>>m>>x>>y;

	ll s=0; ll e = n;
	ll ans =0;
	while(s<=e){
		ll mid=(s+e)/2;
		bool possible = canGiveScholarship(n, m, x, y, mid);

		if(possible){
			//means we can give scholarship to students less than mid as well so,
			ans=mid;
			s=mid+1;
		}
		else{
			e=mid-1;
		}
	}

	cout<<ans<<endl;

	return 0;
}