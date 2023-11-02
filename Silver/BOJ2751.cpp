#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> anslist;
    int num;
    int temp;
    cin >> num;
    for (int i=0;i<num;i++){
        cin >> temp;
        anslist.push_back(temp);
    }
    sort(anslist.begin(),anslist.end());
    for (int i=0;i<num;i++){
        cout << anslist[i] << '\n';
    }

};