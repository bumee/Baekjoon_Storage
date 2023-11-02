#include <iostream>
#include <algorithm>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long int dp[1001] = {0,};
    int n;
    cin >> n;
    dp[1] = 1,
    dp[2] = 2;
    for (int i=3;i<=n;i++){
        dp[i] = (dp[i-1] + dp[i-2])%10007;
    }
    cout << dp[n];
    return 0;
}