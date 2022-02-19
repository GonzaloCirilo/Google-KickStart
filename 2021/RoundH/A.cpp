#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <numeric>
#include <string>

using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;

void solve(){
    string s, f;
    cin >> s >> f;
    int ans = 0;
    vector <int> mins = vector<int>(s.size(), 20);
    for(auto x : f) {
        int ss = 20;
        for(int i = 0; i < s.size(); i++) {
            char y = s[i];
            int iy = y - 'a', ix = x - 'a';
            int du = (iy - ix +26) % 26, dd = (ix  - iy + 26) % 26;
            //cout << "===" << iy << " " << ix << " : " << du << " " << dd <<endl;
            mins[i] = min(mins[i], min(du, dd));
        }
    }

    for(int i = 0; i < mins.size(); i++) {
        ans += mins[i];
    }
    
    cout << " " << ans << endl;

}

int main(){
    int t;
    cin >> t;
    for(int ts = 0; ts < t; ts++){
        cout << "Case #" << ts + 1 << ":";
        solve();
    }
    return 0;
}