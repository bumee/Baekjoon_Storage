#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>
#include <numeric>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string test;
    unsigned int current, future;
    getline(cin, test);
    istringstream ss(test);
    ss >> current >> future;

    vector<int> storage;
    for (int i=0;i<current;i++){
        unsigned int  n;
        cin >> n;
        storage.push_back(n);
    }
    int start = 1;
    sort(storage.begin(),storage.end());
    unsigned int end = storage.back();
    unsigned int cnt = 0;

    while (start <= end){
        cnt = 0;
        unsigned int mid = (start+end)/2;
        for (int i=0;i<storage.size();i++){
            cnt += storage[i]/mid;
        }
        if (cnt>=future) start = mid + 1;
        else end = mid - 1;
    }
    cout << end;
    return 0;
}