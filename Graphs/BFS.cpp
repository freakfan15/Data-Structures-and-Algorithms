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
	//BFS Traversal to print the visited nodes
	void bfs(T src){
		//creating a map to keep track of the visited nodes
		map<T, bool> visited;
		//creating a queue to push and pop the current visiting nodes and it's neighbours
		queue<T> q;

		q.push(src);
		visited[src]=true;

		while(!q.empty()){
			//store the current front item in a variable node of type T
			T node = q.front();
			q.pop();
			cout<<node<<", ";
			for(auto nbr:l[node]){
				//only push if that node has not been visited already
				if(visited[nbr]==false){
					q.push(nbr);
					visited[nbr]=true;
				}
			}
		}
	}
};

int main(int argc, char const *argv[])
{
	Graph<int> g;
	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(1,2);
	g.addEdge(2,3);

	g.bfs(0);


	return 0;
}