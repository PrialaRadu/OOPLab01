#include <iostream>

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
