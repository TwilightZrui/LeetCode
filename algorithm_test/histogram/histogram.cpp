#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <stack> 
#include <ctype.h>
using namespace std;
class histogram
{
public:
    int largestRectangleArea(vector<int>& heights)
    {
    stack<int> sta;
    sta.push(-1);
    int maxArea = 0;
    for(int i=0;i<heights.size();i++)
    {
        while(sta.top() != -1 && heights[sta.top()] >= heights[i])
        {
            int height = heights[sta.top()];
            sta.pop();
            int width = i - sta.top() -1;
            maxArea = max(maxArea, height*width);
        }
        sta.push(i);
    }
    while(sta.top() != -1 )
    {
        int height = heights[sta.top()];
        sta.pop();
        int width = heights.size() - sta.top() - 1;
        maxArea = max(maxArea, height * width);
    }
    return maxArea;
    }
};

int main(){
    int A[] = {2,1,5,6,2,3};
    vector<int> height;
    histogram his;
    for(int i=0;i<6;i++)
    {
        height.push_back(A[i]);
    }
    cout << his.largestRectangleArea(height) <<endl;


    return 0;
}

