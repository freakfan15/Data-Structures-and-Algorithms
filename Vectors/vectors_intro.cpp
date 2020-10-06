#include<iostream>
#include<vector>

using namespace std;
int main(int argc, char const *argv[])
{
	
	vector<int> a;
	vector<int> b(5,10); //five int with value 10 --intialize a vector of zeroes(n, 0);
	vector<int> c(b.begin(), b.end());

	vector<int> d{1,2,3,10,14};

	//look how we can iterate over the vector
	for(int i=0; i<b.size(); i++){
		cout<<c[i]<<", ";
	}
	cout<<endl;

	//method 2
	for(auto it=b.begin(); it!=b.end(); it++){
		cout<<*it<<" ";
	}
	cout<<endl;
	//for each loop
	for(int x:d){
		cout<<x<<", ";
	}

	//how to take input in vectors
	vector<int> v;
	int n;
	cin>>n;

	for(int i=0; i<n; i++){
		int no;
		cin>>no;
		v.push_back(no);
	}
	//printing elements of v
	for(int x:v){
		cout<<x<<", ";
	}
	cout<<endl;
	//understanding at memory level, what are the differenece between vectors v and d
	cout<<v.size()<<endl;     //no of elements the vector can hold
	cout<<v.capacity()<<endl; //size of underlying array
	cout<<v.max_size()<<endl; //max no of elements a vector can hold in the worst case

	//for vector d
	cout<<d.size()<<endl;
	cout<<d.capacity()<<endl;
	cout<<d.max_size()<<endl;


	return 0;
}