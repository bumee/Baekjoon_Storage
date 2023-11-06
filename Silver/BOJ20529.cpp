#include <algorithm>
#include <iostream>
#include <vector>
#define fastcpp ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
int test_case, num;
string MBTI;
vector<string> v;
int main() {
    fastcpp;
    cin >> test_case;
    while (test_case>0){
        test_case--;
        cin >> num;
        if (num>32) {
            cout << 0 << '\n';
            cin.ignore();
            string s;
            getline(cin, s);
        }
        else {
            v = vector<string>();
            int minV = 12;
            for(int i=0;i<num;i++){
                cin >> MBTI;
                v.push_back(MBTI);
            }
            for (int i=0;i<num-2;i++){
                for (int j=i+1;j<num-1;j++){
                    for (int k=j+1;k<num;k++){
                        int cnt = 0;
                        for(int c=0;c<4;c++){
                            if (v[i][c]!=v[j][c]) cnt++;
                            if (v[j][c]!=v[k][c]) cnt++;
                            if (v[k][c]!=v[i][c]) cnt++;
                        }
                        minV = min(minV, cnt);
                    }
                }
            }
            cout << minV << '\n';
        }

    }
    return 0;
}