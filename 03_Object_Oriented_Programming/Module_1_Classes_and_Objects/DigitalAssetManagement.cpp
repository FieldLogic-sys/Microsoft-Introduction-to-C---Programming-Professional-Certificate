#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include <set> // Used to assist in catching duplicate names. I found a bug in the lab, so I researched on how to fix it. This will be documented in the associated README.md file and in the proper usage in the LATex comment method
class DigitalAsset {
    private:
    std::string fileName;
    std::string fileType;
    double fileSizeMB;
    std::string creationDate;
    bool isActive;
    static int totalAssets; // This tracks the number of created assets
    static std::set<std::string> assetRegistry; // Shared Ledger
   public:
   // Default constructor
    DigitalAsset() : fileName("untitiled"), fileType("unknown"), fileSizeMB(0.0), isActive(true) {
        // Get the current date for a creation timestamp
        auto now = std::chrono::system_clock::now();
        auto time_t = std::chrono::system_clock::to_time_t(now);
        creationDate = std::ctime(&time_t);
        creationDate.pop_back(); // This will remove the new line character
        totalAssets++;
        std::cout << "✓ Default asset created: " << fileName << " | Total assets: " << totalAssets << std::endl;

    }

    //Paramaterized constructor
    // I want a good explanation of the DigitalAsset and why we are using : before fileName and what it is called
    DigitalAsset(const std::string& name, const std::string& type, double size)
    : fileName(name), fileType(type), fileSizeMB(size), isActive(true) {
        if (assetRegistry.count(name)) {
            std::cout << "⚠️ COLLISION: '" << name << "' already exists. Renaming..." << std::endl;
            fileName = name + "_DUP_" + std::to_string(totalAssets);
        } else {
            fileName = name;
        }
        assetRegistry.insert(fileName);
        if (size < 0) {
            std::cout << "⚠️ Error: Size cannot be less than 0 --- Defaulting to 0.0!" << std::endl;
            fileSizeMB = 0.0;
        }
        else {
            fileSizeMB = size;
        }

// Extension Validation Logic
if (fileName.find('.') == std::string::npos) {
    std::cout << "⚠️ WARNING: Asset '" << fileName << "' lacks a file extension!" << std::endl;
}
size_t dotPos = fileName.find_last_of('.');
if (dotPos == std::string::npos || dotPos == fileName.length() -1 ){
    std::cout << "⚠️ SECURITY ALERT: Asset '" << fileName << "' has an invalid or missing extension!" << std::endl;
}

        auto now = std::chrono::system_clock::now();
        auto time_t = std::chrono::system_clock::to_time_t(now);
        creationDate = std::ctime(&time_t);
        creationDate.pop_back();
        totalAssets++;
        std::cout << "✓ Default asset created: " << fileName << " | Total assets: " << totalAssets << std::endl;
        };
    


    // Copy constructor
    DigitalAsset(const DigitalAsset& other) :
    fileName(other.fileName + "_copy"), fileType(other.fileType), fileSizeMB(other.fileSizeMB), creationDate(other.creationDate), isActive(other.isActive) {
        totalAssets++;
        std::cout << "✓ Default asset created: " << fileName << " | Total assets: " << totalAssets << std::endl;
    }
// Destructor
~DigitalAsset() {
    assetRegistry.erase(fileName);
    totalAssets--;
    std::cout << "✗ Asset destroyed: " << fileName << " | Remaining assets: " << totalAssets << std::endl;
}
// Member Functions
void displayInfo() const { 
    std::cout << "Asset: " << fileName << " [" << fileType << "] - " << fileSizeMB << "MB - Created: " << creationDate << " - Status: " << (isActive ? "Active" : "Archived") << std::endl;
}

void archive() {
    isActive = false;
    std::cout << "Asset " << fileName << " had been archived." << std::endl;
}
    // I need a reminder of why and when to use static int 
    static int getTotalAssets() {
        return totalAssets;
    
}
};

// Static memeber initisilzation


int DigitalAsset::totalAssets = 0;
std::set<std::string> DigitalAsset::assetRegistry;
int main() {
    std::cout << "===Digital Asset Management System === " << std::endl;
    std::cout << "1. Creating default asset:" <<std::endl;
    DigitalAsset defaultAsset;
    defaultAsset.displayInfo();
    std::cout << std::endl;
DigitalAsset logo("company_logo.png", "image", 2.5);
DigitalAsset video("(promo)video.mp4", "video", 150.0);
DigitalAsset video1("(promo)video.mp4", "video", 150.0);
logo.displayInfo();
video.displayInfo();
video1.displayInfo();
std::cout << std::endl;


// Test copy constructor
std::cout << "3. Testing copy onstructor:" << std::endl;
{
    DigitalAsset logoCopy = logo; //Calling  copy constructor
    logoCopy.displayInfo();
    logoCopy.archive();
    std::cout << "---logocopy going out of scope ---" << std::endl;
} // logoCopy destructor called here
std::cout << "\n4. Final Satus:" << std::endl;
std::cout << "Total assets remaining: " << DigitalAsset::getTotalAssets() << std::endl;
std::cout << "\n=== Program Ending - remaining objects will be destroyed" << std::endl;
return 0;
}


