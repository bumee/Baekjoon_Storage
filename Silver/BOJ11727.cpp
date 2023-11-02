#include <iostream>
#include <algorithm>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long int dp[1001];
    int n;
    cin >> n;
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 3;
    for (int i=3;i<=n;i++){
        dp[i] = (2*dp[i-2] + dp[i-1])%10007;
    }
    cout << dp[n];
    return 0;
}