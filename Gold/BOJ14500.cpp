#include <algorithm>
#include <iostream>
#include <queue>
#include <cstring>
#define fastcpp ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
int height, width;
int map[500][500];
bool visited[500][500];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int bfs(int start, int high) {
    queue<pair<pair<int,int>,pair<int,int>>> q;
    q.push({{start,high},{map[high][start],1}});
    int sum = 0;
    int maxV = 0;
    if (start-1 >= 0 && start+1 < width && high+1 < height){
        int dap = map[high][start] + map[high+1][start] + map[high][start+1] + map[high][start-1];
        maxV = max(maxV, dap);
    }
    if (start-1 >= 0 && start+1 < width && high-1 >= 0) {
        int dap = map[high][start] + map[high-1][start] + map[high][start+1] + map[high][start-1];
        maxV = max(maxV, dap);
    }
    if (high+2 < height && start + 1 < width){
        int dap = map[high][start] + map[high+1][start] + map[high+2][start] + map[high+1][start+1];
        maxV = max(maxV, dap);
    }
    if (high+2 < height && start - 1 >= 0) {
        int dap = map[high][start] + map[high+1][start] + map[high+2][start] + map[high+1][start-1];
        maxV = max(maxV, dap);
    }
    if (high + 1 < height && start + 1 < width){
        int dap = map[high][start] + map[high+1][start] + map[high+1][start+1] + map[high][start+1];
        maxV = max(maxV, dap);
    }
    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int sum = q.front().second.first;
        int cnt = q.front().second.second;
        visited[y][x] = true;
        q.pop();
        for(int i=0;i<4;i++){
            int next_x = x+dx[i];
            int next_y = y+dy[i];
            if (next_x < 0 || next_y < 0 || next_x >= width || next_y >= height) continue;
            if (visited[next_y][next_x]) continue;
            if (cnt>=4) {
                maxV = max(maxV, sum);
                continue;
            }
            q.push({{next_x,next_y},{sum+map[next_y][next_x],cnt+1}});
        }
    }
    return maxV;
}

int main() {
    fastcpp;

    cin >> height >> width;
    for (int i=0;i<height;i++){
        for (int j=0;j<width;j++){
            cin >> map[i][j];
        }
    }
    int maxV = 0;
    for (int i=0;i<height;i++){
        for (int j=0;j<width;j++){
            memset(visited, false, sizeof(visited));
            int a = bfs(j,i);
            maxV = max(maxV, a);
        }
    }
    cout << maxV;
    return 0;
}