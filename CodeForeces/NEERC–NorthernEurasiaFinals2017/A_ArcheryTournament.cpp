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

//RMQ
class SegmentTree {
protected:
	int MAX_N;
	long long n;
	long long *dat;
public:
//セグメント木
	SegmentTree(int n_) {
		MAX_N = 1 << 17;
		dat = (long long *) malloc((2 * MAX_N - 1) * sizeof(int));
		init(n_);
	}

	~SegmentTree() {
		free(dat);
	}

	void init(int n_) {
		n = 1;
		//要素数を2のベキ乗にする
		while (n < n_)
			n *= 2;
		for (long long i = 0; i < 2 * n - 1; i++)
			dat[i] = LLONG_MAX;
	}

//k番目をaに変更
	void update(long long k, long long a) {
		//葉のインデックス
		k += n - 1;
		dat[k] = a;
		//葉から根まで登りながら更新していく
		while (k > 0) {
			k = (k - 1) / 2;
			dat[k] = min(dat[k * 2 + 1], dat[k * 2 + 2]);
		}
	}

	long long query(long long  a, long long b, long long k, long long l, long long r) {
		//範囲にまったく交差しなければ、影響ない数字を返す
		if (r <= a || b <= l)
			return LLONG_MAX;
		//完全に含んでいれば、そのノードの値
		if (a <= l && r <= b)
			return dat[k];
		//そうじゃないなら、子ノードから再帰的に求める
		else {
			long long vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
			long long vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
			return min(vl, vr);
		}
	}
};
//Max
class MaxSegmentTree {
protected:
	int MAX_N;
	long long n;
	long long *dat;
public:
//セグメント木
	MaxSegmentTree(int n_) {
		MAX_N = 1 << 17;
		dat = (long long *) malloc((2 * MAX_N - 1) * sizeof(int));
		init(n_);
	}

	~MaxSegmentTree() {
		free(dat);
	}

	void init(int n_) {
		n = 1;
		//要素数を2のベキ乗にする
		while (n < n_)
			n *= 2;
		for (long long i = 0; i < 2 * n - 1; i++)
			dat[i] = -1* LLONG_MAX;
	}

//k番目をaに変更
	void update(long long k, long long a) {
		//葉のインデックス
		k += n - 1;
		dat[k] = a;
		//葉から根まで登りながら更新していく
		while (k > 0) {
			k = (k - 1) / 2;
			dat[k] = max(dat[k * 2 + 1], dat[k * 2 + 2]);
		}
	}

	long long query(long long  a, long long b, long long k, long long l, long long r) {
		//範囲にまったく交差しなければ、影響ない数字を返す
		if (r <= a || b <= l)
			return -1*LLONG_MAX;
		//完全に含んでいれば、そのノードの値
		if (a <= l && r <= b)
			return dat[k];
		//そうじゃないなら、子ノードから再帰的に求める
		else {
			long long vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
			long long vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
			return max(vl, vr);
		}
	}
};

int main() {
	MaxSegmentTree T(2*100000);

	int num_line;
	cin >> num_line;
	while(num_line--){
		long long  t, x, y;
		cin >> t >> x >> y;
		if(t==1){

		}
	}
	}
	return 0;
}
