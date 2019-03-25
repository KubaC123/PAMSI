#ifndef HeapSort_h
#define HeapSort_h

template <class T>
class HeapSort : public SortAlgorithm {
private:
    
    void maxHeap(T *array, int size, int parent) {
        int max, left, right;
        max = parent;
        left = 2*parent+1;
        right = 2*parent+2;
        if(left<size && array[left]>array[max]) max = left;
        if(right<size && array[right]>array[max]) max = right;
        if(max != parent) {
            std::swap(array[parent], array[max]);
            maxHeap(array, size, max);
        }
    }
    
    void buildHeap(T *array, int size) {
        for(int i=size/2 - 1; i>=0; i--)
            maxHeap(array, size, i);
    }
    
    void heapSortProcedure(T *array, int size) {
        buildHeap(array, size);
        for(int i=size-1; i>=0; i--) {
            std::swap(array[i], array[0]);
            maxHeap(array, i, 0);
        }
    }
    
    
public:
    
    template <class U> friend class IntroSort;
    
    HeapSort(std::string name) : SortAlgorithm(name) { }
    
    void sort(TestArray *testArray) override {
        heapSortProcedure(testArray->getArray(), (int)testArray->getSize());
    }
};
#endif /* HeapSort_h */
