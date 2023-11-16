#include <iostream>
#include <algorithm>
#include <vector>
#define fastcpp ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
int n;
vector<int> dp[501];
int main() {
    fastcpp;

    cin >> n;
    for (int i=1;i<=n;i++){
        for (int j=0;j<i;j++) {
            int dap;
            cin >> dap;
            dp[i].push_back(dap);
        }
    }
    if (n==1) cout << dp[1][0];
    else{
        int ans = 0;
        for (int i=2;i<=n;i++){
            int len = dp[i-1].size();
            for (int j=0;j<dp[i].size();j++){
                int maxV = -1;
                if (j-1>=0) maxV = dp[i][j]+dp[i-1][j-1];
                if (j<len) maxV = (maxV==-1) ? dp[i][j]+dp[i-1][j] : max(maxV,dp[i][j]+dp[i-1][j]);
                dp[i][j] = maxV;
                ans = max(ans, maxV);
            }
        }
        cout << ans;
    }

    return 0;
}