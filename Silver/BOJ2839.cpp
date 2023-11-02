#include <iostream>

using namespace std;
int anslist[5001] = {0, };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;
    cin >> num;
    cin.ignore();
    anslist[3] = 1;
    anslist[4] = 0;
    for (int i = 5; i<5001; i++){
        if (anslist[i-3] != 0){
            anslist[i] = (i%3==0) ? min(anslist[i-3] + 1, i/3) : anslist[i-3] + 1;
            if (anslist[i-5] != 0) {
                anslist[i] = (i%5==0) ? min(anslist[i-5] + 1, i/5) : min(anslist[i-5] + 1, anslist[i]);
            }
        }
        else {
            anslist[i] = (i%3==0) ? i/3 : 0;
            anslist[i] = (i%5==0) ? max(i/5, anslist[i]) : 0;
        }
    }
    int a = anslist[num] == 0 ? -1 : anslist[num];

    cout << a << '\n';

    return 0;
}