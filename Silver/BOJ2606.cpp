#include <iostream>
#include <algorithm>
#include <set>
#include <sstream>
#include <queue>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    int test;
    cin >> test;
    cin.ignore();
    set<int> howConnect[101];
    queue<int> ConnectWith1;
    for (int i=0;i<test;i++){
        string s;
        getline(cin, s);
        istringstream ss(s);
        int first, second;
        ss >> first >> second;
        int nn = first > second ? second : first;
        if (nn==1) ConnectWith1.push(nn+abs(first-second));
        howConnect[first].insert(second);
        howConnect[second].insert(first);
    }
    set<int> anslist = howConnect[1];
    while (!ConnectWith1.empty()){
        int front = ConnectWith1.front();
        if (howConnect[front].size()!=0) {
            for (auto item : howConnect[front]){
                if (item!=1 && anslist.insert(item).second == true) ConnectWith1.push(item);
            }
        }
        ConnectWith1.pop();
    }
    cout << anslist.size();
    return 0;
}