#include <iostream>
#include <algorithm>
#include <sstream>
#include <queue>

using namespace std;
int coordinatelist[128][128];
int coordinate;
int n;
int ans=0;
int white, blue;

void dfs (pair<int,int> start, pair<int,int> end){
    int x = start.first;
    int y = start.second;
    int endx = end.first;
    int endy = end.second;
    int len = endx-x;
    int m = 0;
    int what  = coordinatelist[y][x];
    for (int i=y;i<endy;i++){
        for (int j=x;j<endx;j++){
            if (what!=coordinatelist[i][j]) {
                m=1;
                break;
            }
        }
        if (m==1) break;
    }
    if (m==0) {
        if (what==1) blue++;
        else white++;
        return;
    }
    dfs(make_pair(x, y), make_pair(x+len/2, y+len/2));
    //1사분면
    dfs(make_pair(x, y+len/2), make_pair(x+len/2,y+len));
    //3사분면
    dfs(make_pair(x+len/2, y), make_pair(x+len,y+len/2));
    //2사분면
    dfs(make_pair(x+len/2, y+len/2), make_pair(x+len,y+len));
    //4사분면
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cin.ignore();
    for (int i=0;i<n;i++){
        string s;
        getline(cin,s);
        istringstream ss(s);
        int idx = 0;
        while (ss >> coordinate){
           coordinatelist[i][idx] = coordinate;
           idx++;
        }
    }
    dfs(make_pair(0,0), make_pair(n,n));
    cout << white << '\n';
    cout << blue << '\n';
    return 0;
}