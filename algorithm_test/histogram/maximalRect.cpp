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
    int maximalRectangle(vector<string>& matrix) {
        if (matrix.size() == 0) {
            return 0;
        }
        vector<int> heights(matrix[0].size(), 0); //声明一个初始大小为matrix[0].size()初始值都为0的向量
        int maxArea = 0;
        for (int i = 0; i < matrix.size(); ++i) 
        {
            for (int j = 0; j < matrix[0].size(); ++j) 
            {
                if (matrix[i][j] == '0') {
                    heights[j] = 0;
                }
                else {
                    heights[j] += matrix[i][j] - '0';
                    cout << matrix[i][j] <<endl;
                    //cout << heights[j] << endl;
                }
            }
            maxArea = max(maxArea, largestRectangleArea(heights));
        }
        return maxArea;
    }

    
    int largestRectangleArea(vector<int>& heights)
    {
    stack<int> sta;
    sta.push(-1);
    int maxArea = 0;
    for(int i=0;si<heights.size();i++)
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
    string A[] = {"10100","10111","11111","10010"};
    vector<string> height;
    histogram his;
    for(int i=0;i<4;i++)
    {
        height.push_back(A[i]);
        cout << height[i] << endl;
    }
    cout << his.maximalRectangle(height) <<endl;


    return 0;
}