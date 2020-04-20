#include <stdio.h>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

void fastScan(long long &x){
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

int main(){
    long long t, p, n, s[100003] = {}, cont = 1;
    scanf("%d\n", &t);
    while(t--){
    	long long  prefix[100003] = {};
        fastScan(n);
        fastScan(p);
        for(int i = 0; i < n; i++){
            fastScan(s[i]);
            prefix[i]=0;
        }
        sort(s, s + n, greater<long long>());
        prefix[n-1] = s[n-1];
        for(int i = n-2; i >= 0; i--){
            prefix[i] = prefix[i + 1] + s[i];
        }
        long long min = 999999999999;
        for(int i = 0; i <= n - p; i++){
            long long aux = p * s[i] - (prefix[i]- prefix[i+p]);
            if(aux < min){
                min = aux;
            }
        }
        printf("Case #%lld: %lld\n", cont++, min);
    }
}
