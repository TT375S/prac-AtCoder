#include <cstdlib>
#include <cstdio>
#include <iostream>

typedef int type;
using namespace std;
const bool isDebug = false;

void showArray(type A[], int N){
    for(int i=0; i<N; i++){
        printf("%d", A[i]);
        if(i != N-1) printf(" ");
    }
    printf("\n");
}

int bubbleSort(type A[], int N){
    bool flag_inv = true;
    int changeTime = 0;
    while(flag_inv){
        if(isDebug) showArray(A, N);
        flag_inv = false;
        for(int j=N-1; j>=1; j--){
            if(A[j] < A[j-1]){
                type tmp = A[j];
                A[j] = A[j-1];
                A[j-1] = tmp;

                changeTime++;
                flag_inv = true;
            }
        }
    }
    return changeTime;
}

#define MAX_N 100
int N;
int A[MAX_N];
void input(){
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", &A[i]);
    }
    fflush(stdin);
}

int main(){
    input();
    int changeTime = bubbleSort(A, N);
    printf("%d\n", changeTime);
    showArray(A, N);
    return 0;
}
