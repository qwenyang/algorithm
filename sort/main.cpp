#include <stdio.h>

void BubbleSort(int* const pArray,const int nLen);
void QuickSortList(int* const pArray, const int nLen);

int main() {
    int iNum=0;
    int arrList[1000]={0};
    while( scanf("%d",&iNum) != EOF ) {
        for(int i=0; i<iNum; i++) {
            scanf("%d", arrList+i);
        }
        printf("start sort");
        //BubbleSort(arrList, iNum);
        QuickSortList(arrList, iNum);
        for(int i=0; i<iNum; i++){
            printf("%d ", arrList[i]);
        }
        printf("\n\n");
    } 
    return 0;
}