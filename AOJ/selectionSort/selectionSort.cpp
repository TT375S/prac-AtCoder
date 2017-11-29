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

int selectionSort(type A[], int N){
    int changeTime = 0;
    for(int i=0; i<N; i++){
        int minJ= i;
        for( int j=i; j<N; j++){
            if(A[j] < A[minJ]){
                minJ = j;
            }
        }
        //swap
        if(i != minJ){
            changeTime ++;
            type tmp = A[i];
            A[i] = A[minJ];
            A[minJ] = tmp;
        }
    }
    return changeTime;
}

#define MAX_N 100
int N;
int A[MAX_N];
void input(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
}

int main(){
    input();
    int changeTime = selectionSort(A, N);
    showArray(A, N);
    printf("%d\n", changeTime);
    return 0;
}
