#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;
bool DEBUG = false;

typedef int type;

#define INF INT_MAX


int minByDivideAndConquer(int A[], int left, int right){
    if(DEBUG) printf("l:%d r:%d\n", left, right);
    if(left +1 == right){
         printf("%d\n", A[left]);
         return A[left];
    }
    
    int mid = (left+right)/2;
    
    int a = minByDivideAndConquer(A, left, mid);
    int b = minByDivideAndConquer(A, mid, right);
    //注意...LinuxとBSDではalgorithmライブラリのmin関数は引数の評価順序が違う
    int minNum = min(a, b);
    printf("%d\n",minNum);
    return minNum;
}

void showArray(type A[], int N){
    for(int i=0; i<N; i++){
        printf("%d", A[i]);
        if(i != N-1) printf(" ");
    }
    printf("\n");
}


int main(){
    int N;
    int *A = (int *)malloc(N*sizeof(int));

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> A[i];
    }

    minByDivideAndConquer(A, 0, N);
    //printf("%d\n", minByDivideAndConquer(A, 0, N) );
    free(A);

    return 0;
}
