#include<iostream>
using namespace std;

// acess specifiers- public and private
/* Public- access outside the class
   Private- access inside the class only */
//defining a class is equivalent to define a
//new data type.
class Car{
public:
	int price;
	int model_no;
	char name[20];

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
};

int main()
{

	//create an object
	Car arr[20]; //store inf about 20 cars
	Car c;
	c.price=100;
	c.model_no=112;
	c.name[0]='B';
	c.name[1]='M';
	c.name[2]='W';
	c.name[3]='\0';

	//print
	cout<<"Car Name "<<c.name<<" Model no "<<c.model_no<<" Price "<<c.price<<endl;

	//fn call
	cout<<"Price after discount: "<<c.get_discounted_price(0.3)<<endl;

	//printing car's detail using print fn
	c.print();

	cout<<sizeof(c)<<endl;   //only object c occupies mem
	cout<<sizeof(Car)<<endl; //this Car does not occupy any mem
	
	return 0;
}