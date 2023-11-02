#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    getline(cin, s);
    istringstream ss(s);
    int n;
    int total;
    ss >> n >> total;
    vector<int> coins;
    for (int i=0;i<n;i++) {
        int coin;
        cin >> coin;
        coins.push_back(coin);
    }
    int cnt = 0;
    while (total>0){
        if (total/coins.back()==0) coins.pop_back();
        else {
            cnt += total/coins.back();
            total -= (total/coins.back())*coins.back();
            coins.pop_back();
        }
    }
    cout << cnt;
    return 0;
}