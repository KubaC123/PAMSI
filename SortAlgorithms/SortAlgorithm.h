#ifndef SortAlgorithm_h
#define SortAlgorithm_h

#include "TestArray.h"
#include <string>

class SortAlgorithm {
private:
    std::string name;
public:
    
    SortAlgorithm(std::string name) : name(name) { }
    virtual ~SortAlgorithm() { }
    
    virtual void sort(TestArray *testArray) { };

    std::string getName() const {
        return name;
    }
};

#endif /* SortAlgorithm_h */
