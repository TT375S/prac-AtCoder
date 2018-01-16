/*
隣接リストで友人関係を持ち、幅優先探索で調べ上げる
*/

#include<iostream>
#include<cstdio>
#include<vector>
#include <queue>
#include<cstdlib>

using namespace std;

//引数は隣接リスト、友人1,友人2
bool isFriend(vector< vector<int> > rel, int s, int t){
    bool *isChecked  = (bool *)malloc(rel[0].size() * sizeof(bool));
    for(int i=0; i<rel[0].size(); i++) isChecked[i] = false;

    queue<int> q;    
    q.push(s);

    //隣接リストを幅優先探索で調べていく
    while(!q.empty()){
        int current = q.front();
        q.pop();    

        if(current == t) return true;
        if(isChecked[current]) continue;

        isChecked[current] = true;
        for(int k=0; k<rel[current].size(); k++){
            if(isChecked[rel[current][k]]) continue;
            q.push(rel[current][k]);
        }
    }

    free(isChecked);
    return false;
}

int main(){
    int n_people, n_frel;
    cin >> n_people >> n_frel;

    vector< vector<int> > relList;

    relList.resize(n_people);    

    for(int i=0; i<n_frel; i++){
        int a, b;
        cin >> a>> b;
        relList[a].push_back(b);
        relList[b].push_back(a);
    }

    int s,t;
    cin >> s >> t;
    if(isFriend(relList, s, t)) printf("true\n");
    else printf("false\n");
}
