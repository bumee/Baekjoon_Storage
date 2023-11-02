#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	priority_queue<int, vector<int>, greater<int>> q;

    int test_case;
    cin >> test_case;
    while (test_case>0){
        int test;
        cin >> test;
        if (test==0) {
            if (q.empty()) cout << 0 << '\n';
            else {
                cout << q.top() << '\n';
                q.pop();
            }
        }
        else q.push(test);
        test_case --;
    }
	
	return 0;
}