/*
メモ化再帰でフィボナッチ数列を求める
*/

#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<vector>
#include<string.h>

using namespace std;

#define MAX_N 100000
#define EMPTY -1
int memo[MAX_N];

int fib(int n){
  //計算済みならそれを返す
  if(memo[n] != EMPTY) return memo[n];
  return memo[n] = fib(n-1) + fib(n-2);
}

int main(){
  memset(memo, -1, sizeof(memo));
  memo[0] = 1;
  memo[1] = 1;

  int n;
  cin >> n;
  for(int i=0; i <= n; i++){
    printf("%d", fib(i));
    if(i != n) printf(" ");
  }
  printf("\n");
  return 0;
}
