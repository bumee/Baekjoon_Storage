#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    queue<int> anslist;

    int n;
    cin >> n;
    for (int i=1;i<n+1;i++){
        anslist.push(i);
    }
    while (anslist.size()!=1){
        anslist.pop();
        anslist.push(anslist.front());
        anslist.pop();
    }
    cout << anslist.front();

    return 0;
}