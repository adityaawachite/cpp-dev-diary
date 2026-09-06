
#include <iostream>
#include <mutex>

// Example of 'extern' (simulating linkage with another file)
extern int globalDatabaseConnections = 10; 

class Server {
private:
    std::string serverName;
    mutable std::mutex mtx; // 'mutable' allows locking within a const method
    mutable int cacheValue; 
    
public:
    Server(std::string name) : serverName(name), cacheValue(0) {}

    // 'const' method guarantees the object's logical state remains unchanged
    int getProcessedData() const {
        std::lock_guard<std::mutex> lock(mtx); // Possible because mtx is mutable
        
        if (cacheValue == 0) {
            // Simulating an expensive calculation
            cacheValue = 42; // Allowed in a const function because cacheValue is mutable
        }
        return cacheValue;
    }
};

void connectionTracker() {
    // 'static' ensures the variable retains its value across function calls
    static int activeConnections = 0; 
    activeConnections++;
    
    // 'auto' automatically deduces the variable type 
    auto status = (activeConnections > 5) ? "High Load" : "Normal"; 
    
    std::cout << "Connections: " << activeConnections << " | Status: " << status << std::endl;
}

int main() {
    connectionTracker(); // Connections: 1
    connectionTracker(); // Connections: 2 (retained via static variable)
    
    Server mainServer("Production");
    std::cout << "Data: " << mainServer.getProcessedData() << std::endl;
    
    return 0;
}
