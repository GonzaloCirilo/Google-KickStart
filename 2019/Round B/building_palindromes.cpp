#include <stdio.h>
#include <vector>
#include <set>
using namespace std;
int main() {
	int t, l, r, n, q, c = 1;
	vector<vector<int>>arr;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d\n", &n, &q);
		arr = vector<vector<int>>(27, vector<int>(n+1, 0));
		set<char> se;
		char rune;
		for (int i = 1; i <= n; i++) {
			scanf("%c", &rune);
			se.insert(rune);
			for (int j = 0; j < 27; j++) {
				arr[j][i] += arr[j][i - 1];
			}
			arr[rune - 'A'][i] ++;
		}
		int ans = 0;
		while (q--) {
			int abc[28] = {};
			scanf("%d %d", &l, &r);
			int isOdd = 0;
			for (auto i = se.begin(); i != se.end(); i++) {				
				isOdd += !((arr[*i - 'A'][r] - arr[*i - 'A'][l-1]) % 2)? 0 : 1;				
			}
			if (isOdd <= 1)
				ans++;
		}
		printf("Case #%d: %d\n", c++, ans);
	}
	return 0;
}