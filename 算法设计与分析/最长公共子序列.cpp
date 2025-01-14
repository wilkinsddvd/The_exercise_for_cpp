#include<queue>
#include<cmath>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define INF 0x3f3f3f3f
 
using namespace std;
 
char a[1001], b[1001];
int dp[1001][1001], len1, len2;
 
void lcs(int i, int j)
{
    for(i=1; i<=len1; i++)
    {
        for(j=1; j<=len2; j++)
        {
            if(a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else if(dp[i-1][j] > dp[i][j-1])
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = dp[i][j-1];
        }
    }
}
 
void llcs()
{
    int i, j, z = 0;
    char c[1001];
    memset(c, 0, sizeof(c));
    i = len1, j = len2;
    while(i!=0 && j!=0)
    {
        if(a[i-1] == b[j-1])
        {
            c[z++] = a[--i];
            j--;
        }
        else if(dp[i-1][j] < dp[i][j-1])
            j--;
        else if(dp[i][j-1] <= dp[i-1][j])
            i--;
    }
    for(i=z-1; i>=0; i--)
        printf("%c", c[i]);
    printf("\n");
 
}
 
int main()
{
    while(~scanf(" %s", a))
    {
        scanf(" %s", b);
        memset(dp, 0, sizeof(dp));
        len1 = strlen(a);
        len2 = strlen(b);
        lcs(len1, len2);
        llcs();
    }
    return 0;
}
//������ 
//Input:
//ABCBDAB
//BDCABA
//Output:
//BCBA



