#include <iostream>
#include "AlgorithmTester.h"
#include "Timer.h"
#include <time.h>

int main() {
    SortAlgorithm *heapSort = new HeapSort<int>("HeapSort");
    AlgorithmTester<int> algorithmTester;
    algorithmTester.test(heapSort);
    delete heapSort;
    return 0;
}
    
