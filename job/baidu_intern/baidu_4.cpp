#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <climits>
#include <iomanip>
#include <algorithm>

using namespace std;

int main (){
    int n,k;
    cin >> n >> k;
    vector<float> av;
    av.resize(n);
    
    for(int i=0;i<n;i++)
    {
        cin >> av[i];
    }

sort(av.begin(),av.end())
    double res=0,tot=0,cnt=0;
    for(int i=0;i<n;i++)
    {
        if(i<k-1)
        res+=av[i];
        else
        {
            tot+=av[i];
            cnt+=1;
        }
    }
    res+=tot/cnt;
    printf("%.10f",res);
}