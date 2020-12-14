#include<iostream>
using namespace std;

float squareRoot(int n, int p){
	int s=0, e=n;
	float ans=-1;
	while(s<=e){
		int m=(s+e)/2;
		if(m*m ==n){
			return m;
		}
		else if(m*m <n){
			ans=m;
			s=m+1;
		}
		else{
			e=m-1;
		}

	}
	//now for finding the decimal  part upto p places
	float inc=0.1;
	for(int i=0; i<p; i++){
		while(ans*ans<=n){
			ans=ans+inc;
		}
		ans = ans-inc;
		inc=inc/10;
	}
	return ans;
}

int main(int argc, char const *argv[])
{

	int n;
	cin>>n;
	cout<<squareRoot(n,3)<<endl;
	
	return 0;
}