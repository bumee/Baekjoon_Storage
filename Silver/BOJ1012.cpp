#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;
bool visited[52][52] = {false, };
int mp[52][52] = {0,};
int m,n,k,x,y;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
queue<pair<int,int>> q;

void bfs(int y, int x){
    visited[y][x] = true;
    q.push({y,x});

    while (!q.empty()){
        int cury = q.front().first;
        int curx = q.front().second;
        q.pop();

        for (int i=0;i<4;i++){
            int total_y = cury+dy[i];
            int total_x = curx+dx[i];
            if (total_x>=m || total_x<0 || total_y>=n || total_y<0) continue;
            if (visited[total_y][total_x] || mp[total_y][total_x]==0) continue;
            visited[total_y][total_x] = true;
            q.push({total_y,total_x});
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_case;
    cin >> test_case;
    int ans;
    for (int i=0;i<test_case;i++){
        for (int q=0;q<52;q++){
            for(int w=0;w<52;w++){
                visited[q][w] = false;
                mp[q][w] = 0;
            }
        }
        ans = 0;
        cin >> m >> n >> k;
        for (int j = 0; j < k; j++)
		{
			cin >> x >> y;
			mp[y][x] = 1;
		}
        for (int j=0;j<n;j++){
            for (int z=0;z<m;z++){
                if (!visited[j][z] && mp[j][z]==1){
                    bfs(j,z);
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
