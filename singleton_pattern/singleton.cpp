#include <iostream>
#include <thread>
#include <mutex>
#include "singleton.hpp"

using namespace std;

    // Private constructor and destructor
    mutex Singleton:: mtx;
    Singleton:: Singleton() {
        ctr++;
        cout << "Singleton instance created.\nNumber of instances:" << ctr << endl;
    }

    Singleton:: ~Singleton() {
        cout << "Singleton instance destroyed.\n";
    }



    // Static method that returns a reference to the singleton instance
    Singleton& Singleton::getInstance() {

        if (!instance) {
            mtx.lock();
            if (!instance) {
                // Create a new instance if the pointer is null
                instance = new Singleton();
            }
            mtx.unlock();
        }
        // Return the reference to the pointer
        return *instance;
    }

    // Some operation that the singleton can perform
    void Singleton:: someOperation(string msg) {
        cout << "Operation done by "<< msg << endl;
    }

// Initialize the static pointer to nullptr
Singleton* Singleton::instance = NULL;
int Singleton :: ctr = 0;
void getUser1()
{
    Singleton& singleton1 = Singleton::getInstance();
    singleton1.someOperation("User 1");
}
void getUser2()
{
    Singleton& singleton2 = Singleton::getInstance();
    singleton2.someOperation("User 2");
}
void getUser3()
{
    Singleton& singleton3 = Singleton::getInstance();
    singleton3.someOperation("User 3");
}
int main() {
    // Get the reference to the singleton instance
    thread t1 (getUser1);
    thread t2 (getUser2);
    thread t3 (getUser3);

    t1.join();
    t2.join();
    t3.join();
    
    return 0;
}
