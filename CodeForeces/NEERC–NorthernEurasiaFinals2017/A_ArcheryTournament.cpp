//============================================================================
// Name        : NEERC17_A_ArcheryTournament.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include<climits>
#include<algorithm>
using namespace std;

class SegmentTree {
public:
	int MAX_N;
	int n, *dat;

//セグメント木
	SegmentTree(int n_){
		MAX_N = 1<< 17;
		dat= (int *) malloc( (2*MAX_N -1) * sizeof(int) );
		init(n_);
	}

	~SegmentTree(){
		free(dat);
	}

	void init(int n_) {
		n = 1;
		//要素数を2のベキ乗にする
		while (n < n_)
			n *= 2;
		for (int i = 0; i < 2 * n - 1; i++)
			dat[i] = INT_MAX;
	}

//k番目をaに変更
	void update(int k, int a) {
		//葉のインデックス
		k += n - 1;
		dat[k] = a;
		//葉から根まで登りながら更新していく
		while (k > 0) {
			k = (k - 1) / 2;
			dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
		}
	}

	int query(int a, int b, int k, int l, int r){
		//範囲にまったく交差しなければ、影響ない数字を返す
		if(r<=a || b<= l) return INT_MAX;
		//完全に含んでいれば、そのノードの値
		if(a<=l && r <= b) return dat[k];
		//そうじゃないなら、子ノードから再帰的に求める
		else{
			int vl = query(a, b, k*2 +1, l, (l+r)/2);
			int vr = query(a, b, k*2 +2, (l+r)/2, r);
			return min(vl, vr);
		}
	}
};

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
