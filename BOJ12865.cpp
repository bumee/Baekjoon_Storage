#include <iostream>
#include <algorithm>

using namespace std;

int item, weight;
int howmany, bag;
int dp[101][100001];
int W[101];
int V[101];
void solve() {
    for (int i = 1; i <= bag; i++)
    {
        for (int j = 1; j <= howmany; j++)
        {
            if(W[j]>i){
                dp[j][i] = dp[j-1][i];
            }
            else{
                dp[j][i] = max(dp[j-1][i-W[j]] + V[j], dp[j-1][i]);
            }
        }
        
    }
    cout << dp[howmany][bag];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> howmany >> bag;
    for (int i = 1; i <= howmany; i++)
    {
        cin >> W[i] >> V[i];
    }

    for(int r=0; r<=howmany; r++)
    {
        dp[r][0] = 0;
    }
    for(int c = 0; c<=bag; c++){
        dp[0][c] = 0;
    }
    
    solve();
    return 0;
}