#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

bool DEBUG = false;

char charcters[10][6] = {
                "",
                ".,!? ", 
                "abc",
                "def",
                "ghi",
                "jkl",
                "mno",
                "pqrs",
                "tuv",
                "wxyz" };

int clen[10] = {0, 5, 3, 3, 3, 3, 3, 4, 3, 4};

int main(){
    int lines;
    cin >> lines;
    while(lines--){
        string line;
        cin >> line;
        if(DEBUG)printf("%s\n", line.c_str());
        
        int i_l = 0;
        while(line.c_str()[i_l] != '\0' ){
            int pTimes = -1;
            char button = '-';
            bool isFirst = true;
            while(1){
                if(DEBUG)printf("pTimes:%d, button:%d\n", pTimes, button-'0');
                char temp = line.c_str()[i_l++];
                if(temp == '0'){ 
                    if(pTimes == -1){
                        break;
                    }else{
                        if(DEBUG)printf("OUTPUT:pTimes:%d, button:%d\n", pTimes, button-'0');
                        printf("%c", charcters[button - '0'][pTimes]);
                        break;
                    }
                }

                button = temp;
                
                if(isFirst){ 
                    pTimes = 0;
                    isFirst = false;
                }
                else pTimes++;
                pTimes = pTimes % clen[button-'0'];

            }
        }
        printf("\n");
    }

    return 0;
}
