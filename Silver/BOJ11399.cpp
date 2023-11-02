#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_case;
    cin >> test_case;
    cin.ignore();
    int ans;
    string s;
    getline(cin, s);
    istringstream ss(s);
    vector <int> anslist;
    while (ss >> ans) anslist.push_back(ans);
    int sum = 0;
    sort(anslist.begin(),anslist.end());
    for (int i=0;i<test_case;i++){
        sum += anslist[i]*(test_case-i);
    }
    cout << sum;

    return 0;
}