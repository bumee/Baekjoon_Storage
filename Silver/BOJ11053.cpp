#include <iostream>
#include <algorithm>

#define fastcpp cin.tie(0); ios_base::sync_with_stdio(0);

using namespace std;

int dp[1000];
int mp[1000];
int howmany;

int main() {
    fastcpp;

    cin >> howmany;

    for (int i = 0; i < howmany; i++)
    {
        cin >> mp[i];
    }

    for (int i = 0; i < howmany; i++)
    {
        dp[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (mp[i] > mp[j])
            {
                dp[i] = max(dp[i],dp[j]+1);
            }
        }   
    }

    int size = sizeof(dp)/ sizeof(*dp);

    int maxv = *std::max_element(dp, dp+size);
    cout << maxv << '\n';
    

    return 0;
}