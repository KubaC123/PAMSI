#ifndef QuickSort_h
#define QuickSort_h
#include "SortAlgorithm.h"

template <class T>
class QuickSort : public SortAlgorithm {
private:

    void quickSortProcedure(T *array, int left, int right) {
        int leftPos = left, rightPos = right;
        T key = array[(leftPos+rightPos)/2];

        while (leftPos <= rightPos) {
            while (array[leftPos] < key)
                leftPos++;
            while (array[rightPos] > key)
                rightPos--;
            if (leftPos <= rightPos)
                std::swap(array[leftPos++], array[rightPos--]);
        }
        if (rightPos > left)
            quickSortProcedure(array, left, rightPos);
        if (leftPos < right)
            quickSortProcedure(array, leftPos, right);
    }
    
public:
    
    template <class U> friend class IntroSort;
    
    QuickSort(std::string name) : SortAlgorithm(name) { }
    
    void sort(TestArray *testArray) override {
        quickSortProcedure(testArray->getArray(), 0, (int)testArray->getSize()-1);
    }
};


#endif /* QuickSort_h */
