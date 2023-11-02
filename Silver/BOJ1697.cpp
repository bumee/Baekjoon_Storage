#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;
int current, future;
int anslist[100001] = {0, };
queue<int> stacks;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> current >> future;
    
    anslist[current] = 0;
    stacks.push(current);
    while (!stacks.empty()){
        int k = stacks.front();
        stacks.pop();
        if (k==future) {
            cout << anslist[k];
            return 0;
        }
        int dk[3] = {k-1, k+1, 2*k};
        for (int variation : dk) {
            if (variation>=0 && variation<=100000 && anslist[variation]==0) {
                anslist[variation] = anslist[k] + 1;
                stacks.push(variation);
            }
        }
    }
    return 0;
}