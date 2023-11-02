#include <algorithm>
#include <iostream>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    for (int i=0;i<test_case;i++){
        string test;
        cin >> test;
        int pluscount = 0;
        int minuscount = 0;
        if (test.length()%2!=0) {
            cout << "NO" << '\n';
            continue;
        }
        for (int j=0;j<test.length();j++){
            if (minuscount > pluscount) {
                cout << "NO" << '\n';
                break;
            }
            else if (pluscount >= test.length()/2 || minuscount >= test.length()/2){
                if (pluscount > minuscount) {
                    int m = 0;
                    for (int idx = j;idx<test.length();idx++){
                        if (test[idx] == '(') {
                            m = 1;
                        }
                    }
                    if (m==1) {
                        cout << "NO" << '\n';
                        break;
                    }
                    cout << "YES" << '\n';
                    break;
                }
                else if (minuscount > pluscount) {
                    cout << "NO" << '\n';
                    break;
                }
                else {
                    cout << "YES" << '\n';
                    break;
                }
            }
            else {
                if (test[j] =='(') pluscount += 1;
                else minuscount += 1;
            }
        }
    }

    return 0;
}