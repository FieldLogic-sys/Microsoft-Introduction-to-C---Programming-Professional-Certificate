#ifndef DATABASE_CONNECTION_H
#define DATABASE_CONNECTION_H

#include <iostream>
#include <string>

class DatabaseConnection {
    private:
    std::string connectionString;
    std::string databaseName;
    bool isConnected;
    int connectionId;
    static int nextId;



    bool establishConnection();
    void closeConnection();

    public:
    DatabaseConnection();
    DatabaseConnection(const std::string& connStr, const std::string& dbName);

DatabaseConnection(const DatabaseConnection& other);

    ~DatabaseConnection();


    void executeQuery(const std::string& query);
    // Why is this const by itself is it making the stati int getId into a const?? 
    int getId() const;
};


#endif