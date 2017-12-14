#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;
bool DEBUG = false;

typedef int type;

#define INF INT_MAX

void showArray(type A[], int N){
    for(int i=0; i<N; i++){
        printf("%d", A[i]);
        if(i != N-1) printf(" ");
    }
    printf("\n");
}


int main(){
    int M, Nmin, Nmax;
    int *A = (int *)malloc(M*sizeof(int));

    cin >> M >> Nmin >> Nmax;
    for(int i=0; i<M; i++){
        cin >> A[i];
    }

    sort(A, A+M);
    if(DEBUG) showArray(A, M);
    int maxDiff= 0;
    int num_item = 1;

    //高価値グループはNmin個ある状態からスタート。高価値グループがNmax個になるまで見る
    for(int i=M-1 -(Nmin-1); i>= M-1 -(Nmax-1); i--){
        //高価値グループの最低価格と、低価値グループの最高価格の差
        int tmpDiff = A[i] - A[i -1];
        //差が縮んでしまったらやめる
        if(maxDiff < tmpDiff){ 
            maxDiff = tmpDiff;
            num_item++;
        }else{
            break;
        }
    }

    if(DEBUG)printf("%d\n", maxDiff);
    printf("%d\n", num_item);
    free(A);

    return 0;
}
