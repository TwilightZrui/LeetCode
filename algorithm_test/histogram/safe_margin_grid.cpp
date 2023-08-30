#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <stack> 
#include <ctype.h>
#define random() rand()/double(RAND_MAX)

using namespace std;
const int COL = 15;
const int ROW = 19;
const float TH1 = 0.7;
const float TH2 = 0.3;
const int safeMargin = 2;
int randomNumInt_0_or_1()
{
    double num;
   
    num = random();
    // printf("%0.3f ",num);
    if(num < 0.5) num = 0;
    else num = 1;
    return int(num);
}


int main()
{
    srand(time(NULL));//设置随机数种子，使每次产生的随机序列不同

    float array[COL][ROW] = {
1.000,   0.383,	0.979,	0.407,	0.309,	0.331,	0.978,	0.997,	0.995,	0.995,	0.992,	0.984,	0.994,	0    , 	0    ,	1.000,	1.000,	0,	1.000,	
1.000,   0.386,	0.981,	0.418,	0.307,	0.348,	0.978,	0.998,	0.998,	0.996,	0.996,	0.997,	0.996,	0    , 	0    ,	1.000,	1.000,	0,	1.000,	
1.000,   0.374,	0.987,	0.401,	0.334,	0.354,	0.972,	0.996,	0.996,	0.999,	0.984,	0.992,	0.996,	1.000,	0.986,	1.000,	1.000,	0,	1.000,	
1.000,   0.367,	0.973,	0.410,	0.345,	0.358,	0.977,	0.996,	0.989,	0.990,	1.000,	0.996,	0.999,	1.000,	0.948,	1.000,	1.000,	0,	1.000,	
1.000,   0.348,	0.971,	0.383,	0.337,	0.365,	0.983,	1.000,	0.995,	0    ,  0    , 	0.995,	0.987,	0.990,	0.993,	1.000,	1.000,	0,	1.000,	
0.295,	0.374,	0.980,	0.387,	0.337,	0.361,	0.990,	0.988,	0.992,	0    ,  0    , 	0.992,	0.990,	0.980,	1.000,	1.000,	1.000,	0,	1.000,	
1.000,	0.359,	0.988,	0.385,	0.344,	0.341,	0.982,	0.989,	0.987,	0    ,  0    , 	0.987,	0.986,	0.995,	1.000,	1.000,	1.000,	0,	1.000,	
1.000,	0.353,	0.971,	0.371,	0.301,	0.331,	0.970,	0.990,	0.991,	0    ,  0    , 	0.991,	0.998,	1.000,	0.992,	1.000,	1.000,	0,	1.000,	
1.000,	0.362,	0.968,	0.357,	0.300,	0.327,	0.985,	0.997,	0.994,	0    ,  0    , 	0.994,	0.998,	0.991,	0.993,	1.000,	1.000,	0,	1.000,	
0.300,	0.326,	0.970,	0.351,	0.302,	0.315,	0.972,	0.994,	0.997,	0    ,  0    , 	0.997,	0.988,	0.998,	0.990,	1.000,	1.000,	0,	1.000,	
1.000,	0.344,	0.968,	0.345,	0.329,	0.338,	0.983,	0.994,	0.995,	0.995,  0.995, 	0.995,	0.996,	0.997,	0.998,	1.000,	1.000,	0,	1.000,	
0.287,	0.334,	0.957,	0.355,	0.300,	0.335,	0.986,	0.986,	0.987,	0.989,	0.999,	1.000,	1.000,	0.983,	0.988,	1.000,	1.000,	0,	1.000,	
1.000,	0.328,	0.986,	0.374,	0.278,	0.322,	0.981,	0.989,	0.993,	0.991,	0.995,	0.995,	0.995,	0.982,	0.994,	1.000,	1.000,	0,	1.000,	
0.312,	0.340,	0.965,	0.374,	0.282,	0.328,	0.972,	0.998,	0.993,	1.000,	0.992,	0.995,	0.992,	0.998,	0.999,	0.976,	1.000,	0,	1.000,	
1.000,	0.362,	0.964,	0.365,	0.300,	0.330,	0.984,	0.999,	0.996,	0.987,	0.995,	0.989,	0.997,	0.997,	1.000,	0.999,	1.000,	0,	1.000};

for(int marginCount = 0;marginCount < safeMargin; marginCount++)
{
    cout << endl << "##== marginCount:  " << marginCount << endl;
    cout << endl << "RAW  cut : " << endl;
    for(int HANG = 1;HANG < (COL-1) ;HANG++)
    {
        for(int LIE = 1;LIE < (ROW-1) ;printf("%.1f  ",array[HANG][LIE++]));
        cout << endl;
    }


    cout  << endl << "RAW  th1 : " << endl;
    for(int HANG = 1;HANG < (COL-1) ;HANG++)
    {
        for(int LIE = 1;LIE < (ROW-1) ;LIE++)
        {
            if(array[HANG][LIE] < TH1) array[HANG][LIE] =0;
            else array[HANG][LIE] =1;
            printf("%-3d  ",int(array[HANG][LIE]));
        }
        cout << endl;
    }

//CALA PENG
    for(int HANG = 1;HANG < (COL-1) ;HANG++)
    {
        for(int LIE = 1;LIE < (ROW-1) ;LIE++)
        {
            if(array[HANG][LIE] < TH1)
            {
                array[HANG][LIE-1] -=TH2; 
                array[HANG][LIE+1] -=TH2;
                array[HANG-1][LIE] -=TH2; 
                array[HANG+1][LIE] -=TH2;
                // array[HANG+1][LIE-1] = array[HANG-1][LIE-1] = array[HANG+1][LIE+1] = array[HANG-1][LIE+1] -=TH2;
            }
        }
    }
    // cout << endl <<  "peng: " << endl; 
    // for(int HANG = 1;HANG < (COL-1) ;HANG++)
    // {
    //     for(int LIE = 1;LIE < (ROW-1) ;printf("%-3.1f  ",array[HANG][LIE++]));
    //     cout << endl;
    // }

    cout << endl <<  "expand  TH1: " << endl;
    for(int HANG = 1;HANG < (COL-1) ;HANG++)
    {
        for(int LIE = 1;LIE < (ROW-1) ;LIE++)
        {
            if(array[HANG][LIE] <= TH1) array[HANG][LIE] =0;
            else array[HANG][LIE] =1;
            printf("%-3d  ",int(array[HANG][LIE]));
        }
        cout << endl;
    }

}
    // cout << endl <<  "peng: " << endl; 
    // for(int HANG = 1;HANG < (COL-1) ;HANG++)
    // {
    //     for(int LIE = 1;LIE < (ROW-1) ;printf("%-3.1f  ",array[HANG][LIE++]));
    //     cout << endl;
    // }


    // cout << endl <<  "peng TH1: " << endl;
    // for(int HANG = 1;HANG < (COL-1) ;HANG++)
    // {
    //     for(int LIE = 1;LIE < (ROW-1) ;LIE++)
    //     {
    //         if(array[HANG][LIE] <= TH1) array[HANG][LIE] =0;
    //         else array[HANG][LIE] =1;
    //         printf("%-3d  ",int(array[HANG][LIE]));
    //     }
    //     cout << endl;
    // }

}