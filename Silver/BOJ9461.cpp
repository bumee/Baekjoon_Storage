#include <iostream>
#include <algorithm>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long int up[50];
    long long int down[50];

    int test_case;
    cin >> test_case;
    up[0] = 1;
    up[1] = 1;
    up[2]= 2;
    down[0] = 1;
    down[1] = 2;
    for (int i=6;i<=100;i++){
        if (i%2==0) down[(i/2)-1] = up[(i/2)-1] + up[(i/2)-3];
        else up[i/2] = down[(i/2)-1] + down[(i/2)-3];
    }
    for (int i=0;i<test_case;i++){
        int n;
        cin >> n;
        cout << (n%2 == 0 ? down[(n/2)-1] : up[n/2]) << '\n';
    }
    return 0;
}