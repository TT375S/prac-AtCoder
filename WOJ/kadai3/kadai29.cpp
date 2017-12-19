//#include <bits/stdc++.h>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<iostream>

using namespace std;
bool DEBUG = false;

struct Tnode{
    int l, r;
    int parentId;
    int id;
};

vector<Tnode> nodes;

void preorder(vector<Tnode> nodes, int u){
    if(u == -1) return;
    printf(" %d", u);
    preorder(nodes, nodes[u].l);
    preorder(nodes, nodes[u].r);
}

void inorder(vector<Tnode> nodes, int u){
    if(u == -1) return;
    inorder(nodes, nodes[u].l);
    printf(" %d", u);
    inorder(nodes, nodes[u].r);
}

void postorder(vector<Tnode> nodes, int u){
    if(u == -1) return;
    postorder(nodes, nodes[u].l);
    postorder(nodes, nodes[u].r);
    printf(" %d", u);
}

int main(){
    int n;
    cin >> n;

    //init
    for(int i = 0; i< n; i++){
        Tnode tn;
        tn.parentId = -1;
        tn.l = -1;
        tn.r = -1;
        nodes.push_back(tn);
    }

    int ind_root = -1;

    //load
    for(int i=0; i<n; i++){
        int tid;
        cin >> tid;
        
        if(ind_root == -1) ind_root = tid;  //テストケース見ると先頭行が根みたい
        nodes[tid].id = tid; //idは使ってない

        int cid_l, cid_r;
        cin >> cid_l >> cid_r;
        if(DEBUG) printf("%d l:%d, r:%d\n", tid, cid_l, cid_r); 
        
        nodes[tid].l = cid_l;
        if(cid_l != -1)nodes[cid_l].parentId = tid; //pidも使ってない
        
        nodes[tid].r = cid_r;
        if(cid_l != -1)nodes[cid_r].parentId = tid;
    }
    
    printf("Preorder\n");
    preorder(nodes, ind_root);
    printf("\n");

    printf("Inorder\n");
    inorder(nodes, ind_root);
    printf("\n");

    printf("Postorder\n");
    postorder(nodes, ind_root);
    printf("\n");
    
    return 0;
}
