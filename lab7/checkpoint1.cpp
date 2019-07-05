#include<iostream>
#include<cassert>
using namespace std;
int cnt = 0;
void dfs(int x,int y){
    if(x == 0 && y == 0){
        cnt++;
        return;
    }
    if(x-1>=0)dfs(x-1, y);
    if(y-1>=0)dfs(x, y-1);
}
int main(){
    int x,y;

    cnt = 0;
    x = 0, y = 0;
    dfs(x,y);
    assert(cnt == 1);

    cnt = 0;
    x = 2, y = 1;
    dfs(x,y);
    assert(cnt == 3);

    cnt = 0;
    x = 1, y = 2;
    dfs(x,y);
    assert(cnt == 3);

    cnt = 0;
    x = 2, y = 2;
    dfs(x,y);
    assert(cnt == 6);

    cnt = 0;
    cin>>x>>y;
    dfs(x,y);
    cout<<cnt;

    return 0;
}
