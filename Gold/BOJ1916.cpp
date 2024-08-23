#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>

#define INF 1e9

using namespace std;
vector<int> score;
vector<vector<pair<int,int>>> mp;
int city, bus, from, to;

void solve() {
    priority_queue<pair<int,int>> q;
    score.assign(city + 1, INF); 

    score[from] = 0;
    q.push(make_pair(0, from));

    while(!q.empty()){
        int cost = q.top().first;
        int cur = q.top().second;
        q.pop();

        if (score[cur] < cost){
            continue;
        }

        for (int i = 0; i < mp[cur].size(); i++) {
            int ViaCost = cost + mp[cur][i].first;
            int Next = mp[cur][i].second;
            if (score[Next] < ViaCost)
                continue;
            score[Next] = ViaCost;
            q.push({ViaCost, Next});
        }
        
    }
    cout << score[to] << '\n';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> city;
    cin >> bus;
    mp.resize(city + 1); 
    for (int i = 0; i < bus; i++)
    {
        int start, ends, value;
        cin >> start >> ends >> value;
        mp[start].push_back({value, ends});
    }
    cin >> from >> to;
    solve();

    return 0;
}