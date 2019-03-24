#ifndef TestArray_h
#define TestArray_h

#include <stdlib.h>
#include <algorithm>

class TestArray {
private:
    size_t size;
    double percentOfSortedElements;
    int numberOfSortedElements;
    bool revertOrder;
    int * array;

public:
    TestArray() { }
    
    TestArray(size_t size, double percentOfSortedElements, bool revertOrder) :
    size(size),
    percentOfSortedElements(percentOfSortedElements),
    numberOfSortedElements((int)((double)size * percentOfSortedElements)),
    revertOrder(revertOrder),
    array(createArray()) {
        if(percentOfSortedElements < 0.0 || percentOfSortedElements > 1.0) {
            std::cout << "percent of sorted elements must be between <0.0;1.0>" << std::endl;
            exit(1);
        }
    }
    
    ~TestArray() {
        delete array;
    }
    
    size_t getSize() const {
        return size;
    }
    
    double getPercentOfSortedElements() const {
        return percentOfSortedElements;
    }
    
    int getNumberOfSortedElements() const {
        return numberOfSortedElements;
    }
    
    bool getRevertOrder() const {
        return revertOrder;
    }
    
    int * getArray() const {
        return array;
    }
    
    bool isSorted() {
        return isSortedInAscendingOrder();
    }
    
    void printArray() {
        for(int i=0; i<(int)size; i++) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    }
    
    void printArrayParameters() {
        std::cout << "size: " << (int)size << std::endl;
        std::cout << "percent of sorted elements: " << percentOfSortedElements << std::endl;
        std::cout << "number of sorted elements: " << numberOfSortedElements << std::endl;
        std::cout << "revert order: " << revertOrder << std::endl;
    }
    
private:
    
    int * createArray() {
        if(revertOrder) {
            return createArrayPartiallyRevertSorted();
        } else return createArrayPartiallySorted();
    }
    
    int * createArrayPartiallySorted() {
        int *array = new int[size];
        int i, j;
        if(numberOfSortedElements == 0) {
            for(i=0; i<(int)size; i++)
                array[i] = rand()%(int)size;
        } else {
            for(i=0; i<numberOfSortedElements; i++)
                array[i] = i;
            for(j=i; j<(int)size; j++)
                array[j] = j + rand()%int(i);
        }
        return array;
    }
    
    int * createArrayPartiallyRevertSorted() {
        int *array = new int[size];
        int i, j;
        for(i=(int)size-1; i>numberOfSortedElements; i--)
            array[i] = - rand()%numberOfSortedElements;
        for(j=i; j>0; j--)
        array[j] = numberOfSortedElements - j;
        return array;
    }
    
    bool isSortedInRevertOrder() {
        if(size == 1 || size == 0) return true;
        
        for(int i=1; i<(int)size; i++)
            if(array[i - 1] < array[i]) return false;
        
        return true;
    }
    
    bool isSortedInAscendingOrder() {
        if(size == 1 || size == 0) return true;
        
        for(int i=1; i<(int)size; i++)
            if(array[i - 1] > array[i]) return false;
        
        return true;
    }
    
};

#endif /* TestArray_h */
