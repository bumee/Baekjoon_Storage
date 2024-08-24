#include <iostream>
#include <algorithm>

using namespace std;

int mp[100000][3];
int dp[6];
int N;

void solve(bool ismax) {
    dp[0] = mp[0][0];
    dp[1] = mp[0][1];
    dp[2] = mp[0][2];
    if (ismax){
        for (int i = 1; i < N; i++)
        {
            dp[3] = max(dp[0]+mp[i][0],dp[1]+mp[i][0]);
            dp[4] = max(max(dp[0]+mp[i][1],dp[1]+mp[i][1]),dp[2]+mp[i][1]);
            dp[5] = max(dp[1]+mp[i][2],dp[2]+mp[i][2]);
            dp[0] = dp[3];
            dp[1] = dp[4];
            dp[2] = dp[5];
        }
        cout << max(max(dp[0],dp[1]),dp[2]) << " ";
    }
    else{
         for (int i = 1; i < N; i++)
        {
            dp[3] = min(dp[0]+mp[i][0],dp[1]+mp[i][0]);
            dp[4] = min(min(dp[0]+mp[i][1],dp[1]+mp[i][1]),dp[2]+mp[i][1]);
            dp[5] = min(dp[1]+mp[i][2],dp[2]+mp[i][2]);
            dp[0] = dp[3];
            dp[1] = dp[4];
            dp[2] = dp[5];
        }
        cout << min(min(dp[0],dp[1]),dp[2]) << " ";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> mp[i][0] >> mp[i][1] >> mp[i][2];
    }
    solve(true);
    solve(false);
    return 0;

}