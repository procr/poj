/*************************************************************************
> File Name: 1008.cpp
> Author: 
> Mail: 
> Created Time: 2014年12月04日 星期四 21时03分48秒
************************************************************************/

#include<cstdio>
#include<cstring>
char month1[19][10]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
char month2[20][10]={"imix","ik","akbal","kan","chicchan","cimi","manik","lamat","muluk","ok","chuen","eb","ben","ix","mem","cib","caban","eznab","canac","ahau"};
int n,i,j;
int main()
{
    scanf("%d",&n);
    printf("%d\n",n);
    for (i=0;i<n;i++)
    {
        char month[10];
        int day,year,date;
        scanf("%d.%s%d\n",&day,month,&year);  //C的格式控制很灵活
        for (j=0;j<19;j++)
        {
            if (!strcmp(month1[j],month))
            break;

        }
        date=year*365+j*20+day;
        printf("%d %s %d\n",date%13+1,month2[date%20],date/260);  //代码最简化

    }
    return 0;

}

