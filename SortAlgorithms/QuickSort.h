#ifndef QuickSort_h
#define QuickSort_h
#include "SortAlgorithm.h"

template <class T>
class QuickSort : public SortAlgorithm {
private:
    
    int divide(T *array, int left, int right) {
        T key = array[left];
        int leftPos = left, rightPos = right;
        while(true) {
            while(array[rightPos] > key) rightPos--;
            while(array[leftPos] < key) leftPos++;
            if(leftPos < rightPos) {
                std::swap(array[leftPos], array[rightPos]);
                leftPos++;
                rightPos--;
            }
            else return rightPos;
        }
    }
    
    void quickSortProcedure(T *array, int left, int right) {
        int dividePosition;
        if(left < right) {
            dividePosition = divide(array, left, right);
            quickSortProcedure(array, left, dividePosition-1);
            quickSortProcedure(array, dividePosition+1, right);
        }
    }
    
public:
    
    template <class U> friend class IntroSort;
    
    QuickSort(std::string name) : SortAlgorithm(name) { }
    
    void sort(TestArray *testArray) override {
        quickSortProcedure(testArray->getArray(), 0, (int)testArray->getSize() - 1);
    }
};


#endif /* QuickSort_h */
