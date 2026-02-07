#include <iostream>
#include <string>

using namespace std;

class ElectronicDevice {
private:
    string brand;
    string model;
protected:
    bool isOn;
public:
    ElectronicDevice(const string& b, const string& m) 
        : brand(b), model(m), isOn(false) {}

    virtual ~ElectronicDevice() {}

    // We can't change brand (it's private), but we can change the power state
    void setPower(bool status) {
        isOn = status;
        cout << "[System] Power state changed to: " << (isOn ? "ON" : "OFF") << endl;
    }

    string getBrand() const { return brand; }
};

class Laptop : public ElectronicDevice {
private:
    int ramSize;
public:
    Laptop(const string& b, const string& m, int ram) 
        : ElectronicDevice(b, m), ramSize(ram) {}

    // THE UPDATE FUNCTION (Setter)
    // This allows us to "Upgrade" the RAM safely
    void upgradeRam(int newSize) {
        if (newSize > ramSize) {
            ramSize = newSize;
            cout << "RAM upgraded to " << ramSize << "GB!" << endl;
        } else {
            cout << "Error: New RAM must be larger than current RAM." << endl;
        }
    }

    void display() {
        cout << getBrand() << " Laptop with " << ramSize << "GB RAM." << endl;
    }
};

int main() {
    Laptop myPC("Dell", "XPS", 16);
    myPC.display();

    // Updating the value via the Setter
    myPC.upgradeRam(32); 
    myPC.display();

    // Trying to downgrade (The "Gatekeeper" logic will stop this)
    myPC.upgradeRam(8);

    return 0;
}