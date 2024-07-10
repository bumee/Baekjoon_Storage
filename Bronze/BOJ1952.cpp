#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

int m, n;
bool wall[101][101];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> m >> n;
    memset(wall, 0, sizeof(wall));
    int i=0;
    int mx=0;
    int my=0;
    int cnt = 1;
    int ans = 0;
    wall[0][0] = 1;
    while(1)
        {
            if(cnt==m*n)break;
            int next_x = mx+dx[i];
            int next_y = my+dy[i];
            if (wall[next_y][next_x] || next_y < 0 || next_y > m-1 || next_x < 0 || next_x > n-1){
                ans++;
                if(i==3)i=0;
                else i++;
            }
            else{
                cnt++;
                mx = next_x;
                my = next_y;
                wall[next_y][next_x] = 1;
            }
        }
    cout << ans << '\n';
    

    return 0;
}