#include <iostream>
#include <algorithm>

using namespace std;
int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_case;
    cin >> test_case;
    int dap[11];
    dap[0] = 0;
    dap[1] = 1;
    dap[2] = 2;
    dap[3] = 4;
    for (int i=4;i<11;i++){
        dap[i] = dap[i-3] + dap[i-2] + dap[i-1];
    }
    for (int i=0;i<test_case;i++){
        int test;
        cin >> test;
        cout << dap[test] << '\n';
    }
    return 0;
}