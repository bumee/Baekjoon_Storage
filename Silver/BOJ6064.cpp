#include <iostream>
#include <algorithm>

using namespace std;
int test_case;
int m, n, x, y;

long long int gcd(int a, int b){
    int c;
    while (b!=0){
        c = a%b;
        a = b;
        b = c;
    }
    return a;
}
long long int lcm(int a, int b){
    return a*b / gcd(a,b);
}

int search(int m, int n, int x, int y) {
    int startx = 1;
    int endy = 1;
    long long int k = lcm(m,n);
    if (m<n){
        startx += x-1;
        endy += x-1;
        if (startx==x && endy==y) return x;
        for (long long int i=m;i<=k;i+=m){
            int j = (endy+i)%n;
            int target = (j==0 ? n : j);
            if (target==y) return i+x;
        }
    }
    else {
        startx += y-1;
        endy += y-1;
        if (startx==x && endy==y) return y;
        for (long long int i=n;i<=k;i+=n){
            int j = (startx+i)%m;
            int target = (j==0 ? m : j);
            if (target==x) return i+y;
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> test_case;
    while (test_case>0) {
        test_case--;
        cin >> m >> n >> x >> y;
        cout << search(m,n,x,y) << '\n';
    }

    return 0;
}