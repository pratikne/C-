/**
 * Provides a loosely coupled design between objects that interact. Loosely coupled objects are flexible with changing requirements. Here loose coupling means that the interacting objects should have less information about each other.

When to use this pattern?
You should consider using this pattern in your application when multiple objects are dependent on the state of one object as it provides a neat and well tested design for the same.
Examples
*Social media, RSS feeds, email subscription in which you have the option to follow or subscribe and you receive latest notification.
*All users of an app on play store gets notified if there is an update.*/

#include <iostream>
#include <list>
using namespace std;

class ISubscriber //Abstract class
{
public:
    virtual void notify(string msg) = 0;
};

class User : public ISubscriber
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

class Group
{
private:
    list<ISubscriber*> users; //List storing address of ISubscriber objects

public:
    void subscribe(ISubscriber* user)
    {
        users.push_back(user); //Inserts User in the List
    }
    void unsubscribe(ISubscriber* user)
    {
        users.remove(user); //Removes particular User from the List
    }
    void notify(string message)
    {
        for (auto user : users)
            user->notify(message);
    }
};

int main()
{
    //Subject
    Group* group = new Group;

    //Below are all observers
    User* user1 = new User(1);
    User* user2 = new User(2);
    User* user3 = new User(3);

    group->subscribe(user1);
    group->subscribe(user2);
    group->subscribe(user3);

    group->notify("Hello!!!");

    group->unsubscribe(user3);
    group->notify("Hello Again!!!");

    return 0;
}