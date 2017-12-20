/*
LCS
DNAの配列の最長共通部分列の長さを求める問題
動的計画法
*/

#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;
bool DEBUG = true;

const int MAX_LEN = 1001;

void showMat(vector< vector<int> > mat){
  for(int y = 0; y < mat.size(); y++){
    for(int x = 0; x < mat[0].size(); x++){
      printf("%d ", mat[y][x]);
    }
    printf("\n");
  }
}

void solve(){
  string A;
  string B;
  cin >> A;
  cin >> B;

  //dp[b][a]は、Bのb文字目、Aのa文字目までを見たときの最長共通部分列の長さ
  vector< vector<int> > dp(B.size()+1, vector<int> (A.size()+1,0) );
  
  //iB,iAはdp行列のインデックスではなく、文字列のインデックス
  for(int iB = 0; iB < B.size(); iB++){
    for(int iA = 0; iA < A.size(); iA++){
      int ans = 0;
      //文字が一致してる時は斜め上の数字に+1
      if(A.c_str()[iA] == B.c_str()[iB]) {
        dp[iB+1][iA+1] = 1 + dp[iB+1 -1][iA+1 -1];
      }
      //文字が一致してないときは、左か上の数字のどちらか大きい方
      else{
        dp[iB+1][iA+1] = max(dp[iB+1 -1][iA+1], dp[iB+1][iA+1 -1]);
      }
    }
  }
  if(DEBUG) showMat(dp);
  printf("%d\n", dp[B.size()][A.size()]);
}

int main(){
  solve();
  return 0;
}

