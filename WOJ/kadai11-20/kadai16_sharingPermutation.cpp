#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;
bool DEBUG = true;

/*
「分担の仕方の数」だと、与えられたテストケース 3 2 を想定して
課題A,B,Cがあったとして山田と佐藤で分担すると、それぞれ(A,BC), (AB,C), (B,AC), (C, AB), (BC, A)...と確実に2個以上ある。
*/

int judge(int m, int n, int M, int N){
    if(DEBUG) printf("m:%d n:%d\n", m, n);
   
    if(n == 1) return 1;

    int num_pat=0;
    
    for(int i_m=1; i_m < M-N; i_m++){
        num_pat += judge(i_m, n-1, M, N);
    }

    return num_pat; 
}


#define MAX_n 20
#define MAX_q 2000
int main(){
    int M, N;
    cin >> M >> N;
    
    int all = judge(M, N, M, N);
    
    printf("%d\n", all);
    
    return 0;
}
