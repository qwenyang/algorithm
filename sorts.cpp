#include <stdio.h>

void BubbleSort(int* const pArray,const int nLen){
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