/*************************************************************************
	> File Name: 1011.cpp
	> Author: 
	> Mail: 
	> Created Time: 2014年11月16日 星期日 20时51分10秒
 ************************************************************************/
#include <iostream>
#include <algorithm>
using namespace std;

int n;

bool dfs(int *a, int *used, int targetSum, int curIdx, int curSum, int nUsed)
{
    if (nUsed == n)
        return true;

    int skip = -1;

    for (int i = curIdx; i < n; i++)
    {
        if (used[i] || a[i] == skip)
            continue;

        used[i] = 1;

        if (curSum + a[i] < targetSum)
        {
            bool flag = dfs(a, used, targetSum, i + 1, curSum + a[i], nUsed + 1);
            if (flag)
                return true; 
            else
                skip = a[i];
        }
        else if (curSum + a[i] == targetSum)
        {
            bool flag = dfs(a, used, targetSum, 0, 0, nUsed + 1);
            if (flag)
                return true; 
            else
                skip = a[i];
        }

        used[i] = 0;

        if (curSum == 0)
            break;
    }

    return false;
}


int cmp(const void *a, const void *b)
{
    return *(int *)b - *(int *)a; // TLE if change '-' to '>', weired......:(
}

int main()
{
    while(1)
    {
        cin >> n;
        if (n == 0)
            break;
        int *a = new int[n];
        int *used = new int[n];
        int sum = 0;
        int res;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
            used[i] = 0;
        }

        //sort(a, a + n, cmp);
        qsort(a, n, sizeof(a), cmp);  

        bool found = false;
        for (res = a[0]; res <= sum - res; res++)
        {
            if (!(sum % res) && dfs(a, used, res, 0, 0, 0))
            {
                cout << res << endl;
                found = true;
                break;
            }
        }
        
        if (!found)
        {
            cout << sum << endl; 
        }
        delete a;
        delete used;
    }
    return 0;
}
