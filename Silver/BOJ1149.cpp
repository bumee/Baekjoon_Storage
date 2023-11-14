#include <algorithm>
#include <iostream>
#include <queue>
#define fastcpp ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
int n, color;
int RGBList[1000][3];
int dp[1000][3];
void bfs(){
    for (int i=0;i<3;i++) dp[0][i] = RGBList[0][i];
    for (int i=1;i<n;i++){
        for (int j=0;j<3;j++){
            dp[i][j] = min(dp[i-1][(j+1)%3], dp[i-1][(j+2)%3])+RGBList[i][j];
        }
    } 
}
int main() {
    fastcpp;

    cin >> n;
    for (int i=0;i<n;i++){
        for (int j=0;j<3;j++){
            cin >> RGBList[i][j];
        }
    }
    bfs();
    cout << min({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
    return 0;
}