#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int t, n, p, k, plates[55][50] = {}, dp[55][1503] = {};

	scanf("%d", &t);

	for (int i = 1; i <= t; i++) {
		scanf("%d %d %d", &n, &k, &p);
		for (int j = 1; j <= n; j++) {
			for (int l = 1; l <= k; l++) {
				scanf("%d", &plates[j][l]);
			}
		}

		for (int j = 1; j <= n; j++) {
			for (int l = 2; l <= k; l++) {
				plates[j][l] += plates[j][l - 1];
			}
		}

		for(int x = 1; x <= n; x++){
			for(int y = 0; y <= p; y++){
				dp[x][y] = 0;
				for(int z = 0 ; z <= min(y, k); z++){
					dp[x][y] = max(dp[x][y], plates[x][z] + dp[x - 1][y - z]);
				}
			}
		}

		printf("Case #%d: %d\n", i, dp[n][p]);

	}

	return 0;
}