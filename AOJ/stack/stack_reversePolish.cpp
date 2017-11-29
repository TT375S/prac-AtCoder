#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <stack>
#include <string>

typedef int type;
using namespace std;
const bool isDebug = false;


stack<int> numstack;
void solve(){
    string s;
    while(cin>>s){
        try{
            //int n = std::stoi(s);
            int n = stoi(s);
            numstack.push(n);
        }
        catch (...){
            int b = numstack.top();
            numstack.pop();
            int a = numstack.top();
            numstack.pop();
            int ans = 0;
            switch(s.c_str()[0]){
                case '+':
                    ans = a + b;
                    if(isDebug) printf("%d = %d + %d\n", ans, a, b);
                    numstack.push(ans);
                    break;
                case '-':
                    ans = a - b;
                    if(isDebug) printf("%d = %d - %d\n", ans, a, b);
                    numstack.push(ans);
                    break;
                case '*':
                    ans = a * b;
                    if(isDebug) printf("%d = %d * %d\n", ans, a, b);
                    numstack.push(ans);
                    break;
                default:
                    printf("ERRRRRR\n");
                    break;
            }
            continue;
        }
    }

    int ans = numstack.top();
    numstack.pop();
    printf("%d\n", ans);
}

int main(){
    solve();
    return 0;

}
