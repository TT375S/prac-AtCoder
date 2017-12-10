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
#define INF INT_MAX/4
#define EMPTY -1

bool DEBUG = false;

typedef pair<int, int> P;

struct Edge {
	int to, cap, cost, rev;
	bool isUsed;
};
vector<Edge> G[MAX_V];
vector<Edge> revG[MAX_V];

struct Node {
	int dist, prevV, prevE;
};
vector<Node> V;

//DFSで有向スパニングツリーを作成。使用済み枝を記録
void dfs(vector<Node> nodes, vector<Edge> edges[]) {
	bool *isUsedNode;
	isUsedNode = (bool *) malloc(nodes.size() * sizeof(bool));
	memset(isUsedNode, false, nodes.size() * sizeof(bool));

	isUsedNode[0] = true;

	for (int i_v = 0; i_v < nodes.size(); i_v++) {
		for (int i_e = 0; i_e < edges[i_v].size(); i_e++) {
			Edge &e = edges[i_v][i_e];
			//到達済みなら何もしない
			if (isUsedNode[e.to] == true)
				continue;
			//ノードに到達したことにする
			isUsedNode[e.to] = true;
			e.isUsed = true;
		}
	}

	free(isUsedNode);
}

//使用されなかった枝(弧)を削除
void deleteUnusedArc(vector<Node> nodes, vector<Edge> edges[], bool isRev, int *lines) {
	for (int i_v = 0; i_v < nodes.size(); i_v++) {
		for (int i_e = 0; i_e < edges[i_v].size(); i_e++) {
			Edge &e = edges[i_v][i_e];
			//未使用なら削除する。
			if (e.isUsed == false && *lines >= 1) {
				(*lines) --;
				if (!isRev)
					printf("%d %d\n", i_v, e.to);
				else
					printf("%d %d\n", e.to, i_v);
			}
		}
	}
}

void add_edge(int from, int to, int cap, int cost) {
	int ind_rev_f = revG[to].size();
	int ind_rev_b = G[from].size();
	//コストとキャパは使わないが削除が面倒なので残している
	G[from].push_back((Edge ) { to, cap, cost, ind_rev_f, false });
	revG[to].push_back((Edge ) { from, 0, -1 * cost, ind_rev_b, false });
}

int main() {
	int times = 0;
	cin >> times;
	for (int i_times = 0; i_times < times; i_times++) {
		int n, m;
		cin >> n >> m;

		if(DEBUG) printf("INPUT: n:%d m:%d\n",n, m);

		V.resize(n);
		for (int i_road = 0; i_road < m; i_road++) {
			int x, y;
			cin >> x >> y;
			if(DEBUG) printf("INPUT:i:%d x:%d y:%d\n", i_road, x, y);
			//コストとキャパは使わないが削除が面倒なので残している
			add_edge(x, y, 1, 0);
		}

		//有向のスパニングツリー作成。使用した弧を記録する
		dfs(V, G);
		dfs(V, revG);

		int lines = m - 2*n;
		if(DEBUG) printf("lines:%d\n", lines);

		//未使用の弧を削除する
		deleteUnusedArc(V, G, false, &lines);
		deleteUnusedArc(V, revG, true, &lines);

		return 0;
	}
}

