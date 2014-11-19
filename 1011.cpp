/*************************************************************************
	> File Name: 1011.cpp
	> Author: 
	> Mail: 
	> Created Time: 2014年11月16日 星期日 20时51分10秒
 ************************************************************************/
#include<iostream>
using namespace std;

int lenOfEach[65];
int reachSum[4096] = {0};

void dfs(int *a, int n, int curIdx, int curSum)
{
    if (curIdx == n)
        return;
    reachSum[curSum + a[curIdx]] = 1;
    dfs(a, n, curIdx + 1, curSum + a[curIdx]);
    dfs(a, n, curIdx + 1, curSum);
}


bool check(int eachLen, int sum)
{
    if (sum % eachLen != 0)
        return false;
    int cnt = sum / eachLen;
    for (int i = 1; i <= cnt; i++)
    {
        if (!reachSum[eachLen * i])
            return false;
    }
    return true;
}

int main()
{
    while(1)
    {
        int n;
        int a[50];
        int sum = 0;
        int max = -1;

        cin >> n;
        if (n == 0)
            break;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] > max)
                max = a[i];
            sum += a[i];
            lenOfEach[i + 1] = -1;
        }

        for (int i = 1; i <= n; i++)
        {
            if (sum % i == 0)
            {
                lenOfEach[i] = sum / i;
            }
        }
        
        dfs(a, n, 0, 0);

        for (int i = n; i >= 1; i--)
        {            
            if(lenOfEach[i] != -1 && lenOfEach[i] >= max && check(lenOfEach[i], sum))
            {
                cout << lenOfEach[i] << endl;
                break;
            }
            
        }
    }

    return 0;
}
