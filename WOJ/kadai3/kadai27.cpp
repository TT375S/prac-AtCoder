//#include <bits/stdc++.h>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<iostream>


using namespace std;

struct Tnode{
    vector<int> childlenId;
    int parentId;
    int id;
};

vector<Tnode> nodes;

//根を返す
int root(vector<Tnode> nodes){
    int ind_current = 0;
    while(nodes[ind_current].parentId != -1) ind_current++;
    return ind_current;
}

//深さを調べる
int depth(vector<Tnode> nodes, int ind_current, int ind_target, int _depth){
    printf("CALL DEPTH: root:%d, tag:%d, dep:%d\n", ind_current, ind_target, _depth);
    if(ind_current == ind_target) return _depth;

    for(int ic = 0; ic < nodes[ind_current].childlenId.size(); ic++){
        int d = depth(nodes, nodes[ind_current].childlenId[ic], ind_target, _depth+1);
        if(d != -1) return d;
    }

    return -1;
}

int main(){
    int n;
    cin >> n;

    //init
    for(int i = 0; i< n; i++){
        Tnode n;
        n.parentId = -1;
        nodes.push_back(n);
    }

    //load
    for(int i=0; i<n; i++){
        int tid, n_child;
        
        cin >> tid >> n_child;
        nodes[tid].id = tid; //idは使わない(入力が接点番号順だったから)

        //子を格納
        for(int ic = 0; ic < n_child; ic++){
            int cid;
            cin >> cid;
            nodes[tid].childlenId.push_back(cid);
            nodes[cid].parentId = tid;
        }
    }
    
    int ind_root = root(nodes);

    for(int i=0; i < n; i++){
        printf("%d %d %d\n", i, nodes[i].parentId, depth(nodes, ind_root, i, 0));
    }
    
    return 0;
}
