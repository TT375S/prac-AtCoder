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

//配列Aは末尾に番兵を追加するのでN+1個用意する
int linearSearch(type A[], int N, int target){
    int i = 0;
    //番兵をセット
    A[N] = target;
    while(A[i] != target){
        i++;
    }

    if(i == N){
        return -1;
    }
    return i;
}

#define MAX_N 10001
#define MAX_Q 500
int N, Q;
int A[MAX_N];
int T[MAX_Q];

void input(){
    cin >> N;
    if(isDebug) printf("N:%d\n", N);
    for(int i=0; i<N; i++){
        cin >> A[i];
        if(isDebug) printf("A:%d\n", A[i]);
    }
    cin >> Q;
    if(isDebug) printf("N:%d\n", N);
    for(int i=0; i<Q; i++){
        cin >> T[i];
        if(isDebug) printf("A:%d\n", A[i]);
    }
}

int main(){
    input();
    int fcount = 0;
    for(int it = 0; it<Q; it++){
        int find = linearSearch(A, N, T[it]);
        if(isDebug) printf("found %d at:%d\n", T[it],find);
        //発見したら消す(-1に置き換える)
        if(find != -1) T[it] = -1;
        else fcount++;
    }
    
    int tempFcount = 0;
    for(int it = 0; it<Q; it++){
        if(T[it] != -1){
            tempFcount++;
            printf("%d", T[it]);
            if(fcount != tempFcount) printf(" ");
        }
    }
    printf("\n");

    printf("%d\n", fcount);
    return 0;
}
