#include <iostream>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;
int n, m, start, high;
vector<int> howToMap[101];
int result[101] = {0, };
int minV;
int minidx = 0;
void bfs(int x){
    queue<int> q;
    q.push(x);

    while (!q.empty()){
        int k = q.front();
        q.pop();
        for (int i=0;i<howToMap[k].size();i++){
            int j = howToMap[k][i];
            if (j==x) continue;
            if (result[j]==0) {
                result[j] = result[k] + 1;
                q.push(j);
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i=0;i<m;i++){
        cin >> start >> high;
        howToMap[start].push_back(high);
        howToMap[high].push_back(start);
    }
    for (int i=1;i<=n;i++){
        fill_n(result, 101, 0);
        bfs(i);
        int sum = 0;
        for (int j=1;j<=n;j++) sum += result[j];
        if (i==1 || minV > sum) minV = sum, minidx = i;
    }
    cout << minidx;
    return 0;
}