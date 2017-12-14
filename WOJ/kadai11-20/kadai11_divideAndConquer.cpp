#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

int findMax(int *A, int left, int right){
    int mid = (left+right) / 2;
    int maxNum = 0;
    if ( left == right -1){
        maxNum = A[left];
    }else{
        int former = findMax(A, left, mid);
        int leater = findMax(A, mid, right);
        maxNum = max(former, leater);
    }

    printf("%d\n", maxNum);
    return  maxNum;
}


#define MAX_A 10000

int main(){
    int A[MAX_A];
    int n;
    cin >> n;
    int i = n;
    for(i=0; i< n;i++){
        cin >> A[i];
    }

    findMax(A, 0, n);
    return 0;
}
