#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int n;
string s;
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
vector<int> anslist;
bool visited[25][25];
int map[25][25];
void bfs(pair<int,int> where) {
    queue<pair<int,int>>q;
    q.push(where);
    int cnt = 0;

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i=0;i<4;i++){
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            if (next_x < 0 || next_y < 0 || next_x >= n || next_y >= n) continue;
            if (visited[next_y][next_x] || map[next_y][next_x]==0) continue;
            cnt++;
            visited[next_y][next_x] = true;
            q.push({next_x,next_y});
        }
    }
    anslist.push_back(cnt);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i=0;i<n;i++){
        cin >> s;
        for (int j=0;j<n;j++){
            map[i][j] = s[j]-'0';
        }
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            if (map[i][j]!=0 && !visited[i][j]) bfs({j,i});
        }
    }
    sort(anslist.begin(),anslist.end());
    cout << anslist.size() << '\n';
    for (auto it : anslist) {
        if (it==0) cout << 1 << '\n';
        else cout << it << '\n';
    }

    return 0;
}