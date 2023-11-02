#include <algorithm>
#include <iostream>
#include <set>
#include <sstream>
#include <vector>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    getline(cin, s);
    istringstream ss(s);
    set<string> ans;
    int a, b;
    ss >> a >> b;
    int count = 0;
    vector<string> what;
    for (int i=0;i<a+b;i++){
        string test;
        cin >> test;
        if (ans.insert(test).second == false) {
            count++;
            what.push_back(test);
        }
    }
    cout << count << '\n';
    sort(what.begin(),what.end());
    for (auto it : what) cout << it << '\n';
    return 0;
}