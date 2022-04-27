#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <numeric>

using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;

const double PI = 3.14159265358979323846;

void solve(){
    int r, a, b;
    cin >> r >> a >> b;

    double ans = PI * r * r;

    while(r != 0) {
        r *= a;
        ans += PI * r * r;
        r /= b;
        ans += PI * r * r;
    }

    printf("%.6f\n", ans);
}

int main(){
    int t;
    cin >> t;
    for(int ts = 0; ts < t; ts++){
        cout << "Case #" << ts + 1 << ": ";
        solve();
    }
    return 0;
}