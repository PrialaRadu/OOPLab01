#include "problem.h"
#include <cassert>

void test_countDigitInNum() {
    assert(countDigitInNum(1, 0) == 0);
    assert(countDigitInNum(9349, 9) == 2);
    assert(countDigitInNum(717171, 1) == 3);
    assert(countDigitInNum(1234123412, 1) == 3);
}

void test_buildNewNumWithDigits() {
    int num = 31;
    buildNewNumWithDigits(num, 5, 2);
    assert(num == 3155);
    buildNewNumWithDigits(num, 6, 0);
    assert(num == 3155);
    buildNewNumWithDigits(num, 7, 1);
    assert(num == 31557);
}

void test_biggestNumWithSameDigits() {
    assert(biggestNumWithSameDigits(0) == 0);
    assert(biggestNumWithSameDigits(123) == 321);
    assert(biggestNumWithSameDigits(901901) == 991100);
    assert(biggestNumWithSameDigits(5555) == 5555);
}

void test_all() {
    test_countDigitInNum();
    test_buildNewNumWithDigits();
    test_biggestNumWithSameDigits();
}