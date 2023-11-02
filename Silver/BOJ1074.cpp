#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
long long int n,r,c;
long long int ans = 0;
void dfs(int x, int y, int len) {
    long long int cnt = len * len;
    if (x==r && y==c) {
        cout << ans;
        return;
    }
    if (r >= x + len / 2 && c >= y + len / 2) {
		// 4사분면
		ans += cnt * 3 / 4;
		dfs(x + len / 2, y + len / 2, len / 2);
	}
	else if (r >= x + len / 2 && c >= y) {
		// 3사분면
		ans += cnt * 2 / 4;
		dfs(x + len / 2, y, len / 2);
	}
	else if (r >= x && c >= y + len / 2) {
		// 2사부면
		ans += cnt * 1 / 4;
		dfs(x, y + len / 2, len / 2);
	}
	else if (r >= x && c >= y) {
		// 1사분면
		dfs(x, y, len / 2);
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> r >> c;
    dfs(0,0,pow(2,n));
    return 0;
}