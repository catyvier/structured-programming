/* 2217051004
 *
 */

#include <iostream>

#define minimum(x,y) x < y ? x : y;
#define maximum(x,y) x > y ? x : y;

long long rekursif(long long digitAkhir, long long digit9) {
    if (digit9 == 0) 
        return 0;
    
    else if (digit9 == 1) 
        return digitAkhir;

    return digitAkhir * rekursif(digitAkhir, digit9 - 1);
}

using namespace std;

int main()
{
    int a =  minimum(0, 4);
    int b = maximum(0, 4);
    long long c = rekursif(4, 0);
  
    const char *npm = "2217051004";
    const char *str = &npm[8];

    cout << a << endl; // output 0
    cout << b << endl;  // output 4
    cout << c << endl; // output 4 kali 4 sebanyak 0 kali
  
    cout << str << endl;  // output isi dari pointer
    cout << (void *) &npm[8] << endl;  // output alamat dari data
  
    return 0;
}
