#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <stack>
#include <string>

typedef int type;
using namespace std;
const bool isDebug = false;


stack<int> numstack;
void showStack(){
    stack<int> substack;
    while(!numstack.empty()){
        
        substack.push(numstack.top());
        numstack.pop();
    }
    
    while(!substack.empty()){
        int temp = substack.top();
        printf("%d ", temp);
        substack.pop();
        numstack.push(temp);
    }
    printf("\n");
}
void solve(){
    string s;
    while(cin>>s){
        
        //int n = std::stoi(s);
        int n = atoi(s.c_str());
        if(isDebug)printf("n:%d\n", n);
        bool isNum =!(strcmp(s.c_str(), "0") != 0 && n == 0); 
        if(isDebug)printf("input:%s\n", s.c_str());
        if(isDebug)printf("isNum:%d\n", isNum);
        if(isNum){
            numstack.push(n);
            if(isDebug)printf("isNum!\n");
        }
        else{
        if(isDebug)printf("here!\n");
            if(s.c_str()[0] == '=') break;
            int b = -1, a = -1;
            if(!numstack.empty()){
                if(isDebug)printf("empty!\n");
                b = numstack.top();
                numstack.pop();
            }
            if(!numstack.empty()){
                if(isDebug)printf("empty!\n");
                a = numstack.top();
                numstack.pop();
            }
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
                    if(isDebug)printf("ERRRRRR\n");
                    break;
            }
        }
        if(isDebug)printf("showstack\n");
        showStack();
    }

    //int ans = numstack.top();
    //numstack.pop();
    //printf("%d\n", ans);
}



int main(){
    solve();
    return 0;

}
