#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    int way[1000001];
    way[0]=0;
    way[1]=0;
    way[2]=1;
    way[3]=1;
    for (int i=4;i<n+1;i++){
        if (i%2==0){
            if (i%3==0) {
                way[i] = min(way[i/2],way[i/3])+1;
                way[i] = min(way[i-1]+1,way[i]);
            }
            else way[i] = min(way[i/2],way[i-1])+1;
        }
        else {
            if (i%3==0) way[i] = min(way[i-1],way[i/3])+1;
            else way[i] = way[i-1] + 1;
        }
    }
    cout << way[n];
    return 0;
}