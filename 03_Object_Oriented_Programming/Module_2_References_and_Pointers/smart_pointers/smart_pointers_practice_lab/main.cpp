#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

class ServerConfig {
private:
    string name;
public:
    ServerConfig(string n) : name(n) { 
        cout << "ALLOCATED: " << name << endl; 
    }
    ~ServerConfig() { 
        cout << "DEALLOCATED: " << name << endl; 
    }
    void status() { cout << "Server " << name << " is online." << endl; }
};

class ServerManager {
private:
    // TODO: Create a unique_ptr variable named 'config' that holds a ServerConfig
    unique_ptr<ServerConfig> config;
public:
    // TODO: Write a function 'takeOwnership' that accepts a unique_ptr as a parameter
    // HINT: Inside, use std::move to transfer the parameter into your private variable
    void takeOwnership(unique_ptr<ServerConfig> otherConfig){
            config = std::move(otherConfig);
    }
    
    void checkServer() {
        // TODO: Write an if-statement to check if 'config' actually holds something
        // If it does, call config->status()
        if (config != nullptr){
            config -> status();
        }
    }
};

int main() {
    // TODO: Create a unique_ptr named 'myServer' using make_unique
   
    unique_ptr<ServerConfig> myServer = make_unique<ServerConfig>("Titan-01");
    // TODO: Create a ServerManager object named 'mgr'
    ServerManager mgr;
    // TODO: Use mgr.takeOwnership to pass 'myServer' to the manager
    // HINT: You MUST use std::move() here or it won't compile!
    mgr.takeOwnership(std::move(myServer));
    // TODO: Call mgr.checkServer()
    mgr.checkServer();
    return 0;
}