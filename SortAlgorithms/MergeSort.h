#ifndef MergeSort_h
#define MergeSort_h

template <class T>
class MergeSort : public SortAlgorithm {
private:
    
    void merge(int *array, int low, int high, int mid) {
        int leftPos, rightPos, index, result[high-low+1];
        leftPos = low;
        index = 0;
        rightPos = mid + 1;
        
        while (leftPos <= mid && rightPos <= high) {
            if (array[leftPos] < array[rightPos]) {
                result[index++] = array[leftPos++];
            } else {
                result[index++] = array[rightPos++];
            }
        }
        
        while (leftPos <= mid) {
            result[index++] = array[leftPos++];
        }
        
        while (rightPos <= high) {
            result[index++] = array[rightPos++];
        }
        
        for (leftPos = low; leftPos <= high; leftPos++) {
            array[leftPos] = result[leftPos-low];
        }
    }
    
    void mergeSortProcedure(int *array, int low, int high) {
        int mid;
        if (low < high) {
            mid=(low+high)/2;
            mergeSortProcedure(array, low, mid);
            mergeSortProcedure(array, mid+1, high);
            merge(array, low, high, mid);
        }
    }
            
public:
    
    MergeSort(std::string name) : SortAlgorithm(name) { }
    
    void sort(TestArray *testArray) override {
        mergeSortProcedure(testArray->getArray(), 0, ((int)testArray->getSize())-1);
    }
};

#endif /* MergeSort_h */
