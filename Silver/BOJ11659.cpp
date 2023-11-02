#include <iostream>
#include <algorithm>
#include <sstream>
#include <map>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, howmany;
    string s, what;
    getline(cin, s);
    istringstream ss(s);
    ss >> n >> howmany;
    getline(cin,what);
    istringstream ss2(what);
    int dap;
    int total = 0;
    int anslist[100001] = {0,};
    int idx = 0;
    while (ss2 >> dap) {
        idx ++;
        total += dap;
        anslist[idx] = total;
    }
    while (howmany>0){
        string aa;
        getline(cin, aa);
        istringstream ss3(aa);
        int start, end;
        ss3 >> start >> end;

        cout << anslist[end] - anslist[start-1] << '\n';

        howmany --;
    }

    return 0;
}