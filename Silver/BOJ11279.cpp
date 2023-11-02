#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    priority_queue<int,vector<int>>q;

    int t;
    cin >> t;
    while (t>0){
        int k;
        cin >> k;
        if (k==0) {
            cout << (q.empty() ? 0 : q.top()) << '\n';
            if (!q.empty()) q.pop();
        }
        else q.push(k);
        t--;
    }

    return 0;
}