#include <cstdlib>
#include <cstdio>
#include <iostream>

typedef int type;
using namespace std;
const bool isDebug = true;

void showArray(type A[], int N){
    for(int i=0; i<N; i++){
        printf("%d", A[i]);
        if(i != N-1) printf(" ");
    }
    printf("\n");
}

void insertionSort(type A[], int N){
    
    for(int i=0; i<N; i++){

        type v = A[i];
        int j = i-1;
        while(j>=0 && A[j]>v){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
        if(isDebug) showArray(A, N);
    }
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
    insertionSort(A, N);
    return 0;
}
