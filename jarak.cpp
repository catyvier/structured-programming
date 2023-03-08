/* @Vexender
 *
 *
 */

#include <iostream>
#include <cmath>

using namespace std;

double jarak (double x1, double y1, double x2, double y2)
{
    double res = sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));
    
    return res;
}

int main()
{
    cout << jarak(0,0,3,4);
}
