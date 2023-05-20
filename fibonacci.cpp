// Buat kode program untuk mencari Bilangan Fibonacci dengan menggunakan teknik Rekursif dan Dynamic Programming, kemudian bandingkan running timenya.

#include <iostream>
using namespace std;

long long fibonacciRecursive(long long val) {
    if (val <=1) return val;
    return fibonacciRecursive(val-1) + fibonacciRecursive(val-2);
}

long long fibonacciDynamicProgramming(int n) {
    static long long dp[105] = {0};
    dp[0] = 0;
    dp[1] = 1;

    if (dp[n] == 0) {
        dp[n] = fibonacciDynamicProgramming(n-1) + fibonacciDynamicProgramming(n-2);
    }

    return dp[n];
}

int main()
{
    cout << fibonacciDynamicProgramming(50) << endl;
    return 0;
}
