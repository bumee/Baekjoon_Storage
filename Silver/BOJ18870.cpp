#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>
#include <vector>

using namespace std;
long long int n, dap;
struct Compare {
    bool operator() (const int& a, const int& b) {
        return a < b;
    }
};
long long int anslist[1000000];
vector<long long int> v;
vector<long long int> m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    cin.ignore();
    long long int idx = 0;
    string s;
    getline(cin, s);
    istringstream ss(s);
    while (ss >> dap){
        v.push_back(dap);
        m.push_back(dap);
    }
    sort(m.begin(),m.end());
    m.erase(unique(m.begin(),m.end()),m.end());
    for (auto it : v) cout << lower_bound(m.begin(),m.end(),it) - m.begin() << " ";
    return 0;
}