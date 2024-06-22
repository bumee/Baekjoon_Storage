#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <map>

using namespace std;
int testcase, howmany, how;
long long int icnt = 0;
string what;
priority_queue<long long int, vector<long long int>, greater<long long int>> minpq;
priority_queue<long long int> maxpq;
map<long long int, long long int> mp;

void cleanqueues() {
    while(!minpq.empty() && mp[minpq.top()]==0){minpq.pop();}
    while(!maxpq.empty() && mp[maxpq.top()]==0){maxpq.pop();}
}

void deletemin() {
    if (!minpq.empty()){
        mp[minpq.top()]--;
        minpq.pop();
    }
}

void deletemax() {
    if (!maxpq.empty()){
        mp[maxpq.top()]--;
        maxpq.pop();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> testcase;
    while(testcase>0){
        testcase--;
        cin >> howmany;
        while(!minpq.empty()){minpq.pop();}
        while(!maxpq.empty()){maxpq.pop();}
        mp.clear();
        while(howmany>0){
            howmany--;
            cin >> what >> how;
            if(what=="I"){
                icnt++;
                maxpq.push(how);
                minpq.push(how);
                if(mp.find(how)!=mp.end()){mp[how]++;}
                else{mp[how]=1;}
            }
            else{
                icnt = (icnt>0 ? icnt-1 : 0);
                if(how==-1 && !minpq.empty()){
                    cleanqueues();
                    deletemin();
                }
                else if (how==1 && !maxpq.empty()){
                    cleanqueues();
                    deletemax();
                }
            }
        }
        cleanqueues();
        if(icnt==0 || maxpq.empty() || minpq.empty() || minpq.top() > maxpq.top()){
            cout << "EMPTY" << '\n';
        }
        else{
            cout << maxpq.top() << " " << minpq.top() << '\n';
        }
    }
    return 0;
}