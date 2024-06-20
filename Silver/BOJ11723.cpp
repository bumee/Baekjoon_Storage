#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string inst;
    int check, howmany;
    check = 0;

    int s = 0;

    cin >> howmany;
    while(howmany>0){
        howmany--;
        cin >> inst;
        if(inst=="check"){
            cin >> check;
            if (s & (1<<check)){cout << 1 << '\n';}
            else{cout << 0 << '\n';}
        }
        else if (inst == "all"){s |= (1<<32)-1;}
        else if (inst == "empty"){s = 0;}
        else if (inst == "add"){
            cin >> check;
            s |= (1<<check);
        }
        else if (inst == "remove"){
            cin >> check;
            s &= ~(1<<check);
        }
        else if (inst == "toggle"){
            cin >> check;
            if (s & (1<<check)){s &= ~(1<<check);}
            else{s |= (1<<check); }
        }
    }
    return 0;
}