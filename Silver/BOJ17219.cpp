#include <iostream>
#include <algorithm>
#include <map>
#include <sstream>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string info;
    getline(cin, info);
    istringstream ss(info);
    int test_case;
    int finding;
    map<string,string>infolist;
    ss >> test_case >> finding;
    for (int i=0;i<test_case;i++){
        string names;
        getline(cin,names);
        istringstream sss(names);
        string email;
        string password;
        sss >> email >> password;
        infolist[email] = password;
    }
    for (int i=0;i<finding;i++) {
        string s;
        cin >> s;
        cout << infolist[s] << '\n';
    }

    return 0;
}