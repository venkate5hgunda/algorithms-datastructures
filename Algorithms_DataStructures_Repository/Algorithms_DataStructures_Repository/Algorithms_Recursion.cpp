#include <iostream>
#include <stdio.h>
#include <time.h>

using namespace std;

// NOTE: function calls are stored in STACK abstract data type

#pragma region TailRecursion
void tail_recursion(int n) { // this does not store anything in memory

    if (n == 0) return;

    // we do an operation
    cout << "Tail Recursion. n:" << n << endl;

    // recursive function call is made at the end of the function. the stack will not store any previous calls (function call stack is clean)
    tail_recursion(n - 1);
}
#pragma endregion

#pragma region HeadRecursion
void head_recursion(int n) { // memory haevy operation

    if (n == 0) return;

    // we call the recursive function
    head_recursion(n - 1);

    // once the recursion is done, operation is performed. the call stack has to store all the previous states (function calls are stored in call stack)
    cout << "Head Recursion. n:" << n << endl;
}
#pragma endregion

#pragma region HeadFactorial
long head_factorial(int n) {
    if (n == 1) return 1;
    return n * head_factorial(n - 1);
}
#pragma endregion

#pragma region TailFactorial
long tail_factorial(int n, int accumulator = 1) {
    if (n == 1) return accumulator;
    return tail_factorial(n - 1, n * accumulator);
}
#pragma endregion

#pragma region HeadFibonacci
int head_fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    return head_fibonacci(n - 1) + head_fibonacci(n - 2);
}
#pragma endregion

#pragma region TailFibonacci
int tail_fibonacci(int n, int caseZero = 0, int caseOne = 1) {
    if (n == 0) return caseZero;
    if (n == 1) return caseOne;

    return tail_fibonacci(n - 1, caseOne, caseZero + caseOne);
}
#pragma endregion

#pragma region BinarySearch_TailRecursion
int binarySearch(int number, int numbersArray[], int lowIndex, int highIndex) {
    if (lowIndex > highIndex) return -1; // number not found

    int middleIndex = lowIndex + (highIndex - lowIndex) / 2;

    if (numbersArray[middleIndex] == number) { // number found
        return middleIndex;
    }
    else if (numbersArray[middleIndex] > number) { // number smaller than middle index. go left
        return binarySearch(number, numbersArray, lowIndex, middleIndex - 1);
    }
    else { // number greater than middle index. go right [Condition: numbersArray[middleIndex] < number]
        return binarySearch(number, numbersArray, middleIndex + 1, highIndex);
    }
}
#pragma endregion

#pragma region TowersOfHanoi

#pragma endregion


// demonstrating the difference between head and tail recursion. 
int main()
{
    clock_t start, end;
    int number;

    #pragma region Head & Tail Recursion
    //number = 10;

    //start = clock();
    //cout << "***HEAD RECURSION***" << endl;
    //head_recursion(number);
    //end = clock();
    //cout << "Execution Time: " << double((end - start) * 1.0) / double(CLOCKS_PER_SEC) << endl;

    //cout << endl;

    //start = clock();
    //cout << "***TAIL RECURSION***" << endl;
    //tail_recursion(number);
    //end = clock();
    //cout << "Execution Time: " << double((end - start) * 1.0) / double(CLOCKS_PER_SEC) << endl;
    #pragma endregion

    cout << endl;

    #pragma region Factorial Problem
    //number = 14;

    //start = clock();
    //cout << "***HEAD FACTORIAL***" << endl;
    //cout << "Factorial of " << number << ": " << head_factorial(number) << endl;
    //end = clock();
    //cout << "Execution Time: " << double((end - start) * 1.0) / double(CLOCKS_PER_SEC) << endl;

    //cout << endl;

    //start = clock();
    //cout << "***TAIL FACTORIAL [USING ACCUMULATOR]***" << endl;
    //cout << "Factorial of " << number << ": " << tail_factorial(number) << endl;
    //end = clock();
    //cout << "Execution Time: " << double((end - start) * 1.0) / double(CLOCKS_PER_SEC) << endl;
    #pragma endregion

    cout << endl;

    #pragma region Fibonacci Problem
    //number = 20;

    //start = clock();
    //cout << "***HEAD FIBONACCI***" << endl;
    //cout << "Finoaaci number " << number << " is: " << head_fibonacci(number) << endl;
    //end = clock();
    //cout << "Execution Time: " << double((end - start) * 1.0) / double(CLOCKS_PER_SEC) << endl;

    //cout << endl;

    //start = clock();
    //cout << "***TAIL FIBONACCI [PASS BASE CASE VALUES]***" << endl;
    //cout << "Finoaaci number " << number << " is: " << tail_fibonacci(number) << endl;
    //end = clock();
    //cout << "Execution Time: " << double((end - start) * 1.0) / double(CLOCKS_PER_SEC) << endl;
    #pragma endregion

    cout << endl;

    #pragma region BinarySearch Problem
    //number = 60;
    //int numbersArray[] = { 1,2,3,4,5,10,15,20,30,40,50,60,70 };
    //int arraySize = sizeof(numbersArray) / sizeof(numbersArray[0]);

    //start = clock();
    //cout << "***BINARY SEARCH [OPTIMIZED TAIL RECURSION]***" << endl;
    //cout << "Index of number " << number << " in array is: " << binarySearch(number, numbersArray, 0, arraySize) << endl;
    //end = clock();
    //cout << "Execution Time: " << double((end - start) * 1.0) / double(CLOCKS_PER_SEC) << endl;
    #pragma endregion

    cout << endl;

    #pragma region TowersOfHanoi Problem

    #pragma endregion

}