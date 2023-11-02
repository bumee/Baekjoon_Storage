#include <iostream>
#include <algorithm>
#include <sstream>
#include <queue>

using namespace std;
int n,m;
string s;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int map[100][100];

void bfs(pair<int,int> start) {
    queue<pair<int,int>>q;
    q.push(start);

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i=0;i<4;i++){
            int next_x = x+dx[i];
            int next_y = y+dy[i];
            if (next_x < 1 || next_y < 1 || next_x >= m+1 || next_y >= n+1) continue;
            if (map[next_y-1][next_x-1]==0 || map[next_y-1][next_x-1] > 1) continue;
            map[next_y-1][next_x-1] = map[y-1][x-1] + 1;
            q.push({next_x, next_y});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=0;i<n;i++){
        cin >> s;
        for(int j=0;j<m;j++){
            map[i][j] = s[j]-'0';
        }
    }
    bfs({1, 1});
    cout << map[n-1][m-1];
    return 0;
}