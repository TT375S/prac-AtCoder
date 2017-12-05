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

int insertionSort(type A[], int N){
    int ctimes = 0;
    for(int i=0; i<N; i++){
        type v = A[i];
        int j = i-1;
        while(j>=0 && A[j]<v){
            A[j+1] = A[j];
            j--;
            ctimes++;
        }
        A[j+1] = v;
        if(isDebug) showArray(A, N);
    }
    return ctimes;
}

#define MAX_N 100
int N;
int A[MAX_N];
void input(){
    cin >> N;
    if(isDebug) printf("N:%d\n", N);
    for(int i=0; i<N; i++){
        cin >> A[i];
        if(isDebug) printf("A:%d\n", A[i]);
    }
}

int main(){
    input();
    int ans = insertionSort(A, N);
    printf("%d\n", ans);
    showArray(A, N);
    return 0;
}
