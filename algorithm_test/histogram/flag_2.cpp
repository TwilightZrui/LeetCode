#include "stdio.h"
int main(void){
    int a[5][5],i,j;
    for(i=0;i<5;i++)
        for(j=0;j<5;j++)
            if(i==0 || j==0 || i==4 || j==4)
                a[i][j]=0;
            else
                a[i][j]=i+j+1;
    for(i=0;i<5;i++){
        for(j=0;j<5;printf("%2d",a[i][j++]));
        printf("\n");
    }
    return 0;
}