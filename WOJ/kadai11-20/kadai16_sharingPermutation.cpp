#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;
bool DEBUG = true;

/*
「分担の仕方の数」だと、与えられたテストケース 3 2 を想定して
課題A,B,Cがあったとして山田と佐藤で分担すると、それぞれ(A,BC), (AB,C), (B,AC), (C, AB), (BC, A)...と確実に2個以上ある。
ので「課題の分担数の組みわわせ」だと思う
これだと山田と佐藤で(1, 2), (2, 1)しかないので2個になる
*/

//左から、引数は(残り課題数)、(現在、課題の個数を選んでいる人間のインデックス1オリジン)、(全課題数)、(全人間数)
int judge(int m, int n, int M, int N){
    if(DEBUG) printf("m:%d n:%d\n", m, n);
    
    if(n == 0){ 
        //全員が選び終わったかつ、全部の課題が誰かに選ばれた場合のみが有効
        if(m == 0)return 1;
        else return 0;
    }

    int num_pat=0;
    int remainMan = n-1;    //まだ課題数を選んで無い人数

    //インデックスnの人間は、やる課題の個数を1~ m -i_m個から決める。例えば、5個の課題を3人に割り振られたなら、インデックス3の人間が選べる個数は1~(5-2)である。
    for(int i_m=1; (m - i_m) >= remainMan; i_m++){
        //今回インデックスnの人間が、i_m個ぶん課題をやることにした。
        //残りの人間であるremainMan人はe、m -i_m個以下から何個やるか選ぶ。
        num_pat += judge(m - i_m, remainMan, M, N);    
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
