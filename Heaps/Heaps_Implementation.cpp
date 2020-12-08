#include<iostream>
#include<vector>
using namespace std;

class Heap{
	vector<int> v;
	bool minHeap;
	//making a comparator to compare elements in heap
	bool compare(int a, int b){
		if(minHeap){
			return a < b;
		}
		else{
			return a > b;
		}
	}
	//heapify function rearranges the heap to satisfy the heap ordering property(min/max) 
	void heapify(int idx){
		int left = 2*idx;
		int right = left +1;
		
		int min_idx = idx;
		int last = v.size()-1;

		if(left<=last and compare(v[left], v[idx])){
			min_idx= left;
		}
		if(right<=last and compare(v[right], v[min_idx])){
			min_idx= right;
		}

		if(min_idx!=idx){
			swap(v[idx], v[min_idx]);
			heapify(min_idx);
		}
	}
public:
	//making a default constructor which by default makes the heap as minHeap
	//give false as 2nd parameter to make it a maxHeap
	Heap(int default_size = 10, bool type = true){
		v.reserve(default_size);
		v.push_back(-1); //to block the 1st idx as we are starting from 1
		minHeap = type;
	}

	void push(int d){
		v.push_back(d);
		int idx= v.size()-1;
		int parent= idx/2;

		//keep pushing to the top till you reach the root node or current element is already greater than parent
		while(idx>1 and compare(v[idx], v[parent])){
			swap(v[idx], v[parent]);
			idx=parent;
			parent=parent/2;
		}
	}
	int top(){
		return v[1];
	}
	//making pop fn to remove the top most element in heap
	int pop(){
		int last = v.size()-1;
		swap(v[1], v[last]);
		v.pop_back();
		heapify(1);
	}
	bool empty(){
		return v.size()==1;
	}
};

int main(int argc, char const *argv[])
{
	//give some intial size of teh vector and type(minHeap or maxHeap)
	Heap h;

	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		int no;
		cin>>no;
		h.push(no);
	}

	//printing the heap
	while(!h.empty()){
		cout<<h.top()<<" ";
		h.pop();
	}
	return 0;
}