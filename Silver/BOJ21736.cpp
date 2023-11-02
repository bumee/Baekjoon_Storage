#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int n, m;
int cnt = 0;
int meet = 0;
int start, high;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
char what;
char map[600][600];

void bfs(int x, int y) {
    queue<pair<int,int>> q;
    q.push({x,y});
    while (!q.empty()){
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();
        for (int i=0;i<4;i++){
            int next_x = curx+dx[i];
            int next_y = cury+dy[i];
            if (next_x < 0 || next_y < 0 || next_x >= m || next_y >= n) continue;
            if (map[next_y][next_x]=='X' || map[next_y][next_x]=='V') continue;
            if (map[next_y][next_x]=='P') meet++;
            map[next_y][next_x]='V';
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
            cin >> what;
            map[i][j] = what;
            if (what=='I') {
                start = j;
                high = i;
            }
            if (what=='P') cnt++;
        }
    }
    bfs(start,high);
    if (meet==0) cout << "TT";
    else cout << meet;
    return 0;
}