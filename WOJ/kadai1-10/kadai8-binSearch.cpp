#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>

typedef int type;
typedef long long ll;
using namespace std;
const bool isDebug = false;

void showArray(type A[], int N){
    for(int i=0; i<N; i++){
        printf("%d", A[i]);
        if(i != N-1) printf(" ");
    }
    printf("\n");
}

int binarySearch(type A[], int N, int target){
    ll left = 0, right = N;
    while(left < right){
        ll mid = (left+right)/2;
        if(A[mid] == target){
            return mid;
        }else if(target < A[mid]){
            right = mid;
        }else{
            left = mid + 1;
        }
    }
    return -1;
}


#define MAX_N 100000
#define MAX_Q 50000
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
    std::sort(A, A+N);
    for(int it = 0; it<Q; it++){
        int find = binarySearch(A, N, T[it]);
        if(isDebug) printf("found %d at:%d\n", T[it],find);
        //発見したら消す(-1に置き換える)
        if(find != -1) T[it] = -1;
        else fcount++;
    }
    
    int tempFcount = 0;
    for(int it = 0; it<Q; it++){
        if(T[it] != -1){
            tempFcount++;
            if(isDebug)printf("index at:%d\n", it);
            printf("%d", T[it]);
            if(fcount != tempFcount) printf(" ");
        }
    }
    printf("\n");

    printf("%d\n", fcount);
    return 0;
}
