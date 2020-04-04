#include <stdio.h>

void BubbleSort(int* const pArray,const int nLen);

int main() {
    int iNum;
    int arrList[1000];
    while( scanf("%d",&iNum) != EOF) {
        for(int i =0;i<iNum;i++) {
            scanf("%d ",arrList+i);
        }
        BubbleSort(arrList,iNum);
        for(int i=0;i<iNum;i++){
            printf("%d ",arrList[i]);
        }
        printf("\n\n");
    } 
    return 0;
}