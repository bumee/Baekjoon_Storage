#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <sstream>
#include <string>
#include <deque>

using namespace std;
string info;
string testarray;
int gatsu, aim;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_case;
    cin >> test_case;
    cin.ignore();
    for (int i=0;i<test_case;i++){
        getline(cin,info);
        istringstream ss(info);
        ss >> gatsu >> aim;
        queue<int> anslist;
        deque<int> testlist;

        getline(cin,testarray);

        int target = (testarray[2*aim]-'0');
       
        for (int k=0;k<testarray.length();k+=2){
            testlist.push_back(testarray[k] - '0');
            anslist.push(testarray[k]-'0');
        }
        sort(testlist.begin(), testlist.end());
        int count = 0;
        while (!anslist.empty()){
            while (anslist.front() != testlist.back()){
                anslist.push(anslist.front());
                anslist.pop();
                aim = aim-1 < 0 ? anslist.size()-1 : aim - 1;
            }
            if (anslist.front() == target && aim==0){
                cout << ++count << '\n';
                break;
            }
            else{
                anslist.pop();
                testlist.pop_back();
                aim = aim-1 < 0 ? anslist.size()-1 : aim - 1;
                count++;
            }
        }
        
    }
    return 0;
}