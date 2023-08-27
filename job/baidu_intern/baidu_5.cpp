#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <climits>
#include <iomanip>
#include <algorithm>
using namespace std;
int main()
{
    int n,k;
    cin >> n >> k;
    vector<int> a(n+1);
    
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }

    vector<vector<double>> dp(n+1,vector<double>(k+1,INT_MAX));
dp[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            for(int p=0;p<i;p++)
            {
                double temp;
                temp =0 ;
                dp[i][j]=min(dp[i][j],  dp[p][j-1] + (double)accumulate(a.begin()+p+1,a.begin()+i+1,0))/(i-p);
                
            }
        }
        
    }

    cout << fixed << setprecision(6) << dp[n][k] << endl;
}

