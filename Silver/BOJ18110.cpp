#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    double test;
    cin >> test;
    vector<int> anslist;
    if (test==0){
        cout << 0 << '\n';
        return 0;
    }
    for (int i=0;i<test;i++){
        int itg;
        cin >> itg;
        anslist.push_back(itg);
    }
    sort(anslist.begin(),anslist.end());
    double mok = round(test*0.15);
    double dap = accumulate(anslist.begin()+mok,anslist.end()-mok, 0) / (test-2*mok);
    cout << round(dap) << endl;

    return 0;
}