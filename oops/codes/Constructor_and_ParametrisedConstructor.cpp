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

	//creating a setter for price so that price can only be set in public if its greator than 0 else msp will be assigned
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
	Car d(222, 333 , "Audi");
	d.print();
	c.set_price(200);
	c.model_no=112;
	c.name[0]='B';
	c.name[1]='M';
	c.name[2]='W';
	c.name[3]='\0';

	cout<<endl;
	c.print();
	
	return 0;
}