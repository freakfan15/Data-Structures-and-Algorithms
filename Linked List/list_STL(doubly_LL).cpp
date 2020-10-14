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

	//sort
	l2.sort(); //l2 is sorted lexigraphically

	//iterate over the list and print teh data
	for(string  s:l2){
		cout<<s<<"->";
	}
	//some operations
	cout<<endl<<l2.front()<<endl;

	l2.pop_back();
	l2.push_front("kiwi");

	//print using iterator
	for(auto it=l2.begin(); it!=l2.end(); it++){
		cout<<(*it)<<" -> ";
	}

	cout<<endl<<"reversing the list: ";
	l2.reverse();
	for(auto it=l2.begin(); it!=l2.end(); it++){
		cout<<(*it)<<" -> ";
	}
	cout<<endl;

	//insertings ome more fruits
	l2.push_back("orange");
	l2.push_back("guava");
	//cout<<endl<<"remove a fruit: ";
	//remove a fruit
	//string f;
	//cin>>f;
	//l2.remove(f);
	for(auto it=l2.begin(); it!=l2.end(); it++){
		cout<<(*it)<<" -> ";
	}

	//remove one or more elements from the list at "a particular index" using iterators
	cout<<endl;
	auto it=l2.begin();
	it++; it++; //moving at the third item

	//l2.erase(it);
	cout<<(*it);

	l2.erase(it);
	cout<<endl;
	for(auto it=l2.begin(); it!=l2.end(); it++){
		cout<<(*it)<<" -> ";
	}
	cout<<endl;
	//inserting  an item at somewhere in b/w
	it=l2.begin();
	it++;
	l2.insert(it, "Fruit juice");
	for(auto it=l2.begin(); it!=l2.end(); it++){
		cout<<(*it)<<" -> ";
	}

	return 0;
}