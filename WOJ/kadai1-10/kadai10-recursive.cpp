#include <cstdio>
#include <iostream>
#include <cstdlib>

typedef long long ll;

ll recPow(ll n){
    if(n <= 1) return 1;
    
    return n*recPow(n-1);
}

int main(){
    int n;
    std::cin>>n;
    printf("%lld\n", recPow(n));
    return 0;
}
