//https://www.geeksforgeeks.org/design-patterns-set-2-factory-method/
#include <iostream>
using namespace std;

class Vehicle //creating abstract Vehicle class having pure virtual function
{
public:
    virtual void printVehicle() = 0;
};
class TwoWheeler : public Vehicle
{
public:
    void printVehicle()
    {
        cout << "I am two wheeler" << endl;
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

// Client (or user) class
class Client
{
    
private:
    Vehicle* pVehicle; //creating pointer of type Vehicle

public:
    Client(int type)
    {

        // Client explicitly creates classes according to
        // type
        if (type == 1)
            pVehicle = new TwoWheeler();
        else if (type == 2)
            pVehicle = new FourWheeler();
        else
            pVehicle = NULL;
    }

    ~Client()
    {
        if (pVehicle)
        {
            delete pVehicle;
            pVehicle = NULL;
        }
    }

    Vehicle* getVehicle() { return pVehicle; }

};


// Driver program
int main()
{
    Client *pClient = new Client(1);
    Vehicle *pVehicle = pClient->getVehicle();
    pVehicle->printVehicle();
    return 0;
}