#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int m, n, dap;
int box[1000][1000];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int highest = 0;
int original_none = 0;
int changed=0;
queue<pair<int,int>> where;
void bfs(queue<pair<int,int>> q){
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i=0;i<4;i++){
            int next_x = x+dx[i];
            int next_y = y+dy[i];
            if (next_x < 0 || next_y < 0 || next_x >= m || next_y >= n) continue;
            if (box[next_y][next_x]==-1) continue;
            if (box[next_y][next_x]==0){
                box[next_y][next_x] = box[y][x] + 1;
                highest = highest > box[next_y][next_x] ? highest : box[next_y][next_x];
                q.push({next_x, next_y});
                changed++;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> n;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin >> dap;
            box[i][j] = dap;
            if (dap==1) where.push({j,i});
            if (dap==0) original_none++;
        }
    }
    bfs(where);
    if (original_none==changed) {
        if (original_none==0) {
            cout << 0;
        }
        else cout << highest-1;
    }
    else cout << -1;
    return 0;
}