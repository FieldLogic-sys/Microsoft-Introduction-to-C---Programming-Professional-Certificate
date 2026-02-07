#include <iostream>
#include <fstream>  // THE FILE TOOL
#include <memory>
#include <string>

using namespace std;

int main() {
    // 1. The Custom Deleter: Ensures the log is "Finalized" before closing
    auto logFinisher = [](ofstream* log) {
        if (log->is_open()) {
            *log << "[SYSTEM] Audit Log Session Ended Safely." << endl;
            log->close(); // The "Manual" close inside the smart pointer
        }
        delete log;
        cout << ">> Log file has been safely closed and saved." << endl;
    };

    // 2. Open the file for writing (appends to the end)
    // We use 'new' because we are attaching our Custom Janitor
    unique_ptr<ofstream, decltype(logFinisher)> auditLog(
        new ofstream("security_audit.log", ios::app), 
        logFinisher
    );

    // 3. Check if the "Pipe" to the disk is actually working
    if (auditLog->is_open()) {
        cout << "Logging activity... type a message to record in the audit log: " << endl;
        string userMessage;
        getline(cin, userMessage);

        // Writing to the file works EXACTLY like cout
        *auditLog << "[USER_ACTION] " << userMessage << endl;
        
        cout << "Message recorded to security_audit.log" << endl;
    } else {
        cerr << "Error: Could not open log file!" << endl;
    }

    return 0;
} // The Janitor triggers here, closing the file automatically.