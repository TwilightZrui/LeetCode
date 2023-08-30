/***
 * @Author       : TwilightZrui
 * @Date         : 2022-08-26 22:49:36
 * @LastEditTime : 2022-11-20 20:47:15
 * @FilePath     : /LeetCode/randomNUM.cpp
 * @Description  :
 * @Copyright (c) 2022, All Rights Reserved.
 */
#include <iostream>
#include <cstdlib>
#include <ctime>
#define random(x) rand()/double(RAND_MAX)
int randomNumInt_0_or_1()
{
    double num;
    num = random(1);
    // printf("%0.3f ",num);
    if(num < 0.2) num = 0;
    else num = 1;
    return int(num);
}
float randomNumFloat_0_to_1()
{
    float num;
    num = random(1);
    // printf("%0.3f ",num);
    // if(num < 0.2) num = 0;
    // else num = 1;
    return num;
}

const int COL = 11;
const int ROW = 7;

using namespace std;

int main()
{
    srand((int)time(0));  // 产生随机种子  把0换成NULL也行
    float array[COL][ROW] = {0};
    // for(int hang = 0;hang < COL ;hang++)
    // {
    //     for(int lie = 0;lie < ROW ;lie++)
    //     {
    //         array[hang][lie] = randomNumInt_0_or_1();
    //         printf("%d\t",array[hang][lie]);
    //     }
    //     cout << endl;
    // }

    for(int hang = 0;hang < COL ;hang++)
    {
        for(int lie = 0;lie < ROW ;lie++)
        {
            array[hang][lie] = randomNumFloat_0_to_1();
            printf("%0.3f\t",array[hang][lie]);
        }
        cout << endl;
    }

    // for (int i = 0; i < 10; i++)
    // {
    //     // cout << random(1) << " ";
    //     printf("%0.3f ",random(1));
    // }
    return 0;
}

