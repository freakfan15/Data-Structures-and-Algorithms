#include<iostream>
#include<list>

using namespace std;

int main(int argc, char const *argv[])
{
	list<int> l;

	//we can also init list
	list<int> l1{1,3,5,2,7};
	//list of diff datatype
	list<string> l2{"apple", "banana", "mango", "guava"};
	l2.push_back("pineapple");

	//iterate over the list and print teh data
	for(string  s:l2){
		cout<<s<<"->";
	}



	return 0;
}