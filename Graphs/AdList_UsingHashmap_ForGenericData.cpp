#include<iostream>
#include<list>
#include<unordered_map>
#include<cstring>

using namespace std;
	//Ajd List
	unordered_map<string, list<pair<string, int> > > l;
class Graph{
public:
	void addEdge(string x, string y, bool bidir, int wt){
		
		l[x].push_back(make_pair(y, wt));
		if(bidir){
			l[y].push_back(make_pair(x, wt));
		}
	}

	void printAdjList(){
		//iterate over all the keys in the hashmap
		for(auto p:l){ //here auto = pair
			string city=p.first;
			list<pair<string, int> > nbrs =p.second;  //nbrs means neighbours to the given node

			cout<<city<<"->";
			for(auto nbr:nbrs){  //auto is pair
				string dest = nbr.first;
				int dist = nbr.second;

				cout<<dest<<" "<<dist<<", ";
			}
			cout<<endl;
		}
	}
};

int main(int argc, char const *argv[])
{
	Graph g;
	g.addEdge("A", "C", true, 10);
	g.addEdge("A", "B", true, 20);
	g.addEdge("C", "D", true, 30);
	g.addEdge("B", "D", true, 40);
	g.addEdge("A", "D", false, 50);

	g.printAdjList();
	
	return 0;
}