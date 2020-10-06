#include<iostream>
#include<cstring>
using namespace std;

// acess specifiers- public and private
/* Public- access outside the class
   Private- access inside the class only */
//defining a class is equivalent to define a
//new data type.
class Car{

private:
	float price; // defining it as private variable so that it cannot be changed by public domain
public:
	
	int model_no;
	char name[20];

	//constructor
	Car(){
		cout<<"Inside Car Constructor"<<endl;
	}

	Car(float p, int m, char* n){
		price=p;
		model_no=m;
		strcpy(name, n);

	}
	//creating a copy constructor(no need just over loading the default one to understand what's written inside it by default)
	Car(Car &x){  // we need to pass the object by refrence in copy constructor. 
		cout<<"Copy Constructor: "<<endl;
		price=x.price;
		model_no=x.model_no;
		strcpy(name, x.name);

	}


	//creating a fn to print detail
	void print(){
		cout<<"Name is: "<<name<<endl;
		cout<<"Model is: "<<model_no<<endl;
		cout<<"Price is: "<<price<<endl;
	}

	//create fn
	float get_discounted_price(float x){
		return price*(1.0-x);
	}

	//creating a setter for price so that price can only be set in public if its greator than msp else msp will be assigned
	void set_price(float p){
		float msp=111;
		if(p>msp){
			price=p;
		}
		else{
			price=msp;
		}
	}
	float get_price(){
		return price;
	}

};

int main()
{

	//create an object
	
	//Car c, d, e; // constructor will be called three times cuz of 3 objects
	Car c;
	
	c.set_price(200);
	c.model_no=112;
	c.name[0]='B';
	c.name[1]='M';
	c.name[2]='W';
	c.name[3]='\0';

	cout<<"Car d: "<<endl;
	Car d(222, 333 , "Audi");
	d.print();

	//CopyConstructor
	cout<<"Car e: "<<endl;
	Car e(d);
	e.set_price(450);
	e.print();

	//another way for copyConstructor
	Car f=e; //object e is copied to f;

	cout<<"Car c: "<<endl;
	cout<<endl;
	c.print();
	
	return 0;
}