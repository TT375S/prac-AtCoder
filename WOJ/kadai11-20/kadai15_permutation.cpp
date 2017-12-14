#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;


bool judge(int i, int m, int n, int A[]){
    if(m==0) return true;
    if(i >= n) return false;

    return judge(i+1, m, n, A) || judge(i+1, m-A[i], n, A);
}

#define MAX_n 20
#define MAX_q 2000
int main(){
    int n, q;
    int A[MAX_n], M[MAX_q];

    cin >> n;
    for(int i=0; i<n;i++){
        cin >> A[i];
    }
    cin >> q;
    for(int i=0; i<q;i++){
        cin >> M[i];
        
        if(judge(0, M[i], n, A)){
            printf("true\n");
        }else printf("false\n");
    }



    return 0;
}
