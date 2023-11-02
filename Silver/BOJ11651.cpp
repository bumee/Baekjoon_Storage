#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <sstream>

using namespace std;
map<int,vector<int>> anslist;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    cin.ignore();
    vector<int> newone;
    for (int i=0;i<test_case;i++){
        int x, y;
        string coordinates;
        getline(cin, coordinates);
        istringstream cdn(coordinates);
        cdn >> x >> y;
        if (anslist.count(y)==0){
            anslist[y] = newone;
        }
        anslist[y].push_back(x);
    }
    for (auto iter = anslist.begin(); iter != anslist.end(); iter++) {
        int len = iter->second.size();
        vector<int> a;
        sort(iter->second.begin(),iter->second.end());
        for (int j=0;j<len;j++){
            cout << iter->second[j] << " " << iter->first << '\n';
        }
    }

    return 0;
}