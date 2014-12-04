/*************************************************************************
	> File Name: 1005.cpp
	> Author: 
	> Mail: 
	> Created Time: 2014年12月04日 星期四 20时58分27秒
 ************************************************************************/

#include<iostream>
using namespace std;

#define PI 3.1415926535897932384626

int main()
{
    int n;
    double x, y, area;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        area = PI*(x*x + y*y)/2;
        int year = (int)(area / 50) + 1;
        cout<<"Property "<< i + 1<<": This property will begin eroding in year "<<year<<"."<<endl;  
    }

    cout << "END OF OUTPUT." << endl;

    return 0;
}
