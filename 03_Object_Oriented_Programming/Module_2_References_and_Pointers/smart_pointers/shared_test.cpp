#include <iostream>
#include <memory>
#include <string>

using namespace std;

class ServerConfig {
private: 
    string name;

public:
    // CONSTRUCTOR: This builds the server in memory
    ServerConfig(string n) : name(n) { cout << "Allocated: " << name << endl; }

    // DESTRUCTOR: This runs automatically when use_count hits 0
    ~ServerConfig(){ cout << "DEALLOCATED: " << name << endl; }

    void status() { cout << "Server: " << name << " is online." << endl; }
};

class ServerManager {
private:
    shared_ptr<ServerConfig> config; // Our "Copy" of the shared key

public:
    // This "Grabs" a copy of the key and increases the global use_count
    void sharedOwnership(shared_ptr<ServerConfig> additionalConfig) {
        config = additionalConfig;
    }   
        
    void checkServer() {
        if (config) {
            // The "Arrow" (->) means: "Go to the address inside the box 
            // and run the function located there."
            config->status();

            // use_count() spies on how many shared_ptrs point to this same object
            cout << "Current users of this config: " << config.use_count() << endl;
        }
    }
};

int main() {
    // 1. Create the building and get the first key (Count = 1)
    shared_ptr<ServerConfig> centralConfig = make_shared<ServerConfig>("Titan-for-2");

    ServerManager mgr1;
    ServerManager mgr2;

    // 2. Pass copies of the key to the managers (Count becomes 3)
    mgr1.sharedOwnership(centralConfig);
    mgr2.sharedOwnership(centralConfig);

    // 3. Test the managers
    mgr1.checkServer();
    mgr2.checkServer();

    return 0; 
} // Everything dies here, Count hits 0 -> DEALLOCATED triggers.