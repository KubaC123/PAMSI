#ifndef IntroSort_h
#define IntroSort_h

#include <math.h>
#include "InsertSort.h"
#include "HeapSort.h"
#include "QuickSort.h"

template <class T>
class IntroSort : public SortAlgorithm {
private:
    
    InsertSort<T> *insertSort = new InsertSort<T>("INSERTSORT");
    HeapSort<T> *heapSort = new HeapSort<T>("HEAPSORT");
    QuickSort<T> *quickSort = new QuickSort<T>("QUICKSORT");
    
    void hybridIntroSort(T *array, int size) {
        introSortProcedure(array, size, int(floor(2*log(size)/M_LN2)));
        insertSort->insertSortProcedure(array, size+1);
    }
    
    void introSortProcedure(T *array, int size, int m) {
        int divide;
        if(m <= 0) {
            heapSort->heapSortProcedure(array, size);
            return;
        }
        divide = quickSort->divide(array, 0, size);
        if(divide > 9) {
            introSortProcedure(array, divide, m-1);
        }
        if(size-1-divide > 9) {
            introSortProcedure(array+divide+size, size-1-divide, m-1);
        }
    }
    
public:
    IntroSort(std::string name) : SortAlgorithm(name) {
        insertSort = new InsertSort<T>("INSERTSORT");
        heapSort = new HeapSort<T>("HEAPSORT");
        quickSort = new QuickSort<T>("QUICKSORT");
    }
    
    ~IntroSort() {
        delete insertSort;
        delete heapSort;
        delete quickSort;
    }
    
    void sort(TestArray *testArray) override {
        hybridIntroSort(testArray->getArray(), (int)testArray->getSize()-1);
    }
};

#endif /* IntroSort_h */
