#include <iostream>
#include <memory>

using namespace std;

// Dummy resource for testing

struct CloudSocket
{
    int id;
    void closeSocket() { cout << "Screwing the cap on Socket #" << id << endl; }
};

int main()
{
    // 2. Define the "Deleter" right here as a lambda
    auto myJanitor = [](CloudSocket *s)
    {
        cout << "[CUSTOME DELETER STARTING]" << endl;
        s->closeSocket();
        delete s;
        cout << "[CLEANUP COMPLETE]" << endl;
    };

    // 3. Creating a pointer and hand over the Janitor

    cout << "Creating pointer..." << endl;
    {
        shared_ptr<CloudSocket> ptr(new CloudSocket{101}, myJanitor);
        cout << "Pointer is active." << endl;

    } // The Janitor is triggered here
    cout << "Program ending." << endl;
    return 0;
}
