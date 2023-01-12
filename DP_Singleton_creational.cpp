//Thread safe Singleton Design Pattern
// https://refactoring.guru/design-patterns/singleton/cpp/example#example-1
// https://www.bogotobogo.com/DesignPatterns/singleton.php

/**
 * The Singleton class defines the `getInstance` method that serves as an
 * alternative to constructor and lets client access the same instance of this
 * class over and over.
 * 
 * Singleton pattern limits the instantiation of a class to one object. This is useful when exactly one object is needed to coordinate actions across the system. The concept is sometimes generalized to systems that operate more efficiently when only one object exists, or that restrict the instantiation to a certain number of objects (say, five). Some consider it an anti-pattern, judging that it is overused, introduces unnecessary limitations in situations where a sole instance of a class is not actually required, and introduces global state into an application.



We can modify the design of the code with the following constraints:

We do not want the singleton be copied so that there is only one instance. This can be achieved by declaring a private copy constructor and a private assignment operator.
The getInstance() method should return a reference rather than a pointer. This blocks a client from deleting the object. Also, by making destructor private, we can achieve the same effect.

Advantages :
Saves memory as only one instance is created
Single access point
Flexibility

Application :
Database application
Logging
Config Settings like for game/application
 */


#include <iostream>
#include <thread>
#include <mutex>

using namespace std;


//Singleton Class
class Logger{
private:
    static int count;

    static Logger* loggerInstance; //static pointer to store the address of Logger instance created

    static std::mutex m;

    Logger(){
        /**
        * The Singleton's constructor should always be private to prevent direct
        * construction calls with the `new` operator.
        */
        count++;
        cout<<"New instance created : No. of instance = " << count <<endl;
    }

    ~Logger() {std::cout << "Dtor\n";
        delete loggerInstance;
        }; //can't be destroyed by any function outside this class by anychance

    // Logger(const Logger&); //can't be copied
    
	// Logger& operator=(const Logger&) const; //can't be assigned 

public:
    static Logger* getInstance(); //static method to get the instance

    void LogWrite(string msg){
        cout << msg << endl;
    }
    /**
     * Singletons should not be cloneable/copyable.
     */
    Logger(const Logger &other) = delete;
    /**
     * Singletons should not be copy assignable.
     */
    Logger& operator =(const Logger &other) = delete;
};

int Logger::count = 0;

Logger* Logger::loggerInstance = nullptr;

std::mutex Logger::m;

Logger* Logger::getInstance(){
    m.lock();
    if(loggerInstance == nullptr){
        loggerInstance = new Logger(); //Creating the Instance just here
    }
    return loggerInstance;
    m.unlock()
}

void Thread1(){
    Logger* one = Logger::getInstance();
    one->LogWrite("Message One");
}

void Thread2(){
    Logger* two = Logger::getInstance();
    two->LogWrite("Message Two");
}

int main(){
    
    thread t1(Thread1);
    thread t2(Thread2);

    t1.join();
    t2.join();    

    return 0;
}

/*THEORY>

 Suppose a developer wants to create a simple DBConnection class to connect 
 to a database and wants to access the database at multiple locations from code,
 generally what the developer will do is create an instance of DBConnection class 
 and use it for doing database operations wherever required. 
 This results in creating multiple connections from the database as each instance 
 of DBConnection class will have a separate connection to the database. 
 In order to deal with it, we create DBConnection class as a singleton class, 
 so that only one instance of DBConnection is created and a single connection is established. 
 Because we can manage DB Connection via one instance, we can control load balance, 
 unnecessary connections, etc. **/