#include<iostream>
#include<map>
#include<queue>
#include<list>

using namespace std;

template<typename T>
class Graph{
	map<T, list<T> > l;
public:
	void addEdge(int x, int y){
		l[x].push_back(y);
		l[y].push_back(x);
	}

	void dfs_helper(T src, map<T, bool> &visited){

		cout<<src<<" ";
		visited[src]=true;
		//go to all the nodes that is not visited
		for(auto nbr:l[src]){
			if(visited[nbr]==false){
				dfs_helper(nbr, visited);
			}
		}
		return;
	}
	//DFS Traversal to print the visited nodes
	void dfs(T src){
		 map<T, bool> visited;
		 //iterate through the keys and mark them not visited
		 for(auto p:l){
		 	T node = p.first;
		 	visited[node] = false;
		 }

		 dfs_helper(src, visited);

	}
	
};

int main(int argc, char const *argv[])
{
	Graph<int> g;
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(1,2);
	g.addEdge(2,3);

	//printing the visited using bfs travesal considering 0 as the source node. 
	g.dfs(0);

	return 0;
}