#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<algorithm>

using namespace std;

bool DEBUG = false;

void showArray(int A[], int N){
    for(int i=0; i<N; i++){
        printf("%d", A[i]);
        if(i != N-1) printf(" ");
    }
    printf("\n");
}

//[p,r]の範囲を、A[0]で分割。左側にA[0]以下のもの、A[0]、右側にA[0]より大きいもの、に並べる
int partition(int A[], int p, int r){
    int i_pivot = 0;
    int x = A[i_pivot];
    int i = p-1;    //最後に見たA[0]以下のもののインデックス
    for(int j=p; j<=r; j++){
        if(A[j]<=x){
            i = i+1;    //交換すべき対象は、最後に見たA[0]以下のものの次のもの。だから+1する
            if(DEBUG)printf("swap A[%d]: %d, A[%d]: %d\n", i, A[i],j, A[j]);
            swap(A[i], A[j]);   
        }
        if(DEBUG) showArray(A, 4);
    }
    //最後に、x自身を2つのグループの境目に入れる
    swap(A[i], A[i_pivot]);
    if(DEBUG) showArray(A, 4);
    return i+1;
}

int main(){
    int n;
    cin >> n;
    int *A;
    A = (int *)malloc(n * sizeof(int));
    for(int i= 0; i< n; i++){
        cin >> A[i];
    }

    int mid = partition(A, 0, n-1);

    if(DEBUG)printf("All\n");
    showArray(A, n);	
    printf("%d\n", mid);
    
    free(A);
    return 0;
}
