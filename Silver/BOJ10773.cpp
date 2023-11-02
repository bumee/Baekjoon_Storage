#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    int test;
    vector<int> anslist;
    cin >> test_case;
    for (int i=0;i<test_case;i++){
        cin >> test;
        if (test==0) anslist.pop_back();
        else anslist.push_back(test);
    }
    cout << accumulate(anslist.begin(), anslist.end(), 0) << '\n';

    return 0;
}