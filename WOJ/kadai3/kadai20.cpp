#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;
bool DEBUG = false ;


void showArray(int A[], int N){
    for(int i=0; i<N; i++){
        printf("%d", A[i]);
        if(i != N-1) printf(" ");
    }
    printf("\n");
}

int pivot(int *a, int i, int j){
    int k= i+1;
    while(k<=j && a[i] == a[k]) k++;
    if(k>j) return -1;
    if(a[i] >= a[k]) return i;
    return k;
}

int c_part = 0;

int part(int *A, int il, int ir, int x){
    
    if(DEBUG) printf("CALL PART: [%d, %d) x:%d\n", il, ir, x);
    int l = il, r = ir;
    bool isParted = false;
    while(l<=r){
        //左はx以上の値を
        while(l <= ir && A[l] >= x) l++;
        //右はx未満の値を検索する
        while(r >=il && A[r] < x) r--;
        //if(DEBUG) printf("PART: cl:%d, cr:%d\n", l, r);
        if(l>r) break;

        //if(DEBUG) printf("PART: SWAP: l:%d, %d, r:%d,  %d\n", l,A[l], r, A[r]);
        //swap
        isParted = true;
        int t = A[l];
        A[l] = A[r];
        A[r] = t;
        
        l++;
        r--;
    }
    if(DEBUG) showArray(A, 4);
    if(DEBUG) printf("RET PART: l:%d, r:%d\n", l, r);
    if(isParted) c_part++;
    return l;
}

void quick_sort(int *A, int il, int ir){
    if(DEBUG)printf("CALL SORT: [%d,%d)\n", il, ir);
    if(il == ir) return;
    int ip = pivot(A, il, ir);
    if(ip == -1) return ;
    
    int l = part(A, il, ir, A[ip]);
    if(DEBUG)printf("index_p:%d\n", ip);
    if(DEBUG) printf("[%d,%d), [%d,%d)\n", il, l, l, ir);
    quick_sort(A, il, l-1);
    quick_sort(A, l, ir);
}

#define MAX_N

int main(){
    int n;
    cin >> n;
    int *A = (int *) malloc(n*sizeof(int));
    for(int i=0; i<n; i++){
        cin >> A[i];    
    }
    if(DEBUG)printf("test\n");
    quick_sort(A, 0, n-1);
    if(DEBUG)printf("test\n");
	showArray(A, n);
    free(A);
    printf("%d\n", c_part);
    return 0;
}
