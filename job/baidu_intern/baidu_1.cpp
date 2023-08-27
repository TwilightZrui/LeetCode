#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <climits>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;
// #define int long long 
#define N 5
int n;

vector<int> g[N+5];
int val[N+5][2];
int tag[N+5][2];
void dfs(int u,int p)
{
    for(auto v:g[u])
    {
        if(v==p) continue;
        tag[v][0] +=tag[u][0];
        val[v][1] +=tag[u][1];
        dfs(v,u);
    }
}

void dfs1(int u,int p)
{
    val[u][0]+=tag[u][0];
    val[u][1]+=tag[u][1];
    for(auto v:g[u])
    {
        if(v==p) continue;
        dfs(v,u);
        val[u][0] +=val[v][0];
        val[u][1] +=val[v][1];
    }
}
int main()
{

    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%lld",&x);
        while(x%2==0)val[i][0]++,x/2=2;
        while(x%5==0) val[i][1]++,x/=5;
        
    }
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("lld lld",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int q;
    scanf("%lld",&q);
    while(q--)
    {
        int u,g;
        scanf("%lld %lld",&u,&g);
        while(g%2==0) tag[u][0]++,g/=2;
        while(g%5==0 ) tag[u][1]++,g/=5;
    }
    dfs(1,0);
    dfs1(1,0);
    for(int i=1;i<=n;i++)
    {
        printf("%lld ",min(val[i][0],val[v][1]));
    }
    return 0;
}