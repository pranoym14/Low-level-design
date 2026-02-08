#include <iostream>
#include <list>
#include <string>

using namespace std;

// 1. The Interface for Observers (Subscribers)
class ISubscriber {
public:
    virtual void notify(string message) = 0; // Pure virtual function 
};

// 2. Concrete Observer (The User)
class User : public ISubscriber {
private:
    int userId;
public:
    User(int id) : userId(id) {}

    void notify(string message) override {
        cout << "User " << userId << " received message: " << message << endl;
    }
};

// 3. The Subject (The Group)
class Group {
private:
    list<ISubscriber*> users; // List to keep track of subscribers 
public:
    void subscribe(ISubscriber* user) {
        users.push_back(user); // Add user to the list 
    }

    void unsubscribe(ISubscriber* user) {
        users.remove(user); // Remove user from the list 
    }

    void notify(string message) {
        // Iterate through all subscribers and notify them 
        for (auto user : users) {
            user->notify(message);
        }
    }
};

// 4. Client Side Code
int main() {
    Group* group = new Group();

    // Create users 
    User* user1 = new User(1);
    User* user2 = new User(2);
    User* user3 = new User(3);

    // Users subscribing to the group 
    group->subscribe(user1);
    group->subscribe(user2);
    group->subscribe(user3);

    cout << "--- First Message ---" << endl;
    group->notify("New Message");

    // User 1 unsubscribes [00:05:28]
    group->unsubscribe(user1);

    cout << "\n--- Second Message (User 1 unsubscribed) ---" << endl;
    group->notify("New New Message");

    // Cleanup
    delete group;
    delete user1;
    delete user2;
    delete user3;

    return 0;
}