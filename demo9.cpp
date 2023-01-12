
//Dassault
#include<iostream>
using namespace std;


class Car{
   //*v_ptr
   
   int color;
public:   
   virtual void brake(){
		cout << " I am Car " << endl;
   }
   
   virtual void drive(){
        cout << " I am Car drive" << endl;
   }
   
   Car(const Car& c){
        cout << " Car copy called" << endl;
		color = c.color;
   }

   Car(){
    cout << " Car Const called" << endl;
   }

   virtual ~Car(){
    cout << " Car Dest called" << endl;
   }
   
};


class SportsCar : public Car{
public:
	void brake(){
		cout << "I am sports car" << endl;
	 }

    SportsCar(){
    cout << "Sportscar Const called" << endl;
   }

   ~SportsCar(){
    cout << "Sportscar Dest called" << endl;
   }
};


int main(){

	Car c1;
	c1.brake(); //
	
	Car c3(c1); //copy const invoked
	

	SportsCar s1;
	s1.brake(); //

	Car* c2;
	c2 = new Car; //
	c2->brake(); // I am Car
    delete c2;
    c2 = NULL;

    cout << "------------" << endl;

	c2 = new SportsCar;
	c2->brake(); // I am sports car
	c2->drive();
	delete c2;
	c2 = NULL;

	return 0;
	
}


