#include <iostream>
#include <mutex>
using namespace std;
/*

UML Diagram
+------------------------+
|   Singleton            |
  -int ctr               |
  -mutex mtx             |
+------------------------+
| - Singleton()          |
| -~Singleton()          |
| + getInstance()        |      
| + someOperation()      |
+------------------------+
*/

class Singleton {
private:
    static int ctr;
    static mutex mtx;
    Singleton();
    ~Singleton();
    static Singleton* instance;
public:
    // Delete the copy constructor and the assignment operator
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    static Singleton& getInstance();
    void someOperation(string msg);
};
