#include <algorithm>
#include <iostream>
#define fastcpp ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int n;
int grape[10001];
int dp[10001];
int main() {
    fastcpp;
    cin >> n;
    for (int i=1;i<=n;i++) cin >> grape[i];
    dp[1] = grape[1];
    dp[2] = grape[1]+grape[2];
    for (int i=3;i<=n;i++){
        dp[i] = max({dp[i-1],dp[i-3]+grape[i-1]+grape[i], dp[i-2]+grape[i]});
    }
    cout << dp[n];
    return 0;
}