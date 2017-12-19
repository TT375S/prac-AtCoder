#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <stack>
#include <string>
#include <utility>
#include <queue>
#include <algorithm>

typedef int type;
using namespace std;
const bool isDebug = true;

typedef pair<string, int> p;
queue<p> pque;

int n, q;

void input(){
    cin >> n >> q;
    for(int i=0; i<n; i++){
        string tmpName;
        int tmpTime;
        cin >> tmpName;
        cin >> tmpTime;
        
        pque.push(p(tmpName, tmpTime));     
    }
}

void showQue(){
    bool isEmpty = true;
    queue<p> subq;
    while(!pque.empty()){
        isEmpty = false;
        subq.push(pque.front());
        pque.pop();
    }
    while(!subq.empty()){
        p tempP = subq.front();
        printf("%s %d", tempP.first.c_str(), tempP.second);
        subq.pop();
        pque.push(tempP);
        if(!subq.empty()) printf(" ");
    }
    if(!isEmpty) printf("\n");
}

queue<p> finQ;

void solve(){
    int elapsedTime = 0;
    while(!pque.empty()){
        p currentP = pque.front();
        pque.pop();

        int deltaTime = min(currentP.second, q);
        currentP.second -= deltaTime;
        elapsedTime += deltaTime;

        if(isDebug){
            
            //printf("%s %d\n", currentP.first.c_str(), elapsedTime);
        }

        if(currentP.second  == 0){
            //if(isDebug)printf("%s %d\n", currentP.first.c_str(), elapsedTime);
            finQ.push(p(currentP.first, elapsedTime));
        }else{
            pque.push(currentP);
        }
        
        showQue();
    }
    while(!finQ.empty()){
        p tempP = finQ.front();
        finQ.pop();
        printf("%s %d", tempP.first.c_str(), tempP.second);
        if(!finQ.empty())printf(" ");
    }
    printf("\n");
}

int main(){
    input();
    solve();
    return 0;
}
