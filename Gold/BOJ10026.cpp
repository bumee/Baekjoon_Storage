#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;
int n;
char map[100][100];
string strline;
bool visited[100][100];
int normalcnt = 0;
int abnormalcnt = 0;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
void bfswithNormal(pair<int,int> start, char target){
    queue<pair<int,int>> q;
    q.push(start);
    visited[start.second][start.first] = true;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i=0;i<4;i++){
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            if (next_x < 0 || next_y < 0 || next_x >= n || next_y >= n) continue;
            if (visited[next_y][next_x] || map[next_y][next_x]!=target) continue;
            visited[next_y][next_x] = true;
            q.push({next_x,next_y});
        }
    }
    normalcnt++;
}
void bfswithAbNormal(pair<int,int> start, char target){
    queue<pair<int,int>> q;
    q.push(start);
    visited[start.second][start.first] = true;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i=0;i<4;i++){
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            if (next_x < 0 || next_y < 0 || next_x >= n || next_y >= n) continue;
            if (visited[next_y][next_x]) continue;
            if (target=='R' && map[next_y][next_x]=='B') continue;
            if (target=='G' && map[next_y][next_x]=='B') continue;
            if (target=='B' && map[next_y][next_x]!='B') continue;
            visited[next_y][next_x] = true;
            q.push({next_x,next_y});
        }
    }
    abnormalcnt++;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=0;i<n;i++){
        cin >> strline;
        for (int j=0;j<n;j++){
            map[i][j] = strline[j];
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (!visited[i][j]) bfswithNormal({j,i}, map[i][j]);
        }
    }
    fill(visited[0], visited[100], false);
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (!visited[i][j]) bfswithAbNormal({j,i}, map[i][j]);
        }
    }
    cout << normalcnt << " " << abnormalcnt;
    return 0;
}