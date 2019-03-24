#ifndef InsertSort_h
#define InsertSort_h

template <class T>
class InsertSort : public SortAlgorithm {
private:
    
    void insertSortProcedure(T *array, int size) {
        for(int i=1; i <= size-1; i++) {
            T key = array[i];
            int index = i;
            while((index > 0) && (array[index-1] > key)) {
                array[index] = array[index-1];
                index--;
            }
            array[index] = key;
        }
    }
    
public:
    
    template <class U> friend class IntroSort;
    
    InsertSort(std::string name) : SortAlgorithm(name) { }
    
    void sort(TestArray *testArray) override {
        insertSortProcedure(testArray->getArray(), (int)testArray->getSize());
    }
};

#endif /* InsertSort_h */
