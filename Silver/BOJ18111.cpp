#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <numeric>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int width,height,inventory;
    string info;
    getline(cin,info);
    istringstream ss(info);
    ss >> height >> width >> inventory;

    vector<int> nopi;
    for (int i=0;i<height;i++){
        string s;
        int gap;
        getline(cin,s);
        istringstream ss(s);
        while (ss >> gap) nopi.push_back(gap);
    }
    pair<int,int>ans;
    for (int i=0;i<=256;i++){
        int sum = 0;
        sum = accumulate(nopi.begin(),nopi.end(),0);
        sum -= width*height*i;
        sum += inventory;
        if (sum>=0) {
            int cnt = 0;
            for (int j=0;j<width*height;j++){
                cnt += nopi[j]-i<0 ? i-nopi[j] : 2*(nopi[j]-i);
            }
            if (i==0) ans = make_pair(cnt,i);
            else ans = ans.first == cnt ? (ans.second > i ? ans : make_pair(cnt,i)) : (ans.first > cnt ? make_pair(cnt, i) : ans);
        }
    }
    cout << ans.first << " " << ans.second;


    return 0;
}