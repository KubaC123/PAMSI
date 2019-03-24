#include <iostream>
#include "AlgorithmTester.h"
#include "Timer.h"
#include <time.h>

int main() {
    SortAlgorithm *quickSort = new IntroSort<int>("INtroSort");
    AlgorithmTester<int> algorithmTester;
    algorithmTester.test(quickSort);
    delete quickSort;
    
    return 0;
}
