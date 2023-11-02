#include <iostream>
#include <algorithm>
#include <sstream>
#include <map>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_case;
    cin >> test_case;
    for (int i=0;i<test_case;i++){
        int n;
        map<string,int> anslist;
        cin >> n;
        cin.ignore();
        for (int j=0;j<n;j++){
            string s, name, where;
            getline(cin,s);
            istringstream ss(s);
            ss >> name >> where;
            try {
                anslist[where]++;
            } catch (string k) {
                anslist[k] = 2;
            }
        }
        int dap = 1;
        for (auto iter = anslist.begin(); iter!=anslist.end();iter++) dap *= iter->second+1;
        cout << dap-1 << '\n';
    }

    return 0;
}