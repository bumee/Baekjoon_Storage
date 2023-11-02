#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string test;
    unsigned int start;
    unsigned int end;
    getline(cin,test);
    istringstream ss(test);
    ss >> start >> end;
    
    vector<bool> check(end+1,false);
    check[1] = true;
    for (int i = 2; i*i<=end; i++){
		if (check[i] == false){
			for (int j = i + i; j <= end; j += i){
				check[j] = true;
			}
		}
	}
    for (int i=start;i<=end;i++){
        if (!check[i]) cout << i << '\n';
    }

    return 0;
}