#include <iostream>
#include <memory>

using namespace std;

struct DatabaseHandle {
    string name;
    void close() { cout << " >> Closing Databases: " << name << endl; }
};


int main() {
    // 1. Defininf the janitor logic with a lambda
    auto deleter= [](DatabaseHandle* db) {
        db->close();
        delete db;
        cout << "[Highlander Cleanup Finished]" << endl;
    };


    // We have to tell unique_ptr: "You hold a DatabaseHandle, AND your janitor is a 'decltype(deleter)'"


        unique_ptr<DatabaseHandle, decltype(deleter)> myDB(new DatabaseHandle{"Cloud_Users"}, deleter);


        cout << "Highlander is holding the Database key..." << endl;

        return 0;
}