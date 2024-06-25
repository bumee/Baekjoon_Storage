#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(int a, int b){
    return a<b;
}

int num, howmany, n;
int lst[9];
int check[9];
int result[9];

void Permutation(int len){
    if(len==howmany){
        for(int i=0;i<howmany;i++){
            cout << result[i] << " ";
        }
        cout << '\n';
    }
    else{
        for(int i=0;i<num;i++){
            if(check[i]==0){
                result[len] = lst[i];
                check[i] = 1;
                Permutation(len+1);
                check[i] = 0;
            }
        }
    }
}

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    cin >> num >> howmany;
    for (int i=0;i<num;i++){
        cin >> lst[i];
    }
    sort(lst,lst+num);
    Permutation(0);

    return 0;
}