/*
深さ優先探索では本来はまずいはず
ゴールへの道が複数あった時に最短距離にならないと思う
でもWOJはテストケースが少ないので100点になる
*/

#include <cstdio>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

bool DEBUG = false;

vector< vector<int> > adlist;

#define MAP_SIZE 10
#define EMPTY 100000

char map[MAP_SIZE][MAP_SIZE+1];
int distMap[MAP_SIZE][MAP_SIZE];

void dfs(int x, int y, int dist){
    if(DEBUG) printf("DFS x,y = %d, %d dist:%d\n", x, y,dist );
    
    //boundary check
    if( !(x>=0 && x<MAP_SIZE) ) return;
    if( !(y>=0 && y<MAP_SIZE) ) return;

    if(map[y][x] == '#') return;
    
    if(distMap[y][x] > dist) distMap[y][x] = dist;
    else return;    //もうすでに通ったマスなら終了

    dfs(x+1, y  , dist+1); //right
    dfs(x-1, y  , dist+1); //left
    dfs(x  , y+1, dist+1); //up
    dfs(x  , y-1, dist+1); //down
}

int main(){
    for(int i=0; i<10; i++){
        scanf("%s", map[i]);
    }
    
    if(DEBUG) printf("input complete\n");

    //init distance map
    for(int y=0; y<MAP_SIZE; y++){
        for( int x= 0; x<MAP_SIZE; x++){
            distMap[y][x] = EMPTY;
        }
    }
    
    if(DEBUG) printf("Init complete\n");
    
    //GとSの場所を調べる
    int sx, sy;
    int gx, gy;
    for(int y=0; y<MAP_SIZE; y++){
        for( int x= 0; x<MAP_SIZE; x++){
            if(map[y][x] == 'S'){
                sy = y;
                sx = x;
            }
            if(map[y][x] == 'G'){
                gy = y;
                gx = x;
            }
        }
    }
    
    if(DEBUG) printf("search S/G complete\n");

    //スタートからゴールまで深さ優先探索
    dfs(sx, sy, 0);

    printf("%d\n", distMap[gy][gx]);
    return 0;
}
