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

bool DEBUG =false;

struct Edge {
	long long from, to;
};

typedef pair<long long, long long> P;

void showVectrer(vector<long long> vec){
	for(int i=0; i<vec.size(); i++){
		printf("%lld ", vec[i]);

	}
	printf("\n");
}

void recDFS(long long ind_node, vector<P> edges[], bool isUsedNode[], vector<long long > &usedEdgeIndexList) {
	//if(isUsedNode == true) return;
	isUsedNode[ind_node] = true;
	if(DEBUG) printf("   %lld\n", ind_node+1);
	for (long long i_e = 0; i_e < edges[ind_node].size(); i_e++) {
		P p = edges[ind_node][i_e];
		if (DEBUG)			printf("%lld to %lld, isUsed:%d\n", ind_node + 1, p.first + 1,	isUsedNode[p.first]);
		if (isUsedNode[p.first] == false) {
			usedEdgeIndexList.push_back(p.second);
			//if (DEBUG)			printf("USE %lld to %lld  at %lld\n", edgeList[p.second].from+1, edgeList[p.second].to+1, p.second);
			if (DEBUG)			showVectrer(usedEdgeIndexList);
			recDFS(p.first, edges, isUsedNode, usedEdgeIndexList);
		}
	}
}

int vector_finder(std::vector<long long > vec, long long number) {
  auto itr = std::find(vec.begin(), vec.end(), number);
  size_t index = std::distance( vec.begin(), itr );
  if (index != vec.size()) { // 発見できたとき
    return 1;
  }
  else { // 発見できなかったとき
    return 0;
  }
}

int main() {
	long long times = 0;
	cin >> times;
	for (long long i_times = 0; i_times < times; i_times++) {
		long long n, m;
		cin >> n >> m;
		vector< P > G[MAX_V];
		vector< P > revG[MAX_V];
		vector<Edge> edgeList;

		for (long long i_road = 0; i_road < m; i_road++) {
			long long x, y;
			cin >> x >> y;
			//インデックスが0オリジン想定なのに入力は1オリジンだったりするのは気をつけろ
			x--;
			y--;
			G[x].push_back(make_pair(y, i_road));
			revG[y].push_back(make_pair(x, i_road));
			edgeList.push_back((Edge){x, y});

		}
		vector<long long> usedEdgeIndexList;
		bool *isUsedNode;
		isUsedNode = (bool *) malloc(n * sizeof(bool));

		memset(isUsedNode, false, n * sizeof(bool));
		//有向のスパニングツリー作成。0(市1)を根とする。使用した弧を記録する
		recDFS(0, G, isUsedNode, usedEdgeIndexList);
		if (DEBUG)printf("rev\n");
		memset(isUsedNode, false, n * sizeof(bool));
		recDFS(0, revG, isUsedNode, usedEdgeIndexList);

		free(isUsedNode);

		//long long lines = 1000;
		long long lines = m - 2 * n;

		//未使用の弧を削除する
		for (long long i_e = 0; i_e < m; i_e++) {
			if(!vector_finder(usedEdgeIndexList, i_e)){
				if(lines >= 1){
					lines--;
					printf("%lld %lld\n", edgeList[i_e].from+1, edgeList[i_e].to+1);
				}
			}
		}


	}
	return 0;
}

