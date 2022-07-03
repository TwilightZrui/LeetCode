#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <stack> 
#include <ctype.h>
#define random() rand()/double(RAND_MAX)

using namespace std;
const int COL = 11;
const int ROW = 7;
bool maximalArea(int& maximalArea,int rectangleArea)
{
    bool changeFlag = false;
    if(maximalArea < rectangleArea)
    {
        maximalArea = rectangleArea;
        changeFlag = true;
    }
    return changeFlag;
}


int randomNumInt_0_or_1()
{
    double num;
   
    num = random();
    // printf("%0.3f ",num);
    if(num < 0.2) num = 0;
    else num = 1;
    return int(num);
}
// float randomNumFloat_0_to_1()
// {
//     float num;
//     num = random();
//     // printf("%0.3f ",num);
//     // if(num < 0.2) num = 0;
//     // else num = 1;
//     return num;
// }
struct rectResultStruct
{
    //temp
    int bottlomCOLTemp = 0;

    int RowLength;
    int ColLength;
    int rectArea;

    vector<int> LF_index{0,0,0};
    vector<int> RF_index{0,0,0};
    vector<int> RH_index{0,0,0};
    vector<int> LH_index{0,0,0};
    vector<int> rectCenter_index{0,0,0};

    float center2defaultDistance;
};
rectResultStruct rectResult ;


bool histogramMaxRect(int heights_[], int ArLength ,int nowHANG,
                       int& rectStartROW_, int& rectEndROW_, int& maxArea_,
                      rectResultStruct& RectResult )
{
    stack<int> sta;
    sta.push(-1);

    for(int i =0 ;i < ArLength; i++ )
    {
        while(sta.top() != -1 && heights_[sta.top()] >= heights_[i])
        {
            int height = heights_[sta.top()];
            sta.pop();
            int width = i - sta.top() -1;
            if(maximalArea(maxArea_, height * width))
            {
                rectStartROW_ = sta.top() + 1 ;
                rectEndROW_ = i - 1 ;
                bottlomCOL_ = nowHANG;   

                RectResult.RowLength = height;
                RectResult.ColLength = width;
                RectResult.rectArea = maxArea_;

                RectResult.LF_index[0] = bottlomCOL_ - RectResult.RowLength + 1 ;
                RectResult.LF_index[1] = rectStartROW_;

                RectResult.RF_index[0] = bottlomCOL_ - RectResult.RowLength  + 1;
                RectResult.RF_index[1] = rectEndROW_;

                RectResult.RH_index[0] = bottlomCOL_ ;
                RectResult.RH_index[1] = rectStartROW_;

                RectResult.LH_index[0] = bottlomCOL_ ;
                RectResult.LH_index[1] = rectEndROW_;

                RectResult.rectCenter_index[0] = int((RectResult.LF_index[0] + RectResult.LH_index[0]) / 2);
                RectResult.rectCenter_index[1] = int((RectResult.LF_index[1] + RectResult.RF_index[1]) / 2);

                //     cout << endl << "RectResult.RowLength:" << RectResult.RowLength <<endl;
                //  cout << "RectResult.ColLength:" << RectResult.ColLength << endl;
                // cout << "RectResult.LF_index[0] : " << RectResult.LF_index[0] << endl;
            }
        }
        sta.push(i);
    }
    while(sta.top() != -1)
    {
        int height = heights_[sta.top()];
        sta.pop();
        int width = ArLength - sta.top() - 1;
        if(maximalArea(maxArea_, height * width))
        {
            rectStartROW_ = sta.top()  + 1 ;
            rectEndROW_ = ArLength - 1 ;
            bottlomCOL_ = nowHANG;

            RectResult.RowLength = height;
            RectResult.ColLength = width;
            RectResult.rectArea = maxArea_;

            RectResult.LF_index[0] = bottlomCOL_ - RectResult.RowLength + 1 ;
            RectResult.LF_index[1] = rectStartROW_;

            RectResult.RF_index[0] = bottlomCOL_ - RectResult.RowLength  + 1;
            RectResult.RF_index[1] = rectEndROW_;

            RectResult.RH_index[0] = bottlomCOL_ ;
            RectResult.RH_index[1] = rectStartROW_;

            RectResult.LH_index[0] = bottlomCOL_ ;
            RectResult.LH_index[1] = rectEndROW_;

            RectResult.rectCenter_index[0] = int((RectResult.LF_index[0] + RectResult.LH_index[0]) / 2);
            RectResult.rectCenter_index[1] = int((RectResult.LF_index[1] + RectResult.RF_index[1]) / 2);
        }
    }

    return true;
}

int main()
{
    srand(time(NULL));//设置随机数种子，使每次产生的随机序列不同
    // int bottlomCOL = 0;
    int rectStartROW = 0;
    int rectEndROW = 0;
    int maxArea = 0;
 
    int histogramArray[ROW]= {0};
    int array[COL][ROW] = {0};

    cout << endl;
    for(int hang = 0;hang < COL ;hang++)
    {
        for(int lie = 0;lie < ROW ;lie++)
        {
            array[hang][lie] = randomNumInt_0_or_1();
            printf("%d  ",array[hang][lie]);
        }
        cout << endl;
    }
    cout << endl;






    // ala
    for(int hang = 0;hang < COL ;hang++)
    {
        for(int lie = 0;lie < ROW ;lie++)
        {
            if(array[hang][lie] == 0)
                histogramArray[lie] = 0;
            else
                histogramArray[lie] ++;
            printf("%-3d", histogramArray[lie]);
        }

        histogramMaxRect(histogramArray, ROW, hang, 
                            // bottlomCOL,
                            rectStartROW,rectEndROW,maxArea, 
                            rectResult);
                            
        cout << endl;
    }
    // //result print
    cout << endl << "rectStartROW : " << rectStartROW << endl;
    cout << "rectEndROW: " << rectEndROW << endl;
    cout << "max rectangel bottom hang: " <<bottlomCOL <<endl;  
   
 

    return 0;
}