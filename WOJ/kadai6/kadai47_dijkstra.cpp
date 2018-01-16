#include <vector>
#include <iostream>
#include <algorithm>
//#include <random>
#include <climits>
#include <cmath>
#include <queue>
#include <utility>
using namespace std;

#define MAX_V 100
#define INF INT_MAX/4
#define EMPTY -1

//最小費用流を求める...を利用して普通にダイクストラ法でコストが安い経路を見つける
class minFlow{
public:
    typedef pair<int, int> P;

    struct edge {int to, cap, cost, rev;};
    vector<edge> G[MAX_V];

    struct node {int dist, prevV, prevE;};
    vector<node> V;

    //エッジ配列を変更してしまうので、複数回使えない.事前にコピーするなりして引数で渡すようにしたほうが良いが面倒なので放置
    int min_cost_flow(int ind_startNode, int ind_endNode, int flow){
        int res = 0;

        //流量が規定に到達するまで流せる経路を繰り返し探してそこに流す
        while(flow > 0){
            //ダイクストラ法
            
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
                    bool isFlowable = e.cap > 0;
                    bool isMinUpdatable = V[e.to].dist > V[ind_v].dist + e.cost;
                    if(isFlowable && isMinUpdatable){
                        V[e.to].dist = V[ind_v].dist + e.cost;
                        V[e.to].prevV = ind_v;
                        V[e.to].prevE = ind_e;
                        que.push(P(V[e.to].dist, e.to));
                    }
                }
            }

            //目的ノードまでの距離がINFなら到達できなかったということ        
            if(V[ind_endNode].dist == INF){
                //規定流量に満たないので不可能として-1を返す
                return -1;
            }

            //経路の最小容量を求める
            int d = flow;
            for(int ind_v = ind_endNode; ind_v != ind_startNode; ind_v = V[ind_v].prevV){
                d = min(d, G[ V[ind_v].prevV][V[ind_v].prevE].cap);
            }

            flow -= d;
            //通信料金は 毎秒の通信サイズ*通信料単価
            res += d*V[ind_endNode].dist;

            //辺の容量を更新
            for(int ind_v = ind_endNode; ind_v != ind_startNode; ind_v = V[ind_v].prevV){
                edge &e = G[ V[ind_v].prevV][V[ind_v].prevE]; 
                e.cap -= d;
                G[ind_v][e.rev].cap += d;
            }
        }

        //今回は普通にコストの合計を返す
        //return res;
        return V[ind_endNode].dist;
    }

    void add_edge(int from, int to, int cap, int cost){
        int ind_rev_f = G[to].size();
        int ind_rev_b = G[from].size();

        G[from].push_back((edge){to, cap, cost, ind_rev_f});
        G[to].push_back((edge){from, 0, -1*cost, ind_rev_b});
    }
};

int main(){
    int LINES;
    cin >> LINES;
  
    //上の最小費用流は、エッジを改変してしまう。エッジ配列をコピーして使えば良いが、面倒なので、クラスにして複数持つ  
    vector<minFlow> mfs;
    mfs.resize(LINES);
    
    for(int i=0; i<LINES; i++) mfs[i].V.resize(LINES+1);

    for(int i = 0; i< LINES; i++){
        int currentNode, n_road;
        cin >> currentNode >> n_road;
        for(int i_r = 0; i_r < n_road; i_r++){
            int nextNode, cost;
            cin >> nextNode >>  cost;
            for(int k=0; k<LINES; k++) mfs[k].add_edge(currentNode, nextNode, 1, cost);
        }
    }
    for(int i=0; i<LINES; i++){
        printf("%d %d\n", i, (int)mfs[i].min_cost_flow(0, i, 1));
    }

    return 0;
}
