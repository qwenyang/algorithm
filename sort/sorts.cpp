#include <stdio.h>
#include <algorithm>

// 冒泡排序算法
void BubbleSort(int* const pArray, const int nLen){
    for(int i=0;i<nLen;i++) {
        for(int j=0;j<nLen-i-1;j++){
            if(pArray[j]>pArray[j+1]) {
                int iTmp=pArray[j];
                pArray[j]=pArray[j+1];
                pArray[j+1]=iTmp;
            }
        }
    }
}

// 快速排序[start, end)
void QuickSort(int* const pArray, int start, int end) {
    if(start >= end-1 ) {
        return ;
    }
    int pivos=pArray[start];
    int i=start, j=end-1;
    while(i<j) {
        //顺序很重要，要先从右边开始找
        while(pArray[j] >= pivos && i<j) j--;
        while(pArray[i] <= pivos && i<j) i++;
        if(i < j) {
            std::swap(pArray[i], pArray[j]);
        }
    }
    pArray[start]=pArray[i];
    pArray[i]=pivos;

    QuickSort(pArray, start, i);
    QuickSort(pArray, i+1, end);
}

//快速排序
void QuickSortList(int* const pArray, const int nLen) {
    QuickSort(pArray, 0, nLen);
}
