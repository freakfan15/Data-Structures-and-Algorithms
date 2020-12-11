/*Problem: Find minimum number of coins required for the given amount of money in indian currency*/
#include<iostream>
#include<algorithm>

using namespace std;

//making a comparator for returning the lb
int compare(int a, int b){
	return a<=b;
}

int main(int argc, char const *argv[])
{

	int coins[]={1,2,5,10,20,50,100,200,500,2000};
	int n=sizeof(coins)/sizeof(int);
	int money=168;
	
	while(money>0){
		int lb = lower_bound(coins, coins+n, money, compare)- coins -1;
		int m= coins[lb]; //finding coin for the particular index
		cout<<m<<", ";
		money = money -m;
	}


	return 0;
}