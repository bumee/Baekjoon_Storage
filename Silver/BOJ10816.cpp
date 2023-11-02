#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num, testnum;
    int myValue, testValue;
    map<int,int> anslist;

    cin >> num;
    for (int i=0;i<num;i++){
        cin >> myValue;
        if (anslist.count(myValue) == 0) anslist[myValue] = 1;
        else anslist[myValue] += 1;
    }
    cin >> testnum;
    for (int j=0;j<testnum;j++){
        cin >> testValue;
        cout << ((anslist.count(testValue) == 0) ? 0 : anslist[testValue]) << " ";
    }
    return 0;
}