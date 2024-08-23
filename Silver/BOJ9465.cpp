#include <iostream>


using namespace std;

int dp[2][100000];
int mp[2][100000];
int testcase, num;
int before = 0;

void solve(){
    dp[0][0] = mp[0][0];
    dp[1][0] = mp[1][0];
    dp[0][1] = dp[1][0] + mp[0][1];
    dp[1][1] = dp[0][0] + mp[1][1];

    for (int i = 2; i < num; i++)
    {
        dp[0][i] = max(max(dp[1][i-1]+mp[0][i],dp[0][i-2]+mp[0][i]),dp[1][i-2]+mp[0][i]);
        dp[1][i] = max(max(dp[0][i-1]+mp[1][i],dp[0][i-2]+mp[1][i]),dp[1][i-2]+mp[1][i]);
    }
    cout << max(dp[0][num-1],dp[1][num-1]) << endl;
}

int main() {

    cin >> testcase;
    while(testcase>0){
        testcase--;
        cin >> num;
        for (int i = 0; i < num; i++)
        {
            cin >> mp[0][i];
        }
        for (int i = 0; i < num; i++)
        {
            cin >> mp[1][i];
        }
        solve();
    }
    return 0;
}