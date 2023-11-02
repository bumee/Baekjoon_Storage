#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;
    string isitg ="";
    int ans = 0;
    bool flag = false;
    for (int i=0;i<=s.size();i++){
        if (s[i]=='+' || s[i]=='-' || i==s.size()){
            if (flag) ans -= stoi(isitg);
            else ans += stoi(isitg);
            isitg = "";
        } 
        else isitg += s[i];

         if (s[i]=='-') flag = true;
    }
    cout << ans;
    return 0;
}