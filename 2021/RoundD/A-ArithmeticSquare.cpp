#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <map>
#include <numeric>

using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;

void solve(){
    vi g = vi(9);
    for(int i = 0; i < 8; i++){
        int ind = i >= 4 ? i + 1 : i;
        scanf("%d", &g[ind]);
    }
    map<int,int> d;
    int ans = 0; 
    ans += (g[1] - g[0]) == (g[2] - g[1]);
    ans += (g[7] - g[6]) == (g[8] - g[7]);
    ans += (g[3] - g[0]) == (g[6] - g[3]);
    ans += (g[5] - g[2]) == (g[8] - g[5]);

    if((g[1] + g[7]) % 2 == 0) d[(g[1]+g[7]) / 2]++;
    if((g[3] + g[5]) % 2 == 0) d[(g[3]+g[5]) / 2]++;
    if((g[0] + g[8]) % 2 == 0) d[(g[0]+g[8]) / 2]++;
    if((g[2] + g[6]) % 2 == 0) d[(g[2]+g[6]) / 2]++;

    int max = 0;

    for(auto x : d){
        if(x.second > max){
            max = x.second;
        }
    }
    printf(" %d\n", ans + max);
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