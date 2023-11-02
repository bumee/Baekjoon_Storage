#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string test;
    vector<char> opened;

    while (getline(cin, test)) {
        if (test==".") {
            break;
        }
        else {
            opened.clear();
            int m =0;
            for (int i=0;i<test.length();i++){
                if (test[i]=='(' || test[i]=='[') opened.push_back(test[i]);
                else{
                    if (test[i]==')'){
                        if (opened.back() =='(' && !opened.empty()) opened.pop_back();
                        else {
                            m=1;
                            break;
                        }
                    }
                    else if (test[i]==']'){
                        if (opened.back()=='[' && !opened.empty()) opened.pop_back();
                        else {
                            m=1;
                            break;
                        }
                    }
                }
            }
            if (opened.empty() && m==0) cout << "yes" << '\n';
            else cout << "no" << '\n';
        }
    }
    return 0;
}