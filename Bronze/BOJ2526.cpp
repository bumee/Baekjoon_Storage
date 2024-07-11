#include <iostream>

using namespace std;

int dp[1000] = {0,};
long long int N, P, Ncopy;
int cnt = 0;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> P;
    Ncopy = N;
    while(dp[N]<=2){
        dp[N]++;
        N = (N*Ncopy)%P;    
    }
    for (int i = 0; i < 1000; i++)
    {
        if(dp[i]>=2)cnt++;
    }
    cout << cnt << '\n';
    


    return 0;
}