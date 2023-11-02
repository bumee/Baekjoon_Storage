#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    queue<int>testlist;
    queue<int>usedlist;
    vector<int>anslist;

    int test_case;
    cin >> test_case;
    string isPossible = "";
    string original = "";
    string copy = "";
    for (int i=1;i<test_case+1;i++){
        int test;
        cin >> test;
        testlist.push(test);
        usedlist.push(i);
        original += (char)(test+48);
    }
    while (!usedlist.empty()){
        while (testlist.front()>usedlist.front()){
            anslist.push_back(usedlist.front());
            usedlist.pop();
            isPossible += '+';
        }
        if (testlist.front() == usedlist.front()){
            isPossible += '+';
            isPossible += '-';
            copy += (char)(testlist.front()+48);
            testlist.pop();
            usedlist.pop();
        }
        else{
            if (testlist.front()!=anslist.back()){
                isPossible = "NO";
                break;
            }
            isPossible += '-';
            copy += (char)(testlist.front()+48);
            anslist.pop_back();
            testlist.pop();
        }
    }
    if (isPossible == "NO"){
        cout << isPossible << '\n';
        return 0;
    }
    while (!anslist.empty()){
        copy += (char)(anslist.back()+48);
        isPossible += '-';
        anslist.pop_back();
    }
    if (copy == original){
        for (int i=0;i<isPossible.size();i++){
            cout << isPossible[i] << '\n';
        }
    } else cout << "NO" << '\n';
    return 0;
}