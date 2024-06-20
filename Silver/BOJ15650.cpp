#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int last, howmany;

void Combination(vector<int> arr, vector<int> result, int r, int index, int depth){
    if(r==howmany){
        for(int i=0;i<result.size();i++){
            cout << result[i] << " ";
        }
        cout << endl;
    }
    else if (depth==arr.size()){return;}
    else{
        result[index] = arr[depth];
        Combination(arr, result, r+1, index+1, depth+1);

        Combination(arr, result, r, index, depth+1);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> last >> howmany;

    vector<int> arr, result;

    for (int i=0;i<last;i++){arr.push_back(i+1);}
    for (int i=0;i<howmany;i++){result.push_back(0);}

    Combination(arr,result,0,0,0);
    
    return 0;
}