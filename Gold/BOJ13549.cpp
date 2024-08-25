#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int me, brother;
int dx[2] = {-1,1};
int dp[100001] = {0,};
bool visited[100001];

int solve() {
    queue<int> q;
    q.push(me);
    dp[me] = 0;
    visited[me] = true;
    while(!q.empty()){
        int start = q.front();
        q.pop();
        if(start==brother){return dp[start];}
        if(start*2 <= 100000 && !visited[start*2]) {
            dp[start*2] = dp[start]; 
            q.push(start*2); 
            visited[start*2] = true;
        }
        for (int i = 0; i < 2; i++)
        {
            int newpos = start + dx[i];
            if(newpos >= 0 && newpos <= 100000 && !visited[newpos]){
                dp[newpos] = dp[start] + 1;
                q.push(newpos);
                visited[newpos] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> me >> brother;
    cout << solve();
    return 0;
}