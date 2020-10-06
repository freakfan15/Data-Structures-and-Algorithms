#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Car{
public:
	string car_name;
	int x,y;
	Car(){

	}
	Car(string n, int x, int y){
		car_name=n;
		this->x=x;
		this->y=y;
	}
	int dist(){
		return x*x + y*y;
	}
};

bool compare(Car A, Car B){
	int da=A.dist();
	int db=B.dist();
	if(da==db){
		return A.car_name.length()<B.car_name.length();
	}
	return da<db;
}

int main()
{
	int n;
	cin>>n;
	vector <Car> v;

	for(int i=0; i<n; i++){
		int x,y;
		string name;
		cin>>name>>x>>y;
		Car temp(name, x, y);
		v.push_back(temp);
	}

	sort(v.begin(), v.end(), compare);
	
	for(Car c:v){
		cout<<"Car is "<<c.car_name<<"Distance is "<<c.dist()<<"Location is "<<c.x<<", "<<c.y<<endl;
	}

	return 0;
}