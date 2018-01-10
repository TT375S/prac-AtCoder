#include <cstdio>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector< vector<int> > adlist;

int main(){
    int n;
    cin >> n;
    
    adlist.resize(n);
    for(int i=0; i<n; i++) adlist[i].resize(n);

    //Input adjacency list
    for(int i=0; i<n; i++){
        int ind_n, num_adjNode;
        cin >> ind_n >> num_adjNode;
        for(int k=0; k<num_adjNode; k++){
            int ind_adjNode;
            cin >> ind_adjNode;
            adlist[ind_n-1][ind_adjNode-1] = 1;   //index must be ZERO origin
        }
    }

    //Output adjacency matrix
    for(int row = 0; row < n; row++){
        for(int col = 0; col < n; col++){
            printf("%d", adlist[row][col]);
            if(col != n-1) printf(" ");
        }
        printf("\n");
    }
    
    return 0;
}
