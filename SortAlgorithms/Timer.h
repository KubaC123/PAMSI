#ifndef Timer_h
#define Timer_h

#include <iostream>
#include <ctime>
#include <chrono>

class Timer {
    std::chrono::system_clock::time_point begin, end;
    
public:
    
    Timer() { }
    
    void start() {
        begin = std::chrono::system_clock::now();
    }
    
    void stop() {
        end = std::chrono::system_clock::now();
    }
    
    long double resultMs() {
        return std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
    }
    
};

#endif /* Timer_h */
