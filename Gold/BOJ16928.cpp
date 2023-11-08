#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#define fastcpp ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)

using namespace std;
int latter, snake, from, to;
int board[101] = {0, };
bool visited[101];

int game(int start, int c){
    queue<pair<int,int>> q;
    q.push({start,c});
    while (!q.empty()){
        int x = q.front().first;
        int cnt = q.front().second;
        q.pop();
        for (int i=1;i<=6;i++){
            int nx = x+i;
            if (nx >= 100){
                return cnt+1;
            }
            while(board[nx]!=0) nx = board[nx];
            if (visited[nx]) continue;
            visited[nx] = true;
            q.push({nx, cnt+1});
        }
    }
}

int main() {
    fastcpp;
    cin >> latter >> snake;
    for(int i=0;i<latter;i++){
        cin >> from >> to;
        board[from] = to;
    }
    for(int i=0;i<snake;i++){
        cin >> from >> to;
        board[from] = to;
    }
    cout << game(1, 0);
    return 0;
}