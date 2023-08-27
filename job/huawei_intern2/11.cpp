#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
int meeting_rooms(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b)
         { return a[0] < b[0]; });
    priority_queue<int, vector<int>, greater<int>> end_time;

    for (auto &interval : intervals)
    {
        if (end_time.empty() || interval[0] < end_time.top())
        {
            end_time.push(interval[1]);
        }
        else
        {
            end_time.pop();
            end_time.push(interval[1]);
        }
    }
    return end_time.size();
}

int main()
{

    vector<vector<int>> meetings1{{7, 10}, {2, 7}};
    vector<vector<int>> meetings2{{0, 21}, {5, 10}, {5, 20}};
    vector<vector<int>> meetings3{{0, 24}, {23, 24}};
    vector<vector<int>> meetings4{{0, 24}, {1, 23}, {2, 22}, {3, 21}, {4, 20}};

    int ans1 = meeting_rooms(meetings1);
    int ans2 = meeting_rooms(meetings2);
    int ans3 = meeting_rooms(meetings3);
    int ans4 = meeting_rooms(meetings4);
    cout << ans1 << endl
         << ans2 << endl
         << ans3 << endl
         << ans4 << endl;

    return 0;
}
