#include <iostream>
using namespace std;

int dp[100];

int fib(int n) {

    if(n <= 1)
        return n;

    if(dp[n] != -1)
        return dp[n];

    dp[n] = fib(n-1) + fib(n-2);

    return dp[n];
}

int main() {

    int n;

    cout << "Enter value of n: ";
    cin >> n;

    for(int i = 0; i < 100; i++) {
        dp[i] = -1;
    }

    cout << "Fibonacci Number = "
         << fib(n);

    return 0;
}