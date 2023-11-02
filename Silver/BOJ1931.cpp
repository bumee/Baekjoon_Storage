#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<pair<long long int, long long int>> anslist;
long long int n, start, high;
long long int cnt = 1;
bool compareStart (const pair<long long int, long long int> &a, const pair<long long int, long long int> &b) {
    return a.first < b.first;
}
bool compareEnd (const pair<long long int, long long int> &a, const pair<long long int, long long int> &b) {
    return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    cin.ignore();
    while (n>0){
        cin >> start >> high;
        anslist.push_back(make_pair(start, high));
        n--;
    }
    sort(anslist.begin(),anslist.end(),compareStart);
    sort(anslist.begin(),anslist.end(),compareEnd);
    pair<long long int, long long int> recent = anslist[0];
    for (int i=1;i<anslist.size();i++){
        if (anslist[i].first >= recent.second) {
            cnt++;
            recent = anslist[i];
        }
    }
    cout << cnt;
    return 0;
}