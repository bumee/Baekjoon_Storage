#include <iostream>
#include <algorithm>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int total[301];
    int score[301];
    int n;
    cin >> n;
    for (int i=1;i<=n;i++){
        int ss;
        cin >> ss;
        score[i] = ss;
    }
    total[1] = score[1];
    total[2] = score[1] + score[2];
    total[3] = max(score[1]+score[3], score[2]+score[3]);
    for (int i=4;i<=n;i++){
        total[i] = max(total[i-3]+score[i-1]+score[i], total[i-2]+score[i]);
    }
    cout << total[n];

    return 0;
}