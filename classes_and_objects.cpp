#include<bits/stdc++.h>
using namespace std;

/** Class is user defined datatype...blueprint/prototype....doesnt access mmemory **/

class Volume{
public:
    int length;
    int width;
    int height;
private:
    int row;
public:

    //DEF CONST
    Volume(){
        cout<<"DEFAULT CONSTRUCTOR"<<endl;
    }

    //setter
    Volume(int x, int y, int z, int row){  //PARAMETERISED constructor
        length = x;
        width = y;
        height = z;
        this->row = row;    //used for accessing private elements
    }
    //getter
    void getData(){
        cout<<length<<width<<height<<row<<endl;
    }

    //Destructor
    ~Volume(){
        cout<<"DESTRUCTOR CALLED"<<endl;
    }

};

int main(){
    Volume cylinder;  //default const. is called
    Volume cuboid(10,10,10,10), cube(10,10,10,10);  //para const. is called
    long volume = 0;
    cuboid.getData();
    cube.getData();
/**
    cuboid.height = 10;
    cuboid.length = 10;
    cuboid.width = 10;

    cube.length = 10;
    //cube.row = 10;   //vant access row as it is private element of class
**/
    volume = cuboid.height * cuboid.length * cuboid.width;
    cout << volume << endl;

    volume = pow(cube.length,3);
    cout << volume << endl;

    return 0;
}