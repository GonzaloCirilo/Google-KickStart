#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <map>

using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;

void solve(){
    int n; long long c;
    scanf("%d %lld", &n, &c);
    map<long long, int> d;
    for(int i = 0; i < n; i++){
        long long l, r;
        scanf("%lld %lld", &l, &r);
        l++;
        d[l]++;
        d[r]--;
    }
    vector<long long> a = vector<long long>(n + 1);
    int j = 0;
    long long prev = 0;
    for(auto x : d){
        if(j != 0)
            a[j] += x.first - prev;
        j += x.second;
        prev = x.first;
    }
    long long ans = 0;
    for(int j = n; j >= 0; j--){
        if (c == 0) break;
        ans += j * min(a[j], c);
        c -= min(a[j], c);
    }
    printf(" %lld\n", ans + n);
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