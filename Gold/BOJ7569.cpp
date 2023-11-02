#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <tuple>


using namespace std;
int m,n,h,dap;
int box[100][100][100];
int highest = 0;
int changed = 0;
int original = 0;
int dx[6] = {0,1,0,-1,0,0};
int dy[6] = {1,0,-1,0,0,0};
int dz[6] = {0,0,0,0,1,-1};
queue<tuple<int,int,int>> tomatolist;
void bfs(queue<tuple<int,int,int>> q){
    while(!q.empty()){
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int z = get<2>(q.front());
        q.pop();
        for (int i=0;i<6;i++){
            int next_x = x+dx[i];
            int next_y = y+dy[i];
            int next_z = z+dz[i];
            if (next_x < 0 || next_y < 0 || next_z < 0 || next_x >= m || next_y >= n || next_z >= h) continue;
            if (box[next_z][next_y][next_x]==-1 || box[next_z][next_y][next_x]>=1) continue;
            box[next_z][next_y][next_x] = box[z][y][x] + 1;
            highest = max(highest, box[next_z][next_y][next_x]);
            q.push(make_tuple(next_x,next_y,next_z));
            changed++;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> n >> h;
    for (int i=0;i<h;i++){
        for (int j=0;j<n;j++){
            for (int w=0;w<m;w++){
                cin >> box[i][j][w];
                if (box[i][j][w]==0) original++;
                if (box[i][j][w]==1) tomatolist.push(make_tuple(w,j,i));
            }
            
        }
    }
    bfs(tomatolist);
    if (changed==original) {
        if (highest==0) cout << 0;
        else cout << highest-1;
    }
    else cout << -1;
    return 0;
}