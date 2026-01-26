#include "DatabaseConnection.h"


int DatabaseConnection::nextId = 0;

DatabaseConnection::DatabaseConnection()
: connectionString("localhost:5432"), databaseName("default_db"), isConnected(false), connectionId(++nextId) {
    establishConnection();

}



DatabaseConnection::DatabaseConnection(const std::string& connStr, const std::string& dbName) 
: connectionString(connStr), databaseName(dbName), isConnected(false), connectionId(++nextId) {
    std::cout << "Creating custom connection [ID: " << connectionId << "]..." << std::endl;
    establishConnection();
}



DatabaseConnection::DatabaseConnection(const DatabaseConnection& other)
: connectionString(other.connectionString), databaseName(other.databaseName + "_copy"),
isConnected(false), connectionId(++nextId) {
    establishConnection();
}


DatabaseConnection::~DatabaseConnection() {
    closeConnection();
}

bool DatabaseConnection::establishConnection() {
    std::cout << "✓ Connecting to " << databaseName << " [ID: " << connectionId << "]" << std::endl;
    isConnected = true;
    return true;
}


void DatabaseConnection::closeConnection() {
    if (isConnected) {
        std::cout << "✗ Closing connection [ID: " << connectionId << "]" << std::endl;
        isConnected = false;
    }
}

void DatabaseConnection::executeQuery(const std::string& query) {
    if (isConnected) std::cout << "DB [" << databaseName << "] Executing: " << query << std::endl;
}

int DatabaseConnection::getId() const { return connectionId; }
