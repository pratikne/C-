// C++ program to demonstrate factory method design pattern
//https://www.geeksforgeeks.org/design-patterns-set-2-factory-method/


/**The factory method is a creational design pattern, i.e., related to object creation. In the Factory pattern, we create objects without exposing the creation logic to the client and the client uses the same common interface to create a new type of object. 
*  In the below example, we have totally decoupled the selection of types for object creation from the Client. The library is now responsible to decide which object type to create based on an input. The client just needs to make calls to the library’s factory Create method and pass the type it wants without worrying about the actual implementation of the creation of objects.
Other examples of the Factory Method: 

Say, in a ‘Drawing’ system, depending on the user’s input, different pictures like squares, rectangles, the circle can be drawn. Here we can use the factory method to create instances depending on the user’s input. For adding a new type of shape, no need to change the client’s code.

Another example: On the travel site, we can book train tickets as well as bus tickets and flight tickets. In this case, the user can give his travel type as ‘bus’, ‘train’, or ‘flight’. 
Here we have an abstract class ‘AnyTravel’ with a static member function ‘GetObject’ which depending on the user’s travel type, will create & return an object of ‘BusTravel’ or ‘ TrainTravel’. ‘BusTravel’ or ‘ TrainTravel’ have common functions like passenger name, Origin, and destination parameters.
*/

#include <iostream>
using namespace std;

enum VehicleType
{
    VT_TwoWheeler,
    VT_ThreeWheeler,
    VT_FourWheeler
};

// Library classes
class Vehicle
{
public:
    virtual void printVehicle() = 0; //Pure virtual function..hence it's an abstract class
    static Vehicle* Create(VehicleType type);  //NEW IMP
    virtual ~Vehicle() {}
};
class TwoWheeler : public Vehicle
{
public:
    void printVehicle()
    {
        cout << "I am two wheeler" << endl;
    }
};
class ThreeWheeler : public Vehicle
{
public:
    void printVehicle()
    {
        cout << "I am three wheeler" << endl;
    }
};
class FourWheeler : public Vehicle
{
public:
    void printVehicle()
    {
        cout << "I am four wheeler" << endl;
    }
};

// Factory method to create objects of different types.
// Change is required only in this function to create a new object type
Vehicle* Vehicle::Create(VehicleType type)
{
    if (type == VT_TwoWheeler)
        return new TwoWheeler();
    else if (type == VT_ThreeWheeler)
        return new ThreeWheeler();
    else if (type == VT_FourWheeler)
        return new FourWheeler();
    else
        return NULL;
}

// Client class
class Client
{
private:
    Vehicle* pVehicle;

public:
    // Client doesn't explicitly create objects
    // but passes type to factory method "Create()"
    Client(VehicleType type)
    {
        pVehicle = Vehicle::Create(type);
    }
    ~Client()
    {
        if (pVehicle)
        {
            delete pVehicle;
            pVehicle = NULL;
        }
    }
    Vehicle* getVehicle()
    {
        return pVehicle;
    }
};

// Driver program
int main()
{
    VehicleType type = VT_TwoWheeler;  //Can be user inputted as well
    Client* pClient = new Client(type);
    Vehicle* pVehicle = pClient->getVehicle(); //gets the vehicle instance
    pVehicle->printVehicle();
    delete pClient;
    return 0;
}