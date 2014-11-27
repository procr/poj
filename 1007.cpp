/*************************************************************************
> File Name: 1007.cpp
> Author: 
> Mail: 
> Created Time: 2014年11月27日 星期四 21时07分29秒
************************************************************************/
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
struct Element
{
    string s;
    int inversionNum;
};

bool cmp(Element a, Element b)
{
    return a.inversionNum < b.inversionNum;

}
int main()
{
    int n, m;
    cin >> n >> m;
    Element eles[100];
    for (int i = 0; i < m; i++)
    {
        cin >> eles[i].s;
        eles[i].inversionNum = 0;

        int A, G, C, T;
        A = G = C = T = 0;
        for (int j = n - 1; j >= 0; j--)
        {
            switch(eles[i].s[j])
            {
                case 'A':
                A++;
                break;
                case 'C':
                C++;
                eles[i].inversionNum += A;
                break;
                case 'G':
                G++;
                eles[i].inversionNum += (A + C);
                break;
                case 'T':
                eles[i].inversionNum += (A + C + G);
                break;
            }
        }
    }

    sort(eles, eles + m, cmp);

    for (int i = 0; i < m; i++)
    {
        cout << eles[i].s << endl;
    }

    return 0;
}
