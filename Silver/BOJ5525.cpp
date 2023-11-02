#include <iostream>
#include <algorithm>

using namespace std;
int n,m;
string s;
bool isFirst = false;
int previousValueIdx = 0;
int cnt = 0;
int ans = 0;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    cin >> m;
    cin >> s;
    for (int i=0;i<m;i++){
        if (s[i]=='O' && i-previousValueIdx!=1){
            if (!isFirst) continue;
            cnt = 0;
        }
        else if (s[i] == 'I'){
            isFirst = true;
            if (i-previousValueIdx!=2) {cnt=1; previousValueIdx=i;}
            else {cnt++; previousValueIdx = i;}
        }
        if (cnt==n+1) {ans++; cnt -= 1;}
    }

    cout << ans;

    return 0;
}