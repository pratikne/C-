/**OBSERVER - BEHAVIORAL DP
 * 
 * Provides a loosely coupled design between objects that interact. Loosely coupled objects are flexible with changing requirements. Here loose coupling means that the interacting objects should have less information about each other.

When to use this pattern?
You should consider using this pattern in your application when multiple objects are dependent on the state of one object as it provides a neat and well tested design for the same.

Examples
*Social media, RSS feeds, Email subscription in which you have the option to follow or subscribe and you receive latest notification.
*Cricket App notification updates
-> CricketData
->  CurrentScoreDisplay
->  AverageScoreDisplay
*All users of an app on play store gets notified if there is an update.*/

#include <iostream>
#include <list>
using namespace std;


//Observer
class Observer //Abstract class - Interface
{
public:
    virtual void notify(string msg) = 0;
};


class User : public Observer
{
private:
    int userid;

public:
    User(int userid)
    {
        this->userid = userid;
    }
    void notify(string msg)
    {
        cout << "User " << userid << " received : " << msg << endl;
    }
};



class Subject{
public:
    virtual void subscribe(Observer* user) = 0; //Attach
    virtual void unsubscribe(Observer* user) = 0; //Detach
    virtual void notifySubscriber(string message) = 0;
};

//Subject
class Group : public Subject
{
private:
    //
    list<Observer*> users; //List storing address of Observer objects
    //Example of Aggregation(Type of Association)

public:
    void subscribe(Observer* user)
    {
        users.push_back(user); //Inserts User in the List
    }
    void unsubscribe(Observer* user)
    {
        users.remove(user); //Removes particular User from the List
    }
    void notifySubscriber(string message)
    {
        //Traverse all the user within the list and notify them all
        for (auto user : users)
            user->notify(message);
    }

    ~Group(){
        cout << "Group Destructor called" << endl;
        for(auto user : users){
            cout << "User deleted" << endl;
            delete user;
        }
    }
};

int main()
{
    //Subject
    Group* group = new Group;

    //Observers
    User* user1 = new User(1);
    User* user2 = new User(2);
    User* user3 = new User(3);

    group->subscribe(user1);
    group->subscribe(user2);
    group->subscribe(user3);
    group->notifySubscriber("Hello!!!");

    group->unsubscribe(user3);
    group->notifySubscriber("Hello Again!!!");

    delete group;

    return 0;
}