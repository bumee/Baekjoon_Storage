#include <iostream>
#include <string>

using namespace std;

long long int first, latter;
long long int tryCount = -1;

void checkPossiblethings(long long int num, long long int cnt){
    if (num > latter)
        return;
    else if (num == latter){
        tryCount = (tryCount==-1) ? cnt : min(cnt, tryCount);
        return;
    }
    else{
        checkPossiblethings(num << 1, cnt+1);
        string addednum = to_string(num)+"1";
        checkPossiblethings(stoll(addednum), cnt+1);
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> first >> latter;
    checkPossiblethings(first, 0);
    tryCount = (tryCount==-1) ? -1 : tryCount+1;
    cout << tryCount << '\n';

    return 0;
}