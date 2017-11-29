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
            printf("%s %d\n", currentP.first.c_str(), elapsedTime);
        }else{
            pque.push(currentP);
        }
    }
}

int main(){
    input();
    solve();
    return 0;
}
