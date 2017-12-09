//============================================================================
// Name        : CodF_NEERC20172018_B_Box.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

typedef long long ll;
using namespace std;

bool DEBUG  = false;

bool check(ll a, ll b, ll c, ll w, ll h){
	if(DEBUG) printf("a:%d b:%d c%d w:%d h:%d\n", a, b, c, w, h);
	if(DEBUG) printf("%d<=%d, %d<=%d\n", (2*a + 2*b) , h,  (b+2*c), w);
	if(DEBUG) printf("%d<=%d, %d<=%d\n\n", (a + c) , h,  (3*b + a + c), w);
	bool one = (2*a + 2*b) <= h && (c+2*b) <= w;
	bool two = (a + c) <=h && (3*b + a + c) <= w;
	return one || two;
}

bool permABC(ll a, ll b, ll c, ll w, ll h){
	bool isAbleToCreate = check(a, b, c, w, h) || check(b, a, c, w, h) || check(c, a, b, w, h) || check(a, c, b, w, h) || check(b, c, a, w, h) || check(c, b, a, w, h);
	return isAbleToCreate;
}

void solve(){
	ll a, b, c, w, h;
	cin >> a >> b >> c >> w >> h;
	if(DEBUG) printf("%d %d %d %d %d\n", a, b, c, w, h);
	bool isAbleToCreate = permABC(a, b, c, w, h) || permABC(a, b, c, h, w);
    if(isAbleToCreate) printf("Yes\n");
    else printf("No\n");
}

int main() {
	solve();
	return 0;
}
