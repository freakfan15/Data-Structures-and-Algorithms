#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char const *argv[])
{
	
	vector<int> d{1,2,3,10,14};
	//push back 
	d.push_back(16);

	//pop back / removes the last element
	d.pop_back();

	//insert some elements in the middle
	d.insert(d.begin() +3, 4, 100); // add 100 4 times after position 3
	
	//erase some elments in the middle
	d.erase(d.begin()+2); //removes the element after the 2nd elemnet i.e 3rd
	//we can also erase a range of elements
	d.erase(d.begin()+2, d.begin()+5);

	//size
	cout<<d.size()<<endl;
	cout<<d.capacity()<<endl;

	//we avoid the shrink
	d.resize(8); //we reduce the number of elements but might not reduce the capacity
	cout<<d.capacity()<<endl;

	//also we can empty the vector'
	//but keep in mind that the capacity remains the same as mem is not deleted
	d.clear();

	//empty method
	if(d.empty()){
		cout<<"This is an empty vector"<<endl;
	}
	cout<<d.size();

	//print
	for(int x:d){
		cout<<x<<" ";
	}
	cout<<endl;

	d.push_back(10);
	d.push_back(11);
	d.push_back(12);

	cout<<  d.front()<<endl;
	cout<<d.back()<<endl;

	

	return 0;
}