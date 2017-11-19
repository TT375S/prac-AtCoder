#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
#include <climits>
#include <cmath>
#include <queue>
#include <utility>
using namespace std;

#define MAX_V 10*10
#define INF INT_MAX/4
#define EMPTY -1

typedef pair<int, int> P;

struct edge {int to, cap, cost, rev;};
vector<edge> G[MAX_V];

struct node {int dist, prevV, prevE;};
vector<node> V;

int min_cost(int ind_startNode, int ind_endNode){
    //普通のダイクストラ法
    
    //ノード初期化。未到達の区別のため距離を無限で初期化さえすれば良い
    for(int i=0; i<V.size(); i++){
        V[i].dist = INF;
        V[i].prevV = EMPTY;
        V[i].prevE = EMPTY;
    }
    
    priority_queue<P, vector<P>, greater<P> > que;
    
    V[ind_startNode].dist = 0;
    que.push(P(0, ind_startNode));
    
    while(!que.empty()){
        //一番sからの距離の短いノードを取り出す
        P p = que.top(); que.pop();
        int ind_v = p.second;
        //queに追加された後に、distがより小さく更新されていたら、無視する
        if(V[ind_v].dist < p.first) continue;
        for(int ind_e = 0; ind_e < G[ind_v].size(); ind_e++){
            edge &e = G[ind_v][ind_e];
            bool isMinUpdatable = V[e.to].dist > V[ind_v].dist + e.cost;
            if(isMinUpdatable){
                V[e.to].dist = V[ind_v].dist + e.cost;
                V[e.to].prevV = ind_v;
                V[e.to].prevE = ind_e;
                que.push(P(V[e.to].dist, e.to));
            }
        }
    }
    
    //目的ノードまでの距離がINFなら到達できなかったということ
    if(V[ind_endNode].dist == INF){
        return -1;
    }
    
    return V[ind_endNode].dist;
}

void add_edge(int from, int to, int cap, int cost){
    int ind_rev_f = G[to].size();
    int ind_rev_b = G[from].size();
    
    G[from].push_back((edge){to, cap, cost, ind_rev_f});
    //G[to].push_back((edge){from, 0, -1*cost, ind_rev_b});
}

#define MAX_HW 200

int H, W;
int c[10][10];
int A[MAX_HW][MAX_HW];

void input(){
    cin >> H >> W;
    
    for(int i=0; i<10; i++){
        for(int k=0; k<10; k++){
            cin >> c[i][k];
            //隣接リストに変換
            add_edge(i, k, 0, c[i][k]);
        }
    }
    
    for(int i=0; i<H; i++){
        for(int k=0; k<W; k++){
            cin >> A[i][k];
        }
    }
}

int main(){
    input();
    int min_cost_to_1[10];
    //ノードは0~9までしかないので数は10固定
    V.resize(10);
    
    for(int i=0; i<10; i++){
        min_cost_to_1[i] = min_cost(i, 1);
    }
        
    int sum_cost = 0;
    for(int i=0; i<H; i++){
        for(int k=0; k<W; k++){
            //1か-1でない数字のときは、1への最小変換コストを積算
            if(A[i][k] != 1 && A[i][k] != -1){
                sum_cost += min_cost_to_1[A[i][k]];
            }
        }
    }
    
    printf("%d\n", sum_cost);
    
    return 0;
}

