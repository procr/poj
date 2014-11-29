/*************************************************************************
> File Name: 1061.cpp
> Author: 
> Mail: 
> Created Time: 2014年11月30日 星期日 00时01分12秒
************************************************************************/

#include<iostream>
using namespace std;

//extented GCD
//

long long extgcd(long long a, long long b, long long &x, long long &y)
{
    long long d, t;
    if (b == 0) { x = 1; y = 0; return a;  }
    d = extgcd(b, a % b, x, y);
    t = x - a / b * y; x = y; y = t;
    return d;

}
int main()
{
    long long x, y, m, n, L, X, Y, d, r;
    cin >> x >> y >> m >> n >> L;
    d = extgcd(n - m, L, X, Y); r = L / d;
    if ((x - y) % d) cout << "Impossible" << endl;
    else cout << ((x - y) / d * X % r + r) % r << endl;
    return 0;

}
