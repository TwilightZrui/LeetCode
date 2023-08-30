#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <climits>
#include <iomanip>

using namespace std;
int main()
{
    int x;
    cin >>x;
    int n=floor(0.5 *(-1)+sqrt() );

    string res;
    for(int i=0;i<n;i++)
    {
        res+='r';
    }

    res[0][0] = 0;
    for(int i=0;i<x;i++)
    {
        if(i%3==0)
            res+='e';
        else if(i%3==1)
          res+='d';
        else
        res+='r';
    }

    cout << res<< endl;
}

