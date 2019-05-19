#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int>ii;
vector<vector<int>>table;
int t, n, s[102], e[102], l[102], indx[102];
int dp(int time, int r) {
	if (r == n) return 0;
	if (table[r][time] != -1) return table[r][time];
	int ti = dp(time + s[indx[r]], r + 1) + e[indx[r]] - (l[indx[r]] * time), nti = dp(time, r + 1);
	return table[r][time] = ti > nti ? ti : nti;
}
bool logic(int a, int b) {
	return l[a] * s[b] > l[b] * s[a];
}
int main() {
	scanf("%d", &t);
	int cont = 1;
	while (t--) {
		scanf("%d", &n);
		table = vector<vector<int>>(100, vector<int>(500000, -1));
		for (int i = 0; i < n; indx[i] = i, i++) {
			scanf("%d %d %d", &s[i], &e[i], &l[i]);
		}
		sort(indx, indx + n, logic);
		printf("Case #%d: %d\n", cont++, dp(0, 0));
	}

	return 0;
}