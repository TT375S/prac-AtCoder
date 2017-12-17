#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
#include <utility>

using namespace std;

struct vec3{
    int x, y, z;
};

vector<vec3> pos;
bool DEBUG = false;

void showVec3(vec3 v){
    printf("%d %d %d\n", v.x, v.y, v.z);
}   

void showVec3Array(vector<vec3> va){
    for(int i=0; i<va.size(); i++){
        showVec3(va[i]);
    }
}

int main(){
    int a, b, c;
    cin >> a>> b>> c;
    //以下の不等式のどれかを満たすと作成不能
    if(a > b*c || b>a*c || c>a*b){
        printf("-1\n");
        return 0;
    }
    
    int oa = a, ob = b, oc = c;
    //a <= b <= cに並び替える
    vector<pair<int, int> > temp;
    temp.push_back(make_pair(a, 0)) ;
    temp.push_back(make_pair(b,1));
    temp.push_back(make_pair(c,2));
    sort(temp.begin(), temp.end());
    a = temp[0].first;
    b = temp[1].first;
    c = temp[2].first;
    
    pos.push_back((vec3){0,0,0});
    
    //以下ではa<=b<=cを想定
    //xy平面
    for(int ia = 1; ia < a; ia++){
        pos.push_back((vec3){0, ia, 0});
    }
    //xz平面
    for(int ib= 1; ib < b; ib++){
        pos.push_back((vec3){0, 0, ib});
    }

    if(DEBUG) showVec3Array(pos);
    if(DEBUG) printf("GO\n");   if(DEBUG) showVec3Array(pos);

    //yz平面
    if(DEBUG) printf("a,b,c=%d,%d,%d, pos:%d\n", a, b, c, pos.size());
    //多すぎるなら(0,0,0)を消す
    if(c < pos.size()) pos.erase(pos.begin());
    else{
        int yzCount = pos.size();
        //L字型の間を埋める
        for(int iy = 1; iy < a; iy++){
            for(int iz = 1; iz < b; iz++){
                pos.push_back((vec3){0, iy, iz});
                yzCount++;
                //終了
                if(!(yzCount < c)){
                    iy = a; iz = b;
                }
            }
        }
    }

    if(DEBUG) printf("ans:\n");
    if(DEBUG)showVec3Array(pos);
    if(DEBUG) printf("(%d,%d,%d) o(%d,%d,%d), %d,%d,%d\n", a, b,c, oa, ob, oc, temp[0].second, temp[1].second, temp[2].second);
    //vector<vec3> anspos;
    printf("%d\n", pos.size());
    for(int i=0; i < pos.size(); i++){
        //a:xyPlane b:xzPlane c:yzPlane
             if(temp[0].second == 0 && temp[1].second == 1) printf("%d %d %d\n", pos[i].x, pos[i].y, pos[i].z); //abc, xy,xz,yz
        else if(temp[0].second == 2 && temp[1].second == 1) printf("%d %d %d\n", pos[i].z, pos[i].y, pos[i].x); //cba. yz,xz,xyになるので,x->z, z->xになる
        else if(temp[0].second == 1 && temp[1].second == 2) printf("%d %d %d\n", pos[i].y, pos[i].z, pos[i].x); //bca, xz,yz,xyになるのでy->z, x->y, z->x
        else if(temp[0].second == 2 && temp[1].second == 0) printf("%d %d %d\n", pos[i].z, pos[i].x, pos[i].y); //cab, yz,xy,xzになるのでx->z, z->y, y->x
        else if(temp[0].second == 0 && temp[1].second == 2) printf("%d %d %d\n", pos[i].y, pos[i].x, pos[i].z); //acb, xy,yz,xzになるのでx->y, y->x
        else if(temp[0].second == 1 && temp[1].second == 0) printf("%d %d %d\n", pos[i].x, pos[i].z, pos[i].y); //bac, xz,xy,yzになるのでy->z, z->y

    }
    
    return 0;
}
