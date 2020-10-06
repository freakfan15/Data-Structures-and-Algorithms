#include<iostream>
#include<cstring>
using namespace std;

class Car{

private:
	float price;
public:
	int model_no;
	char* name;

	Car(){
		name=NULL;
	}
	Car(float p, int m, char*n){
		price=p;
		model_no=m;
		name=new char[strlen(n)+1];
		strcpy(name, n);
	}

	//making a deep copy using copy constructor but my code works fine without using it. I have no clue why.
	Car(Car &y){
		price=y.price;
		model_no=y.model_no;
		name = new char[strlen(y.name)+1];
		strcpy(name, y.name);
	}
	// syntax of copy assignment operator
	void operator=(Car &y){
		model_no=y.model_no;
		name = new char[strlen(y.name)+1];
		strcpy(name, y.name);
	}

	void set_price(float p){
		price=p;
	}

	void print(){
		cout<<"Name is: "<<name<<endl;
		cout<<"Model is: "<<model_no<<endl;
		cout<<"Price is: "<<price<<endl;
	}

// we need to desrtroy the dynamically allocated data members explicitly by destruyctors
	~Car(){
		cout<<"Initiating destruction "<<name<<endl;
		if(name!=NULL){
			delete [] name;
		}
	}

};

int main(){

	Car c(100, 200, "Aston Martin");
	Car d;
	d=c;

	c.print();
	cout<<endl;

	d.set_price(400);
	d.name[0]='V';
	d.print();

	//lets create a dynamic object
	Car *e= new Car(10, 20, "Bentley");
	//now in order to print i can't use e.print cuz e is a pointer not an object
	// for that we can use (*e).print(); or e->print(); . Both work the same.
	e->print();
	//delete keyword to delete dynamically created objects
	delete e;
}