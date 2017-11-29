#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <climits>

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

#define MAX_N 2000000
#define INF  INT_MAX
int N;
ll A[MAX_N];
void input(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
}

//void solve(){
//    ll maxDiff = -1*INF;
//    ll minR = INF;
//    for(int i_border = 1; i_border < N; i_border++){
//        //最小値更新
//        if(A[i_border-1] < minR){
//            minR = A[i_border-1];
//        }
//        
//        ll maxR = 0;
//        //最大値更新はO(N)だけかかってしまう？
//        for(int i_k=i_border; i_k < N; i_k++){
//            if(A[i_k] > maxR) maxR = A[i_k];
//        }
//
//        if(maxDiff < maxR-minR) maxDiff = maxR-minR;
//        if(isDebug) printf("%lld %lld %lld\n", minR, maxR, maxDiff);
//    }
//
//    printf("%lld\n", maxDiff);
//}
void solve(){
    ll maxDiff = -1*INF;
    ll minR = A[0];
    for(int i_border = 1; i_border < N; i_border++){
        
        if(maxDiff < A[i_border]-minR) maxDiff = A[i_border]-minR;
        if(isDebug) printf("%lld %lld\n", minR, maxDiff);
        
        //最小値更新
        if(A[i_border] < minR){
            minR = A[i_border];
        }
    }

    printf("%lld\n", maxDiff);
}

int main(){
    input();
    solve();
    return 0;
}
