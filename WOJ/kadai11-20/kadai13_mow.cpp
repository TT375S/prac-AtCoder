#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;



#define MAX_W 1000
#define MAX_H 1000

int go(char map[MAX_H][MAX_W], int x, int y, int W, int H){
    //printf("(%d,%d) called\n", x, y);
    if(map[y][x] == '@'){

    }
    else if(map[y][x] != '.' ) return 0;
    int sum = 0;
    sum++;
    map[y][x] = '-';

    if (x+1 < W){
        sum += go(map, x+1, y, W, H);
    }
    if (x-1 >= 0){
        sum += go(map, x-1, y, W, H);
    }
    if (y-1 >= 0){
        sum += go(map, x, y-1, W, H);
    }
    if (y+1 < H){
        sum += go(map, x, y+1, W, H);
    }

    return sum;
}

int main(){
    int W, H;
    
    while(1){
        cin >> W >> H;
        if( W==0 && H==0) break;
        
        char map[MAX_H][MAX_W];
        int x, y;
        for(int Y=0; Y < H; Y++){
            //for(int X = 0; X < W; X++){
                cin >> map[Y];
            //}
//            printf("%s\n", map[Y]);            
        }

        for(int Y=0; Y<H; Y++){
            for(int X=0; X<W; X++){
                if(map[Y][X] == '@'){
                    x = X;
                    y = Y;
                    break;
                }
            }
        }

        //printf("x,y = %d, %d\n", x, y);

        int ans = 0;
        ans = go(map, x, y, W, H);
        printf("%d\n", ans);
    }
    return 0;
}
