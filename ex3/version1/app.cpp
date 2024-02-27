#include <iostream>
#include <cassert>

//================== Algorithms ======================================================================================

int readInteger() {
    int x;
    std::cout << "Enter your number: " << std::endl;
    std::cin >> x;
    return x;
}

void printResult(int result) {
    std::cout << "Biggest number with same digits is: " << result;
}

int countDigitInNum(int num, int digit) {
    int count = 0;
    while (num) {
        if (num % 10 == digit) count++;
        num /= 10;
    }
    return count;
}

void buildNewNumWithDigits(int &num, int digit, int counts) {
    while (counts) {
        num = num * 10 + digit;
        --counts;
    }
}

int biggestNumWithSameDigits(int num) {
    int newNum = 0;
    for (int digit = 9; digit >= 0; --digit) {
        if (countDigitInNum(num, digit)) buildNewNumWithDigits(newNum, digit, countDigitInNum(num, digit));
    }
    return newNum;
}

//================ Test Functions =====================================================================================

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

//================= Main ==============================================================================================

int main() {
    test_all();

    int num = readInteger();
    int biggestNum = biggestNumWithSameDigits(num);
    printResult(biggestNum);

    return 0;
}