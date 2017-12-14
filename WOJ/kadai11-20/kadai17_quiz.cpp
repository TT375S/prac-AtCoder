#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;
bool DEBUG = false;

int max_ind_quiz;
int max_continuas_yes;

//引数は左から(いま回答中のクイズのインデックス), (回答状況でLSB側が最初のクイズ), (連続してyesと答えた数) , (その最大値)。
int judge(int ind_quiz, int state, int num_continuasiYes, int maxYes){
    
    int num_pat =0;
    
    if(DEBUG) printf("%d %d %d %d\n", ind_quiz, state, num_continuasiYes, maxYes);

    //クイズを最後まで回答してから判断    
    if(ind_quiz > max_ind_quiz) {
        if(maxYes >= max_continuas_yes) num_pat++;
        return num_pat;
    }

    
    num_pat += judge(ind_quiz+1, state, 0, maxYes);
    num_pat += judge(ind_quiz+1, state | (1<<ind_quiz), num_continuasiYes+1, max(num_continuasiYes+1, maxYes) );
    
    return num_pat;
}

int main(){
    cin >> max_ind_quiz;
    max_ind_quiz--;
    cin >> max_continuas_yes;

    printf("%d\n", judge(0, 0, 0, 0));


    return 0;
}
