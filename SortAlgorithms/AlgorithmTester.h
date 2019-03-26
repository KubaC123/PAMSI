#ifndef AlgorithmTester_h
#define AlgorithmTester_h

#include <fstream>
#include <string>
#include <ctime>
#include <chrono>
#include "TestArray.h"
#include "QuickSort.h"
#include "MergeSort.h"
#include "IntroSort.h"
#include "Timer.h"

template <class T>
class AlgorithmTester {
private:
    
    int numberOfArraysInEachTestCase= 100;
    size_t sizeOfArrays[5] = {10000, 50000, 100000, 500000, 1000000};
    double percentOfSortedElements[7] = {0.0, 0.25, 0.5, 0.75, 0.95, 0.99, 0.997};
    std::string resultFilePath;
    std::ofstream output;
    
public:
    
    AlgorithmTester() : output("results.txt", std::ofstream::app) { }

    AlgorithmTester(std::string resultFilePath) :
    resultFilePath(resultFilePath),
    output(resultFilePath, std::ofstream::app| std::ofstream::trunc) { }
    
    ~AlgorithmTester() {
        output.close();
    }

    void test(SortAlgorithm *algorithm) {
            std::cout << algorithm->getName() << " TEST STARTED" << std::endl;
            bool result = testAllCases(algorithm);
            std::cout << algorithm->getName() << " RESULT: " << result << std::endl;
    }
    
    void clearResultFileContent() {
        output.open(resultFilePath, std::ofstream::out | std::ofstream::trunc);
    }
    
private:
    
    bool testAllCases(SortAlgorithm *sortAlgorithm) {
        long double averageTime;
        int testNr = 0;
        testStartedMessage(sortAlgorithm->getName());
        
        for(size_t size : sizeOfArrays) {
            for(double percent : percentOfSortedElements) {
                averageTime = 0;
                for(int i=0; i<numberOfArraysInEachTestCase; i++)  {
                    testNr++;
                    std::cout << "Test nr " << testNr << " || array size " << (int)size << " || % sorted " << percent << std::endl;
                    TestArray *testArray = new TestArray(size, percent, false);
                    Timer timer;
                    timer.start();
                    sortAlgorithm->sort(testArray);
                    timer.stop();
                    averageTime += timer.resultMs();
                    if(!testArray->isSorted()) {
                        return false;
                    }
                    delete testArray;
                }
                testedArraysWithSizeAndPercentOfSortedElementsMessage(size, percent, averageTime/(double)numberOfArraysInEachTestCase);
            }
        }
        testFinishedMessage();
        return true;
    }
    
    void testStartedMessage(std::string algorithmName) {
        auto start = std::chrono::system_clock::now();
        time_t startTime = std::chrono::system_clock::to_time_t(start);
        output << "STARTED " << std::ctime(&startTime) << std::endl << "TESTING " << algorithmName << std::endl << "------------------------------------------------" << std::endl;
    }
    
    void testedArraysWithSizeAndPercentOfSortedElementsMessage(size_t size, double percent, long double averageTime) {
        output << "TESTED arrays with SIZE: " << size << " PERCENT OF SORTED ELEMENTS: " << percent << std::endl << "AVERAGE TIME [micro sec]: " << averageTime << std::endl << "------------------------------------------------" << std::endl;;
    }
    
    void testFinishedMessage() {
        auto end = std::chrono::system_clock::now();
        time_t endTime = std::chrono::system_clock::to_time_t(end);
        output << "FINISHED " << std::ctime(&endTime) << std::endl << "################################################" << std::endl;;
    }
    
};

#endif /* AlgorithmTester_h */
