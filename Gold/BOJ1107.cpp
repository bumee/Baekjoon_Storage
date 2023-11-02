#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;
int future, howmuchOut, dap;
string s;
char err[10];
bool isPossible[1000001];
int up = 0;
int down = 0;
int ans, result;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> future;
    cin >> howmuchOut;
    if (howmuchOut==0){
        int j = to_string(future).length();
        cout << min(abs(future-100), j);
        return 0;
    }
    for (int i=0;i<howmuchOut;i++){
        cin >> err[i];
    }
    for (int i=0;i<=1000000;i++){
        bool check = false;
        string k = to_string(i);
        int len = k.length();
        for (int j=0;j<len;j++){
            for (int w=0;w<howmuchOut;w++){
                if (k[j] == err[w]){isPossible[i]=false; check=true;break;}
            }
        }
        if (!check) isPossible[i] = true;
    }
    isPossible[100] = true;
    int downnum = future;
    int ch = 0;
    while (!isPossible[downnum]) {
        if (downnum==0) {
            if (future!=0) ch=1;
            break;
        }
        downnum--;
    }
    int leng = to_string(downnum).length();
    down = min(abs(future-100), future-downnum+leng);
    if (ch==1) down = abs(future-100);

    int upnum = future;
    while (!isPossible[upnum]) {
        upnum++;
    }
    int leng2 = to_string(upnum).length();
    up = min(abs(future-100), upnum-future+leng2);

    ans = (future!=0) ? min(up, down) : up;
    cout << ans;

    return 0;
}