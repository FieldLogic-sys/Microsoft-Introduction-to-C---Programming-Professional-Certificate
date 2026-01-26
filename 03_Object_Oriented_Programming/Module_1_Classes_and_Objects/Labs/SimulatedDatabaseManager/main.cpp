#include "DatabaseConnection.h"

int main() {
    // 1. Default
    DatabaseConnection db1;

    // 2. Parameterized & Copy in a Scoped Block
    {
        DatabaseConnection db2("10.0.0.1:8080", "Production_DB");
        db2.executeQuery("SELECT * FROM users");

        DatabaseConnection dbCopy = db2; // Copy Constructor
        dbCopy.executeQuery("GET server_status");
    } // db2 and dbCopy die here - Destructors fire!

    db1.executeQuery("CLEANUP cache");
    return 0;
}