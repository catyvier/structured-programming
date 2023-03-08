#include <iostream>
using namespace std;

void hitungRerata()
{
    int N;
    cin >> N;
    
    double total = 0, tmp;
    
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        total += tmp;
    }
    
    cout << total/N;
}

int main()
{
    hitungRerata();
}
