#include <stdio.h>
#include <algorithm>

void PrintArray(int* const pArray, int start, int end) {
    for(int i=start; i<end; i++) {
        printf("%d ",pArray[i]);
    }
    printf("\n");
}

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

//  插入排序
void InsertSort(int* pArray, const int nLen) {
    for(int i=1; i<nLen; i++) {
        int val=pArray[i];
        int j=0;
        for(j=i-1; j>=0; j--) {
            if(pArray[j] > val ) {
                pArray[j+1]=pArray[j];
            } else {
                break;
            }
        }
        pArray[j+1]=val;
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

//向下调整堆 
void HeapAdjustDown(int* const pArray, int k, int n) {
    for(int l=k*2+1; l<n; l=2*k+1) {
        if(l+1<n && pArray[l+1] > pArray[l] ) {// 左右子节点取大
            l++;
        }
        if( pArray[l] > pArray[k] ) {
            std::swap(pArray[k], pArray[l]);
        } else {
            break;
        }
    }
}

// 堆排序 [0....n）
void HeapSort(int* const pArray, int n) {
    //Build Heap
    for(int i=n/2-1; i>=0; i--) {
        HeapAdjustDown(pArray, i, n);
    }
    //Start Sort
    for(int i=n-1; i>=0; i--) {
        std::swap(pArray[i], pArray[0]);
        HeapAdjustDown(pArray, 0, i);
    }
}

//[start, mid) [mid, end)
void SortTwoList(int* const pArray, int start, int mid, int end, int* const tArray) {
    int i=start, j=mid, k=start;
    while(i<mid && j<end) {
        if(pArray[i] <= pArray[j]) {
            tArray[k++]=pArray[i++];
        } else {
            tArray[k++]=pArray[j++];
        }
    }
    while(i<mid) tArray[k++]=pArray[i++];
    while(j<end) tArray[k++]=pArray[j++];
    for(int t=start; t<end; t++) {
        pArray[t] = tArray[t];
    }
}

//[start, end)
void MergeSort(int* const pArray, int start, int end, int* const tArray) {
    if(start >= end-1) {
        return ;
    } else if(start == end -2) {
        if(pArray[start] > pArray[end-1]) {
            std::swap(pArray[start], pArray[end-1]);
        }
        return ;
    }

    int mid = (start+end)/2;
    MergeSort(pArray, start, mid, tArray);
    MergeSort(pArray, mid, end, tArray);

    SortTwoList(pArray, start, mid, end, tArray);
}

void MergeSortList(int* const pArray, int nLen) {
    int arrList[1000]={0};
    MergeSort(pArray, 0,nLen, arrList);
}