#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <climits>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <bits/stdc++.h>
#include <queue>
#include <string>
#include <cstring>

using namespace std;


bool my_strStr(const char* str1, const char* str2)
{
    int st1Len = static_cast<int>(strlen(str1));
     int st2Len = static_cast<int>(strlen(str2));
     bool match = false;
     for(int i = 0; i <= st1Len-st2Len;++i)
     {
       match = true;
        for(int j=0;j<st2Len;++j)
        {
            if(str1[i+j] !=str2[j])
            {
                match = false;
                break;
            }

            if(match) 
            {
                return  match;
            }
        }
     }
     return match;
}

int main() {
        char arr1[20] = "abcdef";
        char arr2[] = "cde";
        cout << "111: " << my_strStr(arr1, arr2) << endl;
    // if (my_strStr(arr1, arr2)) {
    //             printf("you are right");
    //     }
    
   char arr3[] = "dndn";
   cout << "222 : " << my_strStr(arr1, arr3) << endl;
//    if (!my_strStr(arr1, arr3)) {
//                 printf("you are false");
//         }
        return 0;
}