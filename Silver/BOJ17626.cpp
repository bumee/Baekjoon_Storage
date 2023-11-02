#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    int cnt = 0;
    int anslist[50001] = {0,1,2,3,0 };

    for (int i=4;i<=n;i++){
        int root_i = sqrt(i);
        int minV = 4;
        for (int j=root_i;j>=1;j--){
            minV = min(minV, anslist[i-j*j]+1);
        }
        anslist[i] = minV;
    }
    cout << anslist[n];
    return 0;
}