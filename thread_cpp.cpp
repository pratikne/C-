// thread example
#include <iostream> // std::cout
#include <thread>   // std::thread
#include <mutex>    
#include <chrono>   // chrono::seconds
#include <condition_variable>
#include <atomic>

using namespace std;

// atomic variable
atomic<int> temp(0);
// Imagine all the threads trying to access and modify this shared variable at the same time
// This condition is known as a race condition
// C++ offers atomic variables that are thread-safe
// They are implemented using mutex locks

std::condition_variable cond;
std::mutex m;
int myvar = 0;

void addvar(){
    //lock_guard<std::mutex> lock(m); //IMP
    
    m.lock(); //incoming thread locks this section for updation
    ++myvar; //Critical section
    m.unlock(); //same thread unlocks this section for other threads who are waiting
}

class Base{
public:
    static void static_run(int x){   // Static member function
        while(x-- > 0){
            cout<< x << endl;
        }
    }
    void run(int x){   // Non static member function
        while(x-- > 0){
            cout<< x << endl;
        }
    }
    void operator ()(int x){ //Functor
        while(x-- > 0){
            cout<< x << endl;
        }
    }
};

// thread foo adds 5 in the temp
void foo()
{
    this_thread::sleep_for(chrono::seconds(5)); //Thread will sleep for 5 seconds
    //sleep(5);
    temp+=5;
    cout << temp << endl;
}

// thread bar subtracts 5 from the temp
void bar(int x)
{
    cout<<"Hi"<<endl;
    temp-=5;
    cout << temp << endl;
}

int main()
{
    thread th1(addvar);
    thread th2(addvar);

    th1.join();
    th2.join();

    cout<< myvar <<endl;

    //Lambda Function
    auto fun = [](int x)
    {
        while (x-- > 0)
            cout << x << endl;
    };

    thread t1(fun, 10);    //Thread created with Lambda
    thread t2(Base(), 10); //Thread created with Functor

    Base b;
    thread t3(&Base::run,&b,10); //Thread created with Non static member function
    thread t4(&Base::static_run,10); //Thread created with Static member function

    thread first(foo);     // spawn new thread that calls foo()
    thread second(bar, 0); // spawn new thread that calls bar(0)

    std::cout << "main and other created threads now execute concurrently...\n";

    // synchronize threads:
    t1.join();
    if(t1.joinable()) //checks is t1 is joinable..if yes..then only join it
        t1.join();    // Here it wont as t1.join is already handled well before
    t2.join();
    t3.join();
    t4.join();

    first.detach();
    if(first.joinable()){
        first.detach(); 
    }
    second.join(); // pauses until second finishes

    std::cout << "All threads completed their task.\n";

    return 0;
}

/**
 * @note
 * 
 * @create
 * Threads can be created by 5 ways
 * 1) Function call - Eg, thread first and second
 * 2) Lambda call - Eg thread t1
 * 3) Functor (Function object) - Eg thread t2
 * 4) Non static member function - Eg thread t3
 * 5) Static member function - Eg thread t4
 * 
 * @join
 * Once a thread is started, we(Main) wait for it to finish by calling join() on thread object
 * Double join for same thread will result into program termination/crash
 * hence, we need to check thread is joinable or not beforhand using joinable(){
 * if not joinable- join() shoudnt be added for that thread
 * if yes, join it
 * }
 * 
 * @detach
 * used to detach newly created thread from the parent thread(main)
 * let say you no longer want to wait for a thread..so dont join it..instead use t.detach()
 * if main() is returned..detached thread execution is suspended
 * double detach is problematic same like join()..so use the same solution using joinable()
 * if joinable{
 * then only detach()
 * }
 * 
 * @IMP_NOTE
 *always try to join or detach the thread you are creating depending on the requirement
 *if not..it may lead to problem as thread calls its destructors which will terminate the program
 */

/**
 * @RACE CONDITION
 * Race condition occure when two or more threads/processes happens to change a common resource/critical data at same time
 * that critical section needs to be provided 
 * 
 * @MUTEX (Mutual Exclusion - Samjhouta(Hindi))
 * It is used to avoid Race condition
 * Mutex is a locking mechanism
 * Mutex is used to provide synchronization in C++ which means only one thread can access the object at the same time
 * By the use of Mutex keyword we can lock our object from being accessed by multiple threads at the same time.
 * Thread which locks it will only unlock it and noone else
 * Working based on binary value 1/0
 * Initially 1 when initialized..thread locking it will decrement it to 0
 * other threads will till then wait(get blocked) in this lock() call as for them value will be 0
 * once its critical sectio is done execution...it will unlock it and update 1 again
 * other threads will then take over the control ( 1 at a time)
 * lock(), unlock() - blocking call
 * 
 * std::mutex::try_lock() - non blocking version of lock()
 * Tries to lock the mutex..if not returns immediately without blocking
 * if unsucc lock as in above case..returns false 
 * if same threads calls try_lock()...it results is deadlock...(recursive mutex is the solution for you then)
 *
 * @lock_guard
 * 
 * light weight wraper for owing the mutex on scopr basis
 * 
 * lock_guard<mutex> lock(mtx);
 * no need for unlock as mtx will auto unlock once lock_guard is out of scope
 *  
 */

/**
 * @Condition Variable (Signalling mechanism)
 * A.Notify other threads 
 * B.Waiting for some condition
 * 
 * CV allows running threads to wait on some condition and once those condiitons are met..alert/notify other threads using
 * -cond is the object of condition_variable
 * - cond.wait(mutex)
 * - cond.notify_one()
 * - cond.notify_all()
 * Needs mutex to implement
 * 
 */