#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <map> 

typedef int type;
using namespace std;
const bool isDebug = false;

void showArray(type A[], int N){
    for(int i=0; i<N; i++){
        printf("%d", A[i]);
        if(i != N-1) printf(" ");
    }
    printf("\n");
}

//int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}

//int hash(string s){
//    int ret=0;
//    for(int i=0; i<s.size(); i++){
//        ret += 
//    }
//}

void solve(){
    int N;
    cin >> N;
    map<string, string> dict;
    for(int i = 0; i<N; i++){
        string command;
        cin >> command;
        string operand;
        switch(command.c_str()[0]){
            case 'a':
                break;
            case 'r':
                break;
            case 'f':
                break;   
        }
    }
}

int main(){
    return 0;
}
