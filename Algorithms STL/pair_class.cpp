#include<iostream>
#include<algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	pair<int,char> p;
	p.first = 10;
	p.second = 'A';

	//another way
	pair<int,char> p1(p);
	cout<<p1.first<<" "<<p1.second<<endl;

	//another way
	pair<int, string> p2 = make_pair(100, "Vivek");

	cout<<p2.first<<" "<<p2.second;

	//take input
	int a,b;
	cin>>a>>b;

	pair<int, int> p3 = make_pair(a,b);
	cout<<p3.first<<" "<<p3.second<<endl;

	//can make array of pairs
	//vector of pairs
	//also pair of pairs
	pair<pair<int,int>, string> p4;
	p4.second = "Audi";
	p4.first.first = 10;
	p4.first.second = 20;

	cout<<p4.second<<endl;

	return 0;
}