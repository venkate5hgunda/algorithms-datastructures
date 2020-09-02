#include <iostream>

using namespace std;

void tail(int n) { // this does not store anything in memory

    if (n == 0) return;

    // we do an operation
    cout << "Tail Recursion. n:" << n << endl;

    // recursive function call is made at the end of the function. the stack will not store any previous calls (function call stack is clean)
    tail(n - 1);
}

void head(int n) { // memory haevy operation

    if (n == 0) return;

    // we call the recursive function
    head(n - 1);

    // once the recursion is done, operation is performed. the call stack has to store all the previous states (function calls are stored in call stack)
    cout << "Head Recursion. n:" << n << endl;
}