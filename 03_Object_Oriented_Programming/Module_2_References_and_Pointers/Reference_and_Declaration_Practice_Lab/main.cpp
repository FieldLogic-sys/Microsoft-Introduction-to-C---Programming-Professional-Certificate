#include <iostream>
#include <vector>
#include <string>

using namespace std;

// =================================================================
// DATA STRUCTURE (The Manifest)
// =================================================================
struct DataPoint {
    double value;
    string label;
    int timestamp;
};

// =================================================================
// MEMORY MANAGEMENT FUNCTIONS
// =================================================================

/**
 * Factory Function: Allocates memory on the HEAP.
 * Returns a pointer to the new DataPoint.
 */
DataPoint* createDataPoint(double val, const string& lbl, int time) {
    // Allocation: 'new' requests a block from the OS
    DataPoint* newData = new DataPoint;
    
    // Member Access: Using the Arrow Operator (->) for pointers
    newData->value = val;
    newData->label = lbl;
    newData->timestamp = time;    
    
    cout << "[SYSTEM] Created data point at address: " << newData << endl;
    return newData;

    
}

/**
 * Cleanup Function: Deallocates memory and wipes the address.
 * Uses a reference to a pointer (*&) to modify the original clipboard.
 */
void deleteDataPoint(DataPoint*& dataPtr) {
    if (dataPtr != nullptr) {
        cout << "[AUDIT] Deleting data point: " << dataPtr->label << endl;
        
        // Deallocation: Returning the memory to the OS
        delete dataPtr;
        
        // Safety: Zeroing out the address to prevent "Dangling Pointers"
        dataPtr = nullptr;  
    } else {
        cout << "[WARNING] Attempted to delete a null pointer." << endl;
    }
}

// =================================================================
// MAIN EXECUTION BLOCK (The System Test)
// =================================================================
int main() {
    cout << "=== STARTING DATA PROCESSING AUDIT ===\n" << endl;

    // 1. DYNAMIC ALLOCATION PHASE
    // Creating data points on the HEAP (The Warehouse)
    DataPoint* humidity = createDataPoint(65.2, "Humidity", 2000);
    DataPoint* pressure = createDataPoint(1013.25, "Pressure", 2000);    

    // 2. POINTER VALIDATION & ACCESS
    if (humidity != nullptr) {
        cout << "\n--- Current Humidity Metrics ---" << endl;
        cout << "Value:            " << humidity->value << "%" << endl;
        cout << "Target Address:   " << humidity << " (Heap)" << endl;
        cout << "Clipboard Address: " << &humidity << " (Stack)" << endl;        

        // Modification through the "Remote Control"
        humidity->value += 5.0;
        cout << "Updated Humidity: " << humidity->value << "%" << endl;
    }    

    // 3. POINTER ARITHMETIC DEMONSTRATION
    // Array of structs on the STACK
    cout << "\n=== POINTER ARITHMETIC: SENSOR SCAN ===" << endl;
    DataPoint data[3] = {
        {10.5, "Sensor_Alpha", 1000},
        {20.3, "Sensor_Beta",  1001},
        {30.8, "Sensor_Gamma", 1002}
    };    

    // arrayPtr starts at the first element (data[0])
    DataPoint* arrayPtr = data;  

    for (int i = 0; i < 3; i++) {
        cout << "Reading " << arrayPtr->label 
             << " | Value: " << arrayPtr->value 
             << " | Address: " << arrayPtr << endl;
        
        // The Increment: Moves the pointer by sizeof(DataPoint) bytes
        arrayPtr++;  
    }    

    // 4. CLEANUP PHASE (Sanitization)
    cout << "\n=== DECOMMISSIONING SYSTEM ===" << endl;
    deleteDataPoint(humidity);
    deleteDataPoint(pressure);    

    // 5. FINAL VERIFICATION
    // Both should now show 0 (nullptr)
    cout << "Humidity pointer (Post-Delete): " << humidity << endl;
    cout << "Pressure pointer (Post-Delete): " << pressure << endl;    

    cout << "\n[SUCCESS] Memory audit complete. No leaks detected." << endl;

    return 0;
}