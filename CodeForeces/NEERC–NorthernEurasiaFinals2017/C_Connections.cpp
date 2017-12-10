//============================================================================
// Name        : NEERC17_C_Connections.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
#include <climits>
#include <cstdio>
#include <cmath>
#include <queue>
#include <utility>
#include <stdlib.h>
#include <string.h>

using namespace std;

#define MAX_V 100000
#define EMPTY -1

bool DEBUG =true;

struct Edge {
	long long to;
	long long revInd;
	bool isUsed;
};

vector<long long> usedEdges;

void recDFS(long long ind_node, vector<Edge> edges[], bool isUsedNode[]) {
	//if(isUsedNode == true) return;
	isUsedNode[ind_node] = true;
	if(DEBUG) printf("   %d\n", ind_node+1);
	for (long long i_e = 0; i_e < edges[ind_node].size(); i_e++) {
		Edge &e = edges[ind_node][i_e];
		//if (DEBUG)			printf("%d to %d, isUsed:%d\n", ind_node + 1, e.to + 1,	isUsedNode[e.to]);
		if (isUsedNode[e.to] == false) {
			edges[ind_node][i_e].isUsed = true;
			recDFS(e.to, edges, isUsedNode);
		}
	}
}

//int vector_finder(std::vector<long long > vec, long long number) {
//  auto itr = std::find(vec.begin(), vec.end(), number);
//  size_t index = std::distance( vec.begin(), itr );
//  if (index != vec.size()) { // 発見できたとき
//    return 1;
//  }
//  else { // 発見できなかったとき
//    return 0;
//  }
//}

void showEdge(long long num_v, vector<Edge> *G) {
	for (int i_v = 0; i_v < num_v; i_v++) {
		for (int i_e = 0; i_e < G[i_v].size(); i_e++) {
			Edge &e = G[i_v][i_e];
			printf("%d to %d isUsed:%d\n", i_v + 1, e.to + 1, e.isUsed);
		}
	}
}

void revShowEdge(long long num_v, vector<Edge> *G) {
	for (int i_v = 0; i_v < num_v; i_v++) {
		for (int i_e = 0; i_e < G[i_v].size(); i_e++) {
			Edge &e = G[i_v][i_e];
			printf("%d to %d isUsed:%d\n", e.to + 1, i_v + 1, e.isUsed);
		}
	}
}

int main() {
	long long times = 0;
	cin >> times;
	for (long long i_times = 0; i_times < times; i_times++) {
		long long n, m;
		cin >> n >> m;
		vector<Edge> G[MAX_V];
		vector<Edge> revG[MAX_V];

		for (long long i_road = 0; i_road < m; i_road++) {
			long long x, y;
			cin >> x >> y;
			//インデックスが0オリジン想定なのに入力は1オリジンだったりするのは気をつけろ
			x--;
			y--;
			long long ind_G_rev = revG[y].size();
			long long ind_revG_rev = G[x].size();
			G[x].push_back((Edge ) { y, ind_G_rev, false });
			revG[y].push_back((Edge ) { x, ind_revG_rev, false });
			if (DEBUG){
				printf("input: %d to %d\n", x, y);
				printf("size: %d , %d\n", G[x].size(), revG[y].size());
				Edge &e = G[x][G[x].size()-1];
				Edge &re = revG[e.to][e.revInd];
				printf("%d to %d AND %d to %d\n", x, e.to, e.to, re.to);
				showEdge(n, G);
				printf("rev\n");
				showEdge(n, revG);
			}
		}

		bool *isUsedNode;
		isUsedNode = (bool *) malloc(n * sizeof(bool));

		memset(isUsedNode, false, n * sizeof(bool));
		//有向のスパニングツリー作成。0(市1)を根とする。使用した弧を記録する
		recDFS(0, G, isUsedNode);
		if (DEBUG)
			printf("rev\n");
		memset(isUsedNode, false, n * sizeof(bool));
		recDFS(0, revG, isUsedNode);

		free(isUsedNode);

		//long long lines = 1000;
		long long lines = m - 2 * n;
		//long long lines = INF;
		if (DEBUG)
			showEdge(n, G);
		if (DEBUG)
			printf("rev\n");
		if (DEBUG)
			revShowEdge(n, revG);

		//未使用の弧を削除する
		//deleteUnusedArc(V, G, revG, &lines);
		for (int i_v = 0; i_v < n; i_v++) {
			for (int i_e = 0; i_e < G[i_v].size(); i_e++) {
				Edge &e = G[i_v][i_e];
				Edge &re = revG[e.to][e.revInd];

				if (DEBUG){
					printf(" %d to %d\n", i_v+1, e.to+1);
					printf(" %d to %d   AND  %d to %d\n", i_v+1, e.to+1, e.to+1, re.to+1);
					printf("n %d to %d isUsed:%d\n", i_v + 1, i_e + 1,
							G[i_v][i_e].isUsed);
					printf("r %d to %d isUsed:%d\n", e.to + 1, i_e + 1,
							revG[e.to][i_e].isUsed);
				}

				if (e.isUsed == false
						&& re.isUsed == false) {
					if(lines <= 0)break;
					lines--;
					printf("%d %lld\n", i_v + 1, e.to + 1);
				}
			}
		}

		return 0;
	}
}

