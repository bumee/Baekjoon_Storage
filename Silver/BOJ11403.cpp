#include <iostream>
#include <algorithm>
#include <queue>
#include <sstream>
#include <cstring>

using namespace std;
int n, dap;
string s;
int dplist [100][100];
vector<int> anslist[100];
bool visited[100];
void bfs(int start){
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int k = q.front();
        q.pop();
        for (int i=0;i<anslist[k].size();i++){
            int j = anslist[k][i];
            if (visited[j]) continue;
            visited[j] = true;
            q.push(j);
            dplist[start][j] = 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    cin.ignore();
    for (int i=0;i<n;i++){
        getline(cin, s);
        int j=0;
        istringstream ss(s);
        while (ss >> dap) {
            if (dap==1) {
                anslist[i].push_back(j);
            }
            dplist[i][j] = dap;
            j++;
        }
        dplist[i][i] = 0;
    }
    for (int i=0;i<n;i++){
        memset(visited, false, sizeof(visited));
        bfs(i);
    }
    for (int i=0;i<n;i++){
        for (int j=0;j<n;j++){
            cout << dplist[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}