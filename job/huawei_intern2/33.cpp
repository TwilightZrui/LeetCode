#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;
struct Meeting
{
    int start, end;
};
bool cmp(Meeting &a, Meeting &b)
{
    // return (a.end <= b.end); //
    return (a.start < b.start); //
}

int minMeetingRooms(vector<Meeting> &meetings)
{
    sort(meetings.begin(), meetings.end(), cmp);
    int roomCnt = 1, end = meetings[0].end;
    int sz = meetings.size();
    priority_queue<int, vector<int>, greater<int>> end_times;

    // for (int i = 0; i < sz; i++)
    // {
    //     if (!end_times.empty() && end_times.top() <= meetings[i].start)
    //     {
    //         end_times.pop();
    //         end_times.push(meetings[i].end);
    //     }
    // }
    // return end_times.size();
    for (int i = 1; i < sz - 1; i++)
    {
        if ((meetings[i].start >= meetings[i].end) || (meetings[i].end < meetings[i + 1].start))
        {
            end = meetings[i].end;
        }
        else
        {
            roomCnt++;
        }
    }
    return roomCnt;
}

int main()
{

    // vector<Meeting> meetings{{7, 10}, {2, 7}};
    // vector<Meeting> meetings{{0, 21}, {5, 10}, {5, 20}};
    // vector<Meeting> meetings{{0, 24}, {23, 24}};
    vector<Meeting> meetings{{0, 24}, {1, 23}, {2, 22}, {3, 21}, {4, 20}};

    int ans = minMeetingRooms(meetings);
    cout << ans << endl;
    return 0;
}
