#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int m,n,x,y;
bool visited[1001];
vector<int> anslist[1001];

void bfs(int x){
    queue<int> q;
    visited[x] = true;
    q.push(x);

    while(!q.empty()){
        int k = q.front();
        q.pop();
        for (int i=0;i<anslist[k].size();i++){
            int j = anslist[k][i];
            if (!visited[j]) {
                q.push(j);
                visited[j] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    while (m>0){
        m--;
        cin >> x >> y;
        anslist[x].push_back(y);
        anslist[y].push_back(x);
    }
    int coordinate = 1;
    int cnt=0;
    while (coordinate<=n){
        if (!visited[coordinate]){
            cnt++;
            bfs(coordinate);
        }
        coordinate++;
    } 
    cout << cnt;
    return 0;
}