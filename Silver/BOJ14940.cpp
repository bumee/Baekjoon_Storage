#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int n, m, dap;
int startx,starty;
long long int map[1000][1000] = {0,};
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void bfs(long long int start, long long int high){
    queue<pair<long long int, long long int>>q;
    q.push({start,high});

    while (!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i=0;i<4;i++){
            int next_x = x+dx[i];
            int next_y = y+dy[i];
            if (next_x < 0 ||next_y < 0 || next_x >= m || next_y >= n) continue;
            if (map[next_y][next_x]==0) continue;
            if (map[next_y][next_x] > 1 && map[next_y][next_x] != 2) continue;
            map[next_y][next_x] = map[y][x] + 1;
            q.push({next_x,next_y});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin >> dap;
            map[i][j] = dap;
            if (dap==2) {
                startx = j;
                starty = i;
            }
        }
    }
    bfs(startx,starty);
    map[starty][startx] = 0;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cout << (map[i][j]!=0 ? map[i][j]-2 : 0) << " ";
        }
        cout << '\n';
    }

    return 0;
}