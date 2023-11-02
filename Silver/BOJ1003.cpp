#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_case;
    cin >> test_case;
    pair<int,int> anslist[41];
    for (int i=0;i<test_case;i++){
        int n;
        cin >> n;
        anslist[0] = make_pair(1,0);
        anslist[1] = make_pair(0,1);
        for (int i=2;i<=n;i++){
            anslist[i] = make_pair(anslist[i-2].first+anslist[i-1].first, anslist[i-2].second+anslist[i-1].second);
        }
        cout << anslist[n].first << " " << anslist[n].second << '\n';

    }
    
    return 0;
}