#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, pair<int, int>> iii;
iii arr[100001];
int t, n, m,c,d;
vector<int>pset;
void fastScan(int &x){
    bool neg = false;
	register long long c;
	x = 0;
	c = getchar();
	if (c == '-')
	{
		neg = true;
		c = getchar();
	}
	for (; (c > 47 && c < 58); c = getchar())
		x = (x << 1) + (x << 3) + c - 48;
	if (neg)
		x *= -1;
}
void init() {
	pset = vector<int>(n, -1);
}
int findset(int nodo) {
	if (-1 == pset[nodo])
		return nodo;
	return pset[nodo] = findset(pset[nodo]);
}
bool isSameSet(int a, int b) {
	return findset(a) == findset(b);
}
void unionset(int a, int b) {
	if (!isSameSet(a, b))
		pset[findset(a)] = findset(b);
}
int main(){
    fastScan(t);
    for(int i = 1; i <= t; i++){
        fastScan(n);
        fastScan(m);
        for(int j = 0; j < m; j++){
            fastScan(c);
            fastScan(d);
            c--; d--;
            arr[j] = {1,{c,d}};
        }
        init();
        long long mst = 0;
        int cont = 0;
        for (int j = 0; j < m; j++) {
            if(cont == n-1) break;
			iii tri = arr[j];
			if (!isSameSet(tri.second.first, tri.second.second)) {
				mst += tri.first;
				unionset(tri.second.first, tri.second.second);
                cont++;
			}
		}

        if(cont < n - 1)
            mst += (n - 1 - cont) * 2;

        printf("Case #%d: %d\n", i, mst);
    }
    return 0;
}