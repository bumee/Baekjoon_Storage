#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>
#define fastcpp ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
int test_case;
int current, target;
bool visited[10000];

void bfs(){
    queue<pair<int,string>> q;
    q.push({current,""});
    while(!q.empty()){
        int cur = q.front().first;
        string DSLR = q.front().second;
        q.pop();
        if (cur==target) {
            cout << DSLR << '\n';
            return;
        }
        int DValue = (cur*2)%10000;
        int SValue = (cur-1<0) ? 9999 : cur-1;
        int LValue =(cur % 1000) * 10 + (cur / 1000);
        int RValue = cur / 10 + (cur % 10) * 1000;
        if (!visited[DValue]){
            visited[DValue] = true;
            q.push({DValue,DSLR+'D'});
        }
        if (!visited[SValue]){
            visited[SValue] = true;
            q.push({SValue,DSLR+'S'});
        }
        if (!visited[LValue]){
            visited[LValue] = true;
            q.push({LValue,DSLR+'L'});
        }
        if (!visited[RValue]) {
            visited[RValue] = true;
            q.push({RValue,DSLR+'R'});
        }
    }
}

int main() {
    fastcpp;
    cin >> test_case;
    while(test_case>0){
        test_case--;
        cin >> current >> target;
        memset(visited, false, sizeof(visited));
        bfs();
    }
    return 0;
}