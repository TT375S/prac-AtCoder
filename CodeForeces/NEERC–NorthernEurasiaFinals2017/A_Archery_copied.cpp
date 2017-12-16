/*
Cited from http://blog.csdn.net/wxh010910/article/details/78775765
*/

#include <bits/stdc++.h>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back
#define mset(x, y) memset(x, y, sizeof x)
#define mcpy(x, y) memcpy(x, y, sizeof x)
using namespace std;

typedef long long LL;
typedef pair <int, int> pii;

//数字を１文字受け取る。iostreamは遅いから避けた？
inline int Read()
{
    int x = 0, f = 1, c = getchar();
    for (; !isdigit(c); c = getchar())
        if (c == '-')
            f = -1;
    for (;  isdigit(c); c = getchar())
        x = x * 10 + c - '0';
    return x * f;
}

const int MAXN = 200005;

//n=クエリ行数、m=圧縮後の座標数、(x,y)=クエリのx,y座標, opt=クエリの種別t_iに対応、l=圧縮後の座標(のインデックス)
int n, m, x[MAXN], y[MAXN], opt[MAXN], l[MAXN << 1];
//X=座標圧縮後のx座標のインデックス、S[X]はx=X?の直線と交わる円たち(のクエリ行インデックス)をもつ順列つき集合。
set <int> s[MAXN << 3];

//x=検索開始位置、[l,r]=対象区間l,r, [q,l]=クエリ区間ql, qr, v=挿入したいクエリ行インデックス
inline void Insert(int x, int l, int r, int ql, int qr, int v)
{
    //そのノードがクエリ区間とピッタリ一致する    
    if (l == ql && r == qr)
        return (void)s[x].insert(v);
    int mid = l + r >> 1;
    //クエリ区間が右の子か左の子か(が担当する区間)にきっぱり分けられる場合
    if (qr <= mid)
        //左の子ノードはインデックス(x * 2)。
        Insert(x << 1, l, mid, ql, qr, v);
    else if (ql > mid)
        //右の子ノードはインデックス(x * 2 + 1)。
        Insert(x << 1 | 1, mid + 1, r, ql, qr, v);
    //クエリ区間が右の子と左の子にまたがる場合
    else
        //左の子には区間[ql, mid)、右の子には区間[mid+1, qr)をインサート
        Insert(x << 1, l, mid, ql, mid, v), Insert(x << 1 | 1, mid + 1, r, mid + 1, qr, v);
}

//x=検索開始位置、[l,r]=対象区間l,r, [q,l]=クエリ区間ql, qr, v=検索したいクエリ行インデックス
inline void Erase(int x, int l, int r, int ql, int qr, int v)
{
    if (l == ql && r == qr)
        return (void)s[x].erase(v);
    int mid = l + r >> 1;
    if (qr <= mid)
        Erase(x << 1, l, mid, ql, qr, v);
    else if (ql > mid)
        Erase(x << 1 | 1, mid + 1, r, ql, qr, v);
    else
        Erase(x << 1, l, mid, ql, mid, v), Erase(x << 1 | 1, mid + 1, r, mid + 1, qr, v);
}

//x=検索開始位置(座標圧縮後のx座標のインデックスで指定)、[l,r]=対象区間l,r, p=座標圧縮後のx座標(のインデックス)、v=検索したいクエリ行インデックス
inline int Query(int x, int l, int r, int p, int v)
{
    //x軸に平行な直線と交わる円の順序つき集合から一個ずつ、クエリ行インデックスを取り出し、条件に合うか判定する。
    for (auto i : s[x])
        //iがマトのクエリ行インデックス、vが着弾点のクエリ行インデックス。当たってる場合はマトのインデックス
        if (1LL * (::x[i] - ::x[v]) * (::x[i] - ::x[v]) + 1LL * (y[i] - y[v]) * (y[i] - y[v]) < 1LL * y[i] * y[i])
            return i;
    //ヒットするマトが何もなかった、かつココがセグメント木の葉の場合。
    if (l == r)
        return 0;
    int mid = l + r >> 1;
    //左の子か右の子を探しに行く。探したいx座標(座標圧縮後のインデックス)を含む区間を担当している方の子を見に行く
    return p <= mid ? Query(x << 1, l, mid, p, v) : Query(x << 1 | 1, mid + 1, r, p, v);
}

int main()
{
#ifdef wxh010910
    freopen("data.in", "r", stdin);
#endif
    n = Read();
    for (int i = 1; i <= n; i ++)
    {
        //一行ずつ読み、座標を座標圧縮用配列lに保存
        opt[i] = Read(), x[i] = Read(), y[i] = Read();
        if (opt[i] == 1)
            l[++ m] = x[i] - y[i], l[++ m] = x[i] + y[i];
        else
            l[++ m] = x[i];
    }
    //座標圧縮。m=座標圧縮後の座標数
    sort(l + 1, l + m + 1), m = unique(l + 1, l + m + 1) - l - 1;
    //iはクエリ行インデックス
    for (int i = 1, r; i <= n; i ++)
        if (opt[i] == 1)
            //ターゲット追加は、x=1, [l,r] = [1,m], ql=座標圧縮後の円左端のx座標(というかインデックス)、qr=座標圧縮のちの円右端のx座標(というかインデックス), v=クエリ行インデックスi、
            Insert(1, 1, m, lower_bound(l + 1, l + m + 1, x[i] - y[i]) - l, lower_bound(l + 1, l + m + 1, x[i] + y[i]) - l, i);
        else if (r = Query(1, 1, m, lower_bound(l + 1, l + m + 1, x[i]) - l, i))
            //見つかったら削除する
            printf("%d\n", r), Erase(1, 1, m, lower_bound(l + 1, l + m + 1, x[r] - y[r]) - l, lower_bound(l + 1, l + m + 1, x[r] + y[r]) - l, r);
        else
            puts("-1");
    return 0;
}
