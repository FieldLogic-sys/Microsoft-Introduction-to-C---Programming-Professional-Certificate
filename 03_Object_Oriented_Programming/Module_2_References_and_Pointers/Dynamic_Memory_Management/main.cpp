#include <iostream>
#include <map>
#include <ctime>
#include <cstdio>  // Use C-style I/O for recursion safety
#include <cstdlib>
#include <cstring>
#include <cstdint>

using namespace std;

static bool isInsideManager = false;

class MemoryManager {
private:
    struct AllocationInfo {
        size_t size;
        time_t timestamp;
        bool isArray;
        AllocationInfo(size_t s = 0, bool arr = false) 
            : size(s), timestamp(time(nullptr)), isArray(arr) {}
    };
    
    map<void*, AllocationInfo> allocations;
    size_t totalAllocations = 0;
    size_t currentAllocatedBytes = 0;
    size_t peakAllocatedBytes = 0;
    FILE* logFile; // C-style FILE pointer is safer than ofstream here

public:
    MemoryManager() {
        logFile = fopen("memory_log.txt", "w");
        if (logFile) fprintf(logFile, "SYSTEM: Memory Manager initialized\n");
        cout << "Memory Manager started - Monitoring 'Box' RAM..." << endl;
    }
    
    ~MemoryManager() {
        if (logFile) {
            fprintf(logFile, "SYSTEM: Memory Manager shutting down\n");
            fclose(logFile);
        }
        cout << "\n=== Final Audit Report ===" << endl;
        reportLeaks();
    }
    
    void* allocate(size_t size, bool isArray) {
        // Step 1: Use malloc immediately to avoid recursion
        void* ptr = malloc(size);
        if (!ptr) return nullptr;

        // Step 2: Guard the map operations
        isInsideManager = true; 
        allocations[ptr] = AllocationInfo(size, isArray);
        totalAllocations++;
        currentAllocatedBytes += size;
        if (currentAllocatedBytes > peakAllocatedBytes) peakAllocatedBytes = currentAllocatedBytes;
        isInsideManager = false; 

        // Step 3: Log using raw C-style to avoid temp string allocations
        if (logFile) {
            fprintf(logFile, "[%ld] ALLOC: %zu bytes at %p [%s]\n", 
                    time(nullptr), size, ptr, isArray ? "ARRAY" : "SINGLE");
        }
        return ptr;
    }
    
    void deallocate(void* ptr) {
        if (!ptr) return;

        isInsideManager = true;
        auto it = allocations.find(ptr);
        if (it != allocations.end()) {
            size_t size = it->second.size;
            currentAllocatedBytes -= size;
            allocations.erase(it);
            isInsideManager = false; 
            
            if (logFile) {
                fprintf(logFile, "[%ld] FREE: %zu bytes from address %p\n", 
                        time(nullptr), size, ptr);
            }
            free(ptr);
        } else {
            isInsideManager = false;
        }
    }

    void reportLeaks() {
        if (allocations.empty()) {
            cout << "✓ No Speicherleichen (leaks) detected!" << endl;
        } else {
            cout << "⚠ LEAKS DETECTED:" << endl;
            for (auto const& [addr, info] : allocations) {
                cout << "  -> Address " << addr << " (" << info.size << " bytes)" << endl;
            }
        }
    }
};

MemoryManager* gMgr = nullptr;

// OVERLOADS (Now utilizing the safer allocate/deallocate)
void* operator new(size_t size) {
    if (gMgr && !isInsideManager) return gMgr->allocate(size, false);
    return malloc(size);
}
void operator delete(void* ptr) noexcept {
    if (gMgr && !isInsideManager) gMgr->deallocate(ptr);
    else free(ptr);
}
void* operator new[](size_t size) {
    if (gMgr && !isInsideManager) return gMgr->allocate(size, true);
    return malloc(size);
}
void operator delete[](void* ptr) noexcept {
    if (gMgr && !isInsideManager) gMgr->deallocate(ptr);
    else free(ptr);
}

int main() {
    // Avoid ANY cout or complex logic before this line
    gMgr = new MemoryManager();

    cout << "--- Phase 1: Image Processor Stress Test ---" << endl;
    unsigned char* imgA = new unsigned char[1024]; 
    unsigned char* imgC = new unsigned char[4096]; 

    delete[] imgA;
    // Forgetting imgC intentionally

    delete gMgr; 
    return 0;
}