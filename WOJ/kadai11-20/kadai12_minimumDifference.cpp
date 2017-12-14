#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define MAX_A 10000

int main(){
    int A[MAX_A];
    int n;
    while(cin >> n){
        if(n==0) break;
        int i = n;
        for(i=0; i< n;i++){
            cin >> A[i];
            
        }
        sort(A, A+n);
        int minDiff=1000000;
        for(i=1;i<n;i++){
            if(minDiff > A[i]-A[i-1]){
                minDiff = A[i] - A[i-1];
            }
        }
        printf("%d\n", minDiff);
    }
    return 0;
}
