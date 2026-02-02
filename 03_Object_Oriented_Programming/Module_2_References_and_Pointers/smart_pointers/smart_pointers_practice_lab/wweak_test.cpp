#include <iostream>
#include <memory>
#include <string>

using namespace std;

class CloudResource {
private:
    string name;
public:
    CloudResource(string n) : name(n) { cout << "[ALLOC] " << name << " is born." << endl;}
    ~CloudResource() { cout << "[FREE] " << name << " has been deleted." << endl; };
    void ping() { cout << "   >> " << name << " is responding to ping." << endl;}
};

int main() {
    cout << "--- Starting weak_ptr Highlander Drill ---" << endl;

    // 1. First owner arrives. Count = 1.
    shared_ptr<CloudResource> strongOwner = make_shared<CloudResource>("Main-Server");
    cout << "Count after creation: " << strongOwner.use_count() << endl;

    // 2. The Ghost is watching.
    weak_ptr<CloudResource> ghostObserver = strongOwner;
    // NOTICE: Count is STILL 1. The Ghost doesn't keep the building alive!
    cout << "Count with Ghost watching: " << strongOwner.use_count() << endl;

    // 3. Temporary Promotion
    if (auto tempKey = ghostObserver.lock()) {
        // INSIDE HERE: Count becomes 2! tempKey is a real owner for a split second.
        cout << "Count during .lock(): " << strongOwner.use_count() << endl;
        tempKey->ping();
    } 
    // OUTSIDE: tempKey dies. Count returns to 1.
    cout << "Count after .lock() finishes: " << strongOwner.use_count() << endl;

    // 4. Kill the owner
    cout << "\nDropping the strong key..." << endl;
    strongOwner.reset(); // Count hits 0. [FREE] triggers.

    // 5. Final check
    if (auto tempKey = ghostObserver.lock()) {
        tempKey->ping();
    } else {
        cout << "Access Denied: The Highlander has left the building." << endl;
    }

    return 0;
}