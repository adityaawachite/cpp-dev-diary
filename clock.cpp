
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::chrono;

int main() {
    auto start = steady_clock::now();  // record start time
    int count = 1;

    while (true) {
        this_thread::sleep_for(seconds(10));  // wait 10 seconds

        auto now = steady_clock::now();
        auto runtime = duration_cast<seconds>(now - start).count();

        cout << "Timelapse " << count 
             << " | Runtime: " << runtime << " seconds" << endl;

        count++;
    }

    return 0;
}