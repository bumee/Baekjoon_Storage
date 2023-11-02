#include <algorithm>
#include <iostream>
#include <queue>
#include <cmath>

using namespace std;
int n;
long long int dap;

struct Compare {
    bool operator() (long long int a, long long int b) {
        if (abs(a)==abs(b)) return a > b;
        return abs(a) > abs(b);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    priority_queue<long long int, vector<long long int>, Compare>q;
    while(n>0){
        n--;
        cin >> dap;
        if (dap==0) {
            if (q.empty()) cout << 0 << '\n';
            else {
                cout << q.top() << '\n';
                q.pop();
            }
        }
        else q.push(dap);
    }

    return 0;
}