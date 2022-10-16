//Thread safe Singleton Design Pattern
//https://refactoring.guru/design-patterns/singleton/cpp/example#example-1

/**
 * The Singleton class defines the `getInstance` method that serves as an
 * alternative to constructor and lets clients access the same instance of this
 * class over and over.
 */



#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

class Logger{
private:
    static int count;
    static Logger* loggerInstance;
    static std::mutex m;
    Logger(){
        /**
        * The Singleton's constructor should always be private to prevent direct
        * construction calls with the `new` operator.
        */
        count++;
        cout<<"New instance created : No. of instance = " << count <<endl;
    }
public:
    static Logger* getInstance(); //sttaic method to get the instance
    void LogWrite(string msg){
        cout << msg << endl;
    }
    /**
     * Singletons should not be cloneable.
     */
    Logger(Logger &other) = delete;
    /**
     * Singletons should not be assignable.
     */
    void operator=(const Logger &) = delete;
};

int Logger::count = 0;

Logger* Logger::loggerInstance = nullptr;

std::mutex Logger::m;

Logger* Logger::getInstance(){
    m.lock();
    if(loggerInstance == nullptr){
        loggerInstance = new Logger();
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