// Buat kode program untuk mencari Bilangan Fibonacci dengan menggunakan teknik Rekursif dan Dynamic Programming, kemudian bandingkan running timenya.

#include <iostream>
using namespace std;

long long fibonacciRecursive(long long val) {
    if (val <=1) return val;
    return fibonacciRecursive(val-1) + fibonacciRecursive(val-2);
}

long long fibonacciDynamicProgramming(long long val) {
    long long dp[val+1];
    dp[0] = 0;
    dp[1] = 1;

    for (long long i = 2; i <= val; ++i) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[val];
}

int main()
{
    cout << fibonacciDynamicProgramming(50) << endl;
    cout << fibonacciRecursive(50) << endl;

    return 0;
}
