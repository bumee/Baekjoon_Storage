#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int howmany, what;
deque<int> arr;
int fruit[200000];
int mp[10] = {0,};
int mm = 0;

bool overcheck(){
    int cnt = 0;
    for (int i=1;i<10;i++){
        if(mp[i]>0){cnt++;}
    }
    if(cnt>2){
        return true;
    }
    return false;
}

int solve() {
    int left = 0;
    int right = 0;
    while(left<howmany){
        while(right<howmany){
            mp[fruit[right++]]++;
            if(overcheck()){
                right--;
                mp[fruit[right]]--;
                break;
            }
        }
        mm = max(mm, right-left);
        mp[fruit[left++]]--;
    }
    return mm;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> howmany;
    for(int i=0;i<howmany;i++) {
        cin >> fruit[i];
    }
    cout << solve() << '\n';
}