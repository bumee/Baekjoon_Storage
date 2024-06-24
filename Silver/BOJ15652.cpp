#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int howmany, last;

void Comb(vector<int> arr, vector<int> result, int r, int idx, int depth){
    if(r==howmany){
        for (int i=0;i<result.size();i++){
            cout << result[i] << " ";
        }
        cout << "\n";
    }
    else if (depth==arr.size()){return;}
    else {
        result[idx] = arr[depth];
        Comb(arr, result, r+1, idx+1, depth);

        Comb(arr, result, r, idx, depth+1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> arr, result;  

    cin >> last >> howmany;
    for(int i=0;i<last;i++){arr.push_back(i+1);}
    for(int i=0;i<howmany;i++){result.push_back(0);}  

    Comb(arr,result,0,0,0);
    return 0;
}