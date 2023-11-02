#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <queue>
#include <cstring>

using namespace std;
vector<int> dfsstack[1001];
bool visited[1001];
void dfs(int x) {
    visited[x] = true;
    cout << x << " ";

    for (int i=0;i<dfsstack[x].size();i++){
        int j = dfsstack[x][i];
        if (!visited[j]) {
            dfs(j);
        }
    }
}

void bfs(int x) {
    queue<int> bfsqueue;
    bfsqueue.push(x);
    visited[x] = true;

    while(!bfsqueue.empty()){
        int element = bfsqueue.front();
        bfsqueue.pop();
        cout << element << " ";

        for (int i=0;i<dfsstack[element].size();i++){
            int j = dfsstack[element][i];
            if (!visited[j]) {
                bfsqueue.push(j);
                visited[j] = true;
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n,m,v;
    cin >> n >> m >> v;

    for (int i=0;i<m;i++){
        int x, y;
        cin >> x >> y;

        dfsstack[x].push_back(y);
        dfsstack[y].push_back(x);
    }

    for(int i = 1; i <= n; i++){ 
		sort(dfsstack[i].begin(), dfsstack[i].end()); 
	}

    dfs(v);
    cout << endl;
    memset(visited, 0, n+1);
    bfs(v);

    return 0;
}