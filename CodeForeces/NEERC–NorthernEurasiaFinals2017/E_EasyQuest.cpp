#include<iostream>
#include<queue>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

bool DEBUG = true;

void showArray(vector<int> items){
    for(int i=0; i<items.size(); i++){
        printf("%d", items[i]);
        if(i != items.size()-1) printf(" ");
    }
    printf("\n");
}

void DEBUGPRINT(vector<int> array, int a){
    if(!DEBUG) return;
    printf("a:%d\n", a);
    showArray(array);
}

int main(){
    int n;
    cin >> n;
    vector<int> items;
    int wildcard = 0;
    vector<int> unicornItems;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        //benevolent monster
        if(a > 0){
            items.push_back(a);
        }
        //unicorn
        else if(a == 0){
            wildcard ++;
        }
        //evil monster
        else{
            a *= -1;
            sort(items.begin(), items.end());
            //Hero had correct item
            if(binary_search(items.begin(), items.end(), a)){
                int ind = lower_bound(items.begin(), items.end(), a) - items.begin(); 
                items.erase(items.begin() + ind);
            }else{
                //Hero had unicornItem
                if(wildcard >= 1){
                    wildcard--;
                    unicornItems.push_back(a);
                }else{
                    printf("No\n");
                    return 0;
                }
            }
        }
        DEBUGPRINT(items, a);
        if(DEBUG) printf("unicorn: ");
        if(DEBUG) showArray(unicornItems);
    }
    printf("Yes\n");
    showArray(unicornItems);
    return 0;
}

