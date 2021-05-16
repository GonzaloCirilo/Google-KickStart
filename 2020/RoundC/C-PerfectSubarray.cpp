#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <numeric>
#include <set>
#include <map>

using namespace std;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<int> vi;

bool fastScan(int &x) {
	bool neg = false;
	int c = getchar();
	bool end = c == EOF;
	if (end)
		return false;
	x = 0;
	if (c == '-') {
		neg = true;
		c = getchar();
	}
	for (; (c > 47 && c < 58); c = getchar())
		x = (x << 1) + (x << 3) + c - 48;
	if (neg)
		x *= -1;
	return true;
}

vi generatePerfectSquares(int n){
    vi s = vi();
    s.push_back(0);
    for(int i = 1; i * i <= n * n; i++){
        s.push_back(i * i);
    }
    return s;
}

void solve(){
    int n;
    fastScan(n);
    vi arr = vi(n), prefix = vi();
    vector<long long> res = vector<long long>(n + 1);
    int offset = 0;
    prefix.push_back(0);
    int maxe = 0;
    for(int i = 0; i < n; i++){
        fastScan(arr[i]);
        prefix.push_back(prefix[i] + arr[i]);
        offset = min(offset,prefix[i + 1]);
        maxe = max(maxe, prefix[i + 1]);
    }
    offset = min(offset, 0) * -1;
    vi s = generatePerfectSquares(*(max_element(arr.begin(), arr.end())) * n);
    vi p = vi(maxe + 1 + offset, 0);
    for(int i = 0; i < n + 1; i++){
        for(int j = 0; j < s.size(); j++){
            if(prefix[i] - s[j] + offset < 0) break;
            res[i] += p[prefix[i] - s[j] + offset];
        }
        p[prefix[i] + offset]++;
    }
    long long ans = 0;
    for(int i = 0; i < res.size(); i++){
        //printf(" %d", res[i]);
        ans += res[i];
    }
    printf(" %lld\n", ans);
}

int main(){
    int t;
    fastScan(t);
    for(int ts = 0; ts < t; ts++){
        cout << "Case #" << ts + 1 << ":";
        solve();
    }
}