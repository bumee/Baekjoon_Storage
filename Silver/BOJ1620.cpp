#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include <cctype>

using namespace std;
bool cmp (pair<int, string> a, pair<int, string> b){
    return a.second < b.second;
} 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<pair<int, string>> dogam;
    string info;
    getline(cin,info);
    int total, mine;
    istringstream ss(info);
    ss >> total >> mine;
    vector<pair<int, string>> copy;
    for (int i=0;i<total;i++){
        string poketmon;
        cin >> poketmon;
        dogam.push_back(make_pair(i, poketmon));
        copy.push_back(make_pair(i, poketmon));
    }
    sort(dogam.begin(),dogam.end(),cmp);
    sort(copy.begin(),copy.end());
    for (int i=0;i<mine;i++){
        string test;
        cin >> test;
        if (isdigit(test[0]) == 0) {
            unsigned int start = 0;
            unsigned int end = total-1;
            unsigned int mid = 0;
            while (start <= end){
                mid = (start+end)/2;
                if (dogam[mid].second == test) break;
                else if (dogam[mid].second > test) end = mid - 1;
                else start = mid + 1;
            }
            cout << dogam[mid].first+1 << '\n';
        }
        else {
            cout << copy[stoi(test)-1].second << '\n';
        }
    }

    return 0;
}