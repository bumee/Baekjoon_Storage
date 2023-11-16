#include <iostream>
#include <algorithm>
#include <queue>
#define fastcpp ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int n;
int dp[101][11];
int main() {
    fastcpp;

    cin >> n;
    for (int i=1;i<=9;i++) dp[1][i] = 1;
    dp[1][10] = 9;
    dp[1][0] = 0;
    for (int i=2;i<=100;i++){
        int V = 0;
        for (int j=0;j<=9;j++){
            if (j-1>=0) {
                V = (V + dp[i-1][j-1])%1000000000;
                dp[i][j] = (dp[i][j]+dp[i-1][j-1])%1000000000;
            }
            if (j+1<=9) {
                V = (V + dp[i-1][j+1])%1000000000;
                dp[i][j] = (dp[i][j]+dp[i-1][j+1])%1000000000;
            }
        }
        dp[i][10] = V;
    }
    cout << dp[n][10];
    return 0;

}