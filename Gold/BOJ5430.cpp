#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;
int test_case;
string how, howOperate;
int len;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> test_case;
    while (test_case>0){
        test_case--;
        deque<string> q; 
        cin >> howOperate;
        cin >> len;
        cin >> how;
        int totalength = how.length();
        string add = "";
        for (int i=0;i<totalength;i++){
            if (how[i]=='[') continue;
            if (how[i]==',' || how[i]==']' ) {
                if (add=="") break;
                q.push_back(add);
                add = "";
            }
            else add+=how[i];
        }


        string ans = "[";
        bool isReverse = false;
        for (int i=0;i<howOperate.length();i++){
            if (howOperate[i]=='R') isReverse = !isReverse;
            else {
                if (q.empty()) {ans = "error"; break;}
                if (isReverse) q.pop_back();
                else q.pop_front();
            }
        }
        if (ans=="error") cout << ans << '\n';
        else if (q.empty()) cout << "[]" << '\n';
        else {
            while (!q.empty()){
                if (isReverse){
                    ans += q.back();
                    q.pop_back();
                }
                else {
                    ans += q.front();
                    q.pop_front();
                }
                if (q.empty()) ans+=']';
                else ans+=',';
            }
            cout << ans << '\n';
        }
    }

    return 0;
}