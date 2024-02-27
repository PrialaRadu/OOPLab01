#include "problem.h"
#include "tests.h"

int main() {
    test_all();

    int num = readInteger();
    int biggestNum = biggestNumWithSameDigits(num);
    printResult(biggestNum);

    return 0;
}