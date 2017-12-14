#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;
bool DEBUG = false;

typedef int type;

#define INF INT_MAX

void merge(int A[], int left, int mid, int right){
    int n1 = mid - left;
    int n2 = right -mid;

    int *L = (int *)malloc((n1+1) *sizeof(int));
    int *R= (int *)malloc((n2+1) *sizeof(int));

    for(int i=0; i<n1; i++){
        L[i] = A[left +i];
    }
    for(int i=0; i<n2; i++){
        R[i] = A[mid +i];
    }

    //番兵
    L[n1] = -1*INF;
    R[n2] = -1*INF;

    int i_L=0, i_R=0;
    for(int i_A = left; i_A < right; i_A++){
        if(L[i_L] >= R[i_R]){
            A[i_A] = L[i_L];
            i_L++;
        }else{
            A[i_A] = R[i_R];
            i_R++;
        }
    }

    free(L);
    free(R);
}

int mergeSort(int A[], int left, int right){
    if(DEBUG) printf("%d %d\n", left, right);

    int times=0;
    if(left+1 < right){
        int mid = (left+right)/2;
        //分割統治
        times += mergeSort(A, left, mid);
        times += mergeSort(A, mid, right);
        merge(A, left, mid, right);
        times++;
    }
    return times;
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

    int times = mergeSort(A, 0, N);
    showArray(A, N);
    printf("%d\n", times);
    free(A);

    return 0;
}
