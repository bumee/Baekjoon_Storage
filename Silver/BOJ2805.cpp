#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;
long long int trees[1000000];
long long int n, m, idx, dap;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> m;
    idx = 0;
    cin.ignore();
    string s;
    getline(cin,s);
    istringstream ss(s);
    while (ss >> dap) {
        trees[idx] = dap;
        idx++;
    }
    long long int start = 1;
    long long int end = 2000000000;
    while (start<=end){
        long long int mid = (start+end)/2;
        long long int sum = 0;
        for (long long int z=0;z<n;z++) {
            sum += (trees[z] >= mid) ? trees[z]-mid : 0;
        }
        if (sum>=m) start = mid + 1;
        else end = mid - 1;
    }
    cout << end;
    return 0;
}